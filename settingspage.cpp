#include "settingspage.h"
#include "./ui_settingspage.h"
#include <QMessageBox>
#include <QString>
#include <QSettings>

SettingsPage::SettingsPage(QWidget *parent)
    : QWidget(parent)
      , ui(new Ui::SettingsPage)
{
    ui->setupUi(this);

    // Connect buttons
    connect(ui->backButton, &QPushButton::clicked, this, &SettingsPage::onBackButtonClicked);
    connect(ui->updateButton, &QPushButton::clicked, this, &SettingsPage::onUpdateSignaturesClicked);
    connect(ui->darkModeCheck, &QCheckBox::toggled, this, &SettingsPage::onDarkModeToggled);

           // Set version information
    ui->clamVersionLabel->setText(QString("ClamAV Version: 1.2.0")); // Replace with actual version
    ui->qtVersionLabel->setText(QString("Qt Version: %1").arg(QT_VERSION_STR));
    ui->phishnetVersionLabel->setText(QString("PhishNet Release Date: December 2nd, 2024"));

    loadSettings();
}

SettingsPage::~SettingsPage()
{
    delete ui;
}

void SettingsPage::loadSettings()
{
    QSettings settings("PhishNet", "Antivirus");
    bool isDarkMode = settings.value("darkMode", false).toBool();
    ui->darkModeCheck->setChecked(isDarkMode);
    applyDarkMode(this, isDarkMode);
}

void SettingsPage::saveSettings()
{
    QSettings settings("PhishNet", "Antivirus");
    settings.setValue("darkMode", ui->darkModeCheck->isChecked());
}

void SettingsPage::applyDarkMode(QWidget* widget, bool isDark)
{
    if (isDark) {
        widget->setStyleSheet(
            "QWidget { background-color: #2b2b2b; color: #ffffff; }"
            "QPushButton { background-color: #404040; color: white; border: none; padding: 8px 16px; border-radius: 4px; }"
            "QPushButton:hover { background-color: #505050; }"
            "QLabel { color: #ffffff; }"
            "QCheckBox { color: #ffffff; }"
            "QCheckBox::indicator { width: 18px; height: 18px; }"
            "QCheckBox::indicator:unchecked { background-color: #404040; border: 1px solid #666666; border-radius: 3px; }"
            "QCheckBox::indicator:checked { background-color: #cc0000; border: 1px solid #cc0000; border-radius: 3px; }"
            "QGroupBox { color: #ffffff; border: 1px solid #404040; }"
            "#titleLabel { color: #cc0000; }"
            "#updateButton { background-color: #cc0000; }"
            "#updateButton:hover { background-color: #b30000; }"
            );
    } else {
        widget->setStyleSheet(
            "QPushButton#backButton { background-color: #e0e0e0; border: 1px solid #c0c0c0; border-radius: 3px; padding: 5px 15px; }"
            "QPushButton#backButton:hover { background-color: #d0d0d0; }"
            "QLabel#titleLabel { font-size: 20px; color: #cc0000; padding: 10px; font-weight: bold; }"
            "QPushButton#updateButton { background-color: #cc0000; color: white; border: none; padding: 8px 16px; border-radius: 4px; }"
            "QPushButton#updateButton:hover { background-color: #b30000; }"
            );
    }
}

void SettingsPage::onBackButtonClicked()
{
    emit backButtonClicked();
}

void SettingsPage::onUpdateSignaturesClicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Update Signatures");
    msgBox.setText("Updating virus signatures...\nThis feature will be implemented later.");
    msgBox.setStyleSheet(
        "QMessageBox { background-color: #f0f0f0; }"
        "QPushButton { background-color: #666666; color: white; border: none; padding: 6px 12px; border-radius: 4px; }"
        );
    msgBox.exec();
}

void SettingsPage::onDarkModeToggled(bool checked)
{
    applyDarkMode(this, checked);
    saveSettings();
    emit darkModeChanged(checked);
}
