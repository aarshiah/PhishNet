#include <iostream>
#include "scheduler.h"

void displayUsage() {
    std::cout << "\nScan Scheduler Usage:\n"
              << "--------------------\n"
              << "1. Schedule a new scan\n"
              << "2. List scheduled scans\n"
              << "3. Remove a scheduled scan\n"
              << "4. Check scheduled scans\n"
              << "5. Exit\n"
              << "Choice: ";
}

int main() {
    ScanScheduler scheduler;
    int choice;

    while (true) {
        displayUsage();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int typeChoice, intervalChoice;
                std::string path;

                std::cout << "\nSelect scan type:\n"
                         << "1. Quick Scan\n"
                         << "2. System Scan\n"
                         << "3. Custom Scan\n"
                         << "Choice: ";
                std::cin >> typeChoice;

                std::cout << "\nSelect interval:\n"
                         << "1. Daily\n"
                         << "2. Weekly\n"
                         << "3. Bi-weekly\n"
                         << "Choice: ";
                std::cin >> intervalChoice;

                if (typeChoice == 3) {
                    std::cout << "Enter path to scan: ";
                    std::cin.ignore();
                    std::getline(std::cin, path);
                }

                ScanType type;
                switch (typeChoice) {
                    case 1: type = ScanType::QUICK; break;
                    case 2: type = ScanType::SYSTEM; break;
                    case 3: type = ScanType::CUSTOM; break;
                    default: type = ScanType::QUICK; break;
                }

                ScanInterval interval;
                switch (intervalChoice) {
                    case 1: interval = ScanInterval::DAILY; break;
                    case 2: interval = ScanInterval::WEEKLY; break;
                    case 3: interval = ScanInterval::BIWEEKLY; break;
                    default: interval = ScanInterval::DAILY; break;
                }

                int id = scheduler.scheduleNewScan(type, interval, path);
                if (id != -1) {
                    std::cout << "Scan scheduled successfully with ID: " << id << std::endl;
                }
                break;
            }

            case 2:
                scheduler.displayScheduledScans();
                break;

            case 3: {
                int scanId;
                std::cout << "Enter scan ID to remove: ";
                std::cin >> scanId;
                scheduler.removeScan(scanId);
                std::cout << "Scan removed.\n";
                break;
            }

            case 4:
                scheduler.checkAndExecuteScheduledScans();
                break;

            case 5:
                std::cout << "Exiting...\n";
                return 0;

            default:
                std::cout << "Invalid choice.\n";
                break;
        }
    }

    return 0;
}