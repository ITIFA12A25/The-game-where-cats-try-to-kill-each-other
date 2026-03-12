#ifndef STARTINGWINDOW_H
#define STARTINGWINDOW_H

#include <QWidget>

namespace Ui {
class startingWindow;
}

class startingWindow : public QWidget
{
    Q_OBJECT

public:
    explicit startingWindow(QWidget *parent = nullptr);
    ~startingWindow();

private slots:
    void on_playButton_clicked();

private:
    Ui::startingWindow *ui;
};

#endif // STARTINGWINDOW_H
