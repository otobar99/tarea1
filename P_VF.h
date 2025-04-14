#ifndef P_VF_H
#define P_VF_H

#include "Pregunta.h"
#include <string>

using namespace std;

class P_VF : public Pregunta {
private:
    string justificado; // Explicación o justificación de la respuesta

public:
    // Constructor
    P_VF();

    // Métodos getters
    string getJustificado() const;

    // Métodos setters
    void setJustificado(const string& justificado);

    // Otros métodos
    void imprimirPreguntaConJustificado() const;

    // Destructor
    ~P_VF();

    void imprimirPregunta();
    void mostrarPregunta();
    void leerPregunta(ifstream& archivo);
    void revisarPregunta();
    void responderPregunta();
    void editarPregunta();
    void crearPregunta();
    void buscarPregunta(const string& asignatura, int nivel);
};

#endif