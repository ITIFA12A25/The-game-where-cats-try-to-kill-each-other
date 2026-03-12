#include "winwindow.h"
#include "ui_winwindow.h"

winWindow::winWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::winWindow)
{
    ui->setupUi(this);
}

winWindow::~winWindow()
{
    delete ui;
}

void winWindow::changeWinner(std::string winner) {
    ui->wonGame->setText(QString::fromStdString(winner + " has won the game!!"));
}
