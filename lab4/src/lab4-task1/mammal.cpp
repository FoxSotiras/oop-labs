#include "../../include/lab4-task1/mammal.hpp"
#include <iostream>

Mammal::Mammal(): Animal() {}
Mammal::Mammal(const std::string& sound): Animal(sound) {}
Mammal::Mammal(const Mammal& other): Animal(other) {}

void Mammal::communicate() {
    std::cout << "Sound: " << m_sound << '\n';
}
