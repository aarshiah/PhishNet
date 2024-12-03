#ifndef SCHEDULESCANPAGE_H
#define SCHEDULESCANPAGE_H

#include <QWidget>
#include <QTime>
#include <QObject>

namespace Ui {
class ScheduleScanPage;
}

class ScheduleScanPage : public QWidget
{
    Q_OBJECT

  public:
    /**
     * @brief Constructs a ScheduleScanPage widget
     * @param parent Optional parent widget
     */
    explicit ScheduleScanPage(QWidget *parent = nullptr);

    /**
     * @brief Destructor
     */
    ~ScheduleScanPage();

  private slots:
    /**
     * @brief Handles back button click
     * Emits backButtonClicked signal
     */
    void onBackButtonClicked();

    /**
     * @brief Handles schedule button click
     * Processes the selected time and frequency
     */
    void onScheduleButtonClicked();

  signals:
    /**
     * @brief Signal emitted when back button is clicked
     */
    void backButtonClicked();

  private:
    Ui::ScheduleScanPage *ui;
};

#endif // SCHEDULESCANPAGE_H
