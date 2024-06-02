#include "../../include/lab4-task1/animal.hpp"
#include <iostream>
#include <stdexcept>

Animal::Animal(): m_sound("") {}

Animal::Animal(const std::string& sound): m_sound(sound) {
    if (sound.empty()) {
        throw std::runtime_error("Empty string");
    }
}
Animal::Animal(const Animal& other): m_sound(other.m_sound) {}

void Animal::communicate() { std::cout << m_sound << '\n'; }

const std::string& Animal::get_sound() const { return m_sound; }

Animal::~Animal() { std::cout << "The object has been deleted" << '\n'; }
