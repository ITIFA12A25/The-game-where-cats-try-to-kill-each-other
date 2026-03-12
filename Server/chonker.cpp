#include "chonker.h"
#include "cat.h"
#include <iostream>
#include <random>

Chonker::Chonker() : Cat("Chonker", 100, 5, 5) {}

std::string lastMoveMessage;

Cat Chonker::scratch(Cat chonker, Cat opposingCat) const {
    // Random number between 1 and 100
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int randomNumber = dis(gen);

    if (randomNumber < 100 - opposingCat.getSpeed()) {
        opposingCat.setHp(opposingCat.getHp()-chonker.getDamage());
        lastMoveMessage = name + " scratches " + opposingCat.getName() + " for " + std::to_string(chonker.getDamage()) + "HP!";
        return opposingCat;
    } else {
        lastMoveMessage = name + " missed the Scratch!";
        return opposingCat;
    }
}

Cat Chonker::bite(Cat chonker, Cat opposingCat) const {
    // Random number between 1 and 100
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int randomNumber = dis(gen);

    if (randomNumber < 70 - opposingCat.getSpeed()) {
        opposingCat.setHp(opposingCat.getHp() - (chonker.getDamage() * 2));
        lastMoveMessage = name + " bites " + opposingCat.getName() + " for " + std::to_string(static_cast<int>(std::ceil(chonker.getDamage() * 2))) + "HP!";
        return opposingCat;
    } else {
        lastMoveMessage = name + " missed the Bite!";
        return opposingCat;
    }
}

Cat Chonker::headbutt(Cat chonker, Cat opposingCat) const {
    // Random number between 1 and 100
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int randomNumber = dis(gen);

    if (randomNumber < 70 - opposingCat.getSpeed()) {
        opposingCat.setHp(opposingCat.getHp() - (chonker.getDamage() * 1.5));
        lastMoveMessage = name + " headbutts " + opposingCat.getName() + " for " + std::to_string(static_cast<int>(std::ceil(chonker.getDamage() * 1.5))) + "HP!";
        return opposingCat;
    } else {
        lastMoveMessage = name + " missed the Headbutt!";
        return opposingCat;
    }
}

Cat Chonker::kick(Cat chonker, Cat opposingCat) const {
    opposingCat.setHp(opposingCat.getHp() - (chonker.getDamage() * 0.5));
    lastMoveMessage = name + " kicks " + opposingCat.getName() + " for " + std::to_string(static_cast<int>(std::ceil(chonker.getDamage() * 0.5))) + "HP!";
    return opposingCat;
}

