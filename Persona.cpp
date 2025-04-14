#include "Persona.h"
#include <iostream>

using namespace std;

// Constructor
Persona::Persona(){
    this->nombre = " ";
    this->rut = " ";
    this->correo = " ";
}


// Métodos getters
string Persona::getNombre() const {
    return nombre;
}

string Persona::getRut() const {
    return rut;
}

string Persona::getCorreo() const {
    return correo;
}

// Métodos setters
void Persona::setNombre(const string& nombre) {
    this->nombre = nombre;
}

void Persona::setRut(const string& rut) {
    this->rut = rut;
}

void Persona::setCorreo(const string& correo) {
    this->correo = correo;
}

// Otros métodos
void Persona::imprimirPersona() const {
    cout << "Nombre: " << nombre << "\n";
    cout << "RUT: " << rut << "\n";
    cout << "Correo: " << correo << "\n";
}

// Destructor
Persona::~Persona() {
    // No se requiere lógica especial para el destructor
}