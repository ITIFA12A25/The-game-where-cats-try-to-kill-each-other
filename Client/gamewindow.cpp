#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <client.h>
#include <iostream>

int scratchUses = 0;
int biteUses = 0;
int headbuttUses = 0;
int kickUses = 0;

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

void Gamewindow::changeCat(int place, const std::string &catName, int catHP, bool highlighted) {
    double catMaxHP = 0;
    QLabel* catNameLabels[] = { ui->cat1Name, ui->cat2Name};
    QLabel* catHPLabels[] = { ui->cat1HP, ui->cat2HP};
    QLabel* catLabels[] = { ui->cat1, ui->cat2};
    QProgressBar* catHealthbars[] = { ui->cat1Healthbar, ui->cat2Healthbar};

    catNameLabels[place-1]->setText(QString::fromStdString(catName));
    if (highlighted) {
        catNameLabels[place-1]->setStyleSheet("font-weight: bold; text-decoration: underline;");
    }
    catLabels[place-1]->setStyleSheet("border-image: url(:/cats/resources/" + QString::fromStdString(catName) + ".png);"
                                                                                                      "background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, "
                                                                                                      "stop:0 rgba(255, 255, 255, 255), stop:0.1 rgba(255, 255, 255, 255), "
                                                                                                      "stop:0.2 rgba(255, 176, 176, 167), stop:0.3 rgba(255, 151, 151, 92), "
                                                                                                      "stop:0.4 rgba(255, 125, 125, 51), stop:0.5 rgba(255, 76, 76, 205), "
                                                                                                      "stop:0.52 rgba(255, 76, 76, 205), stop:0.6 rgba(255, 180, 180, 84), "
                                                                                                      "stop:1 rgba(255, 255, 255, 0));");
    if (catName == "Zoomies") {
        catMaxHP = 50.0;
    } else if (catName == "Chonker") {
        catMaxHP = 100.0;
    } else if (catName == "Feral") {
        catMaxHP = 65.0;
    }

    catHPLabels[place-1]->setText(QString::number(catHP) + " / " + QString::number(catMaxHP) + " HP");
    catHealthbars[place-1]->setValue((catHP / catMaxHP) * 100);
}

void Gamewindow::changeLastMove(std::string lastMove) {
    ui->lastMove->setText(QString::fromStdString(lastMove));
}

void Gamewindow::changeMoveStatus(bool status) {
    ui->scratchButton->setDisabled(!status);
    ui->biteButton->setDisabled(!status);
    ui->headbuttButton->setDisabled(!status);
    ui->kickButton->setDisabled(!status);
}

void Gamewindow::on_scratchButton_clicked() {
    client& client = client::getInstance("127.0.0.1", 8080);
    client.sendMessage(std::to_string(playerNumber) + "Scratch");
    scratchUses++;
    if (scratchUses == 20) {
        ui->scratchButton->setHidden(true);
    }
    ui->scratchButton->setText("Scratch\n" + QString::number(20-scratchUses) + "/20");
}

void Gamewindow::on_biteButton_clicked(){
    client& client = client::getInstance("127.0.0.1", 8080);
    client.sendMessage(std::to_string(playerNumber) + "Bite");
    biteUses++;
    if (biteUses == 5) {
        ui->biteButton->setHidden(true);
    }
    ui->biteButton->setText("Bite\n" + QString::number(5-biteUses) + "/5");
}


void Gamewindow::on_headbuttButton_clicked() {
    client& client = client::getInstance("127.0.0.1", 8080);
    client.sendMessage(std::to_string(playerNumber) + "Headbutt");
    headbuttUses++;
    if (headbuttUses == 10) {
        ui->headbuttButton->setHidden(true);
    }
    ui->headbuttButton->setText("Headbutt\n" + QString::number(10-headbuttUses) + "/10");
}


void Gamewindow::on_kickButton_clicked() {
    client& client = client::getInstance("127.0.0.1", 8080);
    client.sendMessage(std::to_string(playerNumber) + "Kick");
    kickUses++;
    if (kickUses == 10) {
        ui->kickButton->setHidden(true);
    }
    ui->kickButton->setText("Kick\n" + QString::number(10-kickUses) + "/10");
}

