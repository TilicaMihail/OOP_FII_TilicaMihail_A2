#pragma once
#include <string>

class Student {
private:
    std::string name;
    float mathGrade;
    float englishGrade;
    float historyGrade;

public:
    void SetName(const std::string& studentName);
    std::string GetName() const;

    void SetMathGrade(float grade);
    float GetMathGrade() const;

    void SetEnglishGrade(float grade);
    float GetEnglishGrade() const;

    void SetHistoryGrade(float grade);
    float GetHistoryGrade() const;

    float GetAverageGrade() const;

    static int CompareNames(const Student& student1, const Student& student2);
    static int CompareGrades(const Student& student1, const Student& student2);
    static int CompareAverage(const Student& student1, const Student& student2);
};



