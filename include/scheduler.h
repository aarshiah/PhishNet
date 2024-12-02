#ifndef SCAN_SCHEDULER_H
#define SCAN_SCHEDULER_H

#include <sqlite3.h>
#include <string>
#include <vector>
#include <filesystem>
#include "Database.h"

// Scan frequency options
enum class ScanInterval {
   DAILY,
   WEEKLY,
   BIWEEKLY
};

// Available scan types
enum class ScanType {
   QUICK,      // Default
   SYSTEM,
   CUSTOM
};

// Stores info about a scheduled scan
struct ScheduledScan {
   int id;
   ScanType type;
   ScanInterval interval;
   std::string path;         // For custom scans
   std::string last_run;    
   std::string next_run;    
   bool enabled;
};

// Handles scheduling and execution of automated scans
class ScanScheduler {
private:
   sqlite3* db;
   std::string current_session_id;
   
   // Internal helper functions
   void createSchedulerTable();
   std::string generateSessionId();
   std::string getCurrentTimestamp();
   void executeScan(const ScheduledScan& scan);
   void updateLastRun(int scanId);
   ScanInterval getIntervalById(int scanId);
   std::string calculateNextRun(ScanInterval interval, const std::string& lastRun = "");

public:
   ScanScheduler();
   ~ScanScheduler();

   // Schedule management
   int scheduleNewScan(ScanType type = ScanType::QUICK,
                      ScanInterval interval = ScanInterval::DAILY,
                      const std::string& path = "");
   void checkAndExecuteScheduledScans();
   void removeScan(int scanId);
   void toggleScan(int scanId, bool enable);
   
   // View scheduled scans
   void displayScheduledScans();
   std::vector<ScheduledScan> getScheduledScans();
};

#endif