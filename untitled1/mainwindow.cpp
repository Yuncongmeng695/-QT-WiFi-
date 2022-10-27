#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setWindowTitle("WIFI控制");
    client = new QTcpSocket(this);
    client->abort();
    connect(client,SIGNAL(readyRead()),this,SLOT(ReadData()));
    connect(client,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(ReadError(QAbstractSocket::SocketError)));

    ui->cbb_speed->insertItem(0, "快");
    ui->cbb_speed->insertItem(1, "中");
    ui->cbb_speed->insertItem(2, "慢");

    this->ui->pushButton_back->setDisabled(true);
    this->ui->pushButton_go->setDisabled(true);
    this->ui->pushButton_left->setDisabled(true);
    this->ui->pushButton_right->setDisabled(true);
    this->ui->pushButton_stop->setDisabled(true);
    this->ui->cbb_speed->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete client ;
    delete ui;
}

void MainWindow::ReadData()
{
    QByteArray buffer = client->readAll();
    if(!buffer.isEmpty())
        ui->textBrowser->append(buffer);
}

void MainWindow::ReadError(QAbstractSocket::SocketError)
{
    client->disconnectFromHost();
}

void MainWindow::on_pushButton_go_clicked()
{
    QByteArray ba;
    ba[0]=0xFF;
    ba[1]=0x00;
    ba[2]=0x01;
    ba[3]=0x00;
    ba[4]=0xFF;

    ui->textBrowser->setText("前进");
    client->write(ba,ba.length());
}

void MainWindow::on_pushButton_left_clicked()
{
    QByteArray ba;
    ba[0]=0xFF;
    ba[1]=0x00;
    ba[2]=0x03;
    ba[3]=0x00;
    ba[4]=0xFF;

    ui->textBrowser->setText("左转");
    client->write(ba,ba.length());
}

void MainWindow::on_pushButton_right_clicked()
{
    QByteArray ba;
    ba[0]=0xFF;
    ba[1]=0x00;
    ba[2]=0x04;
    ba[3]=0x00;
    ba[4]=0xFF;

    ui->textBrowser->setText("右转");
    client->write(ba,ba.length());
}

void MainWindow::on_pushButton_stop_clicked()
{
    QByteArray ba;
    ba[0]=0xFF;
    ba[1]=0x00;
    ba[2]=0x00;
    ba[3]=0x00;
    ba[4]=0xFF;

    ui->textBrowser->setText("停止");
    client->write(ba,ba.length());
}

void MainWindow::on_pushButton_back_clicked()
{
    QByteArray ba;
    ba[0]=0xFF;
    ba[1]=0x00;
    ba[2]=0x02;
    ba[3]=0x00;
    ba[4]=0xFF;

    ui->textBrowser->setText("后退");
    client->write(ba,ba.length());
}

void MainWindow::on_pushButton_connect_clicked()
{
    client->abort();
    client->connectToHost("192.168.1.1",2001);
    if (client->waitForConnected(1000))
       {ui->label->setText("已连接小车");
        this->ui->pushButton_back->setEnabled(true);
        this->ui->pushButton_go->setEnabled(true);
        this->ui->pushButton_left->setEnabled(true);
        this->ui->pushButton_right->setEnabled(true);
        this->ui->pushButton_stop->setEnabled(true);
        this->ui->cbb_speed->setEnabled(true);
       }
    else
        ui->label->setText("连接小车失败");
}

void MainWindow::on_cbb_speed_currentIndexChanged(const QString &arg1)
{
    if(this-ui->cbb_speed->currentIndex() == 0)
    {
        QByteArray ba;
        ba[0]=0xFF;
        ba[1]=0x02;
        ba[2]=0x01;
        ba[3]=100;
        ba[4]=0xFF;
        client->write(ba,ba.length());

        ba[0]=0xFF;
        ba[1]=0x02;
        ba[2]=0x02;
        ba[3]=100;
        ba[4]=0xFF;
        client->write(ba,ba.length());

        ui->textBrowser->setText("快速");
    }
    if(this->ui->cbb_speed->currentIndex() == 1)
    {
        QByteArray ba;
        ba[0]=0xFF;
        ba[1]=0x02;
        ba[2]=0x01;
        ba[3]=50;
        ba[4]=0xFF;
        client->write(ba,ba.length());

        ba[0]=0xFF;
        ba[1]=0x02;
        ba[2]=0x02;
        ba[3]=50;
        ba[4]=0xFF;
        client->write(ba,ba.length());

        ui->textBrowser->setText("中速");
    }
    if(this->ui->cbb_speed->currentIndex() == 2)
    {
        QByteArray ba;
        ba[0]=0xFF;
        ba[1]=0x02;
        ba[2]=0x01;
        ba[3]=01;
        ba[4]=0xFF;
        client->write(ba,ba.length());

        ba[0]=0xFF;
        ba[1]=0x02;
        ba[2]=0x02;
        ba[3]=01;
        ba[4]=0xFF;
        client->write(ba,ba.length());

        ui->textBrowser->setText("慢速");
    }
}

