#pragma once

#include <cstddef>
#include <string>

class Binary {
public:
    void read_from_file();
    void read_from_binary();
    void store_garage();
    void update_binary(size_t id);
    void delete_last(size_t id);
private:
    std::string m_name{"binary.bin"};
    std::string m_source{"text/task3.txt"};
};
