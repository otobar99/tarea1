#ifndef ASIGNATURA_H
#define ASIGNATURA_H

#include "Evaluacion.h" // Necesitamos incluir la clase Evaluacion
#include <string>

using namespace std;

class Evaluacion; // Declaración adelantada

class Asignatura {
private:
    int creditos;              // Número de créditos de la asignatura
    string nombre;             // Nombre de la asignatura
    string profesor;         // Profesor a cargo de la asignatura
    int cupos;                 // Cantidad de cupos disponibles
    string* estudiantes;  // Puntero a un objeto de la clase Estudiantes
    Evaluacion* evaluaciones;  // Puntero a un array dinámico de evaluaciones
    int n_evaluaciones;        // Número de evaluaciones en la asignatura

public:
    // Constructor vacío
    Asignatura();

    // Métodos getters
    int getCreditos() const;
    string getNombre() const;
    string getProfesor() const;
    int getCupos() const;
    string* getEstudiantes() const;
    Evaluacion* getEvaluaciones() const;
    int getNEvaluaciones() const;

    // Métodos setters
    void setCreditos(int creditos);
    void setNombre(const string& nombre);
    void setProfesor(const string& profesor);
    void setCupos(int cupos);
    void setEstudiantes(string* estudiantes);
    void setEvaluaciones(int n_evaluaciones);
    void agregarEvaluacion(const Evaluacion& evaluacion, int indice);
    void imprimirAsignatura() const;

    // Destructor
    ~Asignatura();
};

#endif // ASIGNATURA_H