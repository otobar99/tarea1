#include "P_Alternativa.h"
#include <iostream>

using namespace std;

// Constructor
P_Alternativa::P_Alternativa():Pregunta(){;
    alternativas = new string[0];
}

// Métodos getters
int P_Alternativa::getCantidadAlternativas() const {
    return cantidadAlternativas;
}

string* P_Alternativa::getAlternativas() const {
    return alternativas;
}

// Métodos setters
void P_Alternativa::agregarAlternativa(const string& alternativa, int indice) {
    string* nuevoArray = new string[cantidadAlternativas + 1];
    for (int i = 0; i < cantidadAlternativas; i++) {
        nuevoArray[i] = alternativas[i];
    }
    nuevoArray[cantidadAlternativas] = alternativa;
    delete[] alternativas;
    cantidadAlternativas++;
    alternativas = nuevoArray;
}

void P_Alternativa::eliminarAlternativa(int indice) {
    if (indice >= 0 && indice < cantidadAlternativas) {
        string* nuevaLista = new string[cantidadAlternativas - 1];
        for (int i = 0, j = 0; i < cantidadAlternativas; ++i) {
            if (i != indice) {
                nuevaLista[j++] = alternativas[i]; // Copiar todos menos la alternativa eliminada
            }
        }
        delete[] alternativas; // Liberar la lista antigua
        alternativas = nuevaLista;
        cantidadAlternativas--;
    } else {
        cout << "Índice fuera de rango.\n";
    }
}

void P_Alternativa::editarAlternativa(int indice, const string& nuevaAlternativa) {
    if (indice >= 0 && indice < cantidadAlternativas) {
        alternativas[indice] = nuevaAlternativa; // Actualizar el contenido de la alternativa
    } else {
        cout << "Índice fuera de rango.\n";
    }
}

// Métodos específicos
void P_Alternativa::imprimirAlternativas() const {
    cout << "Alternativas:\n";
    for (int i = 0; i < cantidadAlternativas; ++i) {
        cout << i + 1 << ". " << alternativas[i] << "\n";
    }
}

// Destructor
P_Alternativa::~P_Alternativa() {
    delete[] alternativas; // Liberar la memoria del array dinámico
}

void P_Alternativa::imprimirPregunta(){
    imprimirPregunta();
    cout << "Alternativas:\n";
    for (int i = 0; i < cantidadAlternativas; ++i) {
        cout << i + 1 << ". " << alternativas[i] << "\n";
    }
}

void P_Alternativa::mostrarPregunta(){
    mostrarPregunta();
    cout << "Alternativas:\n";
    for (int i = 0; i < cantidadAlternativas; ++i) {
        cout << i + 1 << ". " << alternativas[i] << "\n";
    }
}

void P_Alternativa::leerPregunta(ifstream& archivo){
    leerPregunta(archivo);
    archivo >> cantidadAlternativas;
    delete[] alternativas;
    alternativas = new string[cantidadAlternativas];
    for (int i = 0; i < cantidadAlternativas; ++i) {
        archivo >> alternativas[i];
    }
    archivo.ignore();
}

void P_Alternativa::revisarPregunta(){
    mostrarPregunta();
    cout << "¿Es correcta? (1: Sí, 0: No): ";
    int respuestaCorrecta;
    cin >> respuestaCorrecta;
    if (respuestaCorrecta == 1) {
        setCorrecto(true);
    } else {
        setCorrecto(false);
    }
}
void P_Alternativa::editarPregunta(){
    cout << "¿Qué desea editar?\n 1. Enunciado\n 2. Puntaje\n 3. Taxonomía\n 4. Alternativas\n";
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
            cout << "Ingrese la nueva taxonomía:\n 1. Recordar\n 2. Comprender\n 3. Aplicar\n 4. Analizar\n 5. Evaluar\n 6. Crear\n";
            int nuevaTaxonomia;
            cin >> nuevaTaxonomia;
            setTaxonomia(nuevaTaxonomia);
            switch (nuevaTaxonomia) {
                case 1:
                    setTiempo(15);
                    break;
                case 2:
                    setTiempo(20);
                    break;
                case 3:
                    setTiempo(30);
                    break;
                case 4:
                    setTiempo(40);
                    break;
                case 5:
                    setTiempo(50);
                    break;
                case 6:
                    setTiempo(60);
                    break;
            }
            break;
        }
        case 4:{
            cout << "¿Qué desea hacer?\n 1. Agregar alternativa\n 2. Eliminar alternativa\n 3. Editar alternativa\n";
            int subOpcion;
            cin >> subOpcion;
            if (subOpcion == 1) {
                cout << "Ingrese la nueva alternativa: ";
                string nuevaAlternativa;
                cin.ignore();
                getline(cin, nuevaAlternativa);
                agregarAlternativa(nuevaAlternativa, cantidadAlternativas);
            } else if (subOpcion == 2) {
                cout << "Ingrese el índice de la alternativa a eliminar: ";
                int indiceEliminar;
                cin >> indiceEliminar;
                eliminarAlternativa(indiceEliminar - 1);
            } else if (subOpcion == 3) {
                cout << "Ingrese el índice de la alternativa a editar: ";
                int indiceEditar;
                cin >> indiceEditar;
                cout << "Ingrese la nueva alternativa: ";
                string nuevaAlternativa;
                cin.ignore();
                getline(cin, nuevaAlternativa);
                editarAlternativa(indiceEditar - 1, nuevaAlternativa);
            }
            break;
        }
    }
    return;
}
void P_Alternativa::responderPregunta(){
    mostrarPregunta();
    cout << "Ingrese su respuesta: ";
    string respuestaUsuario;
    cin.ignore();
    getline(cin, respuestaUsuario);
    setRespuesta(respuestaUsuario);
    return;
}

void P_Alternativa::crearPregunta(){
    crearPregunta();
    cout << "Ingrese la cantidad de alternativas: ";
    int cantidadAlternativas;
    cin >> cantidadAlternativas;
    delete[] alternativas;
    alternativas = new string[cantidadAlternativas];
    cantidadAlternativas = cantidadAlternativas;
    for (int i = 0; i < cantidadAlternativas; i++) {
        cout << "Ingrese la alternativa " << i + 1 << ": ";
        string alternativa;
        cin.ignore();
        getline(cin, alternativa);
        alternativas[i] = alternativa;
    }
    switch (getTaxonomia()) {
        case 1:
            setTiempo(15);
            break;
        case 2:
            setTiempo(20);
            break;
        case 3:
            setTiempo(30);
            break;
        case 4:
            setTiempo(40);
            break;
        case 5:
            setTiempo(50);
            break;
        case 6:
            setTiempo(60);
            break;
    }
    return;
}

void P_Alternativa::buscarPregunta(const string& asignatura, int nivel) {
    ifstream archivo("Universidad/" + asignatura + "/" + asignatura + ".txt");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo.\n";
        return;
    }
    string linea;
    while (getline(archivo, linea)) {
        try {
            int tipo = stoi(linea);
            if (tipo == 3) {
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
                        getline(archivo, linea);
                        this->cantidadAlternativas = stoi(linea);
                        delete[] alternativas;
                        alternativas = new string[this->cantidadAlternativas];
                        for (int i = 0; i < this->cantidadAlternativas; i++) {
                            getline(archivo, alternativas[i]);
                        }
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