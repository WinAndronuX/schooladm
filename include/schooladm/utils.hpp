#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

#ifdef _WIN32
#define clearConsole() system("cls")
#define REPORTS_USERS_DIR "..\\reports\\alumnos.csv"
#define REPORTS_REPORT_DIR "..\\reports\\reporte.txt"
#else
#define clearConsole() system("clear")
#define REPORTS_USERS_DIR "./reports/alumnos.csv"
#define REPORTS_REPORT_DIR "./reports/reporte.txt"
#endif

using namespace std;

struct Registro
{
    string nombre;
    string apellido;
    long matricula;
    float calificaciones[3];
    float promedio;
};

long readLong(const string &msg);
float readFloat(const string &msg);

vector<Registro> leerFichero(const string &nombreFichero);
void escribirFichero(const string &nombreFichero, const vector<Registro> &registros);

void agregarAlumno(vector<Registro> &registros);
void modificarAlumno(vector<Registro> &registros, long matricula);
void eliminarAlumno(vector<Registro> &registros, long matricula);

void imprimirDatos(const vector<Registro> &registros, long matricula);
void imprimirAprobados(const vector<Registro> &registros);
void imprimirReprobados(const vector<Registro> &registros);
void imprimirTop(const vector<Registro> &registros);
void crearReporte(const vector<Registro> &registros);

float obtenerPromedioGrupal(const vector<Registro> &registros);
float obtenerDesviacionEstandar(const vector<Registro> &registros);

void menuSistema(vector<Registro> &registros);
void menuFunciones(vector<Registro> &registros);

#endif