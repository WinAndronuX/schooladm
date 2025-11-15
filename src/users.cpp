#include <schooladm/utils.hpp>
#include <iostream>
#include <listview/listview.h>
#include <schooladm/users.hpp>

#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>


using namespace std;

static vector<User> users;

static void readUsers() {
    if (!users.empty()) {users.clear();}

    ifstream file(USERS_DATA_FILENAME, ios::in);

    if (!file.is_open())
        return;

    string line;
    while (getline(file, line)) {

        vector<string> data = split(line, ',');

        User temp;

        temp.userId = stoi(data[0]);
        temp.name = data[1];
        temp.lastName = data[2];
        temp.passwd = data[3];

        users.push_back(temp);
    }

    file.close();
}

static void writeUsers() {

    std::filesystem::create_directories(std::filesystem::path(USERS_DATA_FILENAME).parent_path());

    ofstream file(USERS_DATA_FILENAME);
    if (!file.is_open())
        throw runtime_error("No se pudo escribir el archivo: data/users.csv");

    for (User &user : users) {
        file << user.userId << "," << user.name << "," << user.lastName << "," << user.passwd << endl;
    }

    file.close();
}

static int getUserIndexById(int userId) {

    int id = -1;
    for (int i = 0; i < users.size(); i++)
        if (users[i].userId == userId) {
            id = i;
            break;
        }

    return id;
}

void usersInit() {

    readUsers();

    if (users.empty()) {
        users.push_back(User{1, "admin", "admin", "admin"});
        writeUsers();
    }
}

void usersAdd() {

    int userId;
    while (true) {

        userId = inputInt("Ingrese un id: ", 1);
        if (getUserIndexById(userId) == -1)
            break;

        printError("Error. El ID ya existe");
    }

    string name = inputStr("Ingrese su numbre: ");
    string lastName = inputStr("Ingrese su apellido: ");
    string passwd = inputStr("Ingrese su contraseña: ");

    users.push_back(User{userId, name, lastName, passwd});

    writeUsers();
}

void usersPrint() {

    ListView* lv = listviewCreate("Usuarios", 3);

    listviewHeadAdd(lv, "ID", 7);
    listviewHeadAdd(lv, "Nombre", 18);
    listviewHeadAdd(lv, "Apellidos", 18);

    for (User u: users) {

        listviewAdd(lv, to_string(u.userId).c_str());
        listviewAdd(lv, u.name.c_str());
        listviewAdd(lv, u.lastName.c_str());
    }

    listviewFootPrint(lv);
}

bool usersCheckPasswd(int userId, string passwd) {

    int i = getUserIndexById(userId);
    if (i == -1)
        throw runtime_error("Error. Usuario no encontrado");

    return passwd.c_str() == users[i].passwd;
}

void usersChangePasswd() {

    int userId = inputInt("Ingrese su id: ", 1);

    int i = getUserIndexById(userId);
    if (i == -1)
        throw runtime_error("Error. Usuario no encontrado");

    string newPasswd = inputStr("Ingrese su nueva contraseña: ");

    users[i].passwd = newPasswd;

    writeUsers();
}

void usersDelete() {

    int userId = inputInt("Ingrese el id del usuario a eliminar: ", 1);

    int i = getUserIndexById(userId);
    if (i == -1)
        throw runtime_error("Error. Usuario no encontrado");

    users.erase(users.begin() + i);

    writeUsers();
}
