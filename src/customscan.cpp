#include "customscan.h"

ClamAVTester::ClamAVTester() : engine(nullptr), sigs(0), filesScanned(0), threatsFound(0) {
    memset(&options, 0, sizeof(struct cl_scan_options));
    options.parse = ~0;
    options.general = CL_SCAN_GENERAL_ALLMATCHES;
}

ClamAVTester::~ClamAVTester() {
    if (engine != nullptr) {
        cl_engine_free(engine);
    }
}

bool ClamAVTester::initialize() {
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
    
    return true;
}

bool ClamAVTester::scanFile(const std::string& filepath) {
    const char* virname = nullptr;
    unsigned long int scanned = 0;
    cl_error_t ret;
    
    filesScanned++;
    if (filesScanned % 100 == 0) {
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
            database.logScanResult(filepath, false);
            return false;
    }
}

void ClamAVTester::scanDirectory(const std::string& dirpath) {
    std::string command = "ls -A \"" + dirpath + "\"";
    std::array<char, 128> buffer;
    
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(), "r"), pclose);
    if (!pipe) {
        std::cerr << "Failed to open directory: " << dirpath << std::endl;
        return;
    }
    
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        std::string filename(buffer.data());
        filename.erase(filename.find_last_not_of(" \n\r\t") + 1);
        std::string filepath = dirpath + "/" + filename;
        
        std::string testCommand = "test -d \"" + filepath + "\" && echo dir || echo file";
        std::array<char, 8> testBuffer;
        std::string typeResult;

        std::unique_ptr<FILE, decltype(&pclose)> testPipe(popen(testCommand.c_str(), "r"), pclose);
        if (fgets(testBuffer.data(), testBuffer.size(), testPipe.get()) != nullptr) {
            typeResult = testBuffer.data();
            typeResult.erase(typeResult.find_last_not_of(" \n\r\t") + 1);
        }
        
        if (typeResult == "dir") {
            scanDirectory(filepath);
        } else if (typeResult == "file") {
            scanFile(filepath);
        }
    }
}