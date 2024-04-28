#include <iostream>

template <typename T>
int binary_search(const T * arr, int array_size, T search_element);
const int ARR = 100;

int main() {
    int temp;
    std::cout << "Enter: ";
    std::cin >> temp;
    int arrs[ARR];
    arrs[0] = 1;
    for (int i = 1; i < ARR; ++i)
        arrs[i] = arrs[i - 1] + 3;
    std::cout << binary_search(arrs, ARR, temp) << std::endl;
    return 0;
}

template <typename T>
int binary_search(const T * arr, int array_size, T search_element) {
    int start = 0;
    int stop = array_size - 1;
    while (start <= stop) {
        int pointer = start + (stop - start) / 2;
        if (arr[pointer] == search_element)
            return pointer;
        else if (arr[pointer] < search_element)
            start = pointer + 1;
        else 
            stop = pointer - 1;
    }
    return -1;
}
