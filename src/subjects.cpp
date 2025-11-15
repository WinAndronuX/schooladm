#include <schooladm/utils.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <schooladm/menu.hpp>
#include <schooladm/students.hpp>

#include <schooladm/reports.hpp>
#include <schooladm/users.hpp>

using namespace std;

void addSubject (){
    clearConsole();
    string fieldMenu =
                        "SELECCIONE EL AREA CORRESPONDIENTE A LA ASIGNATURA"
                        "\n"
                        "Opciones:\n"
                        "\t1) Ciencias\n"
                        "\t2) Humanidades\n"
                        "\t3) Artes\n"
                        "\t4) Idiomas\n";
    Subject newSubject;
    cout<<"ingrese el nombre de la asignatura: ";
    getline(cin,newSubject.subjectName);
    int op;
    do{
        cout<<fieldMenu<<endl;
        op = inputInt("opcion: ");
        switch (op) {
        case 1: newSubject.field = 1; break;
        case 2: newSubject.field = 2; break;
        case 3: newSubject.field = 3; break;
        case 4: newSubject.field = 4; break;
        default:
            cout << "Opción inválida.\n";
            break;
        }
    }while(op > 4 || op < 1);
    readStudents();
    for (Student& s : getStudentsVector()) {
        cout << "Ingrese la calificacion para el alumno: " << s.name<<" "<<s.lastName<< "\n";
        float cal = readFloat("");
        Subject subj = newSubject;
        subj.grade = cal;
        s.Subjects.push_back(subj);
        recalcAverage(s);
    }
    writeStudents();
}

void modSubject() {
    string subjectName;
    cout << "ASIGNATURA A MODIFICAR: ";
    getline(cin, subjectName);
    readStudents();
    bool found = false;
    string newName;
    int newField = 0;
    for (auto &st : getStudentsVector()) {
        for (auto &sub : st.Subjects) {
            if (sub.subjectName == subjectName) {
                found = true;
                cout << "Nuevo nombre (enter = igual): ";
                getline(cin, newName);
                if (newName.empty()) newName = sub.subjectName;
                cout << "Nueva área (1-4, 0 = igual): ";
                newField = inputInt("> ");
                if (newField == 0) newField = sub.field;
                goto APPLY;
            }
        }
    }
APPLY:
    if (!found) {
        cout << "No se encontro la Asignatura.\n";
        return;
    }
    for (auto &st : getStudentsVector()) {
        for (auto &sub : st.Subjects) {
            if (sub.subjectName == subjectName) {
                sub.subjectName = newName;
                sub.field = newField;
                recalcAverage(st);
            }
        }
    }
    writeStudents();
    cout << "Modificación aplicada.\n";
}

void delSubject() {
    string subjectName;
    cout << "ASIGNATURA A ELIMINAR: ";
    getline(cin, subjectName);
    readStudents();
    bool found = false;
    for (auto &st : getStudentsVector()) {
        auto &subs = st.Subjects;
        for (size_t i = 0; i < subs.size(); ) {
            if (subs[i].subjectName == subjectName) {
                subs.erase(subs.begin() + i);
                recalcAverage(st);
                found = true;
            } else {
                i++;
            }
        }
    }
    if (!found) {
        cout << "No se encontró la asignatura.\n";
        return;
    }
    writeStudents();
    cout << "Asignatura eliminada de todos los estudiantes.\n";
}

string areaName(int field) {
    switch (field) {
        case 1: return "Ciencias";
        case 2: return "Humanidades";
        case 3: return "Artes";
        case 4: return "Idiomas";
    }
}

void showSubjects() {
    readStudents(); 

    cout << "Materias REGISTRADAS\n";

    for (const Student &sd : getStudentsVector()) {
        for (const Subject &sub : sd.Subjects) {
            cout << "- " << sub.subjectName << " Area: " << areaName(sub.field) << "\n";
        }
        break;
    }
}
