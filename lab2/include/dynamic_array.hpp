#include <cstring>
#include <math.h>
#include <stdexcept>
#include <string>

#pragma once

namespace 
{
    constexpr unsigned short defaultSize_ = 5;
}

class dynamic_array {
    public:
    dynamic_array(size_t len = defaultSize_);
    dynamic_array(const dynamic_array& copy);
    ~dynamic_array();
    size_t size() const;
    size_t max_size() const;
    void push_back(int num);
    void erase(size_t index);
    int find_max() const;
    dynamic_array find_primes() const;
    friend std::ostream& operator <<(std::ostream& stream, const dynamic_array& array);
    friend dynamic_array operator -(const dynamic_array& array1, const dynamic_array& array2);
    friend bool operator ==(const dynamic_array& array1, const dynamic_array& array2);

    private:
    int* m_first_element;
    int* m_last_element;
    size_t m_len;
    static const unsigned short m_delta = 5;

    void reallocate();
    bool is_prime(int num) const;
};
