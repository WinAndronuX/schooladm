#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <schooladm/menu.hpp>
#include <schooladm/students.hpp>
#include <schooladm/utils.hpp>
#include <schooladm/reports.hpp>

void systemMenu(vector<Student> &studentsVector)
{
    string option;
    while (true)
    {
        cout << "=== SISTEMA ===\n"
             << "1. Agregar alumno\n"
             << "2. Eliminar alumno\n"
             << "3. Modificar alumno\n"
             << "4. Volver\n"
             << "Opcion: ";
        getline(cin, option);

        if (option == "1")
        {
            addStudent(studentsVector);
            writeOnFile(REPORTS_USERS_DIR, studentsVector);
        }
        else if (option == "2")
        {
            long m = readLong("Matricula a eliminar: ");
            deleteStudent(studentsVector, m);
            writeOnFile(REPORTS_USERS_DIR, studentsVector);
        }
        else if (option == "3")
        {
            long m = readLong("Matricula a modificar: ");
            modifyStudent(studentsVector, m);
            writeOnFile(REPORTS_USERS_DIR, studentsVector);
        }
        else if (option == "4")
            return;
        else
        {
            cout << "Opcion invalida.\n";
        }
    }
}

void funcMenu(vector<Student> &studentsVector)
{
    string option;
    while (true)
    {
        cout << "=== FUNCIONES ===\n"
             << "1. Imprimir datos\n"
             << "2. Aprobados\n"
             << "3. Reprobados\n"
             << "4. Top 3\n"
             << "5. Generar reporte\n"
             << "6. Volver\n"
             << "Opcion: ";
        getline(cin, option);

        if (option == "1")
        {
            long m = readLong("Matricula: ");
            showStudent(studentsVector, m);
        }
        else if (option == "2")
        {
            showFailedStudents(studentsVector);
        }
        else if (option == "3")
        {
            showFailedStudents(studentsVector);
        }
        else if (option == "4")
        {
            showTopStudents(studentsVector);
        }
        else if (option == "5")
        {
            exportReport(studentsVector);
        }
        else if (option == "6")
            return;
        else
        {
            cout << "Opcion invalida.\n";
        }
    }
}