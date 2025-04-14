#ifndef PREGUNTA_H
#define PREGUNTA_H

#include <string>
#include <fstream>

using namespace std;

class Pregunta {
private:
    string enunciado;
    int puntaje;
    string respuesta;
    int year;
    int taxonomia;
    int tiempo;
    bool correcto;

public:
    // Constructor
    Pregunta();

    // Métodos getters
    string getEnunciado() const;
    int getPuntaje() const;
    string getRespuesta() const;
    int getYear() const;
    int getTaxonomia() const;
    int getTiempo() const;
    bool getCorrecto() const;

    // Métodos setters
    void setEnunciado(const string& enunciado);
    void setPuntaje(int puntaje);
    void setRespuesta(const string& respuesta);
    void setYear(int year);
    void setTaxonomia(int taxonomia);
    void setTiempo(int tiempo);
    void setCorrecto(bool correcto);

    // Otros métodos
    void imprimirPregunta();
    void mostrarPregunta();
    void leerPregunta(ifstream& archivo);
    void revisarPregunta();
    void editarPregunta();
    void responderPregunta();
    void crearPregunta();
    void buscarPregunta(const string& asignatura, int nivel);

    // Destructor
    ~Pregunta();
};

#endif