#include "mainwindow.h"

#include <QApplication>

int windowWidth = 800;
int windowHeight = 800;
int starX = windowWidth / 2;
int starY = windowHeight / 2;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
