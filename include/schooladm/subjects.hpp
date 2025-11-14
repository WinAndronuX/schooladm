#ifndef SUBJECTS_H
#define SUBJECTS_H

#include <string>

using namespace std;

struct Subject{
    string subjectName;
    float grade;
    int field;
};

void addSubject();
void modSubject();
void delSubject();

#endif
