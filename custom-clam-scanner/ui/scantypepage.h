#ifndef SCANTYPEPAGE_H
#define SCANTYPEPAGE_H

#include <QWidget>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include <QThread>
#include <iostream>
#include "customscan.h"
#include "systemscan.h"
#include "quickscan.h"

namespace Ui {
class ScanTypePage;
}

class ScanWorker : public QObject {
    Q_OBJECT
public:
    explicit ScanWorker(QObject* parent = nullptr) 
        : QObject(parent), customScanner(nullptr), systemScanner(nullptr), quickScanner(nullptr) {}
    
    ~ScanWorker() {
        if (quickScanner) delete quickScanner;
        if (systemScanner) delete systemScanner;
        if (customScanner) delete customScanner;
    }
    
    void setScanPath(const QString& path) {
        scanPath = path;
    }

    void setScanType(const QString& type) {
        scanType = type;
    }

public slots:
    void doScan() {
        if (scanType == "quick") {
            std::cout << "Starting quick scan..." << std::endl;
            quickScanner = new QuickScan();
            if (!quickScanner) {
                std::cout << "Failed to create QuickScan object" << std::endl;
                return;
            }
            std::cout << "Created QuickScan object successfully" << std::endl;
            
            quickScanner->startScan();
            
            // Add progress update
            emit scanProgress(quickScanner->getFilesScanned());
            
            std::cout << "Scan completed. Files scanned: " << quickScanner->getFilesScanned() 
                      << " Threats: " << quickScanner->getThreatsFound() << std::endl;
            
            emit scanComplete(quickScanner->getFilesScanned(), quickScanner->getThreatsFound());
            delete quickScanner;
            quickScanner = nullptr;
        }
        else if (scanType == "system") {
            systemScanner = new SystemScan();
            systemScanner->startScan();
            emit scanComplete(systemScanner->getFilesScanned(), systemScanner->getThreatsFound());
            delete systemScanner;
            systemScanner = nullptr;
        }
        else if (scanType == "custom") {
            customScanner = new ClamAVTester(scanPath.toStdString());
            customScanner->startScan();
            emit scanComplete(customScanner->filesScanned, customScanner->threatsFound);
            delete customScanner;
            customScanner = nullptr;
        }
    }

signals:
    void scanComplete(int filesScanned, int threatsFound);
    void scanProgress(int filesScanned);

private:
    ClamAVTester* customScanner;
    SystemScan* systemScanner;
    QuickScan* quickScanner;
    QString scanPath;
    QString scanType;
};

class ScanTypePage : public QWidget
{
    Q_OBJECT

public:
    explicit ScanTypePage(QWidget *parent = nullptr);
    ~ScanTypePage();

private slots:
    void onBackButtonClicked();
    void onScanTypeChanged(int index);
    void onBrowseButtonClicked();
    void onCustomScanButtonClicked();
    void startQuickScan();
    void startSystemScan();
    void startCustomScan();
    void handleScanComplete(int filesScanned, int threatsFound);
    void updateScanProgress(int filesScanned);

signals:
    void backButtonClicked();
    void startScan();

private:
    Ui::ScanTypePage *ui;
    QString selectedDirectory;
    QThread* scanThread;
    ScanWorker* worker;
    void setupScanWorker();
    void setMessageBoxStyle(QMessageBox* msgBox);
};

#endif // SCANTYPEPAGE_H