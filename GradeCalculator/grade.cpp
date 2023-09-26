#include "grade.h"
#include <iostream>
#include <vector>
#include <string>

Grade::Grade(){
    std::vector<int> grades;
}

void Grade::getLabs(){
    for (int i = 1 ; i<11 ; i++){
        int grade = 0;
        
        std::cout << "Enter your lab #" << i << " grade out of 5 points:\n";
        std::cin >> grade;

        while (grade < 1 || grade > 5){
            std::cout << "Invalid entry - must be from 0-5:\n";
            std::cin >> grade;
        }
        
        grades.push_back(grade);
    }
}

void Grade::getHomework(){
    for (int i = 1 ; i<6 ; i++){
        int grade = 0;
        
        std::cout << "Enter your Homework #" << i << " grade out of 100 points:\n";
        std::cin >> grade;

        while (grade < 1 || grade > 100){
            std::cout << "Invalid entry - must be from 0-100:\n";
            std::cin >> grade;
        }
        
        grades.push_back(grade);
    }
}

void Grade::getProject(){
    int grade = 0;
        
        std::cout << "Enter your project grade out of 350 points:\n";
        std::cin >> grade;

        while (grade < 1 || grade > 350){
            std::cout << "Invalid entry - must be from 0-350:\n";
            std::cin >> grade;
        }
        
        grades.push_back(grade);
}

void Grade::getFinal(){
    int grade = 0;
    
    std::cout << "Enter your final grade out 100 points\n";
    std::cin >> grade;

    while (grade < 1 || grade > 100){
        std::cout << "Invalid entry - must be from 0-100:\n";
        std::cin >> grade;
    }
    
    grades.push_back(grade);
}


void Grade::getMEC(){
    int grade = 0;
        
        std::cout << "Enter your MEC project grade grade out of 30 points:\n";
        std::cin >> grade;

        while (grade < 1 || grade > 30){
            std::cout << "Invalid entry - must be from 0-30:\n";
            std::cin >> grade;
        }
        
        grades.push_back(grade);
}

void Grade::calculateGrade(){
    double final_num = 0;
    std::string finalGrade = " ";
    for(int i = 1; i < 19; i++){
        final_num += grades[i];
    }
    final_num = final_num/1000;
    final_num = final_num * 100;

    if(final_num >= 93.0){
        finalGrade = "A";
    }
    else if(final_num >= 90.0 || final_num < 94.0){
        finalGrade = "A-";
    }
    else if(final_num >= 87.0 || final_num < 89.0){
        finalGrade = "B+";
    }
    else if(final_num >= 83.0 || final_num < 87.0){
        finalGrade = "B";
    }
    else if(final_num >= 80.0 || final_num < 83.0){
        finalGrade = "B-";
    }
    else if(final_num >= 77.0 || final_num < 80.0){
        finalGrade = "C+";
    }
    else if(final_num >= 73.0 || final_num < 77.0){
        finalGrade = "C";
    }
    else if(final_num >= 70.0 || final_num < 73.0){
        finalGrade = "C-";
    }
    else if(final_num >= 67.0 || final_num < 70.0){
        finalGrade = "D+";
    }
    else if(final_num >= 60.0 || final_num < 67.0){
        finalGrade = "D";
    }
    else {
        finalGrade = "F";
    }

    std::cout << "\nYour final grade is: " << finalGrade << std::endl;
    
}
