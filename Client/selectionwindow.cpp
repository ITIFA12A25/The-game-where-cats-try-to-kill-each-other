#include "selectionwindow.h"
#include "ui_selectionwindow.h"
#include "client.h"
#include "ui_client.h"
#include "gamewindow.h"
#include "ui_gamewindow.h"

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


void SelectionWindow::on_pushButton_3_clicked()
{
    // Chonker
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        if (selectedButton && selectedButton != button) {
            selectedButton->setStyleSheet(originalStyleSheet);
        }
        if (selectedButton == button) {
            originalStyleSheet = "";
            button->setStyleSheet("border-image: url(:/cats/resources/katze3.png);");
            selectedButton = nullptr;
        } else {
            originalStyleSheet = button->styleSheet();
            button->setStyleSheet("border-image: url(:/cats/resources/katze3.png);"
                                  "background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 255, 255, 255), stop:0.1 rgba(255, 255, 255, 255), stop:0.2 rgba(255, 176, 176, 167), stop:0.3 rgba(255, 151, 151, 92), stop:0.4 rgba(255, 125, 125, 51), stop:0.5 rgba(255, 76, 76, 205), stop:0.52 rgba(255, 76, 76, 205), stop:0.6 rgba(255, 180, 180, 84), stop:1 rgba(255, 255, 255, 0));");
            selectedButton = button;
            selectedCat = "Chonker";
        }
    }
}


void SelectionWindow::on_pushButton_4_clicked()
{
    // Zoomies
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        if (selectedButton && selectedButton != button) {
            selectedButton->setStyleSheet(originalStyleSheet);
        }
        if (selectedButton == button) {
            originalStyleSheet = "";
            button->setStyleSheet("border-image: url(:/cats/resources/katze2.png);");
            selectedButton = nullptr;
        } else {
            originalStyleSheet = button->styleSheet();
            button->setStyleSheet("border-image: url(:/cats/resources/katze2.png);"
                                  "background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 255, 255, 255), stop:0.1 rgba(255, 255, 255, 255), stop:0.2 rgba(255, 176, 176, 167), stop:0.3 rgba(255, 151, 151, 92), stop:0.4 rgba(255, 125, 125, 51), stop:0.5 rgba(255, 76, 76, 205), stop:0.52 rgba(255, 76, 76, 205), stop:0.6 rgba(255, 180, 180, 84), stop:1 rgba(255, 255, 255, 0));");
            selectedButton = button;
            selectedCat = "Zoomies";
        }
    }
}


void SelectionWindow::on_pushButton_5_clicked()
{
    // Feral
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        if (selectedButton && selectedButton != button) {
            selectedButton->setStyleSheet(originalStyleSheet);
        }
        if (selectedButton == button) {
            button->setStyleSheet("border-image: url(:/cats/resources/katze1.png);");
            originalStyleSheet = "";
            selectedButton = nullptr;
        } else {
            originalStyleSheet = button->styleSheet();
            button->setStyleSheet("border-image: url(:/cats/resources/katze1.png);"
                                  "background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 255, 255, 255), stop:0.1 rgba(255, 255, 255, 255), stop:0.2 rgba(255, 176, 176, 167), stop:0.3 rgba(255, 151, 151, 92), stop:0.4 rgba(255, 125, 125, 51), stop:0.5 rgba(255, 76, 76, 205), stop:0.52 rgba(255, 76, 76, 205), stop:0.6 rgba(255, 180, 180, 84), stop:1 rgba(255, 255, 255, 0));");
            selectedButton = button;
            selectedCat = "Feral";
        }
    }
}


void SelectionWindow::on_pushButton_6_clicked()
{
    // Start Game
    if(selectedButton) {
        client *clients = new client();
        clients->sendData(("%c", selectedCat));

        Gamewindow *gamewindow = new Gamewindow();
        this->close();
        gamewindow->show();
    } else {
        // Info popup saying "Please select a cat!"
    }
}

