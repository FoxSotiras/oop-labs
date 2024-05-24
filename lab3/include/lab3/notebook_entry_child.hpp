#include "notebook_entry.hpp"

#pragma once

class NotebookEntryChild : public NotebookEntry {
    public:
    

    private:
    std::string m_child_surname;
    std::string m_child_name;
    std::chrono::year_month_day m_child_birth_day;
};
