#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateWeatherInformation(const QString& jsonResponse);

private:
    Ui::MainWindow* ui;
    QTimer* timer;  // Ajout du minuteur
};
#endif // MAINWINDOW_H