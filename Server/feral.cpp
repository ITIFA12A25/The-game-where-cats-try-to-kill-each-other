#include "feral.h"
#include <iostream>

Feral::Feral() : Cat("Feral", 10, 6) {}

void Feral::attack() const {
    std::cout << name << " snarls and attacks!" << std::endl;
}

void Feral::buff() const {
    std::cout << name << " snarls and attacks!" << std::endl;
}

void Feral::block() const {
    std::cout << name << " snarls and attacks!" << std::endl;
}

void Feral::regenerate() const {
    std::cout << name << " snarls and attacks!" << std::endl;
}
