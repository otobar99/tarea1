#include "Estudiante.h"
#include <iostream>
#include <fstream>

using namespace std;

// Constructor
Estudiante::Estudiante(){
    ::Persona();
    this->cantidadAsignaturas = 0;
    this->asignaturas = new string[0];
    this->nombreCarrera = " ";
}

// Métodos getters
int Estudiante::getCantidadAsignaturas() const {
    return cantidadAsignaturas;
}

string* Estudiante::getAsignaturas() const {
    return asignaturas;
}

string Estudiante::getNombreCarrera() const {
    return nombreCarrera;
}

// Métodos setters
void Estudiante::setCantidadAsignaturas(int cantidad) {
    this->cantidadAsignaturas = cantidad;
    delete[] asignaturas; // Liberar memoria previa si existía
    asignaturas = new string[cantidad]; // Reservar memoria para la nueva cantidad de asignaturas
}

void Estudiante::setAsignaturas(int cantidad) {
    delete[] asignaturas; // Liberar memoria previa
    asignaturas = new string[cantidad]; // Reservar nueva memoria
}

void Estudiante::setNombreCarrera(const string& nombreCarrera) {
    this->nombreCarrera = nombreCarrera;
}


// Métodos específicos
void Estudiante::imprimirEstudiante() const {
    Persona::imprimirPersona();
    cout << "Carrera: " << getNombreCarrera() << "\n";
    cout << "Cantidad de asignaturas: " << getCantidadAsignaturas() << "\n";
    cout << "Lista de asignaturas:\n";
    for (int i = 0; i < getCantidadAsignaturas(); ++i) {
        cout << (i + 1) << ". " << getAsignaturas()[i] << endl;
    }
}

// Destructor
Estudiante::~Estudiante() {
    delete[] asignaturas; // Liberar la memoria reservada para las asignaturas
}

// Ingresar Estudiante

void Estudiante::AsignarEstudiante(int opcion, string r, string* asignaturas_totales, int n_asignaturas){
    string n;
    ifstream estudiantes("Universidad/Estudiantes.txt");
    if (estudiantes.is_open()) {
        string linea;
        if( opcion == 1 ){
            while (getline(estudiantes, linea)) {
                if(linea == r){
                    cout << "El estudiante ya existe en la base de datos." << endl;
                    estudiantes.close();
                    return;
                }
            }
            estudiantes.close();
            ofstream estudiantes("Universidad/Estudiantes.txt", ios::app);
            setRut(r);
            estudiantes << r << endl;
            cout << "Ingrese su nombre: ";
            cin.ignore();
            getline(cin, n);
            Persona::setNombre(n);
            estudiantes << getNombre() << endl;
            cout << "Ingrese su correo: ";
            cin >> n;
            Persona::setCorreo(n);
            estudiantes << getCorreo() << endl;
            cin.ignore();
            cout << "Ingrese su carrera: ";
            getline(cin,this->nombreCarrera);
            estudiantes << this->nombreCarrera << endl;
            cout << "Ingrese la cantidad de asignaturas: ";
            cin >> this->cantidadAsignaturas;
            estudiantes << this->cantidadAsignaturas << endl;
            delete[] this->asignaturas;
            this->asignaturas = new string[this->cantidadAsignaturas];
            int  i = 0;
            int a;
            while (i < this->cantidadAsignaturas) {
                for(int j = 0; j < n_asignaturas; j++){
                    if(asignaturas_totales[j] != " "){
                        cout << j+1 << ". " << asignaturas_totales[j] << endl;
                    }
                }
                cout << "Ingrese el numero de la asignatura a ingresar: ";
                cin >> a;
                if(asignaturas_totales[a-1] != " "){
                    this->asignaturas[i++] = asignaturas_totales[a-1];
                    estudiantes << asignaturas_totales[a-1] << endl;
                    asignaturas_totales[a-1] = " ";
                    cout << "Asignatura ingresada correctamente." << endl;
                }
            }
            estudiantes.close();
            return;
        } else if (opcion == 2){
            while (getline(estudiantes, linea)) {
                if(linea == r){
                    setRut(linea);
                    getline(estudiantes,n);
                    setNombre(n);
                    getline(estudiantes,n);
                    setCorreo(n);
                    getline(estudiantes,this->nombreCarrera);
                    getline(estudiantes,r);
                    this->cantidadAsignaturas = stoi(r);
                    delete[] this->asignaturas;
                    this->asignaturas = new string[this->cantidadAsignaturas];
                    for(int i = 0; i < this->cantidadAsignaturas; i++){
                        getline(estudiantes,this->asignaturas[i]);
                    }
                    estudiantes.close();
                    return;
                }
            }
            cout << "El estudiante no existe en la base de datos." << endl;
            return;
        }
    } else {
        std::cerr << "Error: No se pudo abrir el archivo." << '\n';
        return;
    }
}
