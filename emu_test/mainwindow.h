#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCoreApplication>
#include <QtSerialPort>
#include <QSerialPort>
#include <QIODevice>
#include <bitset>
#include <fstream>
#include <vector>
#include <string>

#include "tank.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum sensor {
        NP = 4,
        WATER = 5,
        TEMPRETURE = 6,
    };

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool serialConnect();

    bool serialClose();

private slots:
    void on_gDatapushButton_clicked();

    void on_exitpushButton_clicked();

private:
    bool checkParamsFromForm();

    void getData();

    QString intToHex(const int data);

    void initMainWindow();

    Ui::MainWindow *ui;
    QSerialPort igla_serial_dev_;
    QString serial_port_num_;

    Tank tank_;
    QByteArray writeNP = "@";
    QByteArray writeWA = "@";
    QByteArray writeTM = "@";
    QByteArray readNP;
    QByteArray readWA;
    QByteArray readTM;
};
#endif // MAINWINDOW_H