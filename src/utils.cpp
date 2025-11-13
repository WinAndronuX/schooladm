#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <schooladm/utils.hpp>

long readLong(const string &msg)
{
    string input;

    cout << msg;
    getline(cin, input);
    return stol(input);
}

float readFloat(const string &msg)
{
    string input;

    cout << msg;
    getline(cin, input);
    return stof(input);
}

vector<Student> getFileAsVector(const string &fileName)
{
    vector<Student> studentsVector;
    ifstream file(fileName);
    if (!file.is_open())
        return studentsVector;

    string linea;
    while (getline(file, linea))
    {
        stringstream ss(linea);
        Student r;

        getline(ss, r.name, ',');
        getline(ss, r.lastName, ',');
        ss >> r.studentId;
        ss.ignore();
        ss >> r.grades[0];
        ss.ignore();
        ss >> r.grades[1];
        ss.ignore();
        ss >> r.grades[2];

        r.average = (r.grades[0] + r.grades[1] + r.grades[2]) / 3.0f;
        studentsVector.push_back(r);
    }
    return studentsVector;
}

void writeOnFile(const string &fileName, const vector<Student> &studentsVector)
{
    ofstream file(fileName);
    for (auto &r : studentsVector)
    {
        file << r.name << "," << r.lastName << "," << r.studentId << ","
             << r.grades[0] << "," << r.grades[1] << "," << r.grades[2] << "\n";
    }
}