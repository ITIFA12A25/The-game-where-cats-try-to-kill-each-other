#include "clienthandler.h"
#include <cstring>
#include <iostream>

int ClientHandler::player = 0;

ClientHandler::ClientHandler() {

}

const char* ClientHandler::handleData(const char* data) {
    char message[50];
    if(strcmp(data, "Zoomies") == 0 && player < 2) {
        player++;
        snprintf(message, sizeof(message), "Player %d: Zoomies", player);
        const char* constMessage = message;
        return constMessage;
    } else if(strcmp(data, "Chonker") == 0 && player < 2) {
        player++;
        snprintf(message, sizeof(message), "Player %d: Chonker", player);
        const char* constMessage = message;
        return constMessage;
    } else if(strcmp(data, "Feral") == 0 && player < 2) {
        player++;
        snprintf(message, sizeof(message), "Player %d: Feral", player);
        const char* constMessage = message;
        return constMessage;
    }

    return "No match in DataHandler!";
}
