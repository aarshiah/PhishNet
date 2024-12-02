#include <iostream>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <ctime>
#include <filesystem>
#include "scheduler.h"
#include "quickscan.h"
#include "systemscan.h"
#include "customscan.h"

// Initialize scheduler database and create tables if needed
ScanScheduler::ScanScheduler() {
   int rc = sqlite3_open("scheduler.db", &db);
   if (rc != SQLITE_OK) {
       std::cerr << "Can't open scheduler database: " << sqlite3_errmsg(db) << std::endl;
   } else {
       createSchedulerTable();
   }
}

// Create table to store scheduled scan information
void ScanScheduler::createSchedulerTable() {
   const char* sql = R"(
       CREATE TABLE IF NOT EXISTS ScheduledScans (
           id INTEGER PRIMARY KEY AUTOINCREMENT,
           scan_type TEXT NOT NULL,
           interval TEXT NOT NULL,
           path TEXT,
           last_run TIMESTAMP,
           next_run TIMESTAMP,
           enabled INTEGER DEFAULT 1
       );
   )";

   char* errMsg = nullptr;
   int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);
   if (rc != SQLITE_OK) {
       std::cerr << "Failed to create scheduler table: " << errMsg << std::endl;
       sqlite3_free(errMsg);
   }
}

// Get formatted timestamp for current time
std::string ScanScheduler::getCurrentTimestamp() {
   auto now = std::chrono::system_clock::now();
   auto time = std::chrono::system_clock::to_time_t(now);
   std::stringstream ss;
   ss << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");
   return ss.str();
}

// Calculate next run time based on interval
std::string ScanScheduler::calculateNextRun(ScanInterval interval, const std::string& lastRun) {
   auto now = std::chrono::system_clock::now();
   if (!lastRun.empty()) {
       std::tm tm = {};
       std::istringstream ss(lastRun);
       ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
       auto base = std::chrono::system_clock::from_time_t(std::mktime(&tm));
       now = base;
   }

   auto nextRun = now;
   switch (interval) {
       case ScanInterval::DAILY:
           nextRun += std::chrono::hours(24);
           break;
       case ScanInterval::WEEKLY:
           nextRun += std::chrono::hours(24 * 7);
           break;
       case ScanInterval::BIWEEKLY:
           nextRun += std::chrono::hours(24 * 14);
           break;
   }

   auto time = std::chrono::system_clock::to_time_t(nextRun);
   std::stringstream ss;
   ss << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");
   return ss.str();
}

// Run a scheduled scan based on its type
void ScanScheduler::executeScan(const ScheduledScan& scan) {
   std::cout << "Executing scheduled scan...\n";

   try {
       switch (scan.type) {
           case ScanType::QUICK: {
               QuickScan scanner;
               scanner.startScan();
               break;
           }
           case ScanType::SYSTEM: {
               SystemScan scanner;
               scanner.startScan();
               break;
           }
           case ScanType::CUSTOM: {
               if (!scan.path.empty()) {
                   ClamAVTester tester;
                   if (tester.initialize()) {
                       if (std::filesystem::is_directory(scan.path)) {
                           tester.scanDirectory(scan.path);
                       } else {
                           tester.scanFile(scan.path);
                       }
                   }
               }
               break;
           }
       }
       updateLastRun(scan.id);
   } catch (const std::exception& e) {
       std::cerr << "Error during scan execution: " << e.what() << std::endl;
   }
}

// Update last run time and calculate next run
void ScanScheduler::updateLastRun(int scanId) {
   const char* sql = R"(
       UPDATE ScheduledScans 
       SET last_run = datetime('now'), 
           next_run = ? 
       WHERE id = ?;
   )";

   sqlite3_stmt* stmt;
   if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
       auto nextRun = calculateNextRun(getIntervalById(scanId));
       sqlite3_bind_text(stmt, 1, nextRun.c_str(), -1, SQLITE_STATIC);
       sqlite3_bind_int(stmt, 2, scanId);
       sqlite3_step(stmt);
       sqlite3_finalize(stmt);
   }
}

// Get scan interval from database
ScanInterval ScanScheduler::getIntervalById(int scanId) {
   const char* sql = "SELECT interval FROM ScheduledScans WHERE id = ?;";
   sqlite3_stmt* stmt;
   ScanInterval interval = ScanInterval::DAILY;

   if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
       sqlite3_bind_int(stmt, 1, scanId);
       if (sqlite3_step(stmt) == SQLITE_ROW) {
           std::string intervalStr = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
           if (intervalStr == "WEEKLY") interval = ScanInterval::WEEKLY;
           else if (intervalStr == "BIWEEKLY") interval = ScanInterval::BIWEEKLY;
       }
       sqlite3_finalize(stmt);
   }
   return interval;
}

