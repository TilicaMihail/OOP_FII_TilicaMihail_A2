//#include <iostream>
//#include "NumberList.h"
//
//int main() {
//    NumberList list;
//    list.Init();
//
//    list.Add(5);
//    list.Add(2);
//    list.Add(8);
//    list.Add(1);
//
//    std::cout << "Before sorting: ";
//    list.Print();
//
//    list.Sort();
//
//    std::cout << "After sorting: ";
//    list.Print();
//
//    return 0;
//}

#include <iostream>
#include "Student.h"

int main() {
    Student student1, student2;

    student1.SetName("Alice");
    student1.SetMathGrade(9.0f);
    student1.SetEnglishGrade(8.5f);
    student1.SetHistoryGrade(9.5f);

    student2.SetName("Bob");
    student2.SetMathGrade(8.0f);
    student2.SetEnglishGrade(7.5f);
    student2.SetHistoryGrade(8.0f);

    std::cout << "Student 1: " << student1.GetName() << " Average Grade: " << student1.GetAverageGrade() << std::endl;
    std::cout << "Student 2: " << student2.GetName() << " Average Grade: " << student2.GetAverageGrade() << std::endl;

    int nameComparison = Student::CompareNames(student1, student2);
    int gradeComparison = Student::CompareGrades(student1, student2);
    int averageComparison = Student::CompareAverage(student1, student2);

    std::cout << "Name comparison: " << nameComparison << std::endl;
    std::cout << "Grade comparison: " << gradeComparison << std::endl;
    std::cout << "Average comparison: " << averageComparison << std::endl;

    return 0;
}

