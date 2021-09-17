#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <algorithm>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->initMainWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::serialConnect() {
    this->igla_serial_dev_.setPortName(this->serial_port_num_.toUpper());
    this->igla_serial_dev_.setBaudRate(QSerialPort::Baud9600);
    this->igla_serial_dev_.setDataBits(QSerialPort::Data8);
    this->igla_serial_dev_.setParity(QSerialPort::NoParity);
    this->igla_serial_dev_.setStopBits(QSerialPort::OneStop);
    return this->igla_serial_dev_.open(QIODevice::ReadWrite);
}

bool MainWindow::serialClose() {
    this->igla_serial_dev_.close();
}

void MainWindow::on_gDatapushButton_clicked()
{
    this->getData();

    //bad to do
    this->writeNP = STARTDATA;
    this->writeWA = STARTDATA;
    this->writeTM = STARTDATA;
    this->readNP.clear();
    this->readWA.clear();
    this->readTM.clear();

    //its bad too doo
    uint8_t CRCnp = QString(NPLVL).toUInt(nullptr, 16) xor this->tank_.tank_no_xex.toUInt(nullptr, 16);
    uint8_t CRCwa = QString(WATERLVL).toUInt(nullptr, 16) xor this->tank_.tank_no_xex.toUInt(nullptr, 16);
    uint8_t CRCtemp = QString(AVERAGETEMP).toUInt(nullptr, 16) xor this->tank_.tank_no_xex.toUInt(nullptr, 16);

    //VERY BAD SHIT
    this->writeNP += this->tank_.tank_no_xex + QString(NPLVL) + QString(DEFDATALEN) + "4" + QString::number(CRCnp,16) + QString(ENDDATA);
    this->writeWA += this->tank_.tank_no_xex + QString(WATERLVL) + QString(DEFDATALEN) + "4" + QString::number(CRCwa,16) + QString(ENDDATA);
    this->writeTM += this->tank_.tank_no_xex + QString(AVERAGETEMP) + QString(DEFDATALEN) + "4" + QString::number(CRCtemp,16) + QString(ENDDATA);

    //todo timer and SUCCESS GETTER INFO OR ERROR
    if(this->serialConnect()) {
        while(this->readNP.size() < 17 || this->readWA.size() < 17 || this->readTM.size() < 17) {
            this->igla_serial_dev_.waitForBytesWritten(200);
            this->igla_serial_dev_.write(this->writeNP, 11);
            this->igla_serial_dev_.waitForReadyRead(1000);
            this->readNP = this->igla_serial_dev_.readAll();

            this->igla_serial_dev_.waitForBytesWritten(200);
            this->igla_serial_dev_.write(this->writeWA, 11);
            this->igla_serial_dev_.waitForReadyRead(1000);
            this->readWA = this->igla_serial_dev_.readAll();

            this->igla_serial_dev_.waitForBytesWritten(200);
            this->igla_serial_dev_.write(this->writeTM, 11);
            this->igla_serial_dev_.waitForReadyRead(1000);
            this->readTM = this->igla_serial_dev_.readAll();
        }
    }
    this->serialClose();

    //TODO PARSING METHOD IN TANKMEASURE
    ui->NPlvlLabel->setText(QString::fromStdString(std::to_string(std::stoul(this->readNP.toStdString().substr(7, 4), nullptr, 16)) + " mm"));
    ui->WATERlvlLabel->setText(QString::fromStdString(std::to_string(std::stoul(this->readWA.toStdString().substr(7, 4), nullptr, 16)) + " mm"));
    ui->TemretureLabel->setText(QString::fromStdString(std::to_string(std::stoul(this->readTM.toStdString().substr(7, 4), nullptr, 16)) + " C"));
    //TODO MORE INFO IN SEPARATE METHOD
    ui->infoProcLbl->setText(QString::fromStdString(this->readNP.toStdString() + '\n' + this->readWA.toStdString() + '\n' + this->readTM.toStdString() + '\n'));


}

bool MainWindow::checkParamsFromForm()
{
    //THIS IS SCARY AS FUCK
    if((this->serial_port_num_.mid(0, 3) != "com" || this->serial_port_num_.mid(0, 3) != "COM") && (this->serial_port_num_.mid(3, 1) < "1" || this->serial_port_num_.mid(3, 1) > "9")) {
        return false;
    }
    if(this->tank_.tank_no < 0 || this->tank_.tank_no > 9) {
        return false;
    }
    return true;
}


void MainWindow::on_exitpushButton_clicked()
{
    this->close();
}


void MainWindow::getData()
{
    this->serial_port_num_ = ui->comlineEdit->text();
    this->tank_.tank_no = ui->tanklineEdit->text().toInt();
    this->tank_.tank_no_xex = this->tank_.getTankNoHEX();
    if(!this->checkParamsFromForm()) {
        QMessageBox::information(this, tr("ERROR"),  "Error in input data com\\tank");
    }
}

QString MainWindow::intToHex(const int data)
{
    char hex_string[20];
    sprintf(hex_string, "%X", data);
    QString res = hex_string;
    data < 10 ? res.insert(0, '0') : res;
    return res;
}

void MainWindow::initMainWindow()
{
    ui->NPlvlLabel->setText("0 mm");
    ui->WATERlvlLabel->setText("0 mm");
    ui->TemretureLabel->setText("0 C");
    ui->infoProcLbl->setText("INFO FIELD");
    ui->tanklineEdit->setText("write TANK no. from 1 to 16");
    ui->comlineEdit->setText("write comport no.");
}
