#include "../include/lab3/notebook_entry.hpp"
#include <stdexcept>

const std::string& NotebookEntry::find_telephone(const std::forward_list<NotebookEntry>& entrys, const char* surname, const char* name) {
    auto begin = entrys.begin();
    auto end = entrys.end();
    while (begin != end) {
        if (begin->m_surname == surname && begin->m_name == name) {
            return begin->m_telephone;
        }
        ++begin;
    }

    throw std::logic_error("Object with that parameters is not found");
}

bool NotebookEntry::is_living_together(const NotebookEntry& first, const NotebookEntry& second) {
    return first.m_address == second.m_address;
}
