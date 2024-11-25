#ifndef CUSTOMSCAN_H
#define CUSTOMSCAN_H

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

    ClamAVTester();
    ~ClamAVTester();
    bool initialize();
    bool scanFile(const std::string& filepath);
    void scanDirectory(const std::string& dirpath);

private:
    cl_engine* engine;
    unsigned int sigs;
    struct cl_scan_options options;
    Database database;
};

#endif