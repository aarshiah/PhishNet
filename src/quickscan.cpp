#include "quickscan.h"
#include <algorithm>
#include <glob.h>

QuickScan::QuickScan() : engine(nullptr), filesScanned(0), threatsFound(0) {}

QuickScan::~QuickScan() {
    if (engine != nullptr) {
        cl_engine_free(engine);
    }
}

bool QuickScan::isTargetFile(const fs::path& file) {
    std::string ext = file.extension().string();
    std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
    return std::find(targetExtensions.begin(), targetExtensions.end(), ext) != targetExtensions.end();
}

bool QuickScan::initializeClamAV() {
    cl_error_t ret;
    
    ret = cl_init(CL_INIT_DEFAULT);
    if (ret != CL_SUCCESS) {
        std::cerr << "Failed to initialize libclamav: " << cl_strerror(ret) << std::endl;
        return false;
    }
    
    engine = cl_engine_new();
    if (engine == nullptr) {
        std::cerr << "Failed to create new engine" << std::endl;
        return false;
    }
    
    ret = cl_load(cl_retdbdir(), engine, &sigs, CL_DB_STDOPT);
    if (ret != CL_SUCCESS) {
        std::cerr << "Failed to load virus database: " << cl_strerror(ret) << std::endl;
        cl_engine_free(engine);
        return false;
    }
    
    ret = cl_engine_compile(engine);
    if (ret != CL_SUCCESS) {
        std::cerr << "Engine compilation failed: " << cl_strerror(ret) << std::endl;
        cl_engine_free(engine);
        return false;
    }

    memset(&options, 0, sizeof(struct cl_scan_options));
    options.parse = ~0;
    options.general = CL_SCAN_GENERAL_ALLMATCHES;
    
    return true;
}

bool QuickScan::scanFile(const std::string& filepath) {
    const char* virname = nullptr;
    unsigned long int scanned = 0;
    cl_error_t ret;

    filesScanned++;
    
    if (filesScanned % 50 == 0) {
        std::cout << "\rFiles scanned: " << filesScanned << std::flush;
    }
    
    ret = cl_scanfile(filepath.c_str(), &virname, &scanned, engine, &options);
    
    switch (ret) {
        case CL_CLEAN:
            database.logScanResult(filepath, false);
            return true;
            
        case CL_VIRUS:
            std::cout << "\n[!] Threat detected in: " << filepath << "\n[!] Threat name: " << virname << std::endl;
            database.logScanResult(filepath, true, virname);
            threatsFound++;
            return false;
            
        default:
            return false;
    }
}

void QuickScan::scanDirectory(const fs::path& path) {
    try {
        for (const auto& entry : fs::recursive_directory_iterator(
            path,
            fs::directory_options::skip_permission_denied
        )) {
            if (fs::is_regular_file(entry) && isTargetFile(entry)) {
                scanFile(entry.path().string());
            }
        }
    } catch (const fs::filesystem_error& e) {
        // Skip inaccessible directories
    }
}

void QuickScan::startScan() {
    auto start_time = std::chrono::steady_clock::now();

    std::cout << "=== Quick Scan Starting ===\n";
    
    database.startSession("quick");

    if (!initializeClamAV()) {
        std::cerr << "Scanner initialization failed\n";
        return;
    }

    for (const auto& location : scanLocations) {
        glob_t glob_result;
        if (glob(location.c_str(), GLOB_TILDE, nullptr, &glob_result) == 0) {
            for (size_t i = 0; i < glob_result.gl_pathc; ++i) {
                scanDirectory(glob_result.gl_pathv[i]);
            }
        }
        globfree(&glob_result);
    }

    auto end_time = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);

    database.endSession(filesScanned, threatsFound);

    if (threatsFound > 0) {
        std::cout << "\nScan Complete - Threats Detected: " << threatsFound << std::endl;
    } else {
        std::cout << "\nScan Complete - No Threats Detected" << std::endl;
    }
}