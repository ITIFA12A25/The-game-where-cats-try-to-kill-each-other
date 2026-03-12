#ifndef WINWINDOW_H
#define WINWINDOW_H

#include <QWidget>

namespace Ui {
class winWindow;
}

class winWindow : public QWidget
{
    Q_OBJECT

public:
    explicit winWindow(QWidget *parent = nullptr);
    ~winWindow();
    void changeWinner(std::string winner);

private:
    Ui::winWindow *ui;
};

#endif // WINWINDOW_H
