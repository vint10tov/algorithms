#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include <bits/stdint-uintn.h>
#include <cstddef>
#include <iostream>
#include <string>

template<typename T>
uint64_t hash(const T & t) {return 0;}

template<>
uint64_t hash<std::string>(const std::string & str);

template<typename T>
class List_v {
    private:
        size_t size_list;
        struct Node {
            T value;
            Node * next; // следующий
            Node * previous; // предыдущий
        };
        Node * head; // указатель на начало
        Node * tail; // указатель на конец
        Node * iter; // указатель для поиска
        List_v(const List_v & list) : size_list(0) {}
        List_v & operator=(const List_v & list);
    public:
        List_v();
        ~List_v();
        void clear();
        void insert_list(const T & t);
        bool search_list(const T & t);
        bool delet_list(const T & t);
        void Show();
        size_t GetSize() const {return size_list;}
};

template<typename T>
class HashTable {
    private:
        size_t size_table; // размер таблицы
        size_t count; // заполненность таблици
        const double proc = 0.7; // порог заполнения
        size_t hash_t; // последний вычисленный хэш
        List_v<T> * list;
        HashTable(const HashTable & ht) : size_table(0) {}
        HashTable & operator=(const HashTable & ht);
    public:
        HashTable(size_t size);
        ~HashTable();
        bool insert_table(const T & t);
        bool delet_table(const T & t);
        bool search_table(const T & t);
        size_t GetSize() const {return size_table;}
        size_t GetCount() const {return count;}
        void clear();
        void Show();
};

#endif

template<>
uint64_t hash<std::string>(const std::string & str) {
    const int PRIME_NUMBER = 53;
    uint64_t hash = 0;
    uint64_t temp = 1;
    for (size_t i = 0; i < str.length(); ++i) {
        hash += (str[i] - 'a' + 1) * temp;
        temp *= PRIME_NUMBER;
    }
    return hash;
}

template<typename T>
List_v<T>::List_v() {
    size_list = 0;
    head = nullptr;
    iter = nullptr;
    tail = nullptr;
}

template<typename T>
List_v<T>::~List_v() {
    if (size_list != 0)
        clear();
}

template<typename T>
void List_v<T>::clear() {
    if (size_list != 0) {
        iter = head;
        Node * temp;
        while (iter != tail) {
            temp = iter->next;
            delete iter;
            iter = temp;
        }
        size_list = 0;
        head = nullptr;
        iter = nullptr;
        tail = nullptr;
    }
}

template<typename T>
void List_v<T>::insert_list(const T & t) {
    if (size_list == 0) {
        head = new Node;
        head->value = t;
        head->next = nullptr;
        head->previous = nullptr;
        tail = head;
        iter = nullptr;
        ++size_list;
    } else {
        iter = new Node;
        iter->value = t;
        iter->next = nullptr;
        iter->previous = tail;
        tail->next = iter;
        tail = iter;
        iter = nullptr;
        ++size_list;
    }
}

template<typename T>
bool List_v<T>::search_list(const T & t) {
    if (size_list != 0) {
        iter = head;
        while (iter != nullptr) {
            if (iter->value == t) {
                return true;
            } else {
                iter = iter->next;
            }
        }
        return false;
    } else {
        return false;
    }
}

template<typename T>
bool List_v<T>::delet_list(const T & t) {
    if (search_list(t)) {
        if (iter == head and head->next == nullptr) {
            delete iter;
            iter = nullptr;
            head = nullptr;
            tail = nullptr;
            size_list = 0;
            return true;
        } else if (iter == head and head->next != nullptr) {
            head = iter->next;
            head->next->previous = nullptr;
            delete iter;
            iter = nullptr;
            --size_list;
            return true;
        } else if (iter == tail) {
            tail->previous->next = nullptr;
            tail = iter->previous;
            delete iter;
            iter = nullptr;
            --size_list;
            return true;
        } else {
            iter->previous->next = iter->next;
            iter->next->previous = iter->previous;
            delete iter;
            --size_list;
            return true;
        }
    } else {
        return false;
    }
}

template<typename T>
void List_v<T>::Show() {
    if (size_list != 0) {
        iter = head;
        while (iter != nullptr) {
            std::cout << iter->value << std::endl;
            iter = iter->next;
        }
    }
}

template<typename T>
HashTable<T>::HashTable(size_t size) {
    size_table = size;
    count = 0;
    hash_t = 0;
    list = new List_v<T>[size_table] {};
}

template<typename T>
HashTable<T>::~HashTable<T>() {
    clear();
    delete  [] list;
}

template<typename T>
bool HashTable<T>::insert_table(const T & t) {
    hash_t = hash(t) % size_table;
    if ((double)count / (double)size_table < proc) {
        list[hash_t].insert_list(t);
        ++count;
        return true;
    } else {
        std::cout << "The table is 70 percent complete" << std::endl;
        return false;
    }
}

template<typename T>
bool HashTable<T>::delet_table(const T & t) {
    hash_t = hash(t) % size_table;
    if (list[hash_t].delet_list(t)) {
        --count;
        return true;
    } else {
        return false;
    }
}

template<typename T>
bool HashTable<T>::search_table(const T &t) {
    hash_t = hash(t) % size_table;
    return list[hash_t].search_list(t);
}

template<typename T>
void HashTable<T>::clear() {
    for (size_t i = 0; i < size_table; ++i) {
        list[i].clear();
    }
}

template<typename T>
void HashTable<T>::Show() {
    for (size_t i = 0; i < size_table; ++i) {
        list[i].Show();
    }
}
