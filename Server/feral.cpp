#include "feral.h"
#include <iostream>
#include <random>

Feral::Feral() : Cat("Feral", 65, 7, 20) {}

Cat Feral::scratch(Cat feral, Cat opposingCat) const {
    // Random number between 1 and 100
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int randomNumber = dis(gen);

    if (randomNumber < 100 - opposingCat.getSpeed()) {
        opposingCat.setHp(opposingCat.getHp()-feral.getDamage());
        lastMoveMessage = name + " scratches " + opposingCat.getName() + " for " + std::to_string(feral.getDamage()) + "HP!";
        return opposingCat;
    } else {
        lastMoveMessage = name + " missed the Scratch!";
        return opposingCat;
    }
}

Cat Feral::bite(Cat feral, Cat opposingCat) const {
    // Random number between 1 and 100
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int randomNumber = dis(gen);

    if (randomNumber < 70 - opposingCat.getSpeed()) {
        opposingCat.setHp(opposingCat.getHp() - (feral.getDamage() * 2));
        lastMoveMessage = name + " bites " + opposingCat.getName() + " for " + std::to_string(static_cast<int>(std::ceil(feral.getDamage() * 2))) + "HP!";
        return opposingCat;
    } else {
        lastMoveMessage = name + " missed the Bite!";
        return opposingCat;
    }
}

Cat Feral::headbutt(Cat feral, Cat opposingCat) const {
    // Random number between 1 and 100
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int randomNumber = dis(gen);

    if (randomNumber < 70 - opposingCat.getSpeed()) {
        opposingCat.setHp(opposingCat.getHp() - (feral.getDamage() * 1.5));
        lastMoveMessage = name + " headbutts " + opposingCat.getName() + " for " + std::to_string(static_cast<int>(std::ceil(feral.getDamage() * 1.5))) + "HP!";
        return opposingCat;
    } else {
        lastMoveMessage = name + " missed the Headbutt!";
        return opposingCat;
    }
}

Cat Feral::kick(Cat feral, Cat opposingCat) const {
    opposingCat.setHp(opposingCat.getHp() - (feral.getDamage() * 0.5));
    lastMoveMessage = name + " kicks " + opposingCat.getName() + " for " + std::to_string(static_cast<int>(std::ceil(feral.getDamage() * 0.5))) + "HP!";
    return opposingCat;
}
