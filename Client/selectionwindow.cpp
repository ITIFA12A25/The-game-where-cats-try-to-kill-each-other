#include "selectionwindow.h"
#include "ui_selectionwindow.h"
#include "client.h"
#include "ui_client.h"
#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "startingwindow.h"
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

void SelectionWindow::on_backButton_clicked() {
    startingWindow *startingwindow = new startingWindow();
    startingwindow->show();

    this->close();
}

// Zoomies selected
void SelectionWindow::on_zoomiesButton_clicked() {
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

// Chonker selected
void SelectionWindow::on_chonkerButton_clicked() {
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

// Feral selected
void SelectionWindow::on_feralButton_clicked() {
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

// Start game
void SelectionWindow::on_playButton_clicked() {
    if(selectedButton) {
        client& client = client::getInstance("127.0.0.1", 8080);
        client.sendMessage(selectedCat);

        Gamewindow& gamewindow = Gamewindow::getInstance();
        this->close();
        gamewindow.show();

    }
}

