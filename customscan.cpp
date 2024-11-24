#include <iostream>
#include <cstdlib>
#include <clamav.h>
#include <string>
#include <sstream>
#include <memory>
#include <array>
#include <iomanip>
#include "Database.h"

class ClamAVTester {
public:  
    int filesScanned;
    int threatsFound;

private:
    cl_engine* engine;
    unsigned int sigs;
    struct cl_scan_options options;
    Database database;

public:
    ClamAVTester() : engine(nullptr), sigs(0), filesScanned(0), threatsFound(0) {
        memset(&options, 0, sizeof(struct cl_scan_options));
        options.parse = ~0;
        options.general = CL_SCAN_GENERAL_ALLMATCHES;
    }

    bool initialize() {
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

    bool scanFile(const std::string& filepath) {
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

    void scanDirectory(const std::string& dirpath) {
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
    
    ~ClamAVTester() {
        if (engine != nullptr) {
            cl_engine_free(engine);
        }
    }
};

void displayUsage(const char* programName) {
    std::cout << "Usage: " << programName << " <scan_type> [path_to_scan]\n\n"
              << "Scan Types:\n"
              << "  file      - Scan a single file\n"
              << "  directory - Scan an entire directory\n"
              << "  history   - View scan history\n\n"
              << "Examples:\n"
              << "  " << programName << " file /path/to/file\n"
              << "  " << programName << " directory /path/to/directory\n"
              << "  " << programName << " history\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        displayUsage(argv[0]);
        return 1;
    }

    std::string scan_type = argv[1];
    Database database;

    if (scan_type == "history") {
        database.viewScanHistory();
        return 0;
    }

    if (argc < 3) {
        std::cerr << "Error: Path required for file or directory scan\n";
        displayUsage(argv[0]);
        return 1;
    }

    std::string path = argv[2];
    ClamAVTester tester;

    if (!tester.initialize()) {
        std::cerr << "Failed to initialize ClamAV" << std::endl;
        return 1;
    }

    if (scan_type == "file") {
        database.startSession("custom_file");
        std::cout << "Starting file scan...\n";
        tester.scanFile(path);
    } else if (scan_type == "directory") {
        database.startSession("custom_directory");
        std::cout << "Starting directory scan...\n";
        tester.scanDirectory(path);
    } else {
        std::cerr << "Invalid scan type. Use 'file', 'directory', or 'history'." << std::endl;
        displayUsage(argv[0]);
        return 1;
    }

    database.endSession(tester.filesScanned, tester.threatsFound);
    
    if (tester.threatsFound > 0) {
        std::cout << "\nScan Complete - Threats Detected: " << tester.threatsFound << std::endl;
    } else {
        std::cout << "\nScan Complete - No Threats Detected" << std::endl;
    }

    return 0;
}
