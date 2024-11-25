#ifndef QUICKSCAN_H
#define QUICKSCAN_H

#include <iostream>
#include <cstdlib>
#include <clamav.h>
#include <string>
#include <filesystem>
#include <chrono>
#include <vector>
#include "Database.h"

namespace fs = std::filesystem;

class QuickScan {
private:
    cl_engine* engine;
    unsigned int sigs;
    struct cl_scan_options options;
    Database database;
    int filesScanned;
    int threatsFound;
    
    const std::vector<std::string> targetExtensions = {
        ".exe", ".dll", ".com", ".bat", ".cmd", ".vbs", ".js", 
        ".jar", ".ps1", ".msi", ".py", ".sh", ".bin",
        ".doc", ".docx", ".pdf", ".zip", ".rar", ".7z"
    };

    const std::vector<std::string> scanLocations = {
        "/home/*/Downloads",
        "/home/*/Desktop",
        "/tmp",
        "/var/tmp",
        "/home/*/.cache",
        "/home/*/.local/share",
        "/opt",
        "/usr/local/bin",
        "/var/cache"
    };

    bool isTargetFile(const fs::path& file);
    bool initializeClamAV();
    bool scanFile(const std::string& filepath);
    void scanDirectory(const fs::path& path);

public:
    QuickScan();
    ~QuickScan();
    void startScan();
};

#endif