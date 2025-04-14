#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "Persona.h"
#include "Asignatura.h"

using namespace std;

class Estudiante : public Persona {
private:
    int cantidadAsignaturas; // Número de asignaturas que está cursando el estudiante
    string* asignaturas; // Puntero a un array dinámico de asignaturas
    string nombreCarrera;    // Nombre de la carrera del estudiante

public:
    // Constructor
    Estudiante();

    // Métodos getters
    int getCantidadAsignaturas() const;
    string* getAsignaturas() const;
    string getNombreCarrera() const;

    // Métodos setters
    void setCantidadAsignaturas(int cantidad);
    void setAsignaturas(int cantidad);
    void setNombreCarrera(const string& nombreCarrera);
    void agregarAsignatura(const string& asignatura, int indice);
    void imprimirEstudiante() const;

    // Destructor
    ~Estudiante();

    void AsignarEstudiante(int opcion, string r, string* asignaturas_totales, int n_asignaturas);
    
};

#endif // ESTUDIANTE_H