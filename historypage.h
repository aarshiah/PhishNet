#ifndef HISTORYPAGE_H
#define HISTORYPAGE_H

#include <QWidget>
#include <QTableWidgetItem>
#include <QObject>

namespace Ui {
class HistoryPage;
}

class HistoryPage : public QWidget
{
    Q_OBJECT

  public:
    explicit HistoryPage(QWidget *parent = nullptr);
    ~HistoryPage();

  private slots:
    void onBackButtonClicked();
    void refreshHistory();
    void onTableItemDoubleClicked(QTableWidgetItem *item);


  signals:
    void backButtonClicked();

  private:
    Ui::HistoryPage *ui;
    void setupTable();
    void addScanRecord(const QString& date, const QString& time,
                       const QString& type, bool infected,
                       const QString& details = QString());
};

#endif // HISTORYPAGE_H
