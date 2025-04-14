#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using namespace std;

class Persona {
private:
    string nombre;
    string rut;
    string correo;

public:
    // Constructor
    Persona();

    // Métodos getters
    string getNombre() const;
    string getRut() const;
    string getCorreo() const;

    // Métodos setters
    void setNombre(const string& nombre);
    void setRut(const string& rut);
    void setCorreo(const string& correo);

    // Otros métodos
    void imprimirPersona() const;

    // Destructor
    ~Persona();
};

#endif // PERSONA_H