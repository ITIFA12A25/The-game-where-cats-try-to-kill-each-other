#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>

extern int SERVER_PORT;

QT_BEGIN_NAMESPACE
namespace Ui {
class client;
}
QT_END_NAMESPACE

class client : public QMainWindow
{
    Q_OBJECT

public:
    client(QWidget *parent = nullptr);
    ~client();
    void startListening(int port);
    void sendData(const char* data, int port);
    void listenForResponses(int clientSocket);
    std::string getLatestResponse();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::client *ui;
    std::string response;
};
#endif // CLIENT_H
