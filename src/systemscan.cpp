#include "systemscan.h"

SystemScan::SystemScan() : engine(nullptr), filesScanned(0), threatsFound(0) {
    lastUpdateTime = std::chrono::steady_clock::now();
}

SystemScan::~SystemScan() {
    if (engine != nullptr) {
        cl_engine_free(engine);
    }
}

bool SystemScan::shouldSkipDirectory(const std::string& path) {
    return std::any_of(skipDirs.begin(), skipDirs.end(),
        [&path](const std::string& skipDir) {
            return path.find(skipDir) == 0;
        });
}

bool SystemScan::initializeClamAV() {
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

bool SystemScan::scanFile(const std::string& filepath) {
    const char* virname = nullptr;
    unsigned long int scanned = 0;
    cl_error_t ret;

    filesScanned++;
    
    auto now = std::chrono::steady_clock::now();
    if (std::chrono::duration_cast<std::chrono::seconds>(now - lastUpdateTime).count() >= 2) {
        std::cout << "\rFiles scanned: " << filesScanned << " | Threats found: " << threatsFound << std::flush;
        lastUpdateTime = now;
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

void SystemScan::scanDirectory(const fs::path& path) {
    if (shouldSkipDirectory(path.string())) {
        return;
    }

    try {
        for (const auto& entry : fs::recursive_directory_iterator(
            path,
            fs::directory_options::skip_permission_denied
        )) {
            if (fs::is_regular_file(entry)) {
                scanFile(entry.path().string());
            }
        }
    } catch (const fs::filesystem_error& e) {
        // Skip inaccessible directories
    }
}

void SystemScan::startScan() {
    auto start_time = std::chrono::steady_clock::now();

    std::cout << "=== System Scan Starting ===\n";
    std::cout << "This may take a while...\n\n";
    
    database.startSession("system");

    if (!initializeClamAV()) {
        std::cerr << "Scanner initialization failed\n";
        return;
    }

    for (const auto& rootDir : rootDirs) {
        if (fs::exists(rootDir)) {
            scanDirectory(rootDir);
        }
    }

    auto end_time = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::minutes>(end_time - start_time);

    database.endSession(filesScanned, threatsFound);

    std::cout << "\n\nScan Summary:\n";
    std::cout << "-------------\n";
    std::cout << "Duration: " << duration.count() << " minutes\n";
    std::cout << "Files Scanned: " << filesScanned << "\n";
    if (threatsFound > 0) {
        std::cout << "Threats Detected: " << threatsFound << std::endl;
    } else {
        std::cout << "No Threats Detected" << std::endl;
    }
}