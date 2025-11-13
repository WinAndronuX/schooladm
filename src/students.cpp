#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <schooladm/students.hpp>
#include <schooladm/utils.hpp>

void addStudent(vector<Student> &studentsVector)
{
    Student r;
    cout << "Nombre: ";
    getline(cin, r.name);

    cout << "Apellido: ";
    getline(cin, r.lastName);

    r.studentId = readLong("Matricula: ");
    r.grades[0] = readFloat("Calificacion 1: ");
    r.grades[1] = readFloat("Calificacion 2: ");
    r.grades[2] = readFloat("Calificacion 3: ");

    r.average = (r.grades[0] + r.grades[1] + r.grades[2]) / 3.0f;
    studentsVector.push_back(r);
}

void modifyStudent(vector<Student> &studentsVector, long studentId)
{
    for (auto &r : studentsVector)
    {
        if (r.studentId == studentId)
        {
            cout << "Nuevo nombre: ";
            cin >> r.name;
            cout << "Nuevo apellido: ";
            cin >> r.lastName;
            cout << "Nueva calificacion 1: ";
            cin >> r.grades[0];
            cout << "Nueva calificacion 2: ";
            cin >> r.grades[1];
            cout << "Nueva calificacion 3: ";
            cin >> r.grades[2];
            r.average = (r.grades[0] + r.grades[1] + r.grades[2]) / 3.0f;
            return;
        }
    }
    cout << "Alumno no encontrado.\n";
}

void deleteStudent(vector<Student> &studentsVector, long studentId)
{
    studentsVector.erase(remove_if(studentsVector.begin(), studentsVector.end(),
                                   [&](const Student &r)
                                   { return r.studentId == studentId; }),
                         studentsVector.end());
}

void showStudent(const vector<Student> &studentsVector, long studentId)
{
    for (auto &r : studentsVector)
    {
        if (r.studentId == studentId)
        {
            cout << "\nNombre: " << r.name << "\nApellido: " << r.lastName
                 << "\nPromedio: " << r.average << "\n";
            cout << (r.average >= 7 ? "Aprobado" : "Reprobado") << "\n";
            return;
        }
    }
    cout << "Alumno no encontrado.\n";
}

void showApprovedStudents(const vector<Student> &studentsVector)
{
    for (auto &r : studentsVector)
        if (r.average >= 7)
            cout << r.studentId << ", ";
    cout << "\n";
}

void showFailedStudents(const vector<Student> &studentsVector)
{
    for (auto &r : studentsVector)
        if (r.average < 7)
            cout << r.studentId << ", ";
    cout << "\n";
}

void showTopStudents(const vector<Student> &studentsVector)
{
    vector<Student> aux = studentsVector;
    sort(aux.begin(), aux.end(), [](auto &a, auto &b)
         { return a.average > b.average; });
    for (int i = 0; i < min(3, (int)aux.size()); i++)
        cout << "Matricula: " << aux[i].studentId << " -> " << " Promedio: " << aux[i].average << "\n";
}

float getGroupAverage(const vector<Student> &studentsVector)
{
    float sum = 0;
    for (auto &r : studentsVector)
        sum += r.average;
    return sum / studentsVector.size();
}

float getStandardDeviation(const vector<Student> &studentsVector)
{
    float average = getGroupAverage(studentsVector);
    float sum = 0;
    for (auto &r : studentsVector)
        sum += pow(r.average - average, 2);
    return sqrt(sum / studentsVector.size());
}