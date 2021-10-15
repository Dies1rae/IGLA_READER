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
    this->igla_serial_dev_.setPortName(this->serial_port_num_);
    this->igla_serial_dev_.setBaudRate(QSerialPort::Baud9600);
    this->igla_serial_dev_.setDataBits(QSerialPort::Data8);
    this->igla_serial_dev_.setParity(QSerialPort::NoParity);
    this->igla_serial_dev_.setStopBits(QSerialPort::OneStop);
    return this->igla_serial_dev_.open(QIODevice::ReadWrite);
}

bool MainWindow::serialClose() {
    this->igla_serial_dev_.close();
    return true;
}

void MainWindow::on_gDatapushButton_clicked()
{ 
    this->getData();

    //bad to do
    this->writeNP = STARTDATA;
    this->writeWA = STARTDATA;
    this->writeTM = STARTDATA;
    this->writeDEN = STARTDATA;
    this->writeVOL = STARTDATA;
    this->writeMASS = STARTDATA;
    this->readNP.clear();
    this->readWA.clear();
    this->readTM.clear();
    this->readDEN.clear();
    this->readVOL.clear();
    this->readMASS.clear();
    this->readREFRESHSTATUS.clear();

    //its bad too doo
    uint8_t CRCnp = this->calcucateCrc(NPLVL);
    uint8_t CRCwa = this->calcucateCrc(WATERLVL);
    uint8_t CRCtemp = this->calcucateCrc(AVERAGETEMP);
    uint8_t CRCDEN = this->calcucateCrc(DENCITY);
    uint8_t CRCVOL = this->calcucateCrc(VOLUME);
    uint8_t CRCMASS = this->calcucateCrc(NPMASS);
    //VERY BAD SHIT
    this->writeNP += this->tank_.tank_no_xex + QString(NPLVL) + QString(DEFDATALEN) + QString::number(CRCnp,16) + QString(ENDDATA);
    this->writeWA += this->tank_.tank_no_xex + QString(WATERLVL) + QString(DEFDATALEN) + QString::number(CRCwa,16) + QString(ENDDATA);
    this->writeTM += this->tank_.tank_no_xex + QString(AVERAGETEMP) + QString(DEFDATALEN) + QString::number(CRCtemp,16) + QString(ENDDATA);
    this->writeDEN += this->tank_.tank_no_xex + QString(DENCITY) + QString(DEFDATALEN) + QString::number(CRCDEN,16) + QString(ENDDATA);
    this->writeMASS += this->tank_.tank_no_xex + QString(NPMASS) + QString(DEFDATALEN) + QString::number(CRCMASS,16) + QString(ENDDATA);
    this->writeVOL += this->tank_.tank_no_xex + QString(VOLUME) + QString(DEFDATALEN) + QString::number(CRCVOL,16) + QString(ENDDATA);

    //todo timer and SUCCESS GETTER INFO OR ERROR

    if(this->serialConnect()) {
        this->igla_serial_dev_.waitForBytesWritten(15);
        this->igla_serial_dev_.write(this->writeREFRESH, 11);
        this->igla_serial_dev_.waitForReadyRead(1000);
        this->readREFRESHSTATUS = this->igla_serial_dev_.readAll();
        if(!!this->readREFRESHSTATUS.size()) {
            return;
        }
        while(!checkBufferCorrect(this->readNP)|| !checkBufferCorrect(this->readWA) || !checkBufferCorrect(this->readTM) ||
              !checkBufferCorrect(this->readDEN) || !checkBufferCorrect(this->readMASS) || !checkBufferCorrect(this->readVOL)) {

            this->igla_serial_dev_.waitForBytesWritten(15);
            this->igla_serial_dev_.write(this->writeNP, 11);
            this->igla_serial_dev_.waitForReadyRead(4);
            this->readNP = this->igla_serial_dev_.readAll();

            this->igla_serial_dev_.waitForBytesWritten(15);
            this->igla_serial_dev_.write(this->writeWA, 11);
            this->igla_serial_dev_.waitForReadyRead(4);
            this->readWA = this->igla_serial_dev_.readAll();

            this->igla_serial_dev_.waitForBytesWritten(15);
            this->igla_serial_dev_.write(this->writeTM, 11);
            this->igla_serial_dev_.waitForReadyRead(4);
            this->readTM = this->igla_serial_dev_.readAll();

            this->igla_serial_dev_.waitForBytesWritten(15);
            this->igla_serial_dev_.write(this->writeDEN, 11);
            this->igla_serial_dev_.waitForReadyRead(4);
            this->readDEN = this->igla_serial_dev_.readAll();

            this->igla_serial_dev_.waitForBytesWritten(15);
            this->igla_serial_dev_.write(this->writeMASS, 13);
            this->igla_serial_dev_.waitForReadyRead(4);
            this->readMASS = this->igla_serial_dev_.readAll();

            this->igla_serial_dev_.waitForBytesWritten(15);
            this->igla_serial_dev_.write(this->writeVOL, 13);
            this->igla_serial_dev_.waitForReadyRead(4);
            this->readVOL = this->igla_serial_dev_.readAll();
        }
    } else {
        QMessageBox::information(this, tr("ERROR"),  "Error in open COM port");
        return;
    }
    this->serialClose();
    //parse and show info

    this->fillMeasure();
    this->tank_.npl_ != ERROR ? ui->NPlvlLabel->setText(QString::fromStdString(std::to_string(this->tank_.npl_) + " mm")) :  ui->NPlvlLabel->setText("Sensor error");

    this->tank_.wl_ != ERROR ? ui->WATERlvlLabel->setText(QString::fromStdString(std::to_string(this->tank_.wl_) + " mm")) : ui->WATERlvlLabel->setText("Sensor error");

    this->tank_.av_temp_ != ERROR ? ui->TemretureLabel->setText(QString::fromStdString(std::to_string(this->tank_.av_temp_) + " C")) : ui->TemretureLabel->setText("Sensor error");

    this->tank_.np_den_ != ERROR ? ui->Denlable->setText(QString::fromStdString(std::to_string(this->tank_.np_den_) + " kg/m3")) : ui->Denlable->setText("Sensor error");
    //TODO MORE INFO IN SEPARATE METHOD
    ui->infoProcLbl->setText(QString::fromStdString("---\n" + this->readNP.toStdString() + '\n' + this->readWA.toStdString() + '\n' + this->readTM.toStdString() + '\n' + this->readDEN.toStdString() + '\n' +
                                                    this->readMASS.toStdString() + '\n' + this->readVOL.toStdString() + '\n' + this->readREFRESHSTATUS.toStdString() + '\n' + "---\n"));
}

