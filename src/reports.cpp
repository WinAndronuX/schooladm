#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <schooladm/reports.hpp>
#include <schooladm/students.hpp>

void exportReport(const vector<Student> &studentsVector)
{
    ofstream file(REPORTS_REPORT_DIR);
    for (auto &r : studentsVector)
        file << r.name << " " << r.lastName << " (" << r.studentId << ") Promedio: " << r.average << "\n";
    file << "\nPromedio grupal: " << getGroupAverage(studentsVector);
    file << "\nDesviacion estandar: " << getStandardDeviation(studentsVector);
    cout << "Reporte generado.\n";
}