#include "Profesor.h"
#include <iostream>
#include <fstream>

using namespace std;

// Constructor
Profesor::Profesor(){
    ::Persona();
    this->n_titulos = 0;
    this->titulos = new string[0];
}

// Métodos getters
int Profesor::getNTitulos() const {
    return n_titulos;
}

string* Profesor::getTitulos() const {
    return titulos;
}

// Métodos setters
void Profesor::setNTitulos(int n_titulos) {
    this->n_titulos = n_titulos;
    delete[] titulos; // Liberar memoria previa si existía
    titulos = new string[n_titulos]; // Reservar memoria para los nuevos títulos
}

void Profesor::setTitulos(int n_titulos) {
    delete[] titulos; // Liberar memoria previa
    titulos = new string[n_titulos]; // Reservar nueva memoria
}

void Profesor::agregarTitulo(const string& titulo, int indice) {
    if (indice >= 0 && indice < n_titulos) {
        titulos[indice] = titulo; // Agregar título en el índice especificado
    } else {
        cout << "Índice fuera de rango.\n";
    }
}

// Métodos específicos
void Profesor::imprimirProfesor() const {
    Persona::imprimirPersona();
    cout << "Número de títulos: " << n_titulos << "\n";
    cout << "Lista de títulos:\n";
    for (int i = 0; i < n_titulos; ++i) {
        cout << "- " << titulos[i] << "\n";
    }
}

// Destructor
Profesor::~Profesor() {
    delete[] titulos;
}

void Profesor::AsignarProfesor(int opcion, string r){
    string n;
    ifstream profesores("Universidad/Profesores.txt");
    if (profesores.is_open()) {
        string linea;
        if( opcion == 1 ){
            while (getline(profesores, linea)) {
                if(linea == r){
                    cout << "El profesor ya existe en la base de datos." << endl;
                    profesores.close();
                    return;
                }
            }
            profesores.close();
            ofstream profesores("Universidad/profesores.txt", ios::app);
            setRut(r);
            profesores << r << endl;
            cout << "Ingrese su nombre: ";
            cin.ignore();
            getline(cin, n);
            Persona::setNombre(n);
            profesores << getNombre() << endl;
            cout << "Ingrese su correo: ";
            cin >> n;
            Persona::setCorreo(n);
            profesores << getCorreo() << endl;
            cout << "Ingrese la cantidad de titulos que posee: ";
            cin >> this->n_titulos;
            profesores << this->n_titulos << endl;
            delete[] titulos;
            this->titulos = new string[this->n_titulos];
            cin.ignore();
            for (int i = 0; i < this->n_titulos; ++i) {
                cout << "Ingrese el titulo " << i + 1 << ": ";
                getline(cin, n);
                this->titulos[i] = n;
                profesores << this->titulos[i] << endl;
            }
            profesores.close();
            return;
        } else if (opcion == 2){
            while (getline(profesores, linea)) {
                if(linea == r){
                    setRut(linea);
                    getline(profesores,n);
                    setNombre(n);
                    getline(profesores,n);
                    setCorreo(n);
                    getline(profesores,r);
                    this->n_titulos = stoi(r);
                    delete[] titulos;
                    this->titulos = new string[this->n_titulos];
                    for (int i = 0; i < this->n_titulos; ++i) {
                        getline(profesores, n);
                        this->titulos[i] = n;
                        }
                    profesores.close();
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