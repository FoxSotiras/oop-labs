#include "../include/lab3/notebook_entry.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

NotebookEntry::~NotebookEntry() {
    std::cout << "The object has been deleted" << '\n';
}

std::string NotebookEntry::get_telephone_number(std::vector<NotebookEntry> entrys, const std::string& surname, const std::string& name) const {
    size_t len = entrys.size();
    for (size_t i = 0; i < len; ++i) {
        if (entrys[i].m_surname == surname && entrys[i].m_name == name) {
            return entrys[i].m_telephone_number;
        }
    }

    throw std::logic_error("The object with this arguments doesn't exist");
}

bool NotebookEntry::check_people_living_together(const NotebookEntry& first, const NotebookEntry& second) const {
    return first.m_residential_address == second.m_residential_address;
}
