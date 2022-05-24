#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      device(new QSerialPort(this))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnConnect_clicked()
{
    ui->lblSerial->setText("Hello world!");
// if (ui->comboBoxDevices->count() == 0){
//     this->addToLogs("No devices found.");
//             return;
// }
 //QString portName = ui->comboBoxDevices->currentText().split(" ").first();
 QString portName = "ttyUSB0";
 this->device->setPortName(portName);
 this->device->setBaudRate(QSerialPort::Baud19200);
 this->device->setDataBits(QSerialPort::Data8);
 this->device->setParity(QSerialPort::NoParity);
 this->device->setStopBits(QSerialPort::OneStop);
 this->device->setFlowControl(QSerialPort::NoFlowControl);

 if(device->open(QIODevice::ReadWrite)){
     qDebug() << "Port opened successfully. Setting the connection params...";
     //this->addToLogs("UART enabled.");
     qDebug() << "Writing down the parameters...";
     qDebug() << "Baud rate:" << this->device->baudRate();
     qDebug() << "Data bits:" << this->device->dataBits();
     qDebug() << "Stop bits:" << this->device->stopBits();
     qDebug() << "Parity:" << this->device->parity();
     qDebug() << "Flow control:" << this->device->flowControl();
     qDebug() << "Read buffer size:" << this->device->readBufferSize();
     qDebug() << "Read buffer size:" << this->device->portName();
     connect(this->device, SIGNAL(readyRead()), this, SLOT(readFromPort()));
 } else {
     //this->addToLogs("The port can not be opened.");
 }
}
