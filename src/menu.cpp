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

    while (true) {
        cout << "=== MENU PRINCIPAL ===\n\n"
             << "Elige una opcion:\n"
             << "\t1. Sistema\n"
             << "\t2. Funciones\n"
             << "\n"
             << "\t0. Regresar\n";

        switch (inputInt("", 0, 2)) {
        case 0:
            return;
            break;
        case 1:
            systemMenu();
            break;
        case 2:
            funcMenu();
            break;
        }
    }
}

void systemMenu() {
    clearConsole();

    while (true) {
        cout << "=== SISTEMA ===\n\n"
             << "Elige una opcion:\n"
             << "\t1. Agregar alumno\n"
             << "\t2. Eliminar alumno\n"
             << "\t3. Modificar alumno\n\n"
             << "\t0. Volver";

        switch (inputInt("", 0, 3)) {
        case 0:
            return;
            break;
        case 1:
            addStudent();
            writeOnFile(REPORTS_USERS_DIR, getStudentsVector());
        case 2:
            deleteStudent(inputInt("Matricula a eliminar: ", 0));
            writeOnFile(REPORTS_USERS_DIR, getStudentsVector());
        case 3:
            modifyStudent(inputInt("Matricula a modificar: ", 0));
            writeOnFile(REPORTS_USERS_DIR, getStudentsVector());
        }
    }
}

void funcMenu() {
    while (true) {
        cout << "=== FUNCIONES ===\n\n"
             << "Elige una opcion:"
             << "\t1. Imprimir datos\n"
             << "\t2. Aprobados\n"
             << "\t3. Reprobados\n"
             << "\t4. Top 3\n"
             << "\t5. Generar reporte\n\n"
             << "\t0. Volver";

        switch (inputInt("", 0, 5)) {
        case 0:
            return;
            break;
        case 1:
            showStudent(inputInt("Matricula: ", 0));
            break;
        case 2:
            showApprovedStudents();
            break;
        case 3:
            showFailedStudents();
            break;
        case 4:
            showTopStudents();
            break;
        case 5:
            exportReport(getStudentsVector());
            break;
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
