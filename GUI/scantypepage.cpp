#include "scantypepage.h"
#include "ui_scantypepage.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QButtonGroup>
#include <QFileDialog>
#include <QIcon>
#include <QPainter>
#include <QPainterPath>

void setMessageBoxStyle(QMessageBox* msgBox)
{
    QPixmap customIcon(32, 32);
    customIcon.fill(Qt::transparent);
    QPainter painter(&customIcon);
    painter.setRenderHint(QPainter::Antialiasing);

    QPainterPath path;
    path.addEllipse(2, 2, 28, 28);
    painter.setPen(QPen(QColor("#cc0000"), 2));
    painter.setBrush(QColor("#f0f0f0"));
    painter.drawPath(path);

    msgBox->setIconPixmap(customIcon);

    msgBox->setStyleSheet(
        "QMessageBox {"
        "    background-color: #f0f0f0;"
        "    color: #333333;"
        "    font-family: Serif;"
        "}"
        "QMessageBox QLabel {"
        "    color: #333333;"
        "    font-family: Serif;"
        "    font-size: 12px;"
        "    padding: 10px;"
        "}"
        "QPushButton {"
        "    background-color: #666666;"
        "    color: white;"
        "    border: none;"
        "    padding: 6px 12px;"
        "    border-radius: 4px;"
        "    font-family: Serif;"
        "    font-weight: bold;"
        "    min-width: 80px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #555555;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #444444;"
        "}");
}

ScanTypePage::ScanTypePage(QWidget *parent)
    : QWidget(parent)
      , ui(new Ui::ScanTypePage)
{
    ui->setupUi(this);

    QButtonGroup* buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(ui->quickScanButton);
    buttonGroup->addButton(ui->systemScanButton);
    buttonGroup->addButton(ui->customScanButton);
    buttonGroup->setExclusive(true);

    connect(ui->backButton, &QPushButton::clicked, this, &ScanTypePage::backToMain);
    connect(ui->quickScanButton, &QPushButton::clicked, this, &ScanTypePage::showQuickScan);
    connect(ui->systemScanButton, &QPushButton::clicked, this, &ScanTypePage::showSystemScan);
    connect(ui->customScanButton, &QPushButton::clicked, this, &ScanTypePage::showCustomScan);
    connect(ui->browseButton, &QPushButton::clicked, this, &ScanTypePage::browseFiles);
    connect(ui->startQuickScanButton, &QPushButton::clicked, this, &ScanTypePage::startQuickScan);
    connect(ui->startSystemScanButton, &QPushButton::clicked, this, &ScanTypePage::startSystemScan);
    connect(ui->startCustomScanButton, &QPushButton::clicked, this, &ScanTypePage::startCustomScan);

    ui->stackedWidget->setCurrentIndex(0);
}

ScanTypePage::~ScanTypePage()
{
    delete ui;
}

void ScanTypePage::backToMain()
{
    emit backButtonClicked();
}

void ScanTypePage::showQuickScan()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void ScanTypePage::showSystemScan()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void ScanTypePage::showCustomScan()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void ScanTypePage::browseFiles()
{
    QString directory = QFileDialog::getExistingDirectory(this, "Select Directory to Scan",
                                                          "/home",
                                                          QFileDialog::ShowDirsOnly
                                                              | QFileDialog::DontResolveSymlinks);
    if (!directory.isEmpty()) {
        QMessageBox* msgBox = new QMessageBox(this);
        msgBox->setWindowTitle("Selected Directory");
        msgBox->setText("You selected: \n" + directory);
        setMessageBoxStyle(msgBox);
        msgBox->exec();
        delete msgBox;
    }
}

void ScanTypePage::startQuickScan()
{
    QMessageBox* msgBox = new QMessageBox(this);
    msgBox->setWindowTitle("Scan Initiated");
    msgBox->setText("Quick Scan has been initiated...\n\nScanning commonly infected areas of your system.\nThis may take 5-10 minutes.");
    setMessageBoxStyle(msgBox);
    msgBox->exec();
    delete msgBox;
}

void ScanTypePage::startSystemScan()
{
    QMessageBox* msgBox = new QMessageBox(this);
    msgBox->setWindowTitle("Scan Initiated");
    msgBox->setText("System Scan has been initiated...\n\nPerforming a thorough system check.\nThis may take 30-60 minutes.");
    setMessageBoxStyle(msgBox);
    msgBox->exec();
    delete msgBox;
}

void ScanTypePage::startCustomScan()
{
    QMessageBox* msgBox = new QMessageBox(this);
    msgBox->setWindowTitle("Scan Initiated");
    msgBox->setText("Custom Scan has been initiated...\n\nScanning selected locations.\nScan time will vary based on selection.");
    setMessageBoxStyle(msgBox);
    msgBox->exec();
    delete msgBox;
}
