#include "infopopupwindow.h"
#include "ui_infopopupwindow.h"

infoPopupWindow::infoPopupWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::infoPopupWindow)
{
    ui->setupUi(this);
}

infoPopupWindow::~infoPopupWindow()
{
    delete ui;
}
