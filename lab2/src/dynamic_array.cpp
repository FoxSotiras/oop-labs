#include "../include/dynamic_array.hpp"

dynamic_array::dynamic_array(size_t len) : m_len(len+m_delta) {
    m_first_element = new int[m_len];
    m_last_element = m_first_element;
}

dynamic_array::dynamic_array(const dynamic_array& copy) {
    m_len = copy.m_len;
    m_first_element = copy.m_first_element;
    m_last_element = copy.m_last_element;
}

//int* test = new int(5);
//delete test;

dynamic_array::~dynamic_array() {
    delete[] m_first_element;
}

size_t dynamic_array::size() const {
    return m_last_element - m_first_element;
}

size_t dynamic_array::max_size() const {
    return m_len;
}

void dynamic_array::push_back(int num) {
    if (size() + 1 > m_len) {
        reallocate();
    }
    *(m_last_element++) = num;
}

void dynamic_array::erase(size_t index) {
    if (index > size()) {
        throw std::logic_error("Index is out of range");
    }
    for (size_t i = index; i < size() - 1; ++i) {
        m_first_element[i] = m_first_element[i + 1];
    }
    --m_last_element;
}

int dynamic_array::find_max() const {
    if (size() == 0) {
        throw std::logic_error("Array is empty");
    }
    int max = m_first_element[0];
    size_t len = size();
    for (size_t i = 1; i < len; ++i) {
        if(m_first_element[i] > max) {
            max = m_first_element[i];
        }
    }
    return max;
}

dynamic_array dynamic_array::find_primes() const {
    if (size() == 0) {
        throw std::logic_error("Array is empty");
    }
    dynamic_array primes;
    size_t len = size();
    for (size_t i = 0; i < len; ++i) {
        if (is_prime(m_first_element[i])) {
            primes.push_back(m_first_element[i]);
        }
    }
    return primes;
}

std::ostream& operator <<(std::ostream& stream, const dynamic_array& array) {
    size_t len = array.size();
    for (size_t i = 0; i < len; ++i) {
        stream << std::to_string(array.m_first_element[i]) + " ";
    }
    return stream;
}

dynamic_array operator -(const dynamic_array& array1,const dynamic_array& array2) {
    dynamic_array copy = array1;
    size_t array2_len = array2.size();
    for(size_t i = 0; i < array2_len; ++i) {
        for(size_t j = 0; j < copy.size(); ++j) {
            if (array2.m_first_element[i] == copy.m_first_element[j]) {
                copy.erase(j);
                break;
            }
        }
    }
    return copy;
}

bool operator ==(const dynamic_array& array1, const dynamic_array& array2) {
    if (array1.size() != array2.size()) {
        return false;
    }
    size_t len = array1.size();
    for(size_t i = 0; i < len; ++i) {
        if (array1.m_first_element[i] != array2.m_first_element[i]) {
            return false;
        }
    }
    return true;
}

void dynamic_array::reallocate() {
    m_len += m_delta;
    int* new_array = new int[m_len];
    std::memcpy(new_array, m_first_element, sizeof(int) * (m_len - m_delta));

    delete[] m_first_element;
    m_first_element = new_array;
    m_last_element = m_first_element + m_len - m_delta;
}

bool dynamic_array::is_prime(int num) const {
    unsigned int cnt = 0;
    for (unsigned int i = 1; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            cnt += 2;
        }
    }
    return cnt == 2 && num != 1;
}
