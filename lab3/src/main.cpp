#include "../include/lab3/notebook_entry.hpp"
#include "../include/lab3/notebook_entry_child.hpp"
#include <vector>


int main() {
    NotebookEntry first;
    NotebookEntry second;
    NotebookEntry third("Buglak", "Dmitriy", "+79951350976", 29, 9, 2005, "Moscow,Dybravnya street,35,151");
    std::vector<NotebookEntry> entrys;
    entrys.push_back(first);
    entrys.push_back(second);
    entrys.push_back(third);

    return 0;
}
