#include <cstring>
#include <math.h>
#include <stdexcept>
#include <string>

#pragma once

class dynamic_array {
    public:
    dynamic_array(size_t len = m_delta) {
        m_len = len + m_delta;
        m_array = new int[m_len];
        m_first_element = m_array;
        m_last_element = m_first_element;
    }

    dynamic_array(const dynamic_array& copy) {
        m_len = copy.m_len;
        m_array = copy.m_array;
        m_first_element = copy.m_first_element;
        m_last_element = copy.m_last_element;
    }

    ~dynamic_array() {
        delete m_array;
    }

    size_t size() const {
        return m_last_element - m_first_element;
    }

    size_t max_size() const {
        return m_len;
    }

    void push_back(int num) {
        if (size() + 1 > m_len) {
            reallocate();
        }
        *(m_last_element++) = num;
    }

    void erase(size_t index) {
        if (index > size()) {
            throw std::logic_error("Index is out of range");
        }
        for (size_t i = index; i < size() - 1; ++i) {
            m_array[i] = m_array[i + 1];
        }
        --m_last_element;
    }

    int find_max() const {
        if (size() == 0) {
            throw std::logic_error("Array is empty");
        }
        int max = m_array[0];
        size_t len = size();
        for (size_t i = 1; i < len; ++i) {
            if(m_array[i] > max) {
                max = m_array[i];
            }
        }
        return max;
    }

    dynamic_array find_primes() {
        if (size() == 0) {
            throw std::logic_error("Array is empty");
        }
        dynamic_array primes;
        size_t len = size();
        for (size_t i = 0; i < len; ++i) {
            if (is_prime(m_array[i])) {
                primes.push_back(m_array[i]);
            }
        }
        return primes;
    }

    friend std::ostream& operator <<(std::ostream& stream, const dynamic_array& array) {
        size_t len = array.size();
        for (size_t i = 0; i < len; ++i) {
            stream << std::to_string(array.m_array[i]) + " ";
        }
        return stream;
    }

    dynamic_array& operator -(const dynamic_array& other) {
        size_t other_len = other.size();
        for(size_t i = 0; i < other_len; ++i) {
            for(size_t j = 0; j < size(); ++j) {
                if (other.m_array[i] == m_array[j]) {
                    erase(j);
                    break;
                }
            }
        }
        return *this;
    }

    bool operator ==(const dynamic_array& other) const {
        if (size() != other.size()) {
            return false;
        }
        size_t len = size();
        for(size_t i = 0; i < len; ++i) {
            if (m_array[i] != other.m_array[i]) {
                return false;
            }
        }
        return true;
    }

    private:
    int* m_array;
    int* m_first_element;
    int* m_last_element;
    size_t m_len;
    static const unsigned short m_delta = 5;

    void reallocate() {
        m_len += m_delta;
        int* new_array = new int[m_len];
        std::memcpy(new_array, m_first_element, sizeof(int) * (m_len - m_delta));

        delete[] m_first_element;
        m_first_element = new_array;
        m_last_element = m_first_element + m_len - m_delta;
    }

    bool is_prime(int num) const {
        unsigned int cnt = 0;
        for (unsigned int i = 1; i <= sqrt(num); ++i) {
            if (num % i == 0) {
                cnt += 2;
            }
        }
        return cnt == 2 && num != 1;
    }
};
