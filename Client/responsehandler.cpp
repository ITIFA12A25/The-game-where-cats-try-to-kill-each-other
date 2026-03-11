#include "responsehandler.h"
#include <cstring>
#include <iostream>

ResponseHandler::ResponseHandler() {

}

void ResponseHandler::handleResponse(const char* data) {
    std::string message(data);

    if(message.find("Player 1") != std::string::npos) {
        std::cout << "Player 1" << std::endl;
    } else if(message.find("Player 2") != std::string::npos) {
        std::cout << "Player 2" << std::endl;
    }
}

