#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#ifndef NOBYTE
#define NOBYTE
#endif
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#define clearConsole() system("cls")
#define sleepSec(s) Sleep((s) * 1000)
#define REPORTS_REPORT_DIR "..\\reports\\report.txt"
#else
#include <unistd.h>
#define clearConsole() system("clear")
#define sleepSec(s) sleep(s)      
#define REPORTS_REPORT_DIR "./reports/report.txt"
#endif
#define PROMPT "> "
#define COLOR_RED "\x1b[31m"
#define COLOR_RESET "\x1b[0m"

long readLong(const std::string &msg);
float readFloat(const std::string &msg);

int inputInt(std::string msg);
int inputInt(std::string msg, int min);
int inputInt(std::string msg, int min, int max);
std::string inputStr(std::string msg);

std::vector<std::string> split(std::string str, char p);

void printError(std::string str);

#endif
