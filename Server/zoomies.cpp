#include "zoomies.h"
#include <iostream>
#include <random>

Zoomies::Zoomies() : Cat("Zoomies", 50, 6, 50) {}

Cat Zoomies::scratch(Cat zoomies, Cat opposingCat) const {
    // Random number between 1 and 100
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int randomNumber = dis(gen);

    if (randomNumber < 100 - opposingCat.getSpeed()) {
        opposingCat.setHp(opposingCat.getHp()-zoomies.getDamage());
        lastMoveMessage = name + " scratches " + opposingCat.getName() + " for " + std::to_string(zoomies.getDamage()) + "HP!";
        return opposingCat;
    } else {
        lastMoveMessage = name + " missed the Scratch!";
        return opposingCat;
    }
}

Cat Zoomies::bite(Cat zoomies, Cat opposingCat) const {
    // Random number between 1 and 100
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int randomNumber = dis(gen);

    if (randomNumber < 70 - opposingCat.getSpeed()) {
        opposingCat.setHp(opposingCat.getHp() - (zoomies.getDamage() * 2));
        lastMoveMessage = name + " bites " + opposingCat.getName() + " for " + std::to_string(static_cast<int>(std::ceil(zoomies.getDamage() * 2))) + "HP!";
        return opposingCat;
    } else {
        lastMoveMessage = name + " missed the Bite!";
        return opposingCat;
    }
}

Cat Zoomies::headbutt(Cat zoomies, Cat opposingCat) const {
    // Random number between 1 and 100
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int randomNumber = dis(gen);

    if (randomNumber < 70 - opposingCat.getSpeed()) {
        opposingCat.setHp(opposingCat.getHp() - (zoomies.getDamage() * 1.5));
        lastMoveMessage = name + " headbutts " + opposingCat.getName() + " for " + std::to_string(static_cast<int>(std::ceil(zoomies.getDamage() * 1.5))) + "HP!";
        return opposingCat;
    } else {
        lastMoveMessage = name + " missed the Headbutt!";
        return opposingCat;
    }
}

Cat Zoomies::kick(Cat zoomies, Cat opposingCat) const {
    opposingCat.setHp(opposingCat.getHp() - (zoomies.getDamage() * 0.5));
    lastMoveMessage = name + " kicks " + opposingCat.getName() + " for " + std::to_string(static_cast<int>(std::ceil(zoomies.getDamage() * 0.5))) + "HP!";
    return opposingCat;
}

