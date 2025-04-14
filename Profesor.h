#ifndef PROFESOR_H
#define PROFESOR_H

#include "Persona.h"
#include "Asignatura.h"

using namespace std;

class Profesor : public Persona {
private:
    int n_titulos;             // Número de títulos académicos del profesor
    string* titulos;           // Puntero a un array dinámico de títulos académicos

public:
    // Constructor
    Profesor();

    // Métodos getters
    int getNTitulos() const;
    string* getTitulos() const;

    // Métodos setters
    void setNTitulos(int n_titulos);
    void setTitulos(int n_titulos);
    void agregarTitulo(const string& titulo, int indice);
    void imprimirProfesor() const;

    // Destructor
    ~Profesor();

    void AsignarProfesor(int opcion, string r);
};

#endif // PROFESOR_H