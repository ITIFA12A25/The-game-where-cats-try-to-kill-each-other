#include "client.h"
#include <gamewindow.h>
#include <winwindow.h>
#include <infopopupwindow.h>
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <QHostAddress>
#include <QMessageBox>

int playerNumber = 2;
int turn = 2;

client::client(const std::string &host, int port) {
    socket = new QTcpSocket();

    // Connect to the host
    socket->connectToHost(QHostAddress(QString::fromStdString(host)), port);
    if (!socket->waitForConnected(3000)) {
        std::cerr << "Connection Error: " << socket->errorString().toStdString() << std::endl;
    }

    // Connect the signal to the slot for reading
    connect(socket, &QTcpSocket::readyRead, this, &client::onReadyRead);
}

client::~client() {
    delete socket;
}

// Helper function
int client::countNumbersInString(const std::string& input) {
    int count = 0;
    for (char c : input) {
        if (std::isdigit(c)) {
            count++; // Increment count if the character is a digit
        }
    }
    return count;
}

void client::sendMessage(const std::string &message) {
    if (!message.empty()) {
        socket->write(QByteArray::fromStdString(message));
    }
}

// Handles messages coming form the Server
void client::handleMessages(std::string message) {
    if (message == "waiting") {
        playerNumber = 1;
        infoPopupWindow *infopopup = new infoPopupWindow();
        infopopup->show();
        turn = 1;
    }

    if (message.find("Won") != std::string::npos) {
        size_t wPos = message.find("W");
        Gamewindow& gamewindow = Gamewindow::getInstance();
        gamewindow.close();

        winWindow *winwindow = new winWindow();
        winwindow->changeWinner(message.substr(0, wPos));
        winwindow->show();
    }

    if (message.size() > 10) {
        Gamewindow& gamewindow = Gamewindow::getInstance();
        size_t spacePos = message.find(" ");
        size_t slashPos = message.find("/");

        std::string cat1Name = message.substr(0, spacePos);
        int cat1HpDigits = countNumbersInString(cat1Name);
        std::string cat2Name = message.substr(spacePos + 1, slashPos - (spacePos + 1));
        int cat2HpDigits = countNumbersInString(cat2Name);

        gamewindow.changeLastMove(message.substr(slashPos+1));

        if (playerNumber == 1) {
            gamewindow.changeCat(1, cat1Name.substr(0, cat1Name.length()-cat1HpDigits), std::stoi(cat1Name.substr(cat1Name.length()-cat1HpDigits)), true);
            gamewindow.changeCat(2, cat2Name.substr(0, cat2Name.length()-cat2HpDigits), std::stoi(cat2Name.substr(cat2Name.length()-cat2HpDigits)), false);
        } else {
            gamewindow.changeCat(2, cat1Name.substr(0, cat1Name.length()-cat1HpDigits), std::stoi(cat1Name.substr(cat1Name.length()-cat1HpDigits)), false);
            gamewindow.changeCat(1, cat2Name.substr(0, cat2Name.length()-cat2HpDigits), std::stoi(cat2Name.substr(cat2Name.length()-cat2HpDigits)), true);
        }

        if (turn % 2 == 0) {
            gamewindow.changeMoveStatus(false);
        } else {
            gamewindow.changeMoveStatus(true);
        }

        turn++;
    }
}

// Reads messages from the Server
void client::onReadyRead() {
    QByteArray response = socket->readAll();
    handleMessages(response.toStdString());
}
