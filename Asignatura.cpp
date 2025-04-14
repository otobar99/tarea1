#include "Asignatura.h"
#include <iostream>

using namespace std;

// Constructor vacío
Asignatura::Asignatura(){

}

// Métodos getters
int Asignatura::getCreditos() const {
    return creditos;
}

string Asignatura::getNombre() const {
    return nombre;
}

string Asignatura::getProfesor() const {
    return profesor;
}

int Asignatura::getCupos() const {
    return cupos;
}

string* Asignatura::getEstudiantes() const {
    return estudiantes;
}

Evaluacion* Asignatura::getEvaluaciones() const {
    return evaluaciones;
}

int Asignatura::getNEvaluaciones() const {
    return n_evaluaciones;
}

// Métodos setters
void Asignatura::setCreditos(int creditos) {
    this->creditos = creditos;
}

void Asignatura::setNombre(const string& nombre) {
    this->nombre = nombre;
}

void Asignatura::setProfesor(const string& profesor) {
    this->profesor = profesor;
}

void Asignatura::setCupos(int cupos) {
    this->cupos = cupos;
    delete[] estudiantes; // Liberar memoria previa si existía
    estudiantes = new string[cupos]; // Reservar memoria para estudiantes (cuando definamos la clase Estudiantes)
}

void Asignatura::setEvaluaciones(int n_evaluaciones) {
    this->n_evaluaciones = n_evaluaciones;
    delete[] evaluaciones; // Liberar memoria previa si existía
    evaluaciones = new Evaluacion[n_evaluaciones]; // Reservar memoria para las evaluaciones
}

void Asignatura::agregarEvaluacion(const Evaluacion& evaluacion, int indice) {
    if (indice >= 0 && indice < n_evaluaciones && evaluaciones != nullptr) {
        evaluaciones[indice] = evaluacion;
    } else {
        cout << "Índice fuera de rango o lista de evaluaciones no inicializada.\n";
    }
}

// Métodos específicos
void Asignatura::imprimirAsignatura() const {
    cout << "Nombre de la asignatura: " << nombre << "\n";
    cout << "Créditos: " << creditos << "\n";
    cout << "Profesor: " << profesor << "\n";
    cout << "Cupos disponibles: " << cupos << "\n";

    if (estudiantes != nullptr) {
        cout << "Estudiantes registrados.\n";
    } else {
        cout << "No hay estudiantes registrados.\n";
    }

    cout << "Número de evaluaciones: " << n_evaluaciones << "\n";
    if (evaluaciones != nullptr) {
        cout << "Lista de evaluaciones:\n";
        for (int i = 0; i < n_evaluaciones; ++i) {
            cout << "Evaluación " << i + 1 << ":\n";
            evaluaciones[i].imprimirEvaluacion(); // Asumiendo que Evaluacion tiene un método imprimirEvaluacion
        }
    } else {
        cout << "No hay evaluaciones registradas.\n";
    }
}

// Destructor
Asignatura::~Asignatura() {
    delete[] estudiantes;   // Liberar memoria reservada para estudiantes
    delete[] evaluaciones;  // Liberar memoria reservada para evaluaciones
}