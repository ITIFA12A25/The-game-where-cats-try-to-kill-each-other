#pragma once
#include "information.h"
#include "ui_information.h"
#include "selectionwindow.h"
#include "ui_selectionwindow.h"
#include "client.h"
#include "ui_client.h"

Information::Information(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Information)
{
    ui->setupUi(this);
}

Information::~Information()
{
    delete ui;
}

void Information::on_pushButton_clicked()
{
    this->close();
}

void Information::setInfoText (std::string text)
{
    QString qstr = QString::fromStdString(text);
    ui->infoLabel->setText(qstr);
}






