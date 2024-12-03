#include "quickscan.h"
#include <algorithm>
#include <glob.h>
#include <filesystem>

// Initialize scanner with target files and locations to check
QuickScan::QuickScan() 
   : engine(nullptr), filesScanned(0), threatsFound(0) {
   // High-risk file extensions commonly used by malware
   targetExtensions = {
       ".exe", ".dll", ".com", ".bat", ".cmd", ".scr", ".pif",
       ".doc", ".docx", ".xls", ".xlsx", ".pdf", ".zip", ".rar", 
       ".js", ".vbs", ".hta", ".bin", ".iso", ".msi", ".ps1"
   };
   
   // Common locations where malware hides
   scanLocations = {
       "~/Downloads/*",
       "~/Desktop/*", 
       "~/Documents/*"
   };
}

QuickScan::~QuickScan() {
   if (engine != nullptr) {
       cl_engine_free(engine);
   }
}

// Check if file extension matches our target list
bool QuickScan::isTargetFile(const fs::path& file) {
   std::string ext = file.extension().string();
   std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
   return std::find(targetExtensions.begin(), targetExtensions.end(), ext) != targetExtensions.end();
}

// Set up ClamAV scanning engine
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
   
   // Load virus database
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

// Move infected file to quarantine folder
void QuickScan::quarantineFile(const std::string& filepath) {
   try {
       fs::create_directories(quarantinePath);
       
       std::string filename = fs::path(filepath).filename().string();
       std::string destination = (fs::path(quarantinePath) / filename).string();
       
       fs::rename(filepath, destination);
       std::cout << "File successfully moved to quarantine: " << destination << std::endl;
       
       database.logScanResult(destination, true, "quarantined");
       
   } catch (const fs::filesystem_error& e) {
       std::cerr << "Error moving file to quarantine: " << e.what() << std::endl;
   }
}

// Scan individual file for threats
bool QuickScan::scanFile(const std::string& filepath) {
   const char* virname = nullptr;
   unsigned long int scanned = 0;
   cl_error_t ret;

   filesScanned++;
   
   // Show progress periodically
   if (filesScanned % 50 == 0) {
       std::cout << "\rFiles scanned: " << filesScanned << std::flush;
   }
   
   ret = cl_scanfile(filepath.c_str(), &virname, &scanned, engine, &options);
   
   switch (ret) {
       case CL_CLEAN:
           database.logScanResult(filepath, false);
           return true;
           
       case CL_VIRUS:
           std::cout << "\n[!] Threat detected in: " << filepath 
                    << "\n[!] Threat name: " << virname << std::endl;
           database.logScanResult(filepath, true, virname);
           threatsFound++;
           quarantineFile(filepath);
           return false;
           
       default:
           std::cerr << "\nError scanning file " << filepath 
                    << ": " << cl_strerror(ret) << std::endl;
           database.logScanResult(filepath, false, "scan_error");
           return false;
   }
}

// Recursively scan directory for target files
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
       std::cerr << "Error accessing directory: " << e.what() << std::endl;
   }
}

// Main scanning function - checks all target locations
void QuickScan::startScan() {
   auto start_time = std::chrono::steady_clock::now();

   std::cout << "=== Quick Scan Starting ===\n";
   std::cout << "Scanning common locations for suspicious files...\n\n";
   
   database.startSession("quick");

   if (!initializeClamAV()) {
       std::cerr << "Scanner initialization failed\n";
       return;
   }

   // Process each target location
   for (const auto& location : scanLocations) {
       glob_t glob_result;
       if (glob(location.c_str(), GLOB_TILDE, nullptr, &glob_result) == 0) {
           for (size_t i = 0; i < glob_result.gl_pathc; ++i) {
               scanDirectory(glob_result.gl_pathv[i]);
           }
       }
       globfree(&glob_result);
   }

   // Show scan summary
   auto end_time = std::chrono::steady_clock::now();
   auto duration = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);

   database.endSession(filesScanned, threatsFound);

   std::cout << "\n\nQuick Scan Summary:\n";
   std::cout << "------------------\n";
   std::cout << "Duration: " << duration.count() << " seconds\n";
   std::cout << "Files Scanned: " << filesScanned << "\n";
   if (threatsFound > 0) {
       std::cout << "Threats Detected: " << threatsFound << "\n";
       std::cout << "Threats have been moved to: " << quarantinePath << std::endl;
   } else {
       std::cout << "No Threats Detected" << std::endl;
   }
}