#include "../include/lab3/notebook_entry.hpp"
#include "../include/lab3/notebook_entry_child.hpp"
#include <iostream>

int main() {
    NotebookEntry one;
    NotebookEntry second;
    NotebookEntry third("Buglak", "Dmitriy", "+79951350976", 2005, 9, 29, "Moscow, Dubravnaia");
    std::forward_list<NotebookEntry> list;
    list.push_front(one);
    list.push_front(second);
    list.push_front(third);

    std::cout << "Surname: " << third.get_surname() << '\n';
    std::cout << "Name: " << third.get_name() << '\n';
    std::cout << "Telephone number: " << third.get_telephone() << '\n';
    std::cout << "Birthday: " << third.get_birthday() << '\n';
    std::cout << "Address: " << third.get_address() << '\n';

    std::cout << NotebookEntry::find_telephone(list, "Buglak", "Dmitriy") << '\n';
    std::cout << NotebookEntry::is_living_together(one, third) << '\n';

    second = NotebookEntry("Lobanov", "Oleg", "+79011350976", 1995, 9, 29, "Moscow, Dubravnaia");
    NotebookEntryChild second_child(second, "Lobanov", "Grigoriy", 2020, 9, 20);
    NotebookEntryChild third_child(third, "Buglak", "Oleg", 2020, 9, 1);
    std::forward_list<NotebookEntryChild> list_child;
    list_child.push_front(second_child);
    list_child.push_front(third_child);

    std::cout << NotebookEntryChild::get_child(list_child, "Buglak", "Dmitriy") << '\n';
    std::cout << NotebookEntryChild::check_age(second_child, third_child) << '\n';

    return 0;
}
