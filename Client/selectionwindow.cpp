#include "selectionwindow.h"
#include "ui_selectionwindow.h"
#include "client.h"
#include "ui_client.h"

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

