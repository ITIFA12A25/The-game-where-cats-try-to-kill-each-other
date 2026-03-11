#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <thread>
#include <vector>

#define PORT 8080
#define MAX_CLIENTS 2
#define BUFFER_SIZE 1024

void handleClient(int clientSocket) {
    char buffer[BUFFER_SIZE];
    while (true) {
        memset(buffer, 0, BUFFER_SIZE);
        ssize_t bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE, 0);
        if (bytesReceived <= 0) {
            std::cout << "Client disconnected." << std::endl;
            break;
        }
        std::cout << "Message from client: " << buffer << std::endl;

        // Send a response back to the client
        std::string response = "Server received: " + std::string(buffer);
        send(clientSocket, response.c_str(), response.size(), 0);
    }
    close(clientSocket);
}

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    std::vector<std::thread> threads;

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Error creating socket." << std::endl;
        return -1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Binding failed." << std::endl;
        return -1;
    }

    if (listen(serverSocket, MAX_CLIENTS) < 0) {
        std::cerr << "Listening failed." << std::endl;
        return -1;
    }

    std::cout << "Server listening on port " << PORT << std::endl;

    for (int i = 0; i < MAX_CLIENTS; ++i) {
        clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);
        if (clientSocket < 0) {
            std::cerr << "Accepting client failed." << std::endl;
            continue;
        }
        std::cout << "Client " << i + 1 << " connected." << std::endl;
        threads.emplace_back(handleClient, clientSocket);
    }

    for (auto& t : threads) {
        t.join();
    }

    close(serverSocket);
    return 0;
}
