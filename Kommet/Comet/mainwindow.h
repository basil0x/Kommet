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
    int on_pushButton_clicked();
    float on_pushButton_clicked_angle();
    void on_pushButton_clicked_start();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
