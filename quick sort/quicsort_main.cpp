#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <ctime>

template <typename T>
void quicsort(T * arr, int left, int right);

const int SIZE = 100;

int main () {
    int arrs[SIZE];
    std::srand(time(0));
    for (size_t i = 0; i < SIZE; ++i) {
        arrs[i] = rand() % 10000;
    std::cout << arrs[i] << "\t";
    }
    std::cout << std::endl;
    std::cout << "Sorted array" << std::endl;
    quicsort(arrs, 0, SIZE - 1);
    for (size_t i = 0; i < SIZE; ++i)
        std::cout << arrs[i] << "\t";
    std::cout << std::endl;
    return 0;
}

template <typename T>
void quicsort(T * arr, int left, int right) { //функция принимает указатель на массив и левую и правую границу сортировки
    if (left < right) {
        T pointer_value = arr[(left + right) / 2]; //находим значение опорного элемента (средний)
        int i = left;
        int j = right;
        while (i <= j) {
            while (arr[i] < pointer_value) //пока не найдем элемент больший или равный опорному будем перемещать индекс начала в право
                ++i;
            while (arr[j] > pointer_value) //пока не найдем элемент меньший или равный опорному будем перемещать индекс конца в лево
                --j;
            if (i <= j) {
                T temp = arr[i]; //поменяем местами элементы с индексами i и j
                arr[i] = arr[j];
                arr[j] = temp;
                ++i; 
                --j; // продвиним индексы ещё на шаг
            }
        }
        quicsort(arr, left, j); // вызываем функцию рекурсивно для двух полученных массивов
        quicsort(arr, i, right);
    }
}
