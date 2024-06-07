#pragma once

#include <string>

class Files {
public:
    void create_file();
    void print_file();
    void add_line(int line);
    void create_additional(const std::string& filename);
private:
    std::string m_filename{"numbers.txt"};
};
