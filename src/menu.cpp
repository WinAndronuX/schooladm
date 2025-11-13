#include <iostream>
#include <vector>
#include <string>
#include <schooladm/menu.hpp>
#include <schooladm/students.hpp>
#include <schooladm/utils.hpp>
#include <schooladm/reports.hpp>
#include <schooladm/users.hpp>

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

void systemMenu(vector<Student> &)
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
            addStudent();
            writeOnFile(REPORTS_USERS_DIR, getStudentsVector());
        }
        else if (option == "2")
        {
            long m = readLong("Matricula a eliminar: ");
            deleteStudent(m);
            writeOnFile(REPORTS_USERS_DIR, getStudentsVector());
        }
        else if (option == "3")
        {
            long m = readLong("Matricula a modificar: ");
            modifyStudent(m);
            writeOnFile(REPORTS_USERS_DIR, getStudentsVector());
        }
        else if (option == "4")
            return;
        else
        {
            cout << "Opcion invalida.\n";
        }
    }
}

void funcMenu(vector<Student> &)
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
            showStudent( m);
        }
        else if (option == "2")
        {
            showApprovedStudents();
        }
        else if (option == "3")
        {
            showFailedStudents();
        }
        else if (option == "4")
        {
            showTopStudents();
        }
        else if (option == "5")
        {
            exportReport(getStudentsVector());
        }
        else if (option == "6")
            return;
        else
        {
            cout << "Opcion invalida.\n";
        }
    }
}

void adminMenu() {

    int opc;

START:
    clearConsole();

    cout <<
    "=== Menu Administrativo ===\n"
    "\n"
    "Elige una opcion:\n"
    "\t1 ) Materias\n"
    "\t2 ) Alumnos\n"
    "\t3 ) Usuarios\n"
    "\n"
    "\t0 ) Salir";

    opc = inputInt("", 0, 3);

    switch (opc) {
    case 0:
        return;
        break;
    case 1:
        goto COURSES;
        break;
    case 2:
        goto STUDENTS;
        break;
    case 3:
        goto USERS;
        break;
    }
COURSES:
    clearConsole();

    cout << "=== Materias ===\n";

    while (true) {
        cout <<
        "\nElige una opcion:\n"
        "\t1 ) Ver materias\n"
        "\t2 ) Crear materia\n"
        "\t3 ) Editar materia\n"
        "\t4 ) Borrar materia\n"
        "\n"
        "\t0 ) Regresar";

        opc = inputInt("", 0, 4);

        switch (opc) {
        case 0:
            goto START;
            break;
        case 1:
            // func
            break;
        case 2:
            // func
            break;
        case 3:
            // func
            break;
        case 4:
            // func
            break;
        }
    }
STUDENTS:
    clearConsole();

    cout << "=== Alumnos ===\n";

    while (true) {
        cout <<
        "\nElige una opcion:\n"
        "\t1 ) Ver alumnos\n"
        "\t2 ) Registrar alumno\n"
        "\t3 ) Dar de baja alumno\n"
        "\t4 ) Subir calificiones\n"
        "\n"
        "\t0 ) Regresar";

        opc = inputInt("", 0, 4);

        switch (opc) {
        case 0:
            goto START;
            break;
        case 1:
            // func
            break;
        case 2:
            // func
            break;
        case 3:
            // func
            break;
        case 4:
            // func
            break;
        }
    }
USERS:
    clearConsole();

    cout << "=== Usuaios ===\n";

    while (true) {
        cout <<
        "\nElige una opcion:\n"
        "\t1 ) Ver usuarios\n"
        "\t2 ) Crear usuario\n"
        "\t3 ) Cambiar contraseña\n"
        "\t4 ) Borrar usuario\n"
        "\n"
        "\t0 ) Regresar";

        opc = inputInt("", 0, 4);

        switch (opc) {
        case 0:
            goto START;
            break;
        case 1:
            usersPrint();
            break;
        case 2:
            usersAdd();
            break;
        case 3:
            usersChangePasswd();
            break;
        case 4:
            usersDelete();
            break;
        }
    }
}
