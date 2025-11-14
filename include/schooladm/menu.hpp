#ifndef MENU_H
#define MENU_H

#ifdef _WIN32
#define clearConsole() system("cls")
#define REPORTS_USERS_DIR "..\\reports\\students.csv"
#define REPORTS_REPORT_DIR "..\\reports\\report.txt"
#else
#define clearConsole() system("clear")
#define REPORTS_USERS_DIR "./reports/students.csv"
#define REPORTS_REPORT_DIR "./reports/report.txt"
#endif


void studentsMenu(int studentId);
void adminMenu();

#endif
