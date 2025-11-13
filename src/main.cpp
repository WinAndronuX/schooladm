#include <iostream>
#include <string>
#include <vector>
#include <schooladm/students.hpp>
#include <schooladm/menu.hpp>
#include <schooladm/utils.hpp>
#include <schooladm/reports.hpp>
#include <schooladm/users.hpp>
#include <schooladm/login.hpp>

using namespace std;

void studentsMenu() {
    clearConsole();

    vector<Student> registros = getFileAsVector(REPORTS_USERS_DIR);
    string opcion;

    while (true)
    {
        cout << "=== MENU PRINCIPAL ===\n"
             << "1. Sistema\n"
             << "2. Funciones\n"
             << "3. Salir\n"
             << "Opcion: ";
        getline(cin, opcion);

        if (opcion == "1")
            systemMenu(registros);
        else if (opcion == "2")
            funcMenu(registros);
        else if (opcion == "3")
            break;
        else
        {
            cout << "Opcion invalida.\n";
        }
    }
}

int main() {

    usersInit();

    bool exit = false;
    while (!exit) {
        switch(login()) {
        default:
        case 0:
            exit = true;
            break;
        case 1:
            studentsMenu();
            break;
        case 2:
            adminMenu();
            break;
        }
    }

    return 0;
}
