#include "../include/rational_number.hpp"

rational_number::rational_number(int a, unsigned int b) {
    if (a == 0 || b == 0) {
        throw std::invalid_argument("Can't be a zero");
    }
    numerator = a;
    denominator = b;
}

rational_number::rational_number(const rational_number& copy) {
    numerator = copy.numerator;
    denominator = copy.denominator;
}

void rational_number::simplify() {
    for (unsigned int i = denominator; i != 1; --i) {
        if (numerator % i == 0 && denominator % i == 0) {
            numerator /= i; denominator /= i;
        }
    }
}

rational_number operator +(rational_number num1, rational_number num2) {
    if (num2.denominator == num1.denominator) {
        num1.numerator += num2.numerator;
    }
    else {
        num1.numerator *= num2.denominator;
        num2.numerator *= num1.denominator;
        num1.denominator *= num2.denominator;
        num1.numerator += num2.numerator;
    }
    return num1;
}

rational_number operator -(rational_number num1, rational_number num2) {
    if (num2.denominator == num1.denominator) {
        num1.numerator -= num2.numerator;
    }
    else {
        num1.numerator *= num2.denominator;
        num2.numerator *= num1.denominator;
        num1.denominator *= num2.denominator;
        num1.numerator -= num2.numerator;
    }
    return num1;
}

rational_number operator *(rational_number num1, rational_number num2) {
    num1.numerator *= num2.numerator;
    num1.denominator *= num2.denominator;
    return num1;
}

rational_number operator /(rational_number num1, rational_number num2) {
    num1.numerator *= num2.denominator;
    if (num2.numerator < 0) {
        num1.numerator *= -1;
        num1.denominator *= -1 * num2.numerator;
    }
    else {
        num1.denominator *= num2.numerator;
    }
    return num1;
}

bool operator ==(const rational_number& num1, const rational_number& num2) {
    if (num1.denominator == num2.denominator) {
        return num1.numerator == num2.numerator;
    }
    else {
        return num1.numerator*num2.denominator == num2.numerator*num1.denominator;
    }
}

bool operator !=(const rational_number& num1, const rational_number& num2) {
    if (num1.denominator == num2.denominator) {
        return num1.numerator != num2.numerator;
    }
    else {
        return num1.numerator*num2.denominator != num2.numerator*num1.denominator;
    }
}

bool operator <(const rational_number& num1, const rational_number& num2) {
    if (num1.denominator == num2.denominator) {
        return num1.numerator < num2.numerator;
    }
    else {
        return num1.numerator*num2.denominator < num2.numerator*num1.denominator;
    }
}

bool operator >(const rational_number& num1, const rational_number& num2) {
    if (num1.denominator == num2.denominator) {
        return num1.numerator > num2.numerator;
    }
    else {
        return num1.numerator*num2.denominator > num2.numerator*num1.denominator;
    }
}

bool operator <=(const rational_number& num1, const rational_number& num2) {
    if (num1.denominator == num2.denominator) {
        return num1.numerator <= num2.numerator;
    }
    else {
        return num1.numerator*num2.denominator <= num2.numerator*num1.denominator;
    }
}

bool operator >=(const rational_number& num1, const rational_number& num2) {
    if (num1.denominator == num2.denominator) {
        return num1.numerator >= num2.numerator;
    }
    else {
        return num1.numerator*num2.denominator >= num2.numerator*num1.denominator;
    }
}

std::ostream& operator <<(std::ostream& stream, const rational_number& num) {
    return stream << std::to_string(num.numerator) + "/" + std::to_string(num.denominator);
}

std::istream& operator >>(std::istream& stream, rational_number& num) {
    std::string input;
    stream >> input;
    if (input.find("/") == std::string::npos) {
        throw std::invalid_argument("Invalid argument");
    }
    num.numerator = std::stoi(input.substr(0, input.find("/")));
    input.erase(0, input.find("/") + 1);
    num.denominator = std::stoi(input);
    return stream;
}
