// Task 1
#include "../include/lab4-task1/bird.hpp"
#include "../include/lab4-task1/mammal.hpp"
#include "../include/lab4-task1/store.hpp"
//Task 2
#include "../include/lab4-task2/files.hpp"

#include <exception>

int main() {
    // Task 1
    Store animals;
    Animal* mammal = new Mammal("Muuuu");
    Animal* bird = new Bird("Caaar");
    animals.add(*mammal);
    animals.add(*bird);

    mammal->communicate();
    bird->communicate();

    animals.save();

    delete mammal;
    delete bird;

    // Task 2
    Files files;
    files.create_file();
    files.print_file();
    
    bool state = false;
    do {
        try {
            files.add_line();
            state = true;
        } catch (const std::exception& error) {
            error.what();
        }
    } while (!state);

    files.print_file();
    files.create_additional();

    return 0;
}
