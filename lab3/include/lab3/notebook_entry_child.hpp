#include "notebook_entry.hpp"
#include <string>

class NotebookEntryChild: public NotebookEntry {
    public:
    NotebookEntryChild();
    NotebookEntryChild(
        const NotebookEntry& parent,
        const std::string& surname,
        const std::string& name,
        unsigned short p_year,
        unsigned short p_month,
        unsigned short p_day
    );
    NotebookEntryChild(const NotebookEntryChild& other);

    void set_child_surname(const std::string& surname);
    const std::string& get_child_surname() const;

    void set_child_name(const std::string& name);
    const std::string& get_child_name() const;

    void set_child_birthday(
        unsigned short p_year,
        unsigned short p_month,
        unsigned short p_day
    );
    void set_child_birthday(const year_month_day& p_day);
    const year_month_day& get_child_birthday() const;

    static std::string get_child(const std::forward_list<NotebookEntryChild>& entrys, const std::string& surname, const std::string& name);
    static bool check_age(const NotebookEntryChild& first, const NotebookEntryChild& second);

    private:
    std::string m_child_surname;
    std::string m_child_name;
    year_month_day m_child_birthday;
};
