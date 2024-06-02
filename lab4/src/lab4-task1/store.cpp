#include "../../include/lab4-task1/store.hpp"
#include <fstream>
#include <stdexcept>

void Store::add(const Animal& object) {
    m_animals.push_front(object);
}

void Store::remove() {
    m_animals.pop_front();
}

void Store::save() {
    if (m_animals.empty()) {
        throw std::runtime_error("List is emplty");
    }

    std::ofstream file("store.txt");
    auto begin = m_animals.begin();
    auto end = m_animals.end();

    while (begin != end) {
        file << begin->get_sound() << '\n';
        ++begin;
    }

    file.close();
}
