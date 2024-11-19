#include "schedulescanpage.h"
#include "ui_schedulescanpage.h"
#include <QMessageBox>
#include <QDebug>

ScheduleScanPage::ScheduleScanPage(QWidget *parent) :
      QWidget(parent),
      ui(new Ui::ScheduleScanPage)
{
    ui->setupUi(this);

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

    // Apply custom style to message boxes globally
    qApp->setStyleSheet(qApp->styleSheet() +
                        "QMessageBox { background-color: #f0f0f0; }"
                        "QMessageBox QLabel { color: black; background-color: transparent; }"
                        "QMessageBox QPushButton { background-color: #e0e0e0; border: 1px solid #c0c0c0; border-radius: 3px; padding: 5px 15px; }"
                        "QMessageBox QPushButton:hover { background-color: #d0d0d0; }");

    // Connect the back button - fixed to match the autogen code
    connect(ui->backButton, &QPushButton::clicked, this, &ScheduleScanPage::onBackButtonClicked);

    // Connect the schedule button
    connect(ui->scheduleButton, &QPushButton::clicked, this, &ScheduleScanPage::onScheduleButtonClicked);
}

ScheduleScanPage::~ScheduleScanPage()
{
    delete ui;
}

void ScheduleScanPage::onBackButtonClicked()
{
    emit backButtonClicked();
}

void ScheduleScanPage::onScheduleButtonClicked()
{
    // Get the selected frequency
    int frequencyDays = ui->frequencyComboBox->currentData().toInt();

    // Get the selected time
    QString selectedTime = QString("%1:%2")
                               .arg(ui->hourComboBox->currentText())
                               .arg(ui->minuteComboBox->currentText());

    // Create and configure message box with solid background
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Scan Scheduled");
    msgBox.setText(QString("Scan has been scheduled successfully for %1:%2, repeating every %3 day(s).")
                       .arg(ui->hourComboBox->currentText())
                       .arg(ui->minuteComboBox->currentText())
                       .arg(frequencyDays));
    msgBox.setIcon(QMessageBox::Information);

    // Execute the message box
    msgBox.exec();
}
