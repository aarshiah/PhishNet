#ifndef SYSTEMSCAN_H
#define SYSTEMSCAN_H

#include <iostream>
#include <cstdlib>
#include <clamav.h>
#include <string>
#include <filesystem>
#include <chrono>
#include <vector>
#include <thread>
#include <algorithm>
#include "Database.h"

namespace fs = std::filesystem;

class SystemScan {
private:
    cl_engine* engine;
    unsigned int sigs;
    struct cl_scan_options options;
    Database database;
    int filesScanned;
    int threatsFound;
    std::chrono::steady_clock::time_point lastUpdateTime;

    // Main system directories to scan
    std::vector<std::string> rootDirs = {
        "/",
        "/home",
        "/usr",
        "/opt", 
        "/var",
        "/tmp"
    };

    // Skip these - system/mount dirs that don't need scanning
    std::vector<std::string> skipDirs = {
        "/proc",
        "/sys", 
        "/dev",
        "/run",
        "/media",
        "/mnt"
    };

    bool shouldSkipDirectory(const std::string& path);
    bool initializeClamAV();
    bool scanFile(const std::string& filepath);
    void scanDirectory(const fs::path& path);
    void quarantineFile(const std::string& filepath);
    const std::string quarantinePath = "/home/gianmarco/clamav/custom-clam-scanner/build/Quarantine";

public:
    SystemScan();
    ~SystemScan();
    void startScan();
    int getFilesScanned() const { return filesScanned; }
    int getThreatsFound() const { return threatsFound; }
};

#endif // SYSTEMSCAN_H