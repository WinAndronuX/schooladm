#include <schooladm/utils.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

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

int inputInt(string msg) {

    cout << msg << endl << PROMPT;

    int n;
    while (!(cin >> n)) {
        cout << COLOR_RED "Error: Entrada invalida. Debe ser un numero" COLOR_RESET  << endl << endl;

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << msg << endl << PROMPT;
    }

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return n;
}

int inputInt(string msg, int min) {

    int n = inputInt(msg);

    if (n < min) {
        cout << COLOR_RED "Error: El numero debe ser mayor o igual a " << min << COLOR_RESET << endl << endl;
        inputInt(msg, min);
    }

    return n;
}

int inputInt(string msg, int min, int max) {

    int n = inputInt(msg);

    if (n < min || n > max) {
        cout << COLOR_RED "Error: El numero debe estar entre " << min << " y " << max << COLOR_RESET << endl << endl;
        inputInt(msg, min, max);
    }

    return n;
}

string inputStr(string msg) {
    cout << msg << endl << PROMPT;

    string res;
    getline(cin, res);

    return res;
}

vector<string> split(string str, char p) {

    int posInit = 0;
    int posFound = 0;
    string splitted;
    vector<string> results;

    while(posFound >= 0){
        posFound = str.find(p, posInit);
        splitted = str.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        results.push_back(splitted);
    }

    return results;
}

void printError(string str) {
    cout << COLOR_RED << str << COLOR_RESET << endl << endl;
}
