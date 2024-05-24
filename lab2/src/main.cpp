#include "../include/dynamic_array.hpp"
#include "../include/rational_number.hpp"
#include <iostream>

int main() {
    dynamic_array array1{1}, array2{1};
    for (size_t i = 0; i < 5; ++i) {
       array1.push_back(i); array2.push_back(i);
    }
    // array1 = array1 - array2;
    std::cout << array1.find_primes() << '\n';
    rational_number num1(1, 2), num2(1, 2);
    rational_number num3 = num1/num2, num4, num5(14, 8);
    std::cout << (num1 == num2) << '\n';
    num5.simplify();
    std::cout << num1 << '\n' << num5 << '\n';
    std::cin >> num4;
}
