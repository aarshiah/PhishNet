// settingspage.h
#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include <QWidget>

namespace Ui {
class SettingsPage;
}

class SettingsPage : public QWidget
{
    Q_OBJECT

  public:
    explicit SettingsPage(QWidget *parent = nullptr);
    ~SettingsPage();

  private slots:
    void onBackButtonClicked();
    void onSaveButtonClicked();
    void onResetDefaultsClicked();
    void onUpdateCheckboxChanged(int state);

  signals:
    void backButtonClicked();

  private:
    Ui::SettingsPage *ui;
    void loadSettings();
    void saveSettings();
};

#endif
