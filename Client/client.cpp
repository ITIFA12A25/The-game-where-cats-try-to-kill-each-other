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
#include "responsehandler.h"

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

<<<<<<< HEAD
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
=======
    if (strcmp(data, "") != 0) {
        send(clientSocket, data, strlen(data), 0);
        std::cout << "Message sent: " << data << std::endl;
>>>>>>> aa483a3 (Katzenklassen implementieren)
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

<<<<<<< HEAD
void client::on_pushButton_2_clicked()
{
=======
std::string client::getLatestResponse() {
    return response;
}

void client::on_pushButton_2_clicked() {
>>>>>>> aa483a3 (Katzenklassen implementieren)
    SelectionWindow *selectionWindow = new SelectionWindow();
    selectionWindow->show();

    this->close();
}
