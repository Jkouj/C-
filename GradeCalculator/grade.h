#pragma once
#include <iostream>
#include <vector>

class Grade {
private:
    std::vector<int> grades;

public:
    Grade();
    void getLabs();
    void getHomework();
    void getProject();
    void getFinal();
    void getMEC();
    void calculateGrade();
};
 
