#include <cstdio>
#include "MyVector.h"

static float operator"" _Kelvin(unsigned long long k) {
    return static_cast<float>(k - 273.15);
}

static float operator"" _Fahrenheit(unsigned long long f) {
    return static_cast<float>((f - 32) * 5 / 9);
}

int main() {
    // Testing user-defined literals
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    printf("300 Kelvin in Celsius: %f\n", a);
    printf("120 Fahrenheit in Celsius: %f\n", b);

    // Create a MyVector object
    MyVector<int> vec;

    // Test push and count methods
    vec.push(3);
    vec.push(1);
    vec.push(2);
    printf("Vector after push operations (count: %u): ", vec.count());
    for (int i = 0; i < vec.count(); ++i) {
        printf("%d ", vec.get(i));
    }
    printf("\n");

    // Test remove method
    vec.remove(1); // Removes element at index 1 (value 1)
    printf("Vector after removing index 1 (count: %u): ", vec.count());
    for (int i = 0; i < vec.count(); ++i) {
        printf("%d ", vec.get(i));
    }
    printf("\n");

    // Test insert method
    vec.insert(1, 99); // Insert 99 at index 1
    printf("Vector after inserting 99 at index 1 (count: %u): ", vec.count());
    for (int i = 0; i < vec.count(); ++i) {
        printf("%d ", vec.get(i));
    }
    printf("\n");

    // Test pop method
    int poppedValue = vec.pop();
    printf("Popped value: %d\n", poppedValue);
    printf("Vector after pop (count: %u): ", vec.count());
    for (int i = 0; i < vec.count(); ++i) {
        printf("%d ", vec.get(i));
    }
    printf("\n");

    // Test sort method
    vec.push(5);
    vec.push(4);
    vec.push(6);
    vec.sort();
    printf("Vector after adding 5, 4, 6, and sorting: ");
    for (int i = 0; i < vec.count(); ++i) {
        printf("%d ", vec.get(i));
    }
    printf("\n");

    // Test firstIndexOf method
    int index = vec.firstIndexOf(5);
    printf("Index of value 5: %d\n", index);

    // Test set method
    vec.set(0, 100); // Set value at index 0 to 100
    printf("Vector after setting index 0 to 100: ");
    for (int i = 0; i < vec.count(); ++i) {
        printf("%d ", vec.get(i));
    }
    printf("\n");

    return 0;
}
