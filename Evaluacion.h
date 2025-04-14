#ifndef EVALUACION_H
#define EVALUACION_H

#include "Profesor.h"
#include "Pregunta.h"
#include "P_VF.h"
#include "P_Alternativa.h"
#include <string>

using namespace std;

class Evaluacion {
private:
    Pregunta** listaPreguntas; // Puntero único a una lista dinámica de preguntas
    int n_preguntas[3];       // Lista de tamaño fijo con 3 números (por ejemplo, preguntas por sección)
    string profesor;        // Profesor que creó la evaluación
    string alumno;            // Nombre del alumno que realiza la evaluación
    string rut;
    string tipoEvaluacion;    // Tipo de evaluación (ej. "Prueba", "Examen")
    int ponderacion;          // Ponderación de la evaluación
    float nota;               // Nota obtenida por el alumno en la evaluación
    int puntaje_total;
    int puntaje_obtenido;
    int tiempo;

public:
    // Constructor vacío que inicializa con datos irrelevantes
    Evaluacion();

    // Métodos getters
    Pregunta** getListaPreguntas() const;
    const int* getNPreguntas() const; // Retorna un puntero constante a la lista
    string getProfesor() const;
    string getAlumno() const;
    string getTipoEvaluacion() const;
    int getPonderacion() const;
    float getNota() const;

    // Métodos setters
    void setProfesor(const string profesor);
    void setAlumno(const string alumno);
    void setTipoEvaluacion(const string& tipoEvaluacion);
    void setPonderacion(int ponderacion);
    void setNota(float nota);
    void setNPreguntas(int index, int valor); // Modifica un valor específico de la lista
    void agregarPregunta(Pregunta* pregunta, int indice);
    void eliminarPregunta(int indice);
    void imprimirEvaluacion() const;

    // Destructor
    ~Evaluacion();

    void mostrarEvaluacion();
    void leerEvaluacion();
    void crearEvaluacion(string asignatura, string profesor);
    void guardarEvaluacion();
    void editarEvaluacion();
    void realizarEvaluacion(string rut, string alumno);
    void revisarEvaluacion();
    
};

#endif // EVALUACION_H