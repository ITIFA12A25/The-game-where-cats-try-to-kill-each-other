#ifndef INFOPOPUPWINDOW_H
#define INFOPOPUPWINDOW_H

#include <QDialog>

namespace Ui {
class infoPopupWindow;
}

class infoPopupWindow : public QDialog
{
    Q_OBJECT

public:
    explicit infoPopupWindow(QWidget *parent = nullptr);
    ~infoPopupWindow();

private:
    Ui::infoPopupWindow *ui;
};

#endif // INFOPOPUPWINDOW_H
