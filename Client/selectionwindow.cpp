#include "selectionwindow.h"
#include "ui_selectionwindow.h"
#include "client.h"
#include "ui_client.h"
#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <iostream>

SelectionWindow::SelectionWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SelectionWindow)
{
    ui->setupUi(this);
}

SelectionWindow::~SelectionWindow()
{
    delete ui;
}

void SelectionWindow::on_pushButton_clicked()
{
    client *clients = new client();
    clients->show();

    this->close();
}

// Chonker selected
void SelectionWindow::on_pushButton_3_clicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if(button) {
        if(selectedButton && selectedButton != button) {
            selectedButton->setStyleSheet(originalStyleSheet);
        }
        if(selectedButton == button) {
            originalStyleSheet = "";
            button->setStyleSheet("border-image: url(:/cats/resources/Chonker.png);");
            selectedButton = nullptr;
        } else {
            originalStyleSheet = button->styleSheet();
            button->setStyleSheet("border-image: url(:/cats/resources/Chonker.png);"
                                  "background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 255, 255, 255), stop:0.1 rgba(255, 255, 255, 255), stop:0.2 rgba(255, 176, 176, 167), stop:0.3 rgba(255, 151, 151, 92), stop:0.4 rgba(255, 125, 125, 51), stop:0.5 rgba(255, 76, 76, 205), stop:0.52 rgba(255, 76, 76, 205), stop:0.6 rgba(255, 180, 180, 84), stop:1 rgba(255, 255, 255, 0));");
            selectedButton = button;
            selectedCat = "Chonker";
        }
    }
}

// Zoomies selected
void SelectionWindow::on_pushButton_4_clicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if(button) {
        if(selectedButton && selectedButton != button) {
            selectedButton->setStyleSheet(originalStyleSheet);
        }
        if(selectedButton == button) {
            originalStyleSheet = "";
            button->setStyleSheet("border-image: url(:/cats/resources/Zoomies.png);");
            selectedButton = nullptr;
        } else {
            originalStyleSheet = button->styleSheet();
            button->setStyleSheet("border-image: url(:/cats/resources/Zoomies.png);"
                                  "background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 255, 255, 255), stop:0.1 rgba(255, 255, 255, 255), stop:0.2 rgba(255, 176, 176, 167), stop:0.3 rgba(255, 151, 151, 92), stop:0.4 rgba(255, 125, 125, 51), stop:0.5 rgba(255, 76, 76, 205), stop:0.52 rgba(255, 76, 76, 205), stop:0.6 rgba(255, 180, 180, 84), stop:1 rgba(255, 255, 255, 0));");
            selectedButton = button;
            selectedCat = "Zoomies";
        }
    }
}

// Feral selected
void SelectionWindow::on_pushButton_5_clicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if(button) {
        if(selectedButton && selectedButton != button) {
            selectedButton->setStyleSheet(originalStyleSheet);
        }
        if(selectedButton == button) {
            button->setStyleSheet("border-image: url(:/cats/resources/Feral.png);");
            originalStyleSheet = "";
            selectedButton = nullptr;
        } else {
            originalStyleSheet = button->styleSheet();
            button->setStyleSheet("border-image: url(:/cats/resources/Feral.png);"
                                  "background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 255, 255, 255), stop:0.1 rgba(255, 255, 255, 255), stop:0.2 rgba(255, 176, 176, 167), stop:0.3 rgba(255, 151, 151, 92), stop:0.4 rgba(255, 125, 125, 51), stop:0.5 rgba(255, 76, 76, 205), stop:0.52 rgba(255, 76, 76, 205), stop:0.6 rgba(255, 180, 180, 84), stop:1 rgba(255, 255, 255, 0));");
            selectedButton = button;
            selectedCat = "Feral";
        }
    }
}


void SelectionWindow::on_pushButton_6_clicked() {
    // Start Game
    if(selectedButton) {
        client *clients = new client();
        clients->sendData(selectedCat, SERVER_PORT);

        Gamewindow *gamewindow = new Gamewindow();
        this->close();
        gamewindow->show();
        std::string latestResponse = clients->getLatestResponse();

        if(latestResponse.size() > 8) {
            size_t spacePos = latestResponse.find(" ");
            gamewindow->changeCat(2, latestResponse.substr(spacePos + 1));
            gamewindow->changeCat(1, latestResponse.substr(0, spacePos));
        } /*else {
            const char* emptyString = "sgsf";
            gamewindow->changeCat(1, latestResponse);
            while(latestResponse.size() < 8) {
                clients->sendData(emptyString, SERVER_PORT);
                latestResponse = clients->getLatestResponse();
                std::cout << latestResponse << std::endl;
            }
            size_t spacePos = latestResponse.find(" ");
            gamewindow->changeCat(2, latestResponse.substr(0, spacePos));
        }*/
    } else {
        // Info popup saying "Please select a cat!"
    }
}


void SelectionWindow::on_pushButton_7_clicked() {
    SERVER_PORT = 8080;
}


void SelectionWindow::on_pushButton_8_clicked() {
    SERVER_PORT = 8081;
}

