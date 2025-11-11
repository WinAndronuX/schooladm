#include "../include/schooladm/utilidades.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<Registro> registros = leerFichero("..\\reportes\\alumnos.csv");
    string opcion;

    while (true)
    {
        system("cls");
        cout << "=== MENU PRINCIPAL ===\n"
             << "1. Sistema\n"
             << "2. Funciones\n"
             << "3. Salir\n"
             << "Opcion: ";
        getline(cin, opcion);

        if (opcion == "1")
            menuSistema(registros);
        else if (opcion == "2")
            menuFunciones(registros);
        else if (opcion == "3")
            break;
        else
        {
            cout << "Opcion invalida.\n";
            system("pause");
        }
    }

    system("pause");
    return 0;
}