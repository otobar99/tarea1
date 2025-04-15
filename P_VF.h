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

    void imprimirPregunta() override;
    void mostrarPregunta() override;
    void leerPregunta(ifstream& archivo) override;
    void revisarPregunta() override;
    void responderPregunta() override;
    void editarPregunta() override;
    void crearPregunta() override;
    void buscarPregunta(const string& asignatura, int nivel) override;
    void guardarPregunta(ofstream& archivo) override;
};

#endif