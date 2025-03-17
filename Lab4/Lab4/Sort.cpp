//#include "Sort.h"
//#include <iostream>
//#include <cstdlib>
//#include <cstdarg>
//#include <sstream>
//
//Sort::Sort(int numElements, int minValue, int maxValue) {
//    data.resize(numElements);
//    for (int& num : data) {
//        num = minValue + rand() % (maxValue - minValue + 1);
//    }
//}
//
//Sort::Sort(std::initializer_list<int> list) : data(list) {}
//
//Sort::Sort(const std::vector<int>& vec, int count) {
//    data.assign(vec.begin(), vec.begin() + count);
//}
//
//Sort::Sort(int count, ...) {
//    va_list args;
//    va_start(args, count);
//    for (int i = 0; i < count; i++) {
//        data.push_back(va_arg(args, int));
//    }
//    va_end(args);
//}
//
//Sort::Sort(const char* numbers) {
//    std::stringstream ss(numbers);
//    std::string item;
//    while (std::getline(ss, item, ',')) {
//        data.push_back(std::stoi(item));
//    }
//}
//
//void Sort::InsertSort(bool ascendent) {
//    for (size_t i = 1; i < data.size(); i++) {
//        int key = data[i];
//        int j = i - 1;
//        while (j >= 0 && ((ascendent && data[j] > key) || (!ascendent && data[j] < key))) {
//            data[j + 1] = data[j];
//            j--;
//        }
//        data[j + 1] = key;
//    }
//}
//
//void Sort::BubbleSort(bool ascendent) {
//    for (size_t i = 0; i < data.size() - 1; i++) {
//        for (size_t j = 0; j < data.size() - i - 1; j++) {
//            if ((ascendent && data[j] > data[j + 1]) || (!ascendent && data[j] < data[j + 1])) {
//                std::swap(data[j], data[j + 1]);
//            }
//        }
//    }
//}
//
//void Sort::QuickSort(bool ascendent) {
//    QuickSortHelper(0, data.size() - 1, ascendent);
//}
//
//void Sort::QuickSortHelper(int low, int high, bool ascendent) {
//    if (low < high) {
//        int pivot = Partition(low, high, ascendent);
//        QuickSortHelper(low, pivot - 1, ascendent);
//        QuickSortHelper(pivot + 1, high, ascendent);
//    }
//}
//
//int Sort::Partition(int low, int high, bool ascendent) {
//    int pivot = data[high];
//    int i = low - 1;
//    for (int j = low; j < high; j++) {
//        if ((ascendent && data[j] < pivot) || (!ascendent && data[j] > pivot)) {
//            std::swap(data[++i], data[j]);
//        }
//    }
//    std::swap(data[i + 1], data[high]);
//    return i + 1;
//}
//
//void Sort::Print() const {
//    for (int num : data) {
//        std::cout << num << " ";
//    }
//    std::cout << std::endl;
//}
//
//int Sort::GetElementsCount() const {
//    return data.size();
//}
//
//int Sort::GetElementFromIndex(int index) const {
//    if (index >= 0 && index < data.size()) {
//        return data[index];
//    }
//    return -1; 
//}

#include "Sort.h"
#include <iostream>
#include <stdlib.h>   
#include <stdarg.h>
#include <time.h>  

Sort::~Sort() {
    delete[] data;  
}

Sort::Sort(int numElements, int minValue, int maxValue) {
    this->numElements = numElements;
    this->data = new int[numElements];
    for (int i = 0; i < numElements; i ++) {
        this->data[i] = minValue + rand() % (maxValue - minValue + 1);
    }
}

Sort::Sort(std::initializer_list<int> list) {
    numElements = list.size();  
    this->data = new int[numElements];  

    int i = 0;
    for (int value : list) {
        this->data[i] = value, 
        i ++;  
    }
}

Sort::Sort(const std::vector<int>& vec, int count) {
    numElements = count;
    data = new int[count];  

    for (int i = 0; i < count; i++) {
        data[i] = vec[i];  
    }
}

Sort::Sort(int count, ...) {
    va_list args;
    va_start(args, count);
    numElements = count;
    this->data = new int[count];
    for (int i = 0; i < count; i++) {
        this->data[i] = va_arg(args, int);
    }
    va_end(args);
}

Sort::Sort(const char* numbers) {
    std::vector<int> nums;
    int num = 0, count = 0;
    for (int i = 0; numbers != nullptr && numbers[i] != '\0'; i++) {
        if (numbers[i] - '0' <= 9 && numbers[i] - '0' >= 0)
            num = num * 10 + numbers[i] - '0';
        else
            nums.push_back(num),
            count ++,
            num = 0;
    }
    nums.push_back(num),
    count ++;
    numElements = count;
    data = new int[count];
    for (int i = 0; i < count; i++)
        data[i] = nums[i];
}

void Sort::InsertSort(bool ascendent) {
    for (size_t i = 1; i < numElements; i++) {
        int key = data[i];
        int j = i - 1;
        while (j >= 0 && ((ascendent && data[j] > key) || (!ascendent && data[j] < key))) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

void Sort::BubbleSort(bool ascendent) {
    for (size_t i = 0; i < numElements - 1; i++) {
        for (size_t j = 0; j < numElements - i - 1; j++) {
            if ((ascendent && data[j] > data[j + 1]) || (!ascendent && data[j] < data[j + 1])) {
                std::swap(data[j], data[j + 1]);
            }
        }
    }
}

void Sort::QuickSort(bool ascendent) {
    QuickSortHelper(0, numElements - 1, ascendent);
}

void Sort::QuickSortHelper(int low, int high, bool ascendent) {
    if (low < high) {
        int pivot = Partition(low, high, ascendent);
        QuickSortHelper(low, pivot - 1, ascendent);
        QuickSortHelper(pivot + 1, high, ascendent);
    }
}

int Sort::Partition(int low, int high, bool ascendent) {
    int pivot = data[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if ((ascendent && data[j] < pivot) || (!ascendent && data[j] > pivot)) {
            std::swap(data[++i], data[j]);
        }
    }
    std::swap(data[i + 1], data[high]);
    return i + 1;
}

void Sort::Print() const {
    for (int i = 0; i < numElements; i ++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

int Sort::GetElementsCount() const {
    return numElements;
}

int Sort::GetElementFromIndex(int index) const {
    if (index >= 0 && index < numElements) {
        return data[index];
    }
    return -1;
}

