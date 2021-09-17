/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *infoProcLbl;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_3;
    QPushButton *exitpushButton;
    QLabel *label_5;
    QLabel *NPlvlLabel;
    QLabel *WATERlvlLabel;
    QLabel *label_4;
    QLabel *label;
    QLabel *TemretureLabel;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QPushButton *gDatapushButton;
    QLabel *label_6;
    QLineEdit *tanklineEdit;
    QLineEdit *comlineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1082, 568);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        infoProcLbl = new QLabel(centralwidget);
        infoProcLbl->setObjectName(QString::fromUtf8("infoProcLbl"));

        gridLayout->addWidget(infoProcLbl, 7, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        exitpushButton = new QPushButton(centralwidget);
        exitpushButton->setObjectName(QString::fromUtf8("exitpushButton"));

        gridLayout->addWidget(exitpushButton, 9, 1, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        NPlvlLabel = new QLabel(centralwidget);
        NPlvlLabel->setObjectName(QString::fromUtf8("NPlvlLabel"));

        gridLayout->addWidget(NPlvlLabel, 3, 1, 1, 1);

        WATERlvlLabel = new QLabel(centralwidget);
        WATERlvlLabel->setObjectName(QString::fromUtf8("WATERlvlLabel"));

        gridLayout->addWidget(WATERlvlLabel, 4, 1, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        TemretureLabel = new QLabel(centralwidget);
        TemretureLabel->setObjectName(QString::fromUtf8("TemretureLabel"));

        gridLayout->addWidget(TemretureLabel, 5, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 7, 0, 1, 1);

        gDatapushButton = new QPushButton(centralwidget);
        gDatapushButton->setObjectName(QString::fromUtf8("gDatapushButton"));

        gridLayout->addWidget(gDatapushButton, 8, 1, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        tanklineEdit = new QLineEdit(centralwidget);
        tanklineEdit->setObjectName(QString::fromUtf8("tanklineEdit"));

        gridLayout->addWidget(tanklineEdit, 0, 1, 1, 1);

        comlineEdit = new QLineEdit(centralwidget);
        comlineEdit->setObjectName(QString::fromUtf8("comlineEdit"));

        gridLayout->addWidget(comlineEdit, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1082, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        infoProcLbl->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "NPlvl", nullptr));
        exitpushButton->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Temreture", nullptr));
        NPlvlLabel->setText(QApplication::translate("MainWindow", "NPlvl", nullptr));
        WATERlvlLabel->setText(QApplication::translate("MainWindow", "WATERlvl", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "WATERlvl", nullptr));
        label->setText(QApplication::translate("MainWindow", "Tank No.", nullptr));
        TemretureLabel->setText(QApplication::translate("MainWindow", "Temreture", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Proccess", nullptr));
        gDatapushButton->setText(QApplication::translate("MainWindow", "GetData", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Com port", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
