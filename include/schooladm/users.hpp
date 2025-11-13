#ifndef USERS_H
#define USERS_H

#include <string>

#define USERS_DATA_FILENAME "data/users.csv"

using namespace std;

typedef struct {
    int userId;
    string name;
    string lastName;
    string passwd;
} User;

void usersInit();
void usersAdd();
void usersPrint();
bool usersCheckPasswd(int userId, string passwd);
void usersChangePasswd();
void usersDelete();

#endif
