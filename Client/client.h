#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QHostAddress>
#include <string>
#include <QObject>

extern int playerNumber;

class client : public QObject {
    Q_OBJECT

public:
    // Static method to get the Singleton instance of the Client class
    static client& getInstance(const std::string &host = "localhost", int port = 8080) {
        static client instance(host, port); // Instantiate the client
        return instance;
    }

    // Delete copy constructor and assignment operator to enforce unique instance
    client(const client&) = delete;
    client& operator=(const client&) = delete;

    ~client(); // Destructor
    void sendMessage(const std::string &message);
    void handleMessages(std::string message);

private:
    // Private constructor to initialize the connection
    client(const std::string &host, int port);

    // Slot-like private method to handle data reception
    void onReadyRead();
    int countNumbersInString(const std::string& inpput);

    QTcpSocket *socket; // Socket for communication
};

#endif // CLIENT_H
