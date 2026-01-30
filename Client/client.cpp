#include "client.h"
#include "ui_client.h"
#include "selectionwindow.h"
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "responsehandler.h"

client::client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::client)
{
    ui->setupUi(this);
}

client::~client()
{
    delete ui;
}

void client::sendData(const char* message) {
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        std::cerr << "Error creating socket" << std::endl;
        return;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);

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

    ssize_t bytesSent = send(clientSocket, message, strlen(message), 0);
    if (bytesSent == -1) {
        std::cerr << "Error sending message" << std::endl;
    } else {
        std::cout << "Message sent: " << message << std::endl;

        char buffer[1024] = {0};
        ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
        if (bytesRead == -1) {
            std::cerr << "No Response received." << std::endl;
        } else {
            ResponseHandler handler;
            buffer[bytesRead] = '\0';
            std::cout << "Response received: " << buffer << std::endl;
            handler.handleResponse(buffer);
        }
    }

    ::close(clientSocket);
}

void client::on_pushButton_2_clicked()
{
    SelectionWindow *selectionWindow = new SelectionWindow();
    selectionWindow->show();

    this->close();
}
