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
    virtual void imprimirPregunta();
    virtual void mostrarPregunta();
    virtual void leerPregunta(ifstream& archivo);
    virtual void revisarPregunta();
    virtual void editarPregunta();
    virtual void responderPregunta();
    virtual void crearPregunta();
    virtual void buscarPregunta(const string& asignatura, int nivel);
    virtual void guardarPregunta(ofstream& archivo);

    // Destructor
    ~Pregunta();
};

#endif