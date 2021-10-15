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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool serialConnect();

    bool serialClose();

private slots:
    void on_gDatapushButton_clicked();

    void on_exitpushButton_clicked();

private:
    void fillMeasure();

    bool checkCrc(const QByteArray& data);

    bool checkParamsFromForm();

    bool checkBufferCorrect(const QByteArray& data);

    uint8_t calcucateCrc(const std::string& sensornum);

    void getData();

    void initMainWindow();

    Ui::MainWindow *ui;
    QSerialPort igla_serial_dev_;
    QString serial_port_num_;

    Tank tank_;
    QByteArray writeNP = STARTDATA;
    QByteArray writeWA = STARTDATA;
    QByteArray writeTM = STARTDATA;
    QByteArray writeDEN = STARTDATA;
    QByteArray writeVOL = STARTDATA;
    QByteArray writeMASS = STARTDATA;
    QByteArray writeREFRESH = REFRESHDATA;
    QByteArray readNP;
    QByteArray readWA;
    QByteArray readTM;
    QByteArray readDEN;
    QByteArray readVOL;
    QByteArray readMASS;
    QByteArray readREFRESHSTATUS;
};
#endif // MAINWINDOW_H
