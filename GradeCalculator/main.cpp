#include "grade.h"

int main(int argc, char*argv[]) {
    Grade gradeBook = Grade();
    gradeBook.getLabs();
    gradeBook.getHomework();
    gradeBook.getFinal();
    gradeBook.getProject();
    gradeBook.getMEC();
    gradeBook.calculateGrade();
}