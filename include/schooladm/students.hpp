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

struct Student
{
    string name;
    string lastName;
    long studentId;
    float grades[3];
    float average;
};

void addStudent(vector<Student> &registros);
void modifyStudent(vector<Student> &registros, long matricula);
void deleteStudent(vector<Student> &registros, long matricula);

void showStudent(const vector<Student> &registros, long matricula);
void showFailedStudents(const vector<Student> &registros);
void showApprovedStudents(const vector<Student> &registros);
void showTopStudents(const vector<Student> &registros);

float getGroupAverage(const vector<Student> &registros);
float getStandardDeviation(const vector<Student> &registros);

#endif