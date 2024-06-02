#pragma once

#include <string>

class Files {
public:
    void create_file();
    void print_file();
    void add_line();
    void create_additional();
private:
    std::string m_filename{"numbers.txt"};
};
