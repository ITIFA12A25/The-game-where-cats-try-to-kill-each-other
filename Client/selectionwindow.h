#ifndef SELECTIONWINDOW_H
#define SELECTIONWINDOW_H

#include <QWidget>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class SelectionWindow;
}
QT_END_NAMESPACE

class SelectionWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SelectionWindow(QWidget *parent = nullptr);
    ~SelectionWindow();

private slots:
    void on_backButton_clicked();
    void on_zoomiesButton_clicked();
    void on_chonkerButton_clicked();
    void on_feralButton_clicked();
    void on_playButton_clicked();

private:
    Ui::SelectionWindow *ui;
    QPushButton* selectedButton = nullptr;
    QString originalStyleSheet;
    std::string selectedCat = "";
};

#endif
