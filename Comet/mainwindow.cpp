#include "mainwindow.h"
#include "cometwidget.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    double v0 = 42058.1;
    double angle = M_PI/2;
    ui->widget->startSimulation(v0, angle);
}

MainWindow::~MainWindow()
{
    delete ui;
}
