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
#include <QtWidgets/QFrame>
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
    QLabel *WATERlvlLabel;
    QLabel *label_4;
    QLabel *label;
    QFrame *line_4;
    QLabel *label_3;
    QLineEdit *tanklineEdit;
    QLabel *NPlvlLabel;
    QPushButton *exitpushButton;
    QLabel *TemretureLabel;
    QFrame *line_6;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_5;
    QLabel *infoProcLbl;
    QFrame *line;
    QPushButton *gDatapushButton;
    QFrame *line_2;
    QFrame *line_5;
    QLineEdit *comlineEdit;
    QLabel *label_6;
    QSpacerItem *verticalSpacer;
    QFrame *line_3;
    QFrame *line_7;
    QFrame *line_8;
    QFrame *line_9;
    QFrame *line_10;
    QFrame *line_11;
    QFrame *line_12;
    QFrame *line_13;
    QFrame *line_14;
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
        WATERlvlLabel = new QLabel(centralwidget);
        WATERlvlLabel->setObjectName(QString::fromUtf8("WATERlvlLabel"));
        QFont font;
        font.setPointSize(12);
        font.setUnderline(true);
        WATERlvlLabel->setFont(font);

        gridLayout->addWidget(WATERlvlLabel, 5, 1, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        label_4->setFont(font1);

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 0, 2, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        tanklineEdit = new QLineEdit(centralwidget);
        tanklineEdit->setObjectName(QString::fromUtf8("tanklineEdit"));

        gridLayout->addWidget(tanklineEdit, 0, 1, 1, 1);

        NPlvlLabel = new QLabel(centralwidget);
        NPlvlLabel->setObjectName(QString::fromUtf8("NPlvlLabel"));
        NPlvlLabel->setFont(font);

        gridLayout->addWidget(NPlvlLabel, 4, 1, 1, 1);

        exitpushButton = new QPushButton(centralwidget);
        exitpushButton->setObjectName(QString::fromUtf8("exitpushButton"));
        QFont font2;
        font2.setPointSize(15);
        exitpushButton->setFont(font2);

        gridLayout->addWidget(exitpushButton, 9, 1, 1, 1);

        TemretureLabel = new QLabel(centralwidget);
        TemretureLabel->setObjectName(QString::fromUtf8("TemretureLabel"));
        TemretureLabel->setFont(font);

        gridLayout->addWidget(TemretureLabel, 6, 1, 1, 1);

        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_6, 2, 2, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 3, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        infoProcLbl = new QLabel(centralwidget);
        infoProcLbl->setObjectName(QString::fromUtf8("infoProcLbl"));
        infoProcLbl->setFont(font);
        infoProcLbl->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(infoProcLbl, 2, 3, 1, 1);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 3, 1, 1, 1);

        gDatapushButton = new QPushButton(centralwidget);
        gDatapushButton->setObjectName(QString::fromUtf8("gDatapushButton"));
        QFont font3;
        font3.setPointSize(20);
        gDatapushButton->setFont(font3);

        gridLayout->addWidget(gDatapushButton, 8, 1, 1, 1);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 3, 0, 1, 1);

        line_5 = new QFrame(centralwidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_5, 1, 2, 1, 1);

        comlineEdit = new QLineEdit(centralwidget);
        comlineEdit->setObjectName(QString::fromUtf8("comlineEdit"));

        gridLayout->addWidget(comlineEdit, 1, 1, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 10, 1, 1, 1);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 3, 3, 1, 1);

        line_7 = new QFrame(centralwidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_7, 4, 2, 1, 1);

        line_8 = new QFrame(centralwidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_8, 10, 2, 1, 1);

        line_9 = new QFrame(centralwidget);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_9, 9, 2, 1, 1);

        line_10 = new QFrame(centralwidget);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setFrameShape(QFrame::VLine);
        line_10->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_10, 8, 2, 1, 1);

        line_11 = new QFrame(centralwidget);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setFrameShape(QFrame::VLine);
        line_11->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_11, 5, 2, 1, 1);

        line_12 = new QFrame(centralwidget);
        line_12->setObjectName(QString::fromUtf8("line_12"));
        line_12->setFrameShape(QFrame::VLine);
        line_12->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_12, 6, 2, 1, 1);

        line_13 = new QFrame(centralwidget);
        line_13->setObjectName(QString::fromUtf8("line_13"));
        line_13->setFrameShape(QFrame::HLine);
        line_13->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_13, 7, 0, 1, 1);

        line_14 = new QFrame(centralwidget);
        line_14->setObjectName(QString::fromUtf8("line_14"));
        line_14->setFrameShape(QFrame::HLine);
        line_14->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_14, 7, 1, 1, 1);

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
        WATERlvlLabel->setText(QApplication::translate("MainWindow", "WATERlvl", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "WATERlvl", nullptr));
        label->setText(QApplication::translate("MainWindow", "Tank No.", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "NPlvl", nullptr));
        NPlvlLabel->setText(QApplication::translate("MainWindow", "NPlvl", nullptr));
        exitpushButton->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        TemretureLabel->setText(QApplication::translate("MainWindow", "Temreture", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Proccess", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Temreture", nullptr));
        infoProcLbl->setText(QApplication::translate("MainWindow", "Information field", nullptr));
        gDatapushButton->setText(QApplication::translate("MainWindow", "GetData", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Com port", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
