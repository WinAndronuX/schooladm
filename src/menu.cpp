#include <schooladm/utils.hpp>
#include <iostream>
#include <string>
#include <schooladm/menu.hpp>
#include <schooladm/students.hpp>

#include <schooladm/reports.hpp>
#include <schooladm/users.hpp>
#include <schooladm/subjects.hpp>

using namespace std;

void studentsMenu(int studentId) {

    clearConsole();

    cout <<
    "=== Menu Alumnos ===\n";

    while (true) {
        cout <<
        "\nElige una opcion:\n"
        "\t1) Mi informacion\n"
        "\t2) Kardex\n\n"
        "\t0) Salir\n";

        int opc = inputInt("", 0, 2);

        switch (opc) {
        case 0:
            return;
            break;
        case 1:
            showStudent(studentId);
            break;
        case 2:
            printKardex(studentId);
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
    "\t3 ) Reportes\n"
    "\t4 ) Usuarios\n"
    "\n"
    "\t0 ) Salir";

    opc = inputInt("", 0, 4);

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
        goto REPORTS;
        break;
    case 4:
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
            showSubjects();
            break;
        case 2:
            addSubject();
            break;
        case 3:
            modSubject();
            break;
        case 4:
            delSubject();
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
        "\t2 ) Agregar alumno\n"
        "\t3 ) Modificar alumno\n"
        "\t4 ) Eliminar alumno\n"
        "\t5 ) Subir calificiones\n"
        "\n"
        "\t0 ) Regresar";

        opc = inputInt("", 0, 5);

        switch (opc) {
        case 0:
            goto START;
            break;
        case 1:
            showStudents();
            break;
        case 2:
            addStudent();
            break;
        case 3:
            modifyStudent(inputInt("Matricula a modificar: ", 0));
            break;
        case 4:
            deleteStudent(inputInt("Matricula a eliminar: ", 0));
            break;
        }
    }
REPORTS:
    clearConsole();

    cout << "=== Reportes ===\n\n";

    while (true) {
        cout <<
        "Elige una opcion:\n"
        "\t1 ) Alumnos Aprobados\n"
        "\t2 ) Alumnos Reprobados\n"
        "\t3 ) Top 3 Alumnos\n"
        "\t4 ) Exportar reporte\n\n"
        "\t0 ) Regresar";

        opc = inputInt("", 0, 4);

        switch (opc) {
        case 0:
            goto START;
            break;
        case 1:
            showApprovedStudents();
            break;
        case 2:
            showFailedStudents();
            break;
        case 3:
            showTopStudents();
            break;
        case 4:
            exportReport(getStudentsVector());
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
