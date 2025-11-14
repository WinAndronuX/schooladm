#include "schooladm/subjects.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <schooladm/students.hpp>
#include <schooladm/utils.hpp>
#include <filesystem>

vector<Student> studentsVector;

void readStudents() {
    if (!studentsVector.empty()) {studentsVector.clear();}

    ifstream file(STUDENTS_DATA_FILE);

    if (!file.is_open())
        return;

    string line;
    while (getline(file, line)) {

        cout << line << endl;
        vector<string> data = split(line, ',');

        Student st;
        st.studentId = stoi(data[0]);
        st.name = data[1];
        st.lastName = data[2];
        st.average = stof(data[4]);

        if (data[3] != "") {
            vector<string> subjects = split(data[3], '|');

            for(string subject : subjects) {
                vector<string> value = split(subject, ':');
                st.Subjects.push_back({value[0], stof(value[1]), stoi(value[2])});
            }
        }

        studentsVector.push_back(st);
    }

    file.close();
}

void writeStudents() {

    std::filesystem::create_directories(std::filesystem::path(STUDENTS_DATA_FILE).parent_path());

    ofstream file(STUDENTS_DATA_FILE);
    if (!file.is_open())
        throw runtime_error("Error. No se pudo escribir el archivo data/students.csv");

    for (Student &st: studentsVector) {
        file << st.studentId << "," << st.name << "," << st.lastName << ",";

        for (int i = 0; i < st.Subjects.size(); i++) {
            file << st.Subjects[i].subjectName << ":" << st.Subjects[i].grade << ":" << st.Subjects[i].field;
            if (i < st.Subjects.size() - 1) file << "|";
        }
        file << "," << st.average;
    }

    file.close();
}

void addStudent()
{
    Student r;
    cout << "Nombre: ";
    getline(cin, r.name);

    cout << "Apellido: ";
    getline(cin, r.lastName);

    r.studentId = readLong("Matricula: ");
    // r.Subjects[0].field = readFloat("Calificacion 1: ");
    // r.Subjects[1].field = readFloat("Calificacion 2: ");
    // r.Subjects[2].field = readFloat("Calificacion 3: ");

    // recalcAverage(r);
    studentsVector.push_back(r);
    writeStudents();
}

void modifyStudent(long studentId)
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
            cin >> r.Subjects[0].field;
            cout << "Nueva calificacion 2: ";
            cin >> r.Subjects[1].field;
            cout << "Nueva calificacion 3: ";
            cin >> r.Subjects[2].field;
            recalcAverage(r);
            return;
        }
    }
    cout << "Alumno no encontrado.\n";
    writeStudents();
}

void deleteStudent(long studentId)
{
    studentsVector.erase(remove_if(studentsVector.begin(), studentsVector.end(),
                                   [&](const Student &r)
                                   { return r.studentId == studentId; }),
                         studentsVector.end());
    writeStudents();
}

void showStudent(const long studentId)
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

void showApprovedStudents()
{
    for (auto &r : studentsVector)
        if (r.average >= 7)
            cout << r.studentId << ", ";
    cout << "\n";
}

void showFailedStudents()
{
    for (auto &r : studentsVector)
        if (r.average < 7)
            cout << r.studentId << ", ";
    cout << "\n";
}

void showTopStudents()
{
    vector<Student> aux = studentsVector;
    sort(aux.begin(), aux.end(), [](auto &a, auto &b)
         { return a.average > b.average; });
    for (int i = 0; i < min(3, (int)aux.size()); i++)
        cout << "Matricula: " << aux[i].studentId << " -> " << " Promedio: " << aux[i].average << "\n";
}

float getGroupAverage()
{
    float sum = 0;
    for (auto &r : studentsVector)
        sum += r.average;
    return sum / studentsVector.size();
}

float getStandardDeviation()
{
    float average = getGroupAverage();
    float sum = 0;
    for (auto &r : studentsVector)
        sum += pow(r.average - average, 2);
    return sqrt(sum / studentsVector.size());
}

bool existStudent(long matricula) {

    for (Student &s: studentsVector)
        if (s.studentId == matricula)
            return true;

    return false;
}

vector<Student>& getStudentsVector() {
    return studentsVector;
}

void recalcAverage(Student &s) {
    if (s.Subjects.empty()) {
        s.average = 0;
        return;
    }
    float sum = 0;
    for (const Subject &sub : s.Subjects) {
        sum += sub.grade;
    }
    s.average = sum / s.Subjects.size();
}
