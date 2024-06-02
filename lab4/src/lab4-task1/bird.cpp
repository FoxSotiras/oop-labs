#include "../../include/lab4-task1/bird.hpp"
#include <iostream>

Bird::Bird(): Animal() {}
Bird::Bird(const std::string& sound): Animal(sound) {}
Bird::Bird(const Bird& other): Animal(other) {}

void Bird::communicate() {
    std::cout << "Singing: " << m_sound << '\n';
}
