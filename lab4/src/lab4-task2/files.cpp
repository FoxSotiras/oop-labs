#include "../../include/lab4-task2/files.hpp"
#include <fstream>
#include <ios>
#include <iostream>
#include <limits>
#include <random>
#include <stdexcept>
#include <string>

namespace {
    void check_file(const std::ifstream& file) {
        if (!file) {
            throw std::runtime_error("File doesn't exist");
        }
    }
}

void Files::create_file() {
    std::ofstream file(m_filename);//move to class
    std::random_device rd;
    std::uniform_int_distribution<unsigned int> dist(0, 10000);

    unsigned short len = 10;
    for (unsigned short i = 0; i < len; ++i) {
        file << dist(rd) << '\n';
    }

    file.close();
}

void Files::print_file() {
    std::ifstream file(m_filename);
    check_file(file);

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << '\n';
    }

    file.close();
}

void Files::add_line() {
    std::ofstream file(m_filename, std::ios::app);

    int line;
    std::cout << "Input number to write: ";
    if (std::cin >> line) {
        file << line << '\n';
    }
    else {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::runtime_error("Invalid argument");
        
    }

    file.close();
}

void Files::create_additional() {
    std::ofstream file_output("additional.txt");//argument
    std::ifstream file_input(m_filename);
    check_file(file_input);

    std::string line;
    unsigned short count = 0;
    while (std::getline(file_input, line)) {
        file_output << line;
        ++count;
        if (count == 3) {
            file_output << '\n';
            count = 0;
        }
        else {
            file_output << ' ';
        }
    }
    if (count != 0) {
        file_output << '\n';
    }

    file_input.close();
    file_output.close();
}
