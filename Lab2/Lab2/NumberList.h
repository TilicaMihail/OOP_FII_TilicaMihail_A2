#pragma once
class NumberList {
private:
    int numbers[10];
    int count;

public:
    void Init();             // Initializes the count to 0
    bool Add(int x);         // Adds x to the numbers array and increments count
    void Sort();             // Sorts the numbers array
    void Print();            // Prints the numbers array
};

