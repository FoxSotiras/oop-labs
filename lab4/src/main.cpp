// Task 1
#include "../include/lab4-task1/bird.hpp"
#include "../include/lab4-task1/mammal.hpp"
#include "../include/lab4-task1/store.hpp"
//Task 2
#include "../include/lab4-task2/files.hpp"
// Task 3
#include "../include/lab4-task3/binary.hpp"

#include <exception>
#include <iostream>
#include <limits>

int main() {
    // Task 1
    Store animals;
    Animal* mammal = new Mammal("Muuuu");
    Animal* bird = new Bird("Caaar");
    animals.add(mammal);
    animals.add(bird);

    mammal->communicate();
    bird->communicate();

    animals.save();

    delete mammal;
    delete bird;

    // Task 2
    Files files;
    files.create_file();
    files.print_file();
    
    int line;
    std::cout << "Input number to write: ";
    if (std::cin >> line) {
        bool state = false;
        do {
            try {
                files.add_line(line);
                state = true;
            } catch (const std::exception& error) {
                error.what();
            }
        } while (!state);
    }
    else {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::runtime_error("Invalid argument");
        
    }

    files.print_file();
    files.create_additional("add.txt");

    // Task3
    Binary binary;
    binary.read_from_file();
    binary.read_from_binary();
    binary.store_garage("add.bin");
    binary.update_binary(3);
    binary.read_from_binary();
    binary.delete_last(3);
    binary.read_from_binary();

    return 0;
}
