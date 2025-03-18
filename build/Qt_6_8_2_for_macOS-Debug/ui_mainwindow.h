/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpinBox *limitSpinBox;
    QLabel *labelThreads;
    QSlider *threadSlider;
    QLabel *resultText;
    QHBoxLayout *hboxLayout;
    QPushButton *startButton;
    QPushButton *stopButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 300);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        limitSpinBox = new QSpinBox(centralwidget);
        limitSpinBox->setObjectName("limitSpinBox");
        limitSpinBox->setMinimum(1);
        limitSpinBox->setMaximum(100000000);
        limitSpinBox->setValue(100000);

        verticalLayout->addWidget(limitSpinBox);

        labelThreads = new QLabel(centralwidget);
        labelThreads->setObjectName("labelThreads");

        verticalLayout->addWidget(labelThreads);

        threadSlider = new QSlider(centralwidget);
        threadSlider->setObjectName("threadSlider");
        threadSlider->setMinimum(1);
        threadSlider->setMaximum(8);
        threadSlider->setValue(4);
        threadSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(threadSlider);

        resultText = new QLabel(centralwidget);
        resultText->setObjectName("resultText");

        verticalLayout->addWidget(resultText);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName("hboxLayout");
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");

        hboxLayout->addWidget(startButton);

        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName("stopButton");

        hboxLayout->addWidget(stopButton);


        verticalLayout->addLayout(hboxLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Collatz Sequence", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Limit (Max Number):", nullptr));
        labelThreads->setText(QCoreApplication::translate("MainWindow", "Threads:", nullptr));
        resultText->setText(QCoreApplication::translate("MainWindow", "Results will appear here...", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
