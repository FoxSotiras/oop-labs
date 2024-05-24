#include <stdexcept>
#include <string>

#pragma once

class rational_number {
    public:
    rational_number(int a = 1, unsigned int b = 1);
    rational_number(const rational_number& copy);
    void simplify();
    friend rational_number operator +(rational_number num1, rational_number num2);
    friend rational_number operator -(rational_number num1, rational_number num2);
    friend rational_number operator *(rational_number num1, rational_number num2);
    friend rational_number operator /(rational_number num1, rational_number num2);
    friend bool operator ==(const rational_number& num1, const rational_number& num2);
    friend bool operator !=(const rational_number& num1, const rational_number& num2);
    friend bool operator <(const rational_number& num1, const rational_number& num2);
    friend bool operator >(const rational_number& num1, const rational_number& num2);
    friend bool operator <=(const rational_number& num1, const rational_number& num2);
    friend bool operator >=(const rational_number& num1, const rational_number& num2);
    friend std::ostream& operator <<(std::ostream& stream, const rational_number& num);
    friend std::istream& operator >>(std::istream& stream, rational_number& num);

    private:
    int numerator;
    unsigned int denominator;
};
