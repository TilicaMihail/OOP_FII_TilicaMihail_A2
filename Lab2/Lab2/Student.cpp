#include "Student.h"

void Student::SetName(const std::string& studentName) {
    name = studentName;
}

std::string Student::GetName() const {
    return name;
}

void Student::SetMathGrade(float grade) {
    if (grade >= 1.0f && grade <= 10.0f) {
        mathGrade = grade;
    }
}

float Student::GetMathGrade() const {
    return mathGrade;
}

void Student::SetEnglishGrade(float grade) {
    if (grade >= 1.0f && grade <= 10.0f) {
        englishGrade = grade;
    }
}

float Student::GetEnglishGrade() const {
    return englishGrade;
}

void Student::SetHistoryGrade(float grade) {
    if (grade >= 1.0f && grade <= 10.0f) {
        historyGrade = grade;
    }
}

float Student::GetHistoryGrade() const {
    return historyGrade;
}

float Student::GetAverageGrade() const {
    return (mathGrade + englishGrade + historyGrade) / 3.0f;
}

int Student::CompareNames(const Student& student1, const Student& student2) {
    if (student1.GetName() == student2.GetName()) {
        return 0;
    }
    return student1.GetName() > student2.GetName() ? 1 : -1;
}

int Student::CompareGrades(const Student& student1, const Student& student2) {
    float sum1 = student1.GetMathGrade() + student1.GetEnglishGrade() + student1.GetHistoryGrade();
    float sum2 = student2.GetMathGrade() + student2.GetEnglishGrade() + student2.GetHistoryGrade();

    if (sum1 == sum2) {
        return 0;
    }
    return sum1 > sum2 ? 1 : -1;
}

int Student::CompareAverage(const Student& student1, const Student& student2) {
    if (student1.GetAverageGrade() == student2.GetAverageGrade()) {
        return 0;
    }
    return student1.GetAverageGrade() > student2.GetAverageGrade() ? 1 : -1;
}
