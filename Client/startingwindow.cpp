#include "startingwindow.h"
#include "ui_startingwindow.h"
#include "selectionwindow.h"
#include "ui_selectionwindow.h"

startingWindow::startingWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::startingWindow)
{
    ui->setupUi(this);
}

startingWindow::~startingWindow()
{
    delete ui;
}

void startingWindow::on_playButton_clicked() {
    SelectionWindow *selectionwindow = new SelectionWindow();
    this->close();
    selectionwindow->show();
}

