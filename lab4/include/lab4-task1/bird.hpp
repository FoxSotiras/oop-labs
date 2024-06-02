#pragma once

#include "animal.hpp"

class Bird: public Animal {
public:
    Bird();
    Bird(const std::string& sound);
    Bird(const Bird& other);

    void communicate() override;
};
