//#pragma once
//#include <vector>
//#include <string>
//
//class Sort {
//private:
//    std::vector<int> data;
//    void QuickSortHelper(int low, int high, bool ascendent);
//    int Partition(int low, int high, bool ascendent);
//public:
//    
//    Sort(int numElements, int minValue, int maxValue);
//    Sort(std::initializer_list<int> list);
//    Sort(const std::vector<int>& vec, int count);
//    Sort(const char* numbers);
//    Sort(int count, ...); 
//
//    void InsertSort(bool ascendent = false);
//    void QuickSort(bool ascendent = false);
//    void BubbleSort(bool ascendent = false);
//
//    void Print() const;
//    int GetElementsCount() const;
//    int GetElementFromIndex(int index) const;
//};


#pragma once
#include <vector>

class Sort {
private:
    int* data = nullptr;
    int numElements = 0;
    void QuickSortHelper(int low, int high, bool ascendent);
    int Partition(int low, int high, bool ascendent);
public:

    Sort(int numElements, int minValue, int maxValue);
    Sort(std::initializer_list<int> list);
    Sort(const std::vector<int>& vec, int count);
    Sort(const char* numbers);
    Sort(int count, ...);

    ~Sort();

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);

    void Print() const;
    int GetElementsCount() const;
    int GetElementFromIndex(int index) const;
};
