#include "Universidad.h"
#include <iostream>
#include <filesystem>

using namespace std;


// Constructor
Universidad::Universidad(){
    ifstream universidad_archivo("Universidad/Universidad.txt");
    if (universidad_archivo.is_open()) {
        getline(universidad_archivo, nombre_universidad);
        universidad_archivo.close();
        this->n_asignaturas = 0;
        for (const auto& entry : filesystem::directory_iterator("Universidad/")) {
            if (entry.is_directory()) {
                this->n_asignaturas++;
            }
        }
        int c = 0;
        asignaturas = new string[n_asignaturas];
        for (const auto& entry : filesystem::directory_iterator("Universidad/")) {
            if (entry.is_directory()) {
                asignaturas[c++] = entry.path().filename().string();
            }
        }
    } else {
        cerr << "Error: No se pudo abrir el archivo " << endl;
    }
}

// Métodos getters
string Universidad::getNombreUniversidad() const {
    return nombre_universidad;
}

int Universidad::getNAsignaturas() const {
    return n_asignaturas;
}

string* Universidad::getAsignaturas() const {
    return asignaturas;
}

// Métodos setters
void Universidad::setNombreUniversidad(string nombre_universidad) {
    this->nombre_universidad = nombre_universidad;
}

// Métodos específicos
void Universidad::imprimirUniversidad() const {
    cout << "Nombre de la Universidad: " << nombre_universidad << "\n";
    cout << "Número de Asignaturas: " << n_asignaturas << "\n";
    cout << "Asignaturas: \n";
    for(int i = 0; i < n_asignaturas; i++) {
        cout << asignaturas[i] << endl;
    }
}

// Destructor
Universidad::~Universidad() {
    delete[] asignaturas;
}