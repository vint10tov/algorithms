#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>

template <typename T>
void selection_sort(T * arr, int arr_size);

const int SIZE = 50;

int main() { 
    int arrs[SIZE];
    std::srand(time(0));
    for (size_t i = 0; i < SIZE; ++i) {
        arrs[i] = rand() % 10000;
        std::cout << arrs[i] << std::endl;
    }
    std::cout << "Sorted array" << std::endl;
    selection_sort(arrs, SIZE);
    for (size_t i = 0; i < SIZE; ++i)
        std::cout << arrs[i] << std::endl;
    return 0;
}

template <typename T>
void selection_sort(T * arr, int arr_size) {
    if (arr_size != 0 and arr_size != 1) {
        for (size_t i = 0; i < arr_size - 1; ++i) {
            size_t min_index = i;
            for (size_t j = i + 1; j < arr_size; ++j) {
                if (arr[j] < arr[min_index])
                    min_index = j;
            }
            if (min_index != i) {
                T temp = arr[i];
                arr[i] = arr[min_index];
                arr[min_index] = temp;
            }
        }
    }
}
