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

    const std::vector<std::string> rootDirs = {
        "/",
        "/home",
        "/usr",
        "/opt",
        "/var",
        "/tmp"
    };

    const std::vector<std::string> skipDirs = {
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

public:
    SystemScan();
    ~SystemScan();
    void startScan();
};

#endif