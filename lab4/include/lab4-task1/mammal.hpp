#pragma once

#include "animal.hpp"

class Mammal: public Animal {
public:
    Mammal();
    Mammal(const std::string& sound);
    Mammal(const Mammal& other);

    void communicate() override;
};
