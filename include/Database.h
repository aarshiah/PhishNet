#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>
#include <vector>
#include <filesystem>

struct ScanRecord {
    std::string file_path;    // Path of scanned file
    bool detected;            // Whether a threat was detected
    std::string scan_date;    // Date when scan was performed
    std::string threat_name;  // Name of the detected threat
    std::string scan_type;    // Type of scan performed
};

struct ScanSession {
    std::string session_id;    // Unique identifier for scan session
    std::string scan_type;     // Type of scan (quick, system, custom)
    std::string start_time;    // When the scan started
    std::string end_time;      // When the scan completed
    int files_scanned;         // Total number of files scanned
    int threats_found;         // Total number of threats detected
};

class Database {
private:
    sqlite3* db;                      // SQLite database connection pointer
    std::string current_session_id;   // Current scan session identifier
    
    void createTables();              // Creates necessary database tables
    std::string generateSessionId();  // Generates unique session ID
    std::string getCurrentTimestamp();// Gets current time as string
    void generateReport(const std::string& session_id); // Generates scan report

public:
    Database();  // Constructor to initialize database
    ~Database(); // Destructor to clean up resources
    
    // Session management
    void startSession(const std::string& scan_type);
    void endSession(int files_scanned, int threats_found);
    
    // Scanning results
    void logScanResult(const std::string& filePath, bool detected, const std::string& threatName = "");
    
    // History and reporting
    std::vector<ScanSession> getRecentSessions(int limit = 10);
    std::vector<ScanRecord> getSessionResults(const std::string& session_id);
    std::string getScanSummary(const std::string& session_id);
    void viewScanHistory();  // Added method for viewing scan history
};

#endif