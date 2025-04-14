#ifndef UNIVERSIDAD_H
#define UNIVERSIDAD_H

#include <string>
#include <fstream>

using namespace std;

class Universidad {
private:
    string nombre_universidad;
    int n_asignaturas;
    string* asignaturas;

public:
    // Constructor
    Universidad();

    // Métodos getters
    string getNombreUniversidad() const;
    int getNAsignaturas() const;
    string* getAsignaturas() const;

    // Métodos setters
    void setNombreUniversidad(string nombre_universidad);

    // Métodos específicos
    void imprimirUniversidad() const;

    // Destructor
    ~Universidad();
};

#endif // UNIVERSIDAD_H