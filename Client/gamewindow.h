#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include <string>

namespace Ui {
class Gamewindow;
}

class Gamewindow : public QDialog
{
    Q_OBJECT

public:
    // Static method to get the instance of the Gamewindow class
    static Gamewindow& getInstance(QWidget *parent = nullptr) {
        static Gamewindow instance(parent); // Guaranteed to be destroyed, instantiated on first use
        return instance;
    }

    // Delete copy constructor and assignment operator to enforce unique instance
    Gamewindow(const Gamewindow&) = delete;
    void operator=(const Gamewindow&) = delete;

    ~Gamewindow();

public slots:
    void changeCat(int place, const std::string &catName, int catHP, bool highlighted);
    void changeLastMove(std::string lastMove);
    void changeMoveStatus(bool status);

private slots:
    void on_scratchButton_clicked();
    void on_biteButton_clicked();

    void on_headbuttButton_clicked();

    void on_kickButton_clicked();

private:
    int scratchUses;
    int biteUses;
    int headbuttUses;
    int kickUses;
    explicit Gamewindow(QWidget *parent = nullptr);
    Ui::Gamewindow *ui;
};

#endif // GAMEWINDOW_H
