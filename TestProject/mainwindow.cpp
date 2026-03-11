#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHostAddress>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    socket = new QTcpSocket(this);

    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::on_readyRead);

    socket->connectToHost(QHostAddress::LocalHost, 8080);
    if (!socket->waitForConnected(3000)) {
        QMessageBox::critical(this, tr("Connection Error"), socket->errorString());
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_sendButton_clicked() {
    QString message = ui->messageLineEdit->text();
    if (!message.isEmpty()) {
        socket->write(message.toUtf8());
        ui->messageLineEdit->clear();
    }
}

void MainWindow::on_readyRead() {
    QByteArray response = socket->readAll();
    ui->responseTextEdit->append(response);
}
