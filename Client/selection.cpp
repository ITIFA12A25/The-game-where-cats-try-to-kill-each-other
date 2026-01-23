#include "selection.h"
#include "ui_client.h"

selection::selection(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
}

selection::~selection() {
    delete ui;
}

void selection::showSelection() {
    this->show();  // Show the widget
}
