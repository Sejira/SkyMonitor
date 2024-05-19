/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *temperatureLabel;
    QLabel *descriptionLabel;
    QLabel *humidityLabel;
    QLabel *windSpeedLabel;
    QLabel *minTemperatureLabel;
    QLabel *maxTemperatureLabel;
    QLabel *pressureLabel;
    QLabel *sunriseLabel;
    QLabel *sunsetLabel;
    QLineEdit *cityLineEdit;
    QLineEdit *countryLineEdit;
    QPushButton *submitButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *statusLabel;
    QLabel *cityLabel;
    QLabel *countryLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        temperatureLabel = new QLabel(centralwidget);
        temperatureLabel->setObjectName("temperatureLabel");
        temperatureLabel->setGeometry(QRect(40, 40, 201, 16));
        descriptionLabel = new QLabel(centralwidget);
        descriptionLabel->setObjectName("descriptionLabel");
        descriptionLabel->setGeometry(QRect(40, 100, 201, 16));
        humidityLabel = new QLabel(centralwidget);
        humidityLabel->setObjectName("humidityLabel");
        humidityLabel->setGeometry(QRect(40, 120, 201, 16));
        windSpeedLabel = new QLabel(centralwidget);
        windSpeedLabel->setObjectName("windSpeedLabel");
        windSpeedLabel->setGeometry(QRect(40, 140, 201, 16));
        minTemperatureLabel = new QLabel(centralwidget);
        minTemperatureLabel->setObjectName("minTemperatureLabel");
        minTemperatureLabel->setGeometry(QRect(40, 60, 201, 16));
        maxTemperatureLabel = new QLabel(centralwidget);
        maxTemperatureLabel->setObjectName("maxTemperatureLabel");
        maxTemperatureLabel->setGeometry(QRect(40, 80, 201, 16));
        pressureLabel = new QLabel(centralwidget);
        pressureLabel->setObjectName("pressureLabel");
        pressureLabel->setGeometry(QRect(40, 160, 201, 16));
        sunriseLabel = new QLabel(centralwidget);
        sunriseLabel->setObjectName("sunriseLabel");
        sunriseLabel->setGeometry(QRect(40, 180, 201, 16));
        sunsetLabel = new QLabel(centralwidget);
        sunsetLabel->setObjectName("sunsetLabel");
        sunsetLabel->setGeometry(QRect(40, 200, 201, 16));
        cityLineEdit = new QLineEdit(centralwidget);
        cityLineEdit->setObjectName("cityLineEdit");
        cityLineEdit->setGeometry(QRect(110, 230, 113, 23));
        countryLineEdit = new QLineEdit(centralwidget);
        countryLineEdit->setObjectName("countryLineEdit");
        countryLineEdit->setGeometry(QRect(110, 260, 113, 23));
        submitButton = new QPushButton(centralwidget);
        submitButton->setObjectName("submitButton");
        submitButton->setGeometry(QRect(40, 290, 80, 24));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 230, 57, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 260, 57, 21));
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(140, 290, 151, 21));
        cityLabel = new QLabel(centralwidget);
        cityLabel->setObjectName("cityLabel");
        cityLabel->setGeometry(QRect(240, 230, 111, 21));
        countryLabel = new QLabel(centralwidget);
        countryLabel->setObjectName("countryLabel");
        countryLabel->setGeometry(QRect(240, 260, 111, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        temperatureLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        descriptionLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        humidityLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        windSpeedLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        minTemperatureLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        maxTemperatureLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pressureLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        sunriseLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        sunsetLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        submitButton->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Ville", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Pays", nullptr));
        statusLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        cityLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        countryLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
