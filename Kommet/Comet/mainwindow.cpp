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
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked_start);
    QSlider *slider = ui->sl_scale;

    slider->setMinimum(getV0Range().first);
    slider->setMaximum(getV0Range().second);
    slider->setValue(42058);

}

void MainWindow::on_pushButton_clicked_start()
{
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
float MainWindow::on_pushButton_clicked_angle()
{
    float alfa = ui->sl_scale_1->value() * (M_PI / 180.0);

    qDebug() << "Slider value on button click:" << alfa;
    return alfa;

}

MainWindow::~MainWindow()
{


    delete ui;
}
