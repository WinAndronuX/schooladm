#include <iostream>
#include <fstream>
#include <vector>
#include <schooladm/reports.hpp>
#include <schooladm/students.hpp>

using namespace std;

void exportReport(const vector<Student> &studentsVector)
{
    ofstream file(REPORTS_REPORT_DIR);
    for (auto &r : studentsVector)
        file << r.name << " " << r.lastName << " (" << r.studentId << ") Promedio: " << r.average << "\n";
    file << "\nPromedio grupal: " << getGroupAverage();
    file << "\nDesviacion estandar: " << getStandardDeviation();
    cout << "Reporte generado.\n";
}
