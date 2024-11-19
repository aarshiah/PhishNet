#include "historypage.h"
#include "ui_historypage.h"
#include <QDateTime>
#include <QMessageBox>
#include <QDebug>
#include <QPushButton>
#include <QTableWidgetItem>

HistoryPage::HistoryPage(QWidget *parent) :
      QWidget(parent),
      ui(new Ui::HistoryPage)
{
    ui->setupUi(this);

    // Set up the table
    setupTable();

    // Connect signals
    connect(ui->backButton, &QPushButton::clicked,
            this, &HistoryPage::onBackButtonClicked);

    // Load history data
    refreshHistory();
}

HistoryPage::~HistoryPage()
{
    delete ui;
}

void HistoryPage::setupTable()
{
    ui->historyTable->setColumnCount(5);
    QStringList headers;
    headers << "Date" << "Time" << "Scan Type" << "Status" << "Info";
    ui->historyTable->setHorizontalHeaderLabels(headers);

    // Set column widths
    ui->historyTable->setColumnWidth(0, 100); // Date
    ui->historyTable->setColumnWidth(1, 80);  // Time
    ui->historyTable->setColumnWidth(2, 100); // Scan Type
    ui->historyTable->setColumnWidth(3, 80);  // Status
    ui->historyTable->setColumnWidth(4, 50);  // Info button
}


void HistoryPage::onTableItemDoubleClicked(QTableWidgetItem *item)
{
  // Handle double click event
}

void HistoryPage::refreshHistory()
{
    ui->historyTable->setRowCount(0); // Clear existing items

    // TODO: Load actual history from database or file
    // For now, adding sample data
    addScanRecord("2024-03-20", "09:30", "Quick Scan", false, "No threats found");
    addScanRecord("2024-03-19", "14:15", "Full Scan", true, "Malware detected: Trojan.Win32");
    addScanRecord("2024-03-18", "22:00", "Custom Scan", false, "Scanned: Documents folder");
    addScanRecord("2024-03-17", "10:45", "Quick Scan", false, "No threats found");
}

void HistoryPage::addScanRecord(const QString& date, const QString& time,
                                const QString& type, bool infected,
                                const QString& details)
{
    int row = ui->historyTable->rowCount();
    ui->historyTable->insertRow(row);

    // Add items
    ui->historyTable->setItem(row, 0, new QTableWidgetItem(date));
    ui->historyTable->setItem(row, 1, new QTableWidgetItem(time));
    ui->historyTable->setItem(row, 2, new QTableWidgetItem(type));

    // Status with color coding
    QTableWidgetItem *statusItem = new QTableWidgetItem(infected ? "Infected" : "Clean");
    statusItem->setForeground(infected ? Qt::red : Qt::darkGreen);
    statusItem->setFont(QFont("Serif", -1, infected ? QFont::Bold : QFont::Normal));
    ui->historyTable->setItem(row, 3, statusItem);

    // Create info button
    QPushButton* infoButton = new QPushButton("i", ui->historyTable);
    infoButton->setFixedSize(24, 24);
    infoButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #e0e0e0;"
        "   border: none;"
        "   border-radius: 12px;"
        "   font-family: Serif;"
        "   font-weight: bold;"
        "   color: #404040;"
        "}"
        "QPushButton:hover {"
        "   background-color: #d0d0d0;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #c0c0c0;"
        "}"
        );
    infoButton->setCursor(Qt::PointingHandCursor);


    connect(ui->historyTable, &QTableWidget::itemDoubleClicked,
            this, &HistoryPage::onTableItemDoubleClicked);connect(ui->historyTable, &QTableWidget::itemDoubleClicked,
            this, &HistoryPage::onTableItemDoubleClicked);

    // Connect button to lambda that shows details
    connect(infoButton, &QPushButton::clicked, this, [this, date, time, type, infected, details]() {
        QString message = QString("Scan Details:\n\n"
                                  "Date: %1\n"
                                  "Time: %2\n"
                                  "Type: %3\n"
                                  "Status: %4\n"
                                  "Details: %5")
                              .arg(date)
                              .arg(time)
                              .arg(type)
                              .arg(infected ? "Infected" : "Clean")
                              .arg(details);

        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Scan Details");
        msgBox.setText(message);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
    });

    ui->historyTable->setCellWidget(row, 4, infoButton);
}

void HistoryPage::onBackButtonClicked()
{
    emit backButtonClicked();
}
