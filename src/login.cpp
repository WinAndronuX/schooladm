#include <iostream>
#include <schooladm/login.hpp>
#include <schooladm/utils.hpp>
#include <schooladm/users.hpp>
#include <stdexcept>
#include <string>


using namespace std;

static const string loginMsg =
"***************************\n"
"*         SIASE 2         *\n"
"***************************\n"
"\n"
"Opciones:\n"
"\t1 ) Alumnos\n"
"\t2 ) Profesores\n"
"\n"
"\t0 ) Salir";

int login() {
    clearConsole();

    cout << loginMsg;

    int opc = inputInt("", 0, 2);

    switch (opc) {
        case 0:
            cout << "Adios..." << endl;
            break;
        case 1: {
            int i = 0;

            do {
                int studentId = inputInt("Matricula: ", 1);

                // Logica para ver que exista el alumno
                return 1;

            } while(i < 3);

            break;
        }
        case 2: {
            int i = 0;

            do {
                int userId = inputInt("ID: ", 1);
                string passwd = inputStr("Contraseña: ");

                try {
                    if (usersCheckPasswd(userId, passwd))
                        return 2;

                    printError("Credenciales Incorrectas");
                } catch (runtime_error &e) {
                    printError(e.what());
                }

                i++;
            } while (i < 3);

            cout << "Espere 3 segundos" << endl;
            sleepSec(3);
            login();

            break;
        }
    }

    return 0;
}
