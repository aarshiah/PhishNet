#include <iostream>
#include <cstdlib>
#include <clamav.h>
#include <string>
#include <sstream>
#include <memory>
#include <array>
#include <filesystem>


class ClamAVTester {
private:
   cl_engine* engine;
   unsigned int sigs;
   struct cl_scan_options options;
    // this is the directory path for the quarantine file, change as needed
   const std::string quarantinePath = "/home/ubuntu/Desktop/PhishNetCode/PhishNet/Quarantine";


public:
   ClamAVTester() : engine(nullptr), sigs(0) {
       // Initialize scan options
       memset(&options, 0, sizeof(struct cl_scan_options));
       options.parse = ~0;                        // Enable all parse options
       options.general = CL_SCAN_GENERAL_ALLMATCHES;
   }


   bool initialize() {
       cl_error_t ret;


       // Initialize ClamAV library
       ret = cl_init(CL_INIT_DEFAULT);
       if (ret != CL_SUCCESS) {
           std::cerr << "Failed to initialize libclamav: " << cl_strerror(ret) << std::endl;
           return false;
       }


       // Create new engine
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


       // Compile engine
       ret = cl_engine_compile(engine);
       if (ret != CL_SUCCESS) {
           std::cerr << "Engine compilation failed: " << cl_strerror(ret) << std::endl;
           cl_engine_free(engine);
           return false;
       }


       return true;
   }


   void quarantineFile(const std::string& filepath) {
       // Check if the source file exists
       //if (!std::filesystem::exists(filepath)) {
       //    std::cerr << "Error: File does not exist: " << filepath << std::endl;
       //    return;
       //}


       // Construct the destination path
       std::string filename = std::filesystem::path(filepath).filename().string();
       std::string destination = quarantinePath + "/" + filename;


       // Ensure the destination directory exists
       if (!std::filesystem::exists(quarantinePath)) {
           std::cerr << "Error: Quarantine path does not exist: " << quarantinePath << std::endl;
           return;
       }


       // Move the file
       std::error_code ec; // For capturing errors
       std::filesystem::rename(filepath, destination, ec);
       if (ec) {
           std::cerr << "Error moving file to quarantine: " << ec.message() << std::endl;
       } else {
           std::cout << "File successfully moved to quarantine: " << destination << std::endl;
       }
   }


   bool scanFile(const std::string& filepath) {
       const char* virname = nullptr;
       unsigned long int scanned = 0;
       cl_error_t ret;


       ret = cl_scanfile(filepath.c_str(), &virname, &scanned, engine, &options);


       switch (ret) {
           case CL_CLEAN:
               std::cout << "File clean: " << filepath << std::endl;
               return true;


           case CL_VIRUS:
               std::cout << "Virus detected in " << filepath << ": " << virname << std::endl;
               quarantineFile(filepath);
               return false;


           default:
               std::cout << "Error scanning file " << filepath << ": " << cl_strerror(ret) << std::endl;
               return false;
       }
   }


   void scanDirectory(const std::string& dirpath) {
       std::string command = "ls -A \"" + dirpath + "\"";  // Command to list directory contents
       std::array<char, 128> buffer;
       std::string result;


       // Use popen to run the command and get output
       std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(), "r"), pclose);
       if (!pipe) {
           std::cerr << "Failed to open directory: " << dirpath << std::endl;
           return;
       }


       while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
           std::string filename(buffer.data());
           filename.erase(filename.find_last_not_of(" \n\r\t") + 1);  // Trim whitespace


           std::string filepath = dirpath + "/" + filename;


           // Check if the entry is a directory or file
           std::string testCommand = "test -d \"" + filepath + "\" && echo dir || echo file";
           std::array<char, 8> testBuffer;
           std::string typeResult;


           std::unique_ptr<FILE, decltype(&pclose)> testPipe(popen(testCommand.c_str(), "r"), pclose);
           if (fgets(testBuffer.data(), testBuffer.size(), testPipe.get()) != nullptr) {
               typeResult = testBuffer.data();
               typeResult.erase(typeResult.find_last_not_of(" \n\r\t") + 1);
           }


           if (typeResult == "dir") {
               scanDirectory(filepath);  // Recursively scan subdirectory
           } else if (typeResult == "file") {
               scanFile(filepath);       // Scan file
           }
       }
   }


   ~ClamAVTester() {
       if (engine != nullptr) {
           cl_engine_free(engine);
       }
   }
};


int main(int argc, char* argv[]) {
   if (argc != 3) {
       std::cerr << "Usage: " << argv[0] << " <scan_type> <path_to_scan>" << std::endl;
       return 1;
   }


   std::string scan_type = argv[1];
   std::string path = argv[2];


   ClamAVTester tester;


   if (!tester.initialize()) {
       std::cerr << "Failed to initialize ClamAV" << std::endl;
       return 1;
   }


   if (scan_type == "file") {
       tester.scanFile(path);
   } else if (scan_type == "directory") {
       tester.scanDirectory(path);
   } else {
       std::cerr << "Invalid scan type. Use 'file' or 'directory'." << std::endl;
       return 1;
   }


   return 0;
}












