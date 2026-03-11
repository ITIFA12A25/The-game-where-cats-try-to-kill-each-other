#include "zoomies.h"
#include <iostream>

Zoomies::Zoomies() : Cat("Zoomies", 8, 4) {}

void Zoomies::attack() const {
    std::cout << name << " snarls and attacks!" << std::endl;
}

void Zoomies::buff() const {
    std::cout << name << " snarls and attacks!" << std::endl;
}

void Zoomies::block() const {
    std::cout << name << " snarls and attacks!" << std::endl;
}

void Zoomies::regenerate() const {
    std::cout << name << " snarls and attacks!" << std::endl;
}
