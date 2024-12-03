#include "schedulescanpage.h"
#include "ui_schedulescanpage.h"
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>

ScheduleScanPage::ScheduleScanPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ScheduleScanPage)
    , scheduler(new ScanScheduler())
{
    try {
        ui->setupUi(this);
        setupUI();
        loadScheduledScans();
    }
    catch (const std::exception& e) {
        qDebug() << "Exception in ScheduleScanPage constructor:" << e.what();
    }
}

ScheduleScanPage::~ScheduleScanPage()
{
    try {
        delete scheduler;
        delete ui;
    }
    catch (const std::exception& e) {
        qDebug() << "Exception in ScheduleScanPage destructor:" << e.what();
    }
}

void ScheduleScanPage::setupUI()
{
    // Set up frequency combo box
    ui->frequencyComboBox->addItem("Daily", static_cast<int>(ScanInterval::DAILY));
    ui->frequencyComboBox->addItem("Weekly", static_cast<int>(ScanInterval::WEEKLY));
    ui->frequencyComboBox->addItem("Bi-weekly", static_cast<int>(ScanInterval::BIWEEKLY));

    // Connect signals
    connect(ui->backButton, &QPushButton::clicked, this, &ScheduleScanPage::onBackButtonClicked);
    connect(ui->scheduleButton, &QPushButton::clicked, this, &ScheduleScanPage::onScheduleButtonClicked);
}

void ScheduleScanPage::loadScheduledScans()
{
    // TODO: Implement loading scheduled scans based on available UI elements
}

void ScheduleScanPage::onScheduleButtonClicked()
{
    try {
        ScanInterval interval = static_cast<ScanInterval>(ui->frequencyComboBox->currentData().toInt());
        
        int scanId = scheduler->scheduleNewScan(ScanType::QUICK, interval, "");
        
        if (scanId != -1) {
            QMessageBox::information(this, "Success", 
                QString("Scan scheduled successfully!\nScan ID: %1").arg(scanId));
            loadScheduledScans();
        } else {
            QMessageBox::warning(this, "Error", "Failed to schedule scan.");
        }
    }
    catch (const std::exception& e) {
        qDebug() << "Exception in onScheduleButtonClicked:" << e.what();
        QMessageBox::critical(this, "Error", "An error occurred while scheduling the scan.");
    }
}

void ScheduleScanPage::onDeleteScanClicked(int scanId)
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirm Delete",
        "Are you sure you want to delete this scheduled scan?",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        scheduler->removeScan(scanId);
        loadScheduledScans();
    }
}

void ScheduleScanPage::onBackButtonClicked()
{
    emit backButtonClicked();
}