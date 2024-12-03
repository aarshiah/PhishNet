#ifndef SCANTYPEPAGE_H
#define SCANTYPEPAGE_H
#include <QWidget>
#include <QFileDialog>

namespace Ui {
class ScanTypePage;
}

class ScanTypePage : public QWidget
{
    Q_OBJECT
  public:
    explicit ScanTypePage(QWidget *parent = nullptr);
    ~ScanTypePage();

  private slots:
    void backToMain();
    void showQuickScan();
    void showSystemScan();
    void showCustomScan();
    void browseFiles();
    void startQuickScan();
    void startSystemScan();
    void startCustomScan();

  signals:
    void backButtonClicked();

  private:
    Ui::ScanTypePage *ui;
};

#endif // SCANTYPEPAGE_H
