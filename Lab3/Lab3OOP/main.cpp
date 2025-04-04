//#include <iostream>
//#include "Math.h"
//
//int main()
//{
//    // Integer operations
//    std::cout << "Add(3, 4): " << Math::Add(3, 4) << std::endl;
//    std::cout << "Add(3, 4, 5): " << Math::Add(3, 4, 5) << std::endl;
//
//    std::cout << "Mul(3, 4): " << Math::Mul(3, 4) << std::endl;
//    std::cout << "Mul(3, 4, 5): " << Math::Mul(3, 4, 5) << std::endl;
//
//    // Double operations
//    std::cout << "Add(3.5, 4.2): " << Math::Add(3.5, 4.2) << std::endl;
//    std::cout << "Add(3.5, 4.2, 5.1): " << Math::Add(3.5, 4.2, 5.1) << std::endl;
//
//    std::cout << "Mul(3.5, 4.2): " << Math::Mul(3.5, 4.2) << std::endl;
//    std::cout << "Mul(3.5, 4.2, 5.1): " << Math::Mul(3.5, 4.2, 5.1) << std::endl;
//
//    // Variadic function
//    std::cout << "Add(5 numbers: 1, 2, 3, 4, 5): " << Math::Add(5, 1, 2, 3, 4, 5) << std::endl;
//
//    // String concatenation
//    const char* str1 = "Hello, ";
//    const char* str2 = "World!";
//
//    char* result = Math::Add(str1, str2);
//    if (result)
//    {
//        std::cout << "Concatenated string: " << result << std::endl;
//        free(result); // Free allocated memory
//    }
//    else
//    {
//        std::cout << "String concatenation failed (nullptr detected)" << std::endl;
//    }
//
//    return 0;
//}

#include <iostream>
#include "Canvas.h"

int main()
{
    Canvas canvas(40, 40);

   /* canvas.DrawLine(2, 2, 30, 10, '*');*/
    /*canvas.DrawRect(5, 5, 15, 12, '#');
    canvas.FillRect(18, 6, 28, 10, '@');*/
    canvas.DrawCircle(20, 10, 8, 'O');
    //canvas.FillCircle(30, 15, 3, '+');

    canvas.Print();

    return 0;
}

