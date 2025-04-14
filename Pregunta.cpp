#include "Pregunta.h"
#include <iostream>

using namespace std;

// Constructor
Pregunta::Pregunta(){
}

// Métodos getters
string Pregunta::getEnunciado() const {
    return enunciado;
}

int Pregunta::getPuntaje() const {
    return puntaje;
}

string Pregunta::getRespuesta() const {
    return respuesta;
}

int Pregunta::getYear() const {
    return year;
}

int Pregunta::getTaxonomia() const {
    return taxonomia;
}

int Pregunta::getTiempo() const {
    return tiempo;
}

// Métodos setters
void Pregunta::setEnunciado(const string& enunciado) {
    this->enunciado = enunciado;
}

void Pregunta::setPuntaje(int puntaje) {
    this->puntaje = puntaje;
}

void Pregunta::setRespuesta(const string& respuesta) {
    this->respuesta = respuesta;
}

void Pregunta::setTaxonomia(int taxonomia) {
    this->taxonomia = taxonomia;
}
void Pregunta::setCorrecto(bool correcto) {
    this->correcto = correcto;
}
void Pregunta::setTiempo(int tiempo) {
    this->tiempo = tiempo;
}

// Otros métodos
void Pregunta::imprimirPregunta(){
    cout << "Enunciado: " << enunciado << "\n";
    cout << "Puntaje: " << puntaje << "\n";
    cout << "Respuesta: " << respuesta << "\n";
    cout << "Año: " << year << "\n";
    cout << "Taxonomía: " << taxonomia << "\n";
    cout << "Tiempo: " << tiempo << "\n";
}

void Pregunta::mostrarPregunta(){
    cout << "Pregunta: " << enunciado << "\n";
    cout << "Puntaje: " << puntaje << "\n";
    cout << "Respuesta: " << respuesta << "\n";
}

// Destructor
Pregunta::~Pregunta() {
}

void Pregunta::revisarPregunta(){
    imprimirPregunta();
    cout << "¿Es correcta? (1: Sí, 0: No): ";
    int respuestaCorrecta;
    cin >> respuestaCorrecta;
    if (respuestaCorrecta == 1) {
        correcto = true;
    } else {
        correcto = false;
    }
}
void Pregunta::editarPregunta(){
    cout << "¿Qué desea editar?\n 1. Enunciado\n 2. Puntaje\n 3. Taxonomía\n";
    int opcion;
    cin >> opcion;
    switch (opcion) {
        case 1:{
            cout << "Ingrese el nuevo enunciado: ";
            string nuevoEnunciado;
            cin.ignore();
            getline(cin, nuevoEnunciado);
            setEnunciado(nuevoEnunciado);
            break;
        }
        case 2:{
            cout << "Ingrese el nuevo puntaje: ";
            int nuevoPuntaje;
            cin >> nuevoPuntaje;
            setPuntaje(nuevoPuntaje);
            break;
        }
        case 3:{
            cout << "Ingrese la nueva taxonomía:\n1. Recordar\n2. Comprender\n3. Aplicar\n4. Analizar\n5. Evaluar\n6. Crear\n";
            int nuevaTaxonomia;
            cin >> nuevaTaxonomia;
            setTaxonomia(nuevaTaxonomia);
            switch (nuevaTaxonomia) {
                case 1:
                    setTiempo(20);
                    break;
                case 2:
                    setTiempo(30);
                    break;
                case 3:
                    setTiempo(40);
                    break;
                case 4:
                    setTiempo(60);
                    break;
                case 5:
                    setTiempo(90);
                    break;
                case 6:
                    setTiempo(120);
                    break;
            }
            break;
        }
    }
    return;
}

void Pregunta::responderPregunta(){
    mostrarPregunta();
    cout << "Ingrese su respuesta: ";
    string respuestaUsuario;
    cin.ignore();
    getline(cin, respuestaUsuario);
    setRespuesta(respuestaUsuario);
    return;
}

void Pregunta::leerPregunta(ifstream& archivo){
    string linea;
    int tax;
    getline(archivo, linea);
    setEnunciado(linea);
    getline(archivo, linea);
    setPuntaje(stoi(linea));
    getline(archivo, linea);
    setTaxonomia(stoi(linea));
    getline(archivo, linea);
    setRespuesta(linea);
    return;
}

void Pregunta::crearPregunta(){
    string enunciado;
    int puntaje, taxonomia;
    cout << "Ingrese el enunciado de la pregunta: ";
    cin.ignore();
    getline(cin, enunciado);
    setEnunciado(enunciado);
    cout << "Ingrese el puntaje de la pregunta: ";
    cin >> puntaje;
    setPuntaje(puntaje);
    cout << "Ingrese la taxonomía de la pregunta: \n1. Recordar\n2. Comprender\n3. Aplicar\n4. Analizar\n5. Evaluar\n6. Crear\n";
    cin >> taxonomia;
    setTaxonomia(taxonomia);
    switch (taxonomia) {
        case 1:
            setTiempo(20);
            break;
        case 2:
            setTiempo(30);
            break;
        case 3:
            setTiempo(40);
            break;
        case 4:
            setTiempo(60);
            break;
        case 5:
            setTiempo(90);
            break;
        case 6:
            setTiempo(120);
            break;
    }
}

void Pregunta::buscarPregunta(const string& asignatura, int nivel) {
    ifstream archivo("Universidad/" + asignatura + "/" + asignatura + ".txt");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo.\n";
        return;
    }
    string linea;
    while (getline(archivo, linea)) {
        try {
            int tipo = stoi(linea);
            if (true) {
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