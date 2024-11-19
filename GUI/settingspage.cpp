// settingspage.cpp
#include "settingspage.h"
#include "ui_settingspage.h"
#include <QMessageBox>
#include <QSettings>

SettingsPage::SettingsPage(QWidget *parent)
    : QWidget(parent)
      , ui(new Ui::SettingsPage)
{
    ui->setupUi(this);

    connect(ui->backButton, &QPushButton::clicked, this, &SettingsPage::onBackButtonClicked);
    connect(ui->saveButton, &QPushButton::clicked, this, &SettingsPage::onSaveButtonClicked);
    connect(ui->resetDefaultsButton, &QPushButton::clicked, this, &SettingsPage::onResetDefaultsClicked);
    connect(ui->autoUpdateCheck, &QCheckBox::stateChanged, this, &SettingsPage::onUpdateCheckboxChanged);

    loadSettings();
}

SettingsPage::~SettingsPage()
{
    delete ui;
}

void SettingsPage::loadSettings()
{
    QSettings settings("PhishNet", "Antivirus");

    ui->autoUpdateCheck->setChecked(settings.value("AutoUpdate", true).toBool());
    ui->startupScanCheck->setChecked(settings.value("StartupScan", true).toBool());
    ui->realtimeProtectionCheck->setChecked(settings.value("RealtimeProtection", true).toBool());
    ui->scanArchivesCheck->setChecked(settings.value("ScanArchives", true).toBool());
    ui->notificationsCheck->setChecked(settings.value("ShowNotifications", true).toBool());

    ui->scanSpeedSlider->setValue(settings.value("ScanSpeed", 50).toInt());
    ui->updateFreqCombo->setCurrentText(settings.value("UpdateFrequency", "Daily").toString());
}

void SettingsPage::saveSettings()
{
    QSettings settings("PhishNet", "Antivirus");

    settings.setValue("AutoUpdate", ui->autoUpdateCheck->isChecked());
    settings.setValue("StartupScan", ui->startupScanCheck->isChecked());
    settings.setValue("RealtimeProtection", ui->realtimeProtectionCheck->isChecked());
    settings.setValue("ScanArchives", ui->scanArchivesCheck->isChecked());
    settings.setValue("ShowNotifications", ui->notificationsCheck->isChecked());
    settings.setValue("ScanSpeed", ui->scanSpeedSlider->value());
    settings.setValue("UpdateFrequency", ui->updateFreqCombo->currentText());
}

void SettingsPage::onBackButtonClicked()
{
    emit backButtonClicked();
}

void SettingsPage::onSaveButtonClicked()
{
    saveSettings();

    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Settings Saved");
    msgBox.setText("Your settings have been saved successfully.");
    msgBox.setStyleSheet(
        "QMessageBox { background-color: #f0f0f0; }"
        "QPushButton { background-color: #666666; color: white; border: none; padding: 6px 12px; border-radius: 4px; }"
        );
    msgBox.exec();
}

void SettingsPage::onResetDefaultsClicked()
{
    QMessageBox::StandardButton reply;
    QMessageBox msgBox;
    msgBox.setWindowTitle("Reset Settings");
    msgBox.setText("Are you sure you want to reset all settings to default values?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setStyleSheet(
        "QMessageBox { background-color: #f0f0f0; }"
        "QPushButton { background-color: #666666; color: white; border: none; padding: 6px 12px; border-radius: 4px; }"
        );

    if (msgBox.exec() == QMessageBox::Yes) {
        ui->autoUpdateCheck->setChecked(true);
        ui->startupScanCheck->setChecked(true);
        ui->realtimeProtectionCheck->setChecked(true);
        ui->scanArchivesCheck->setChecked(true);
        ui->notificationsCheck->setChecked(true);
        ui->scanSpeedSlider->setValue(50);
        ui->updateFreqCombo->setCurrentText("Daily");
        saveSettings();
    }
}

void SettingsPage::onUpdateCheckboxChanged(int state)
{
    ui->updateFreqCombo->setEnabled(state == Qt::Checked);
}
