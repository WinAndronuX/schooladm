#ifndef REPORTS_H
#define REPORTS_H

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

void exportReport(const vector<Student> &registros);

#endif