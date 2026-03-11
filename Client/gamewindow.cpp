#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <client.h>

Gamewindow::Gamewindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Gamewindow)
{
    ui->setupUi(this);
}

Gamewindow::~Gamewindow()
{
    delete ui;
}

void Gamewindow::changeCat(int place, std::string catName) {
    QLabel* catNameLabels[] = { ui->cat1Name, ui->cat2Name};
    QLabel* catLabels[] = { ui->cat1, ui->cat2};

    catNameLabels[place-1]->setText(QString::fromStdString(catName));
    catLabels[place-1]->setStyleSheet("border-image: url(:/cats/resources/" + QString::fromStdString(catName) + ".png);"
                                                                                                      "background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, "
                                                                                                      "stop:0 rgba(255, 255, 255, 255), stop:0.1 rgba(255, 255, 255, 255), "
                                                                                                      "stop:0.2 rgba(255, 176, 176, 167), stop:0.3 rgba(255, 151, 151, 92), "
                                                                                                      "stop:0.4 rgba(255, 125, 125, 51), stop:0.5 rgba(255, 76, 76, 205), "
                                                                                                      "stop:0.52 rgba(255, 76, 76, 205), stop:0.6 rgba(255, 180, 180, 84), "
                                                                                                      "stop:1 rgba(255, 255, 255, 0));");
}

void Gamewindow::on_pushButton_clicked()
{
    client *clients = new client();
    clients->sendData("selectedCat", SERVER_PORT);
}

