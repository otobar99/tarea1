#include "P_VF.h"
#include <iostream>

using namespace std;

// Constructor
P_VF::P_VF():Pregunta(){
    this->justificado = " ";
}

// Métodos getters
string P_VF::getJustificado() const {
    return justificado;
}

// Métodos setters
void P_VF::setJustificado(const string& justificado) {
    this->justificado = justificado;
}

// Métodos específicos
void P_VF::imprimirPregunta(){
    Pregunta::imprimirPregunta();
    cout << "Justificado: " << justificado << "\n";
}

// Destructor
P_VF::~P_VF() {
}

void P_VF::mostrarPregunta(){
    Pregunta::mostrarPregunta();
    cout << "Justificado: " << justificado << "\n";
}

void P_VF::leerPregunta(ifstream& archivo){
    Pregunta::leerPregunta(archivo);
    string linea;
    getline(archivo, linea);
    setJustificado(linea);
}

void P_VF::revisarPregunta(){
    Pregunta::imprimirPregunta();
    cout << "¿Es correcta? (1: Sí, 0: No): ";
    int respuestaCorrecta;
    cin >> respuestaCorrecta;
    if(respuestaCorrecta == 1){
        setCorrecto(true);
    } else {
        setCorrecto(false);
    }
}

void P_VF::responderPregunta(){
    Pregunta::mostrarPregunta();
    cout << "Ingrese su respuesta (V/F): ";
    string respuestaUsuario;
    cin.ignore();
    getline(cin, respuestaUsuario);
    setRespuesta(respuestaUsuario);
    if (respuestaUsuario == "F" || respuestaUsuario == "f") {
        cout << "Ingrese justificación: ";
        string justificacion;
        cin.ignore();
        getline(cin, justificacion);
        setJustificado(justificacion);
    } else {
        setJustificado(" ");
    }
}

void P_VF::editarPregunta(){
    Pregunta::editarPregunta();
    switch (getTaxonomia()) {
        case 1:
            setTiempo(20);
            break;
        case 2:
            setTiempo(30);
            break;
        case 3:
            setTiempo(35);
            break;
        case 4:
            setTiempo(45);
            break;
        case 5:
            setTiempo(60);
            break;
        case 6:
            setTiempo(70);
            break;
    }
}

void P_VF::crearPregunta(){
    Pregunta::crearPregunta();
    switch (getTaxonomia()) {
        case 1:
            setTiempo(20);
            break;
        case 2:
            setTiempo(30);
            break;
        case 3:
            setTiempo(35);
            break;
        case 4:
            setTiempo(45);
            break;
        case 5:
            setTiempo(60);
            break;
        case 6:
            setTiempo(70);
            break;
    }
    return;
}

void P_VF::buscarPregunta(const string& asignatura, int nivel) {
    ifstream archivo("Universidad/" + asignatura + "/" + asignatura + ".txt");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo.\n";
        return;
    }
    string linea;
    while (getline(archivo, linea)) {
        try {
            int tipo = stoi(linea);
            if (tipo == 2) {
                getline(archivo, linea);
                if(2025 - stoi(linea) >= 2) {
                    getline(archivo, linea);
                    if(stoi(linea) == nivel) {
                        setTaxonomia(stoi(linea));
                        getline(archivo, linea);
                        setEnunciado(linea);
                        getline(archivo, linea);
                        setTiempo(stoi(linea));
                        getline(archivo, linea);
                        setPuntaje(stoi(linea));
                        break;
                    }
                }
                    
            }
        } catch (const invalid_argument&) {
            continue;
        } catch (const out_of_range&) {
            continue;
        }
    }
    archivo.close();
}