bool MainWindow::checkParamsFromForm()
{
    if(this->tank_.tank_no < 0 || this->tank_.tank_no > 15) {
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
    this->tank_.tank_no_xex = intToHex(this->tank_.tank_no);
    if(!this->checkParamsFromForm()) {
        QMessageBox::information(this, tr("ERROR"),  "Error in input data com\\tank\n Set default port to 0");
        this->serial_port_num_ = "0";
        this->tank_.tank_no = ui->tanklineEdit->text().toInt();
        this->tank_.tank_no_xex = intToHex(this->tank_.tank_no);
    }
}

void MainWindow::initMainWindow()
{
    ui->NPlvlLabel->setText("0 mm");
    ui->WATERlvlLabel->setText("0 mm");
    ui->TemretureLabel->setText("0 C");
    ui->Denlable->setText("0 kg/m3");
    ui->infoProcLbl->setText("INFO FIELD");
    ui->tanklineEdit->setText("write TANK no. from 1 to 16");
    ui->comlineEdit->setText("write comport no.");
}


bool MainWindow::checkCrc(const QByteArray& data) {
    uint8_t crc_src = data.at(1);
    for(int ptr = 2; ptr < data.size() - 4; ptr++) {
        qDebug() << data.at(ptr);
        crc_src ^= data.at(ptr);
    }
    crc_src > 0x0F ? crc_src = crc_src % 16, crc_src += 48 : crc_src += 64;
    uint8_t crc_dst = std::stoul(data.toStdString().substr(data.size() - 4, 2), nullptr, 16);
    return crc_src == crc_dst;
}

uint8_t MainWindow::calcucateCrc(const std::string& sensornum) {
    uint8_t calculated_crc = QString(sensornum[0]).toUInt(nullptr, 16) xor QString(sensornum[1]).toUInt(nullptr, 16) xor (this->tank_.tank_no_xex.toStdString()[0] - '0') xor (this->tank_.tank_no_xex.toStdString()[1] - '0');
    return this->tank_.tank_no > 9 ? calculated_crc + 32 : calculated_crc + 64;
}

bool MainWindow::checkBufferCorrect(const QByteArray& data) {
    return data.toStdString()[0] == '@' && data.toStdString()[data.size() - 2] == '*';
}

void MainWindow::fillMeasure() {
    this->checkCrc(this->readNP) ? this->tank_.npl_ = std::stoul(this->readNP.toStdString().substr(7, 4), nullptr, 16) + (std::stod(this->readNP.toStdString().substr(12, 1)) / 10.0) :  this->tank_.npl_ = ERROR;
    this->checkCrc(this->readWA) ? this->tank_.wl_ = std::stoul(this->readWA.toStdString().substr(7, 4), nullptr, 16) + (std::stod(this->readWA.toStdString().substr(12, 1)) / 10.0)  : this->tank_.wl_ = ERROR;
    this->checkCrc(this->readTM) ? this->tank_.av_temp_ = std::stoul(this->readTM.toStdString().substr(9, 2), nullptr, 16) + (std::stod(this->readTM.toStdString().substr(12, 1)) / 10.0)  : this->tank_.av_temp_ = ERROR;
    if(this->readTM.toStdString()[7] == 'F' && this->readTM.toStdString()[8] == 'F') {
        this->tank_.av_temp_ *= -1;
    }
    this->checkCrc(this->readDEN) ? this->tank_.np_den_ = std::stoul(this->readDEN.toStdString().substr(7, 4), nullptr, 16) + (std::stod(this->readDEN.toStdString().substr(12, 1)) / 10.0)  : this->tank_.np_den_ = ERROR;
}
