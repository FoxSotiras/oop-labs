#include <vector>

#pragma once

class Polynomial {
    int m_degree;
    std::vector<double> m_odds_array;

    public:
    Polynomial(int degree = 0);
    Polynomial(const Polynomial &other);

    Polynomial operator +(const Polynomial &operands);
    Polynomial operator -(const Polynomial &operand);
    Polynomial operator *(const Polynomial &operand);

    double get_value(const double &x);
    void print_polynomial();
};
