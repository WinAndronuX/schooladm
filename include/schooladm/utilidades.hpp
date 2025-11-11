using namespace std;

struct Registro
{
    string nombre;
    string apellido;
    long matricula;
    float calificaciones[3];
    float promedio;
};

string input;
long readLong(const string &msg)
{
    cout << msg;
    getline(cin, input);
    return stol(input);
}

float readFloat(const string &msg)
{
    cout << msg;
    getline(cin, input);
    return stof(input);
}

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