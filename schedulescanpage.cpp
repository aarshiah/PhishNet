#include "schedulescanpage.h"
#include "ui_schedulescanpage.h"
#include <QMessageBox>
#include <QDebug>

ScheduleScanPage::ScheduleScanPage(QWidget *parent) :
      QWidget(parent),
      ui(new Ui::ScheduleScanPage)
{
    try {
        ui->setupUi(this);

        // Clear any existing items first
        ui->frequencyComboBox->clear();
        ui->hourComboBox->clear();
        ui->minuteComboBox->clear();

               // Set up the frequency combo box
        ui->frequencyComboBox->addItem("Daily", QVariant(1));
        ui->frequencyComboBox->addItem("Weekly", QVariant(7));
        ui->frequencyComboBox->addItem("Monthly", QVariant(30));

               // Populate hours (00-23)
        for (int hour = 0; hour < 24; ++hour) {
            ui->hourComboBox->addItem(QString("%1").arg(hour, 2, 10, QChar('0')));
        }

               // Populate minutes (00, 15, 30, 45)
        QStringList minutes = {"00", "15", "30", "45"};
        for (const QString& minute : minutes) {
            ui->minuteComboBox->addItem(minute);
        }

               // Set initial selections
        ui->hourComboBox->setCurrentText("08");
        ui->minuteComboBox->setCurrentText("00");

               // Connect buttons
        connect(ui->backButton, &QPushButton::clicked,
                this, &ScheduleScanPage::onBackButtonClicked);
        connect(ui->scheduleButton, &QPushButton::clicked,
                this, &ScheduleScanPage::onScheduleButtonClicked);
    }
    catch (const std::exception& e) {
        qDebug() << "Exception in ScheduleScanPage constructor:" << e.what();
    }
}

ScheduleScanPage::~ScheduleScanPage()
{
    try {
        if (ui) {
            delete ui;
            ui = nullptr;
        }
    }
    catch (const std::exception& e) {
        qDebug() << "Exception in ScheduleScanPage destructor:" << e.what();
    }
}

void ScheduleScanPage::onBackButtonClicked()
{
    emit backButtonClicked();
}

void ScheduleScanPage::onScheduleButtonClicked()
{
    try {
        // Get the selected frequency
        int frequencyDays = ui->frequencyComboBox->currentData().toInt();

        // Get the selected time
        QString selectedTime = QString("%1:%2")
                                   .arg(ui->hourComboBox->currentText())
                                   .arg(ui->minuteComboBox->currentText());

               // Create and show message box
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Scan Scheduled");
        msgBox.setText(QString("Scan has been scheduled successfully for %1, repeating every %2 day(s).")
                           .arg(selectedTime)
                           .arg(frequencyDays));
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
    }
    catch (const std::exception& e) {
        qDebug() << "Exception in onScheduleButtonClicked:" << e.what();
    }
}
