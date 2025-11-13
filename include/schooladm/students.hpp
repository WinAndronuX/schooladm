#ifndef STUDENTS_H
#define STUDENTS_H

#include <string>
#include <vector>

#ifdef _WIN32
#define clearConsole() system("cls")
#define REPORTS_USERS_DIR "..\\reports\\students.csv"
#define REPORTS_REPORT_DIR "..\\reports\\report.txt"
#else
#define clearConsole() system("clear")
#define REPORTS_USERS_DIR "./reports/students.csv"
#define REPORTS_REPORT_DIR "./reports/report.txt"
#endif

using namespace std;

struct Student {
    string name;
    string lastName;
    long studentId;
    float grades[3];
    float average;
};

void addStudent();
void modifyStudent(long matricula);
void deleteStudent(long matricula);

void showStudent(long matricula);
void showFailedStudents();
void showApprovedStudents();
void showTopStudents();

float getGroupAverage();
float getStandardDeviation();

bool existStudent(long matricula);

vector<Student> getStudentsVector();

#endif
