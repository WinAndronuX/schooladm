#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include "students.hpp"

#ifdef _WIN32
#include <Windows.h>
#define clearConsole() system("cls")
#define sleepSec(s) Sleep(s * 100)
#define REPORTS_USERS_DIR "..\\reports\\students.csv"
#define REPORTS_REPORT_DIR "..\\reports\\report.txt"
#else
#include <unistd.h>
#define clearConsole() system("clear")
#define sleepSec(s) sleep(s)
#define REPORTS_USERS_DIR "./reports/students.csv"
#define REPORTS_REPORT_DIR "./reports/report.txt"
#endif

#define PROMPT "> "
#define COLOR_RED "\x1b[31m"
#define COLOR_RESET "\x1b[0m"

using namespace std;

long readLong(const string &msg);
float readFloat(const string &msg);

vector<Student> getFileAsVector(const string &nombreFichero);
void writeOnFile(const string &nombreFichero, const vector<Student> &registros);

int inputInt(string msg);
int inputInt(string msg, int min);
int inputInt(string msg, int min, int max);
string inputStr(string msg);

vector<string> split(string str, char p);

void printError(string str);

#endif
