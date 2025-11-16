#include <schooladm/utils.hpp>
#include "listview/listview.h"
#include "schooladm/subjects.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <schooladm/students.hpp>
#include <filesystem>
#include <set>

using namespace std;

vector<Student> studentsVector;

static int getStudentIndexByStudentId(const int studentId) {

    for (int i = 0; i < studentsVector.size(); i++)
        if (studentsVector[i].studentId == studentId)
            return i;

    return -1;
}

void readStudents() {
    studentsVector.clear();
    ifstream file(STUDENTS_DATA_FILE);
    if (!file.is_open()) return;
    string line;
    while (getline(file, line)) {
        vector<string> data = split(line, ',');
        if (data.size() < 5) continue;
        Student st;
        st.studentId = stol(data[0]);
        st.name = data[1];
        st.lastName = data[2];
        st.average = stof(data[4]);
        if (!data[3].empty()) {
            vector<string> subjects = split(data[3], '|');
            for (const string &subject : subjects) {
                vector<string> value = split(subject, ':');
                if (value.size() == 3)
                    st.Subjects.push_back({value[0], stof(value[1]), stoi(value[2])});
            }
        }
        studentsVector.push_back(st);
    }
    file.close();
}

void writeStudents() {
    filesystem::create_directories(filesystem::path(STUDENTS_DATA_FILE).parent_path());
    ofstream file(STUDENTS_DATA_FILE);
    if (!file.is_open())
        throw runtime_error("Error. No se pudo escribir el archivo data/students.csv");
    for (const Student &st : studentsVector) {
        file << st.studentId << "," << st.name << "," << st.lastName << ",";
        for (size_t i = 0; i < st.Subjects.size(); ++i) {
            file << st.Subjects[i].subjectName << ":" << st.Subjects[i].grade << ":" << st.Subjects[i].field;
            if (i < st.Subjects.size() - 1) file << "|";
        }
        file << "," << st.average << "\n";
    }
    file.close();
}

void recalcAverage(Student &s) {
    if (s.Subjects.empty()) { s.average = 0; return; }
    float sum = 0;
    for (const Subject &sub : s.Subjects) sum += sub.grade;
    s.average = sum / s.Subjects.size();
}

bool existStudent(long matricula) {
    for (const Student &s : studentsVector)
        if (s.studentId == matricula) return true;
    return false;
}

vector<Student>& getStudentsVector() {
    return studentsVector;
}

void addStudent() {
    readStudents();

    Student newStudent;
    cout << "Nombre: ";
    getline(cin, newStudent.name);
    cout << "Apellido: ";
    getline(cin, newStudent.lastName);
    newStudent.studentId = readLong("Matricula: ");
    if (!studentsVector.empty()) {
        const vector<Subject> &existingSubjects = studentsVector[0].Subjects;
        for (const Subject &sub : existingSubjects) {
            Subject s = sub;
            cout << "Ingrese la calificacion para " << s.subjectName << " Area: "
                 << areaName(s.field) << ": ";
            s.grade = readFloat("");
            newStudent.Subjects.push_back(s);
        }
    }
    recalcAverage(newStudent);
    studentsVector.push_back(newStudent);
    writeStudents();
    cout << "Alumno agregado correctamente.\n";
}

void showStudent(const long studentId) {
    for (const Student &r : studentsVector) {
        if (r.studentId == studentId) {
            cout << "\nNombre: " << r.name
                 << "\nApellido: " << r.lastName
                 << "\nPromedio: " << r.average
                 << "\n" << (r.average >= 7 ? "Aprobado" : "Reprobado") << "\n";
            return;
        }
    }
    cout << "Alumno no encontrado.\n";
}

void deleteStudent(long studentId) {
    studentsVector.erase(remove_if(studentsVector.begin(), studentsVector.end(),
                                   [&](const Student &r){ return r.studentId == studentId; }),
                         studentsVector.end());
    writeStudents();
}

