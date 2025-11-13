#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include "students.hpp"

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

long readLong(const string &msg);
float readFloat(const string &msg);

vector<Student> getFileAsVector(const string &nombreFichero);
void writeOnFile(const string &nombreFichero, const vector<Student> &registros);

#endif