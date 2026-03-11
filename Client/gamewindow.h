#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>

namespace Ui {
class Gamewindow;
}

class Gamewindow : public QDialog
{
    Q_OBJECT

public:
    explicit Gamewindow(QWidget *parent = nullptr);
    ~Gamewindow();

public slots:
    void changeCat(int place, std::string catName);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Gamewindow *ui;
};

#endif // GAMEWINDOW_H
