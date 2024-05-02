#include "../include/dynamic_array.hpp"
#include <iostream>

int main() {
    dynamic_array array1{1}, array2{1};
    for (size_t i = 0; i < 5; ++i) {
       array1.push_back(i); array2.push_back(i + 2);
    }
    array1 = array1 - array2;
    std::cout << array1 << '\n';
}
