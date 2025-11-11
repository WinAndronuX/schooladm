#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include "include/schooladm/utilidades.hpp"

void menuSistema(vector<Registro> &registros)
{
    string option;
    while (true)
    {
        system("cls");
        cout << "=== SISTEMA ===\n"
             << "1. Agregar alumno\n"
             << "2. Eliminar alumno\n"
             << "3. Modificar alumno\n"
             << "4. Volver\n"
             << "Opcion: ";
        getline(cin, option);

        if (option == "1")
        {
            agregarAlumno(registros);
            escribirFichero("..\\reportes\\alumnos.csv", registros);
            system("pause");
        }
        else if (option == "2")
        {
            long m = readLong("Matricula a eliminar: ");
            eliminarAlumno(registros, m);
            escribirFichero("..\\reportes\\alumnos.csv", registros);
            system("pause");
        }
        else if (option == "3")
        {
            long m = readLong("Matricula a modificar: ");
            modificarAlumno(registros, m);
            escribirFichero("..\\reportes\\alumnos.csv", registros);
            system("pause");
        }
        else if (option == "4")
            return;
        else
        {
            cout << "Opcion invalida.\n";
            system("pause");
        }
    }
}

void menuFunciones(vector<Registro> &registros)
{
    string option;
    while (true)
    {
        system("cls");
        cout << "=== FUNCIONES ===\n"
             << "1. Imprimir datos\n"
             << "2. Aprobados\n"
             << "3. Reprobados\n"
             << "4. Top 3\n"
             << "5. Generar reporte\n"
             << "6. Volver\n"
             << "Opcion: ";
        getline(cin, option);

        if (option == "1")
        {
            long m = readLong("Matricula: ");
            imprimirDatos(registros, m);
            system("pause");
        }
        else if (option == "2")
        {
            imprimirAprobados(registros);
            system("pause");
        }
        else if (option == "3")
        {
            imprimirReprobados(registros);
            system("pause");
        }
        else if (option == "4")
        {
            imprimirTop(registros);
            system("pause");
        }
        else if (option == "5")
        {
            crearReporte(registros);
            system("pause");
        }
        else if (option == "6")
            return;
        else
        {
            cout << "Opcion invalida.\n";
            system("pause");
        }
    }
}

vector<Registro> leerFichero(const string &nombreFichero)
{
    vector<Registro> registros;
    ifstream file(nombreFichero);
    if (!file.is_open())
        return registros;

    string linea;
    while (getline(file, linea))
    {
        stringstream ss(linea);
        Registro r;

        getline(ss, r.nombre, ',');
        getline(ss, r.apellido, ',');
        ss >> r.matricula;
        ss.ignore();
        ss >> r.calificaciones[0];
        ss.ignore();
        ss >> r.calificaciones[1];
        ss.ignore();
        ss >> r.calificaciones[2];

        r.promedio = (r.calificaciones[0] + r.calificaciones[1] + r.calificaciones[2]) / 3.0f;
        registros.push_back(r);
    }
    return registros;
}

void escribirFichero(const string &nombreFichero, const vector<Registro> &registros)
{
    ofstream file(nombreFichero);
    for (auto &r : registros)
    {
        file << r.nombre << "," << r.apellido << "," << r.matricula << ","
             << r.calificaciones[0] << "," << r.calificaciones[1] << "," << r.calificaciones[2] << "\n";
    }
}

void agregarAlumno(vector<Registro> &registros)
{
    Registro r;
    cout << "Nombre: ";
    getline(cin, r.nombre);

    cout << "Apellido: ";
    getline(cin, r.apellido);

    r.matricula = readLong("Matricula: ");
    r.calificaciones[0] = readFloat("Calificacion 1: ");
    r.calificaciones[1] = readFloat("Calificacion 2: ");
    r.calificaciones[2] = readFloat("Calificacion 3: ");

    r.promedio = (r.calificaciones[0] + r.calificaciones[1] + r.calificaciones[2]) / 3.0f;
    registros.push_back(r);
}

void modificarAlumno(vector<Registro> &registros, long matricula)
{
    for (auto &r : registros)
    {
        if (r.matricula == matricula)
        {
            cout << "Nuevo nombre: ";
            cin >> r.nombre;
            cout << "Nuevo apellido: ";
            cin >> r.apellido;
            cout << "Nueva calificacion 1: ";
            cin >> r.calificaciones[0];
            cout << "Nueva calificacion 2: ";
            cin >> r.calificaciones[1];
            cout << "Nueva calificacion 3: ";
            cin >> r.calificaciones[2];
            r.promedio = (r.calificaciones[0] + r.calificaciones[1] + r.calificaciones[2]) / 3.0f;
            return;
        }
    }
    cout << "Alumno no encontrado.\n";
}

void eliminarAlumno(vector<Registro> &registros, long matricula)
{
    registros.erase(remove_if(registros.begin(), registros.end(),
                              [&](const Registro &r)
                              { return r.matricula == matricula; }),
                    registros.end());
}

void imprimirDatos(const vector<Registro> &registros, long matricula)
{
    float promedioGrupal = obtenerPromedioGrupal(registros);
    for (auto &r : registros)
    {
        if (r.matricula == matricula)
        {
            cout << "\nNombre: " << r.nombre << "\nApellido: " << r.apellido
                 << "\nPromedio: " << r.promedio << "\n";
            cout << (r.promedio >= 7 ? "Aprobado" : "Reprobado") << "\n";
            return;
        }
    }
    cout << "Alumno no encontrado.\n";
}

void imprimirAprobados(const vector<Registro> &registros)
{
    for (auto &r : registros)
        if (r.promedio >= 7)
            cout << r.matricula << ", ";
    cout << "\n";
}

void imprimirReprobados(const vector<Registro> &registros)
{
    for (auto &r : registros)
        if (r.promedio < 7)
            cout << r.matricula << ", ";
    cout << "\n";
}

void imprimirTop(const vector<Registro> &registros)
{
    vector<Registro> copia = registros;
    sort(copia.begin(), copia.end(), [](auto &a, auto &b)
         { return a.promedio > b.promedio; });
    for (int i = 0; i < min(3, (int)copia.size()); i++)
        cout << "Matricula: " << copia[i].matricula << " -> " << " Promedio: " << copia[i].promedio << "\n";
}

void crearReporte(const vector<Registro> &registros)
{
    ofstream file("..\\reportes\\reporte.txt");
    for (auto &r : registros)
        file << r.nombre << " " << r.apellido << " (" << r.matricula << ") Promedio: " << r.promedio << "\n";
    file << "\nPromedio grupal: " << obtenerPromedioGrupal(registros);
    file << "\nDesviacion estandar: " << obtenerDesviacionEstandar(registros);
    cout << "Reporte generado.\n";
}

float obtenerPromedioGrupal(const vector<Registro> &registros)
{
    float suma = 0;
    for (auto &r : registros)
        suma += r.promedio;
    return suma / registros.size();
}

float obtenerDesviacionEstandar(const vector<Registro> &registros)
{
    float prom = obtenerPromedioGrupal(registros);
    float suma = 0;
    for (auto &r : registros)
        suma += pow(r.promedio - prom, 2);
    return sqrt(suma / registros.size());
}