// Add new scheduled scan to database
int ScanScheduler::scheduleNewScan(ScanType type, ScanInterval interval, const std::string& path) {
   const char* sql = R"(
       INSERT INTO ScheduledScans (scan_type, interval, path, next_run)
       VALUES (?, ?, ?, ?);
   )";

   sqlite3_stmt* stmt;
   int scanId = -1;

   if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
       std::string typeStr;
       switch (type) {
           case ScanType::QUICK: typeStr = "QUICK"; break;
           case ScanType::SYSTEM: typeStr = "SYSTEM"; break;
           case ScanType::CUSTOM: typeStr = "CUSTOM"; break;
       }

       std::string intervalStr;
       switch (interval) {
           case ScanInterval::DAILY: intervalStr = "DAILY"; break;
           case ScanInterval::WEEKLY: intervalStr = "WEEKLY"; break;
           case ScanInterval::BIWEEKLY: intervalStr = "BIWEEKLY"; break;
       }

       std::string nextRun = calculateNextRun(interval);

       sqlite3_bind_text(stmt, 1, typeStr.c_str(), -1, SQLITE_STATIC);
       sqlite3_bind_text(stmt, 2, intervalStr.c_str(), -1, SQLITE_STATIC);
       sqlite3_bind_text(stmt, 3, path.c_str(), -1, SQLITE_STATIC);
       sqlite3_bind_text(stmt, 4, nextRun.c_str(), -1, SQLITE_STATIC);

       if (sqlite3_step(stmt) == SQLITE_DONE) {
           scanId = sqlite3_last_insert_rowid(db);
       }
       sqlite3_finalize(stmt);
   }

   return scanId;
}

// Check and run any scans that are due
void ScanScheduler::checkAndExecuteScheduledScans() {
   auto scans = getScheduledScans();
   auto now = std::chrono::system_clock::now();
   auto currentTime = std::chrono::system_clock::to_time_t(now);

   for (const auto& scan : scans) {
       if (!scan.next_run.empty()) {
           std::tm scheduledTime = {};
           std::istringstream ss(scan.next_run);
           ss >> std::get_time(&scheduledTime, "%Y-%m-%d %H:%M:%S");
           auto scheduledTimeT = std::mktime(&scheduledTime);

           if (currentTime >= scheduledTimeT) {
               executeScan(scan);
           }
       }
   }
}

// Get all enabled scheduled scans
std::vector<ScheduledScan> ScanScheduler::getScheduledScans() {
   std::vector<ScheduledScan> scans;
   const char* sql = "SELECT * FROM ScheduledScans WHERE enabled = 1;";
   
   sqlite3_stmt* stmt;
   if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
       while (sqlite3_step(stmt) == SQLITE_ROW) {
           ScheduledScan scan;
           scan.id = sqlite3_column_int(stmt, 0);
           
           std::string typeStr = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
           if (typeStr == "QUICK") scan.type = ScanType::QUICK;
           else if (typeStr == "SYSTEM") scan.type = ScanType::SYSTEM;
           else scan.type = ScanType::CUSTOM;

           std::string intervalStr = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
           if (intervalStr == "WEEKLY") scan.interval = ScanInterval::WEEKLY;
           else if (intervalStr == "BIWEEKLY") scan.interval = ScanInterval::BIWEEKLY;
           else scan.interval = ScanInterval::DAILY;

           scan.path = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
           
           if (sqlite3_column_text(stmt, 4))
               scan.last_run = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
           
           if (sqlite3_column_text(stmt, 5))
               scan.next_run = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
           
           scan.enabled = sqlite3_column_int(stmt, 6) != 0;
           
           scans.push_back(scan);
       }
       sqlite3_finalize(stmt);
   }
   
   return scans;
}

// Show formatted list of scheduled scans
void ScanScheduler::displayScheduledScans() {
   auto scans = getScheduledScans();
   
   std::cout << "\n=== Scheduled Scans ===\n";
   std::cout << std::string(100, '-') << "\n";
   std::cout << std::left
             << std::setw(5) << "ID"
             << std::setw(10) << "Type"
             << std::setw(10) << "Interval"
             << std::setw(30) << "Next Run"
             << std::setw(30) << "Last Run"
             << "Path\n";
   std::cout << std::string(100, '-') << "\n";

   for (const auto& scan : scans) {
       std::string typeStr;
       switch (scan.type) {
           case ScanType::QUICK: typeStr = "Quick"; break;
           case ScanType::SYSTEM: typeStr = "System"; break;
           case ScanType::CUSTOM: typeStr = "Custom"; break;
       }

       std::string intervalStr;
       switch (scan.interval) {
           case ScanInterval::DAILY: intervalStr = "Daily"; break;
           case ScanInterval::WEEKLY: intervalStr = "Weekly"; break;
           case ScanInterval::BIWEEKLY: intervalStr = "Biweekly"; break;
       }

       std::cout << std::left
                 << std::setw(5) << scan.id
                 << std::setw(10) << typeStr
                 << std::setw(10) << intervalStr
                 << std::setw(30) << scan.next_run
                 << std::setw(30) << (scan.last_run.empty() ? "Never" : scan.last_run)
                 << (scan.path.empty() ? "-" : scan.path) << "\n";
   }
   std::cout << std::string(100, '-') << "\n";
}

// Remove a scheduled scan
void ScanScheduler::removeScan(int scanId) {
   const char* sql = "DELETE FROM ScheduledScans WHERE id = ?;";
   
   sqlite3_stmt* stmt;
   if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
       sqlite3_bind_int(stmt, 1, scanId);
       sqlite3_step(stmt);
       sqlite3_finalize(stmt);
   }
}

// Enable or disable a scheduled scan
void ScanScheduler::toggleScan(int scanId, bool enable) {
   const char* sql = "UPDATE ScheduledScans SET enabled = ? WHERE id = ?;";
   
   sqlite3_stmt* stmt;
   if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
       sqlite3_bind_int(stmt, 1, enable ? 1 : 0);
       sqlite3_bind_int(stmt, 2, scanId);
       sqlite3_step(stmt);
       sqlite3_finalize(stmt);
   }
}

ScanScheduler::~ScanScheduler() {
   if (db) {
       sqlite3_close(db);
   }
}