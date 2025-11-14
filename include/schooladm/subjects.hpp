#ifndef SUBJECTS_H
#define SUBJECTS_H

#include <string>

struct Subject{
    string subjectName;
    float grade;
    int field;
};

void recalcAverage(Student &s);

#endif