#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ws = new QWebSocket();
    ui->setupUi(this);
    connect(ws, &QWebSocket::connected, this, &MainWindow::onConnected);
    connect(ws, &QWebSocket::disconnected, this, &MainWindow::onDisconnected);
    connect(ws, &QWebSocket::textMessageReceived, this, &MainWindow::onReceive);
    ws->open(QUrl("ws://192.168.0.228:81"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onReceive(const QString &mes)
{
    QString message = mes;
    if(message == "?0")
    {
        ui->endis->setText("Включить");
    }
    else if(message == "?1")
    {
        ui->endis->setText("Выключить");
    }
    else if(message.contains('*'))
    {
        message = message.replace('*', "");
        ui->step->setValue(message.toInt());
    }
    else if(message.contains('#'))
    {
        message = message.replace('#', "");
        ui->speed->setValue(message.toInt());
    }
    else if(message.contains('@'))
    {
        message = message.replace('@', "");
        ui->brightness->setValue(message.toInt());
    }
}

void MainWindow::onDisconnected()
{
    ui->step->setEnabled(false);
    ui->speed->setEnabled(false);
    ui->brightness->setEnabled(false);
    ui->endis->setEnabled(false);
    ui->progress->setVisible(true);
    ui->connection->setVisible(true);
}

void MainWindow::onConnected()
{
    ui->step->setEnabled(true);
    ui->speed->setEnabled(true);
    ui->brightness->setEnabled(true);
    ui->endis->setEnabled(true);
    ui->progress->setVisible(false);
    ui->connection->setVisible(false);
}

void MainWindow::on_brightness_valueChanged(int value)
{
    ws->sendTextMessage("@" + QString::number(ui->brightness->value()));
}

void MainWindow::on_step_valueChanged(int value)
{
    ws->sendTextMessage("*" + QString::number(ui->step->value()));
}

void MainWindow::on_speed_valueChanged(int value)
{
    ws->sendTextMessage("#" + QString::number(ui->speed->value()));
}

void MainWindow::on_endis_clicked()
{
    ws->sendTextMessage("?");
}
