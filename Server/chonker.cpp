#include "chonker.h"
#include <iostream>

Chonker::Chonker() : Cat("Chonker", 15, 4) {} // Call base class constructor

void Chonker::attack() const {
    std::cout << name << " snarls and attacks!" << std::endl;
}

void Chonker::buff() const {
    std::cout << name << " snarls and attacks!" << std::endl;
}

void Chonker::block() const {
    std::cout << name << " snarls and attacks!" << std::endl;
}

void Chonker::regenerate() const {
    std::cout << name << " snarls and attacks!" << std::endl;
}

