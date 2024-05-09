#include <cstdio>
#include <cstddef>
#include <iostream>
#include <string>
#include <cstring>
#include "hashtable.h"

int main() {
    /*List_v<std::string> list_str1{};
    std::string str1;
    std::string str2 {"hello"};
    while (getline(std::cin, str1)) {
        if (str1 == "q")
            break;
        list_str1.insert_list(str1);
    };
    std::cout << list_str1.search_list(str2) << std::endl;
    list_str1.delet_list(str2);
    std::cout << list_str1.search_list(str2) << std::endl;
    list_str1.Show();*/
    int size;
    std::cout << "Enter size hash table: ";
    std::cin >> size;
    HashTable<std::string> ht(size);
    char choice;
    std::string str;
    std::cout << "Enter :\n" << "i - insert, s - search, d - delete, w - show, or q: quit\n";
    std::cin >> choice;
    for (;;) {
        if (choice == 'q') {
            break;
        }
        switch (choice) {
            case 'i': std::cout << "Enter str: ";
                      std::cin.ignore();
                      getline(std::cin, str);
                      ht.insert_table(str);
                      break;
            case 's': std::cout << "Enter str search: ";
                      std::cin.ignore();
                      getline(std::cin, str);
                      std::cout << "Search: " << str << "  ((" << ht.search_table(str) << "))" << std::endl;
                      break;
            case 'd': std::cout << "Enter str delete: ";
                      std::cin.ignore();
                      getline(std::cin, str);
                      std::cout << "Delete: " << str << "  ((" << ht.delet_table(str) << "))" << std::endl;
                      break;
            case 'w': std::cout << "Show hash table:\n"; 
                      ht.Show();
                      break;
        }
        std::cout << "Enter :\n" << "i - insert, s - search, d - delete, w - show, or q: quit\n";
        std::cin >> choice;
    }
    ht.clear();

    return 0;
}
