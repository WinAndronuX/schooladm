#ifndef STUDENTS_H
#define STUDENTS_H

#include <string>
#include <vector>
#include <schooladm/subjects.hpp>

#ifdef _WIN32
#define clearConsole() system("cls")
#define REPORTS_USERS_DIR "..\\reports\\students.csv"
#define REPORTS_REPORT_DIR "..\\reports\\report.txt"
#else
#define clearConsole() system("clear")
#define REPORTS_USERS_DIR "./reports/students.csv"
#define REPORTS_REPORT_DIR "./reports/report.txt"
#endif

#define STUDENTS_DATA_FILE "data/students.csv"

using namespace std;

struct Student {
    string name;
    string lastName;
    long studentId;
    vector<Subject> Subjects;
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

vector<Student>& getStudentsVector();

void recalcAverage(Student &s);
void readStudents();
void writeStudents();

#endif
