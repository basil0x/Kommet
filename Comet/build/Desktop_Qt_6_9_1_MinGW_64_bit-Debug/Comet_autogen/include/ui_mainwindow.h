/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <cometwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    CometWidget *widget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_1;
    QSlider *sl_scale_1;
    QLabel *l_scale_1;
    QLabel *label;
    QSlider *sl_scale;
    QLabel *l_scale;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new CometWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 40, 761, 471));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 801, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_1 = new QLabel(horizontalLayoutWidget);
        label_1->setObjectName("label_1");

        horizontalLayout->addWidget(label_1);

        sl_scale_1 = new QSlider(horizontalLayoutWidget);
        sl_scale_1->setObjectName("sl_scale_1");
        sl_scale_1->setMinimum(0);
        sl_scale_1->setMaximum(90);
        sl_scale_1->setValue(0);
        sl_scale_1->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout->addWidget(sl_scale_1);

        l_scale_1 = new QLabel(horizontalLayoutWidget);
        l_scale_1->setObjectName("l_scale_1");
        l_scale_1->setMargin(4);

        horizontalLayout->addWidget(l_scale_1);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        sl_scale = new QSlider(horizontalLayoutWidget);
        sl_scale->setObjectName("sl_scale");
        sl_scale->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout->addWidget(sl_scale);

        l_scale = new QLabel(horizontalLayoutWidget);
        l_scale->setObjectName("l_scale");
        l_scale->setMargin(4);

        horizontalLayout->addWidget(l_scale);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 510, 761, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(sl_scale, &QSlider::valueChanged, l_scale, qOverload<int>(&QLabel::setNum));
        QObject::connect(sl_scale_1, &QSlider::valueChanged, l_scale_1, qOverload<int>(&QLabel::setNum));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_1->setText(QCoreApplication::translate("MainWindow", "Ugao", nullptr));
        l_scale_1->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Po\304\215etna brzinna", nullptr));
        l_scale->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
