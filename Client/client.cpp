#include "client.h"
#include "ui_client.h"
#include "ui_gamewindow.h"
#include "gamewindow.h"
#include "selectionwindow.h"
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

int SERVER_PORT = 8080;


client::client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::client)
{
    ui->setupUi(this);
    std::string response;
}

client::~client()
{
    delete ui;
}

void client::sendData(const char* data, int port) {
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        std::cerr << "Error creating socket" << std::endl;
        return;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);

    if (inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        ::close(clientSocket);
        return;
    }

    if (::connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Error connecting to server" << std::endl;
        ::close(clientSocket);
        return;
    }

    ssize_t bytesSent = send(clientSocket, data, strlen(data), 0);
    if (bytesSent == -1) {
        std::cerr << "Error sending message" << std::endl;
    } else {
        std::cout << "Message sent: " << data << std::endl;
    }

    char buffer[1024];

        ssize_t bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
        if (bytesReceived == -1) {
            std::cerr << "No response received." << std::endl;
        } else {
            buffer[bytesReceived] = '\0';
            std::cout << "Response received: " << buffer << std::endl;
            response = buffer;
        }

    ::close(clientSocket);
}

std::string client::getLatestResponse() {
    return response;
}

void client::on_pushButton_2_clicked() {
    SelectionWindow *selectionwindow = new SelectionWindow();
    this->close();
    selectionwindow->show();
}

