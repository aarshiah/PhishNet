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

// Quick malware scanner focusing on high-risk locations and file types
class QuickScan {
private:
   cl_engine* engine;
   unsigned int sigs;
   struct cl_scan_options options;
   Database database;
   int filesScanned;
   int threatsFound;
   
   // Common malware file extensions to check
   std::vector<std::string> targetExtensions = {
       ".exe", ".dll", ".com", ".bat", ".cmd", ".vbs", ".js", 
       ".jar", ".ps1", ".msi", ".py", ".sh", ".bin",
       ".doc", ".docx", ".pdf", ".zip", ".rar", ".7z"
   };

   // High-risk system locations that often contain malware
   std::vector<std::string> scanLocations = {
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

   // Helper functions for scanning process
   bool isTargetFile(const fs::path& file);
   bool initializeClamAV();
   bool scanFile(const std::string& filepath);
   void scanDirectory(const fs::path& path);
   void quarantineFile(const std::string& filepath);
   const std::string quarantinePath = "/home/gianmarco/clamav/custom-clam-scanner/build/Quarantine";

public:
   QuickScan();
   ~QuickScan();
   // Starts quick scan of specified locations and extensions
   void startScan();
};

#endif