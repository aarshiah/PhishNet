// quarantinepage.cpp
#include "quarantinepage.h"
#include "ui_quarantinepage.h"
#include <QMessageBox>

QuarantinePage::QuarantinePage(QWidget *parent)
    : QWidget(parent)
      , ui(new Ui::QuarantinePage)
{
    ui->setupUi(this);

           // Connect signals
    connect(ui->backButton, &QPushButton::clicked, this, &QuarantinePage::onBackButtonClicked);
    connect(ui->deleteButton, &QPushButton::clicked, this, &QuarantinePage::onDeleteButtonClicked);
    connect(ui->keepButton, &QPushButton::clicked, this, &QuarantinePage::onKeepButtonClicked);
    connect(ui->fileList, &QListWidget::itemSelectionChanged, this, &QuarantinePage::onItemSelectionChanged);

           // Initial setup
    loadQuarantinedFiles();
    updateButtons();
}

QuarantinePage::~QuarantinePage()
{
    delete ui;
}

void QuarantinePage::onBackButtonClicked()
{
    emit backButtonClicked();
}

void QuarantinePage::onDeleteButtonClicked()
{
    auto selectedItems = ui->fileList->selectedItems();
    if (selectedItems.isEmpty()) return;

    QMessageBox msgBox;
    msgBox.setWindowTitle("Confirm Deletion");
    msgBox.setText("Are you sure you want to permanently delete the selected file(s)?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    msgBox.setStyleSheet(
        "QMessageBox { background-color: #f0f0f0; }"
        "QPushButton { background-color: #666666; color: white; border: none; padding: 6px 12px; border-radius: 4px; }"
        "QPushButton:hover { background-color: #555555; }"
        );

    if (msgBox.exec() == QMessageBox::Yes) {
        // TODO: Implement actual file deletion
        foreach(QListWidgetItem* item, selectedItems) {
            delete ui->fileList->takeItem(ui->fileList->row(item));
        }
    }
    updateButtons();
}

void QuarantinePage::onKeepButtonClicked()
{
    auto selectedItems = ui->fileList->selectedItems();
    if (selectedItems.isEmpty()) return;

    QMessageBox msgBox;
    msgBox.setWindowTitle("Keep Files");
    msgBox.setText("Selected files will be moved to quarantine folder.");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setStyleSheet(
        "QMessageBox { background-color: #f0f0f0; }"
        "QPushButton { background-color: #666666; color: white; border: none; padding: 6px 12px; border-radius: 4px; }"
        "QPushButton:hover { background-color: #555555; }"
        );
    msgBox.exec();

           // TODO: Implement actual file quarantine
    updateButtons();
}

void QuarantinePage::loadQuarantinedFiles()
{
    // TODO: Load actual quarantined files
    // Sample data for now
    ui->fileList->addItem("C:/Users/Downloads/infected_file1.exe - Trojan.Win32");
    ui->fileList->addItem("C:/Users/Documents/suspicious_doc.pdf - Malware.PDF.123");
    ui->fileList->addItem("C:/Program Files/infected_app/virus.dll - Backdoor.Win32");
}

void QuarantinePage::updateButtons()
{
    bool hasSelection = !ui->fileList->selectedItems().isEmpty();
    ui->deleteButton->setEnabled(hasSelection);
    ui->keepButton->setEnabled(hasSelection);
}

void QuarantinePage::onItemSelectionChanged()
{
    updateButtons();
}
