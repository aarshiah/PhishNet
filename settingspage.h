#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class SettingsPage; }
QT_END_NAMESPACE

class SettingsPage : public QWidget
{
    Q_OBJECT

  public:
    explicit SettingsPage(QWidget *parent = nullptr);
    ~SettingsPage();
    static void applyDarkMode(QWidget* widget, bool isDark);

  private slots:
    void onBackButtonClicked();
    void onUpdateSignaturesClicked();
    void onDarkModeToggled(bool checked);

  signals:
    void backButtonClicked();
    void darkModeChanged(bool isDark);

  private:
    Ui::SettingsPage *ui;
    void loadSettings();
    void saveSettings();
};

#endif // SETTINGSPAGE_H
