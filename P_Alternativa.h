#ifndef P_ALTERNATIVA_H
#define P_ALTERNATIVA_H

#include "Pregunta.h"
#include <string>

using namespace std;

class P_Alternativa : public Pregunta {
private:
    string* alternativas; // Puntero para manejar la lista dinámica de alternativas
    int cantidadAlternativas; // Número de alternativas

public:
    // Constructor
    P_Alternativa();

    // Métodos getters
    int getCantidadAlternativas() const;
    string* getAlternativas() const;

    // Métodos setters
    void agregarAlternativa(const string& alternativa, int indice);
    void eliminarAlternativa(int indice);
    void editarAlternativa(int indice, const string& nuevaAlternativa);
    void imprimirAlternativas() const;

    // Destructor
    ~P_Alternativa();

    void imprimirPregunta();
    void mostrarPregunta();
    void leerPregunta(ifstream& archivo);
    void revisarPregunta();
    void editarPregunta();
    void responderPregunta();
    void crearPregunta();
    void buscarPregunta(const string& asignatura, int nivel);
};

#endif