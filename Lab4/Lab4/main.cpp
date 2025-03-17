#include "Sort.h"
#include <iostream>

int main() {
    Sort s1(10, 1, 100); // Random values
    Sort s2 = { 5, 2, 9, 1, 8 }; // Initialization list
    std::vector<int> vec = { 4, 7, 1, 3, 9, 6 };
    Sort s3(vec, 4); // From vector, first 4 elements
    Sort s4("10,40,100,5,70"); // From string
    Sort s5(5, 15, 3, 8, 22, 7); // Variadic

    s1.Print();
    s1.InsertSort(true);
    s1.Print();

    s2.Print();
    s2.BubbleSort(false);
    s2.Print();

    s3.Print();
    s3.QuickSort(true);
    s3.Print();

    s4.Print();
    s4.InsertSort(false);
    s4.Print();

    s5.Print();
    s5.BubbleSort(true);
    s5.Print();

    return 0;
}