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
#include <thread>

using namespace std;

struct Player {
    int socket;
    std::string name;
    std::unique_ptr<Cat> cat;
};

void sendMessageToClient(int clientSocket, const std::string& messageString) {
    const char* message = messageString.c_str();
    send(clientSocket, message, strlen(message), 0);
    cout << "Response sent to client: " << message << endl;
}

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

int main() {
    const int PORT1 = 8080;
    const int PORT2 = 8081;
    std::vector<Player> players(2);

    // create player sockets
    int serverSocket1 = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket1 == -1) {
        cerr << "Error creating socket for Player 1" << endl;
        return 1;
    }

    int serverSocket2 = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket2 == -1) {
        cerr << "Error creating socket for Player 2" << endl;
        return 1;
    }

    // bind player sockets
    sockaddr_in serverAddress1;
    serverAddress1.sin_family = AF_INET;
    serverAddress1.sin_port = htons(PORT1);
    serverAddress1.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket1, (struct sockaddr*)&serverAddress1, sizeof(serverAddress1)) == -1) {
        cerr << "Error binding socket for Player 1" << endl;
        close(serverSocket1);
        return 1;
    }

    sockaddr_in serverAddress2;
    serverAddress2.sin_family = AF_INET;
    serverAddress2.sin_port = htons(PORT2);
    serverAddress2.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket2, (struct sockaddr*)&serverAddress2, sizeof(serverAddress2)) == -1) {
        cerr << "Error binding socket for Player 2" << endl;
        close(serverSocket2);
        return 1;
    }

    // check if sockets are listenable
    if (listen(serverSocket1, 5) == -1 || listen(serverSocket2, 5) == -1) {
        cerr << "Error listening on sockets" << endl;
        close(serverSocket1);
        close(serverSocket2);
        return 1;
    }

    int playerCount = 0;
    int clientSocket;
    sockaddr_in clientAddress;
    socklen_t clientAddressLen = sizeof(clientAddress);

    while (playerCount < 2) {
        // Accept connection on the first socket
        if (playerCount < 1) {
            clientSocket = accept(serverSocket1, (struct sockaddr*)&clientAddress, &clientAddressLen);
            if (clientSocket == -1) {
                cerr << "Error accepting connection on Player 1 socket" << endl;
                continue;
            }
            players[playerCount] = { clientSocket, "Player1", nullptr}; // Assign the client socket
        } else {
            // Accept connection on the second socket
            clientSocket = accept(serverSocket2, (struct sockaddr*)&clientAddress, &clientAddressLen);
            if (clientSocket == -1) {
                cerr << "Error accepting connection on Player 2 socket" << endl;
                continue;
            }
            players[playerCount] = { clientSocket, "Player2", nullptr}; // Assign the client socket
        }

        playerCount++;
        cout << players[playerCount - 1].name << " connected." << endl;

        char buffer[1024] = { 0 };
        recv(clientSocket, buffer, sizeof(buffer), 0);
        cout << "Message from " << players[playerCount - 1].name << ": " << buffer << endl;

        // responses
        if (strcmp(buffer, "Chonker") == 0) {
                sendMessageToClient(clientSocket, "Chonker");
                players[playerCount-1].cat = std::make_unique<Chonker>();
        } else if (strcmp(buffer, "Zoomies") == 0) {
                sendMessageToClient(clientSocket, "Zoomies");
                players[playerCount-1].cat = std::make_unique<Zoomies>();
        } else if (strcmp(buffer, "Feral") == 0) {
                sendMessageToClient(clientSocket, "Feral");
                players[playerCount-1].cat = std::make_unique<Feral>();
        }
    }

    if (playerCount == 2) {
        std::string player1CatType = getCatName(players[0].cat);
        std::string player2CatType = getCatName(players[1].cat);

        sendMessageToClient(players[0].socket, " " + player2CatType);
        sendMessageToClient(players[1].socket, " " + player1CatType);
    }

    while (playerCount < 10) {

    }

    close(clientSocket);
    close(serverSocket1);
    close(serverSocket2);

    return 0;
}
