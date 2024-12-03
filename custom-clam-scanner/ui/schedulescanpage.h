#ifndef SCHEDULESCANPAGE_H
#define SCHEDULESCANPAGE_H

#include <QWidget>
#include <QTime>
#include <QObject>
#include "scheduler.h"

namespace Ui {
class ScheduleScanPage;
}

class ScheduleScanPage : public QWidget
{
    Q_OBJECT

public:
    explicit ScheduleScanPage(QWidget *parent = nullptr);
    ~ScheduleScanPage();

private slots:
    void onBackButtonClicked();
    void onScheduleButtonClicked();
    void onDeleteScanClicked(int scanId);

signals:
    void backButtonClicked();

private:
    Ui::ScheduleScanPage *ui;
    ScanScheduler* scheduler;
    void setupUI();
    void loadScheduledScans();
    QString selectedDirectory;
};

#endif // SCHEDULESCANPAGE_H