#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>
#include <cat.h>
#include <memory>
#include <chonker.h>
#include <zoomies.h>
#include <feral.h>
#include <arpa/inet.h>
#include <thread>
#include <mutex>
#include <algorithm>

#define PORT 8080
#define MAX_CLIENTS 2
#define BUFFER_SIZE 1024

struct Player {
    std::string name;
    std::unique_ptr<Cat> cat;
};

int playerCount = 0;
std::vector<Player> players(2);
std::vector<int> clientSockets; // Store client sockets
std::mutex clientsMutex; // Mutex for thread-safe access to clientSockets

// Helper function
std::string getCatName(const std::unique_ptr<Cat>& cat) {
    if (dynamic_cast<Chonker*>(cat.get())) {
        return "Chonker";
    } else if (dynamic_cast<Zoomies*>(cat.get())) {
        return "Zoomies";
    } else if (dynamic_cast<Feral*>(cat.get())) {
        return "Feral";
    }
    return "None";
}

// Handles the messages received from the Client
std::string handleMessages(std::string message) {
    // Reads the Cats that the players picked
    if (playerCount < 2) {
        playerCount++;
        players[playerCount-1] = {"Player", nullptr};
        std::cout << players[playerCount - 1].name << " connected." << std::endl;

        if (message == "Chonker") {
            players[playerCount-1].cat = std::make_unique<Chonker>();
        } else if (message == "Zoomies") {
            players[playerCount-1].cat = std::make_unique<Zoomies>();
        } else if (message == "Feral") {
            players[playerCount-1].cat = std::make_unique<Feral>();
        }
    }

    // Checks the message for Attacks
    if (message.find("Scratch") != std::string::npos) {
        int playerNumber = std::stoi(message.substr(0,1));
        if (playerNumber == 1) {
            *players[1].cat = players[0].cat->scratch(*players[0].cat, *players[1].cat);
        } else {
            *players[0].cat = players[1].cat->scratch(*players[1].cat, *players[0].cat);
        }
    } else if (message.find("Bite") != std::string::npos) {
        int playerNumber = std::stoi(message.substr(0,1));
        if (playerNumber == 1) {
            *players[1].cat = players[0].cat->bite(*players[0].cat, *players[1].cat);
        } else {
            *players[0].cat = players[1].cat->bite(*players[1].cat, *players[0].cat);
        }
    } else if (message.find("Headbutt") != std::string::npos) {
        int playerNumber = std::stoi(message.substr(0,1));
        if (playerNumber == 1) {
            *players[1].cat = players[0].cat->headbutt(*players[0].cat, *players[1].cat);
        } else {
            *players[0].cat = players[1].cat->headbutt(*players[1].cat, *players[0].cat);
        }
    } else if (message.find("Kick") != std::string::npos) {
        int playerNumber = std::stoi(message.substr(0,1));
        if (playerNumber == 1) {
            *players[1].cat = players[0].cat->kick(*players[0].cat, *players[1].cat);
        } else {
            *players[0].cat = players[1].cat->kick(*players[1].cat, *players[0].cat);
        }
    }

    // Updates the cats HP and sends it back to the clients
    if (playerCount == 2) {
        std::string player1CatType = getCatName(players[0].cat);
        std::string player2CatType = getCatName(players[1].cat);
        int player1CatHP = players[0].cat->getHp();
        int player2CatHP = players[1].cat->getHp();
        // Checks if someone has won the game
        if (player1CatHP <= 0) {
            return player2CatType + "Won";
        } else if (player2CatHP <= 0) {
            return player1CatType + "Won";
        }
        return player1CatType + std::to_string(player1CatHP) + " " + player2CatType + std::to_string(player2CatHP) + "/" + lastMoveMessage;
    } else if (playerCount == 1) {
        return "waiting";
    }
    return "";
}

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

        // Prepare the response
        std::string response = handleMessages(std::string(buffer));

        // Send response to all connected clients
        clientsMutex.lock();
        for (const auto& sock : clientSockets) {
            send(sock, response.c_str(), response.size(), 0);
        }
        clientsMutex.unlock();
    }
    close(clientSocket);

    // Remove the client socket when done
    clientsMutex.lock();
    clientSockets.erase(std::remove(clientSockets.begin(), clientSockets.end(), clientSocket), clientSockets.end());
    clientsMutex.unlock();
}

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    std::vector<std::thread> threads;

    // Create a socket for the server
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    // Errorhandling
    if (serverSocket == -1) {
        std::cerr << "Error creating socket." << std::endl;
        return -1;
    }

    // Set up server address structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Binding failed." << std::endl;
        return -1;
    }

    // Start listening for incoming connections
    if (listen(serverSocket, MAX_CLIENTS) < 0) {
        std::cerr << "Listening failed." << std::endl;
        return -1;
    }

    // Notify that server is ready
    std::cout << "Server listening on port " << PORT << std::endl;

    // Accept incoming client connections
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);
        if (clientSocket < 0) {
            std::cerr << "Accepting client failed." << std::endl;
            continue;
        }
        std::cout << "Client " << i + 1 << " connected." << std::endl;

        clientsMutex.lock();
        clientSockets.push_back(clientSocket);
        clientsMutex.unlock();

        // Create a new thread to handle the client
        threads.emplace_back(handleClient, clientSocket);
    }

    // Wait for all client handling threads to finish
    for (auto& t : threads) {
        t.join();
    }

    close(serverSocket);
    return 0;
}
