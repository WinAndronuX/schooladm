#include <iostream>
#include <schooladm/students.hpp>
#include <schooladm/menu.hpp>
#include <schooladm/utils.hpp>
#include <schooladm/reports.hpp>
#include <schooladm/users.hpp>
#include <schooladm/login.hpp>

using namespace std;

int main() {
    usersInit();
    readStudents();

    bool exit = false;
    while (!exit) {
        int opc = login();
        switch(opc) {
        case 0:
            exit = true;
            break;
        case 1:
            studentsMenu(actualStudentId);
            break;
        case 2:
            adminMenu();
            break;
        default:
            cout << "Opcion invalida: " << opc << endl;
        }
    }

    return 0;
}
