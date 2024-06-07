#include "../../include/lab4-task3/binary.hpp"
#include "../../include/lab4-task3/taxi.hpp"
#include <fstream>
#include <ios>
#include <iostream>
#include <stdexcept>

using namespace std::chrono;

namespace {
    void check_file(const std::fstream& file) {
        if (!file) {
            throw std::runtime_error("File doesn't exist");
        }
    }
}

void Binary::read_from_file() {
    std::fstream file_input(m_source, std::ios::in);
    check_file(file_input);
    std::fstream file_output(m_name, std::ios::binary | std::ios::out);

    Taxi taxi;
    size_t count = 0;
    while (file_input >> taxi.surname >> taxi.year >> taxi.month >> taxi.day >> taxi.is_in_garage) {
        taxi.id = count;
        file_output.write(reinterpret_cast<char*>(&taxi), sizeof(taxi));
        ++count;
    }

    file_input.close();
    file_output.close();
}

void Binary::read_from_binary() {
    std::fstream file(m_name, std::ios::binary | std::ios::in);
    check_file(file);

    Taxi taxi;
    file.seekg(0);
    while (file.read(reinterpret_cast<char*>(&taxi), sizeof(taxi))) {
        std::cout << taxi.id << ". " << taxi.surname << " " << taxi.year <<
            "-" << taxi.month << "-" << taxi.day << " " << taxi.is_in_garage << '\n';
    }

    file.close();
}

void Binary::store_garage(const std::string& filename) {
    std::fstream file_input(m_name, std::ios::binary | std::ios::in);
    check_file(file_input);
    std::fstream file_output(filename, std::ios::binary | std::ios::out);

    Taxi taxi;
    file_input.seekg(0);
    while (file_input.read(reinterpret_cast<char*>(&taxi), sizeof(taxi))) {
        if (taxi.is_in_garage == true) {
            file_output.write(reinterpret_cast<char*>(&taxi), sizeof(taxi));
        }
    }

    file_input.close();
    file_output.close();
}

void Binary::update_binary(size_t id) {
    std::fstream file(m_name, std::ios::binary | std::ios::in | std::ios::out);
    check_file(file);

    Taxi taxi;
    file.seekg(0);
    bool state = true;
    while (file.read(reinterpret_cast<char*>(&taxi), sizeof(taxi))) {
        if (taxi.id == id) {
            taxi.is_in_garage = !taxi.is_in_garage;
            file.seekp(file.tellg() - static_cast<long long>(sizeof(taxi)));
            file.write(reinterpret_cast<char*>(&taxi), sizeof(taxi));
            state = false;
            break;
        }
    }

    file.close();

    if (state) {
        throw std::invalid_argument("Object with that id doesn't exist");
    }
}

void Binary::delete_last(size_t id) {
    std::fstream file(m_name, std::ios::binary | std::ios::in | std::ios::out);
    std::ofstream temp("temp.bin", std::ios::binary);
    check_file(file);

    Taxi taxi;
    file.seekg(0);
    bool state = true;
    while (file.read(reinterpret_cast<char*>(&taxi), sizeof(taxi))) {
        if (taxi.id == id) {
            temp.seekp(file.tellg() - static_cast<long long>(sizeof(taxi)));
            state = false;
        }
        temp.write(reinterpret_cast<char*>(&taxi), sizeof(taxi));
    }

    file.close();

    if (state) {
        throw std::invalid_argument("Object with that id doesn't exist");
    }
}
