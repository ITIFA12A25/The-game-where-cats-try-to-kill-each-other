#ifndef SELECTION_H
#define SELECTION_H

#include <QWidget>
#include "ui_client.h"

class selection : public QWidget
{
    Q_OBJECT

public:
    selection(QWidget *parent = nullptr);
    ~selection();
    void showSelection();

private:
    Ui::client *ui;
};

#endif // SELECTION_H
