#include "../include/lab1-task1/lib_card.hpp"
#include "../include/lab1-task2/polynomial.hpp"
#include <iostream>

void task1();
void task2();

int main()
{
    unsigned short task;

    task:
    std::cout << "Task 1 or 2? ";
    std::cin >> task;
    if (!std::cin)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid task number, retry." << '\n';
        goto task;
    }
    switch (task) {
        case 1:
        task1();
        break;
        case 2:
        task2();
        break;
        default:
        std::cout << "Invalid task number, retry." << '\n';
        goto task;
        break;
    }

    return 0;
}

void task1() {
    LibCards lib_cards;
    for (unsigned short i = 0; i < 3; ++i) {
        lib_cards.create_card();
    }
    lib_cards.sort_cards();
    std::vector<LibCard> list = lib_cards.get_list();
}

void task2() {
    Polynomial polynomial1(2);
    Polynomial polynomial2(2);
    Polynomial c = polynomial1 * polynomial2;
    std::cout << c.get_value(2) << '\n';
    c.print_polynomial();
}