void modifyStudent(long studentId) {
    for (auto &student : studentsVector) {
        if (student.studentId == studentId) {
            int option;
            do {
                cout << "<<< Modificar Alumno >>>\n";
                cout << "1) Cambiar nombre\n";
                cout << "2) Cambiar apellido\n";
                cout << "3) Modificar calificaciones\n";
                cout << "0) Salir\n";
                option = inputInt("Seleccione una opcion: ");
                switch (option) {
                    case 1: {
                        cout << "Nuevo nombre: ";
                        getline(cin, student.name);
                        break;
                    }
                    case 2: {
                        cout << "Nuevo apellido: ";
                        getline(cin, student.lastName);
                        break;
                    }
                    case 3: {
                        if (student.Subjects.empty()) {
                            cout << "El alumno no tiene materias.\n";
                            break;
                        }
                        cout << "Materias del alumno:\n";
                        for (size_t i = 0; i < student.Subjects.size(); i++) {
                            cout << i + 1 << ") " << student.Subjects[i].subjectName
                                 << " (Area: " << areaName(student.Subjects[i].field)
                                 << ", Calificacion: " << student.Subjects[i].grade << ")\n";
                        }
                        int subjIndex = inputInt("Seleccione la materia a modificar (0 para cancelar): ");
                        if (subjIndex > 0 && subjIndex <= (int)student.Subjects.size()) {
                            float newGrade = readFloat("Ingrese nueva calificacion: ");
                            student.Subjects[subjIndex - 1].grade = newGrade;
                            recalcAverage(student);
                            cout << "Calificacion actualizada.\n";
                        }
                        break;
                    }
                    case 0:
                        cout << "Saliendo del menu.\n";
                        break;
                    default:
                        cout << "Opcion invalida.\n";
                        break;
                }
            } while (option != 0);

            writeStudents();
            return;
        }
    }
    cout << "Alumno no encontrado.\n";
}

void showApprovedStudents() {
    for (const auto &r : studentsVector)
        if (r.average >= 70) cout << r.studentId << ", ";
    cout << "\n";
}

void showFailedStudents() {
    for (const auto &r : studentsVector)
        if (r.average < 70) cout << r.studentId << ", ";
    cout << "\n";
}

void showTopStudents() {
    vector<Student> aux = studentsVector;
    sort(aux.begin(), aux.end(), [](auto &a, auto &b){ return a.average > b.average; });
    for (int i = 0; i < min(3, (int)aux.size()); i++)
        cout << "Matricula: " << aux[i].studentId << " -> " << " Promedio: " << aux[i].average << "\n";
}

float getGroupAverage() {
    float sum = 0;
    for (const auto &r : studentsVector) sum += r.average;
    return sum / studentsVector.size();
}

float getStandardDeviation() {
    float average = getGroupAverage();
    float sum = 0;
    for (const auto &r : studentsVector) sum += pow(r.average - average, 2);
    return sqrt(sum / studentsVector.size());
}

void showStudents() {
    readStudents();

    ListView* lv = listviewCreate("Listado de Estudiantes", 4);

    listviewHeadAdd(lv, "Matricula", 9);
    listviewHeadAdd(lv, "Nombre", 18);
    listviewHeadAdd(lv, "Apellido", 18);
    listviewHeadAdd(lv, "Promedio", 6);

    for (const Student &s : getStudentsVector()) {
        listviewAdd(lv, to_string(s.studentId).c_str());
        listviewAdd(lv, s.name.c_str());
        listviewAdd(lv, s.lastName.c_str());
        listviewAdd(lv, to_string(s.average).c_str());
    }

    listviewFootPrint(lv);
}

void printKardex(int studentId) {
    Student& st = studentsVector[getStudentIndexByStudentId(studentId)];

    ListView* lv = listviewCreate("Kardex", 3);

    listviewHeadAdd(lv, "Materia", 24);
    listviewHeadAdd(lv, "Tipo", 12);
    listviewHeadAdd(lv, "Calificacion", 6);

    for (Subject &s : st.Subjects) {
        listviewAdd(lv, s.subjectName.c_str());
        listviewAdd(lv, areaName(s.field).c_str());
        listviewAdd(lv, to_string(s.grade).c_str());
    }

    listviewFootPrint(lv);
}
