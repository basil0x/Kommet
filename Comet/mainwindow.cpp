#include "mainwindow.h"
#include "cometwidget.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked_angle);
    QSlider *slider = ui->sl_scale;

    slider->setMinimum(getV0Range().first);
    slider->setMaximum(getV0Range().second);
    double v0 = on_pushButton_clicked(); // TODO: uzeti iz slajdera v0 i ugao
    double angle = on_pushButton_clicked_angle();
    ui->widget->startSimulation(v0, angle);

}

int MainWindow::on_pushButton_clicked()
{
    int v0 = ui->sl_scale->value();
    qDebug() << "Slider value on button click:" << v0;
    return v0;

}
int MainWindow::on_pushButton_clicked_angle()
{
    int alfa = ui->sl_scale_1->value();
    qDebug() << "Slider value on button click:" << alfa;
    return alfa;

}

MainWindow::~MainWindow()
{


    delete ui;
}
