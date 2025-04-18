#include "Evaluacion.h"
#include <iostream>

using namespace std;

// Constructor vacío
Evaluacion::Evaluacion(){
    listaPreguntas = nullptr;
    n_preguntas[0] = 0;
    n_preguntas[1] = 0;
    n_preguntas[2] = 0;
    profesor = " ";
    alumno = " ";
    rut = " ";
    tipoEvaluacion = " ";
    ponderacion = 0;
    nota = 0;
    puntaje_total = 0;
    puntaje_obtenido = 0;
    tiempo = 0;
}

// Métodos getters
Pregunta** Evaluacion::getListaPreguntas() const {
    return listaPreguntas;
}

const int* Evaluacion::getNPreguntas() const {
    return n_preguntas;
}

string Evaluacion::getProfesor() const {
    return profesor;
}

string Evaluacion::getAlumno() const {
    return alumno;
}

string Evaluacion::getTipoEvaluacion() const {
    return tipoEvaluacion;
}

int Evaluacion::getPonderacion() const {
    return ponderacion;
}

float Evaluacion::getNota() const {
    return nota;
}

// Métodos setters
void Evaluacion::setProfesor(const string profesor) {
    this->profesor = profesor;
}

void Evaluacion::setAlumno(const string alumno) {
    this->alumno = alumno;
}

void Evaluacion::setTipoEvaluacion(const string& tipoEvaluacion) {
    this->tipoEvaluacion = tipoEvaluacion;
}

void Evaluacion::setPonderacion(int ponderacion) {
    this->ponderacion = ponderacion;
}

void Evaluacion::setNota(float nota) {
    this->nota = nota;
}

void Evaluacion::setNPreguntas(int index, int valor) {
    if (index >= 0 && index < 3) {
        n_preguntas[index] = valor; // Modifica un elemento de la lista de tamaño fijo
    } else {
        cout << "Índice fuera de rango.\n";
    }
}

void Evaluacion::agregarPregunta() {
    cout << "Ingrese el tipo de pregunta: \n1. Verdadero o Falso\n2. Alternativa\n3. Respuesta Corta\n";
    int tipoPregunta;
    cin >> tipoPregunta;
    Pregunta** nuevaLista = new Pregunta*[n_preguntas[0] + n_preguntas[1] + n_preguntas[2] + 1];
    cout << "1. Crear pregunta\n2. Aleatorio\n";
    int opcion;
    cin >> opcion;
    switch (opcion) {
        case 1:
            if (tipoPregunta == 1) {
                listaPreguntas[n_preguntas[0] + n_preguntas[1] + n_preguntas[2]] = new P_VF();
                listaPreguntas[n_preguntas[0] + n_preguntas[1] + n_preguntas[2]]->crearPregunta();
                nuevaLista[n_preguntas[0] + n_preguntas[1] + n_preguntas[2]] = listaPreguntas[n_preguntas[0] + n_preguntas[1] + n_preguntas[2]];
                n_preguntas[0]++;
            } else if (tipoPregunta == 2) {
                listaPreguntas[n_preguntas[0] + n_preguntas[1] + n_preguntas[2]] = new P_Alternativa();
                listaPreguntas[n_preguntas[0] + n_preguntas[1] + n_preguntas[2]]->crearPregunta();
                nuevaLista[n_preguntas[0] + n_preguntas[1] + n_preguntas[2]] = listaPreguntas[n_preguntas[0] + n_preguntas[1] + n_preguntas[2]];
                n_preguntas[1]++;
            } else {
                cout << "Tipo de pregunta no válido.\n";
            }
            break;
    }
}

void Evaluacion::eliminarPregunta(int indice) {
    if (indice >= 0 && indice < n_preguntas[0] + n_preguntas[1] + n_preguntas[2] && listaPreguntas != nullptr) {
        // Liberar la memoria de la pregunta que se va a eliminar
        delete listaPreguntas[indice];

        // Crear una nueva lista con un tamaño reducido
        Pregunta** nuevaLista = new Pregunta*[n_preguntas[0] + n_preguntas[1] + n_preguntas[2] - 1];

        for (int i = 0, j = 0; i < n_preguntas[0] + n_preguntas[1] + n_preguntas[2]; ++i) {
            if (i != indice) {
                nuevaLista[j++] = listaPreguntas[i]; // Copiar todas las preguntas excepto la eliminada
            }
        }

        // Liberar la memoria de la lista antigua
        delete[] listaPreguntas;

        // Asignar la nueva lista
        listaPreguntas = nuevaLista;

        // Reducir el conteo de preguntas
        if (indice < n_preguntas[0]) {
            n_preguntas[0]--;
        } else if (indice < n_preguntas[0] + n_preguntas[1]) {
            n_preguntas[1]--;
        } else {
            n_preguntas[2]--;
        }
    } else {
        cout << "Índice fuera de rango o lista de preguntas no inicializada.\n";
    }
}

// Métodos específicos
void Evaluacion::imprimirEvaluacion() const {
    cout << "Profesor: " << profesor << "\n";
    cout << "Alumno: " << alumno << "\n";
    cout << "Tipo de evaluación: " << tipoEvaluacion << "\n";
    cout << "Ponderación: " << ponderacion << "\n";
    cout << "Nota: " << nota << "\n";
    cout << "Número de preguntas por sección:\n";
    cout << "Sección 1: " << n_preguntas[0] << "\n";
    cout << "Sección 2: " << n_preguntas[1] << "\n";
    cout << "Sección 3: " << n_preguntas[2] << "\n";
    cout << "Preguntas:\n";
    if (listaPreguntas != nullptr) {
        for (int i = 0; i < n_preguntas[0] + n_preguntas[1] + n_preguntas[2]; ++i) {
            cout << i + 1 << ". ";
            if (listaPreguntas[i] != nullptr) {
                listaPreguntas[i]->imprimirPregunta();
            } else {
                cout << "Pregunta no disponible.\n";
            }
        }
    } else {
        cout << "No hay preguntas en esta evaluación.\n";
    }
}

// Destructor
Evaluacion::~Evaluacion() {
    if (listaPreguntas != nullptr) {
        for (int i = 0; i < n_preguntas[0] + n_preguntas[1] + n_preguntas[2]; ++i) {
            delete listaPreguntas[i];
        }
        delete[] listaPreguntas;
    }
}

void Evaluacion::leerEvaluacion(string nombreArchivo) {
    ifstream eval(nombreArchivo);

    if (!eval.is_open()) {
        cerr << "Error abriendo archivo." << std::endl;
        return;
    }

    string linea;
    getline(eval, profesor);
    getline(eval, alumno);
    getline(eval, tipoEvaluacion);
    eval >> ponderacion;
    eval >> nota;
    eval >> n_preguntas[0];
    eval >> n_preguntas[1];
    eval >> n_preguntas[2];
    for(int i = 0; i < n_preguntas[0] + n_preguntas[1] + n_preguntas[2]; ++i) {
        if (i < n_preguntas[0]) {
            listaPreguntas[i] = new P_VF();
        } else if (i < n_preguntas[0] + n_preguntas[1]) {
            listaPreguntas[i] = new P_Alternativa();
        } else {
            listaPreguntas[i] = new Pregunta();
        }
        listaPreguntas[i]->leerPregunta(eval);
    }
    eval.close();
    return;
}
void Evaluacion::crearEvaluacion(string asignatura, string profesor) {
    this->profesor = profesor;
    cout << "Ingrese el tipo de evaluación: ";
    cin >> tipoEvaluacion;
    cout << "Ingrese la ponderación: ";
    cin >> ponderacion;
    cout << "Ingrese cuantas preguntas verdadero o falso: ";
    cin >> n_preguntas[0];
    cout << "Ingrese cuantas preguntas de alternativas: ";
    cin >> n_preguntas[1];
    cout << "Ingrese cuantas preguntas de respuesta corta: ";
    cin >> n_preguntas[2];

    // Liberar memoria previa si existe
    if (listaPreguntas != nullptr) {
        for (int i = 0; i < n_preguntas[0] + n_preguntas[1] + n_preguntas[2]; ++i) {
            delete listaPreguntas[i];
        }
        delete[] listaPreguntas;
    }

    // Crear nuevo arreglo de punteros
    listaPreguntas = new Pregunta*[n_preguntas[0] + n_preguntas[1] + n_preguntas[2]];

    for (int i = 0; i < n_preguntas[0] + n_preguntas[1] + n_preguntas[2]; i++) {
        if (i < n_preguntas[0]) {
            cout << "Pregunta verdadero o falso: " << i + 1 << endl;
            listaPreguntas[i] = new P_VF();
        } else if (i < n_preguntas[0] + n_preguntas[1]) {
            cout << "Pregunta de alternativas: " << i + 1 - n_preguntas[0] << endl;
            listaPreguntas[i] = new P_Alternativa();
        } else {
            cout << "Pregunta de respuesta corta: " << i + 1 - n_preguntas[0] - n_preguntas[1] << endl;
            listaPreguntas[i] = new Pregunta();
        }

        cout << "Quiere crear una pregunta, o que se elija aleatoreamente?" << endl;
        cout << "1. Crear pregunta" << endl;
        cout << "2. Aleatorio" << endl;
        int opcion;
        cin >> opcion;
        if (opcion == 1) {
            listaPreguntas[i]->crearPregunta();
        } else if (opcion == 2) {
            cout << "Elija el nivel taxonómico: " << endl;
            cout << "1. Recordar" << endl;
            cout << "2. Comprender" << endl;
            cout << "3. Aplicar" << endl;
            cout << "4. Analizar" << endl;
            cout << "5. Sintetizar" << endl;
            int nivel;
            cin >> nivel;
            listaPreguntas[i]->buscarPregunta(asignatura, nivel);
            if (listaPreguntas[i]->getEnunciado() == " ") {
                cout << "No se encontró una pregunta adecuada.\n";
                i--;
                continue;
            }
        }

        this->tiempo += listaPreguntas[i]->getTiempo();
        listaPreguntas[i]->mostrarPregunta();
    }
    guardarEvaluacion(asignatura);
    imprimirEvaluacion();
}

void Evaluacion::guardarEvaluacion(string asignatura){
    ofstream archivo("Universidad/"+asignatura+"/"+getTipoEvaluacion()+".txt", std::ios::out | std::ios::app); // write & append
    archivo << profesor << "\n";
    archivo << alumno << "\n";
    archivo << tipoEvaluacion << "\n";
    archivo << ponderacion << "\n";
    archivo << nota << "\n";
    archivo << n_preguntas[0] << "\n";
    archivo << n_preguntas[1] << "\n";
    archivo << n_preguntas[2] << "\n";
    if (listaPreguntas != nullptr) {
        for (int i = 0; i < n_preguntas[0] + n_preguntas[1] + n_preguntas[2]; ++i) {
            cout << i + 1 << ". ";
            if (listaPreguntas[i] != nullptr) {
                listaPreguntas[i]->guardarPregunta(archivo);
            } else {
                cout << "Pregunta no disponible.\n";
            }
        }
    } else {
        cout << "No hay preguntas en esta evaluación.\n";
    }
}

void Evaluacion::editarEvaluacion(){
    int opcion = -1;
    while (opcion != 0) {
        cout << "Que desea editar: \n1. tipo de evaluacion\n2. ponderacion\n3. pregunta\n4. Agregar pregunta\n0. Salir\n";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "Ingrese el nuevo tipo de evaluacion: ";
                cin >> tipoEvaluacion;
                break;
            case 2:
                cout << "Ingrese la nueva ponderacion: ";
                cin >> ponderacion;
                break;
            case 3:{
                cout << "Ingrese el numero de la pregunta que desea editar: ";
                int numPregunta;
                cin >> numPregunta;
                cout << "Que desea editar?\n1. Editar\n2. Eliminar\n";
                int opcion2;
                cin >> opcion2;
                switch (opcion2) {
                    case 1:
                        listaPreguntas[numPregunta]->editarPregunta();
                        break;
                    case 2:
                        eliminarPregunta(numPregunta - 1);
                        break;
                    default:
                        cout << "Opción inválida.\n";
                        break;
                }
                break;
            }
            case 4:
                agregarPregunta();
            default:
                cout << "Opción inválida.\n";
                break;
        }
    }
}

void Evaluacion::realizarEvaluacion(string rut, string alumno) {
    this->rut = rut;
    this->alumno = alumno;
    int numPregunta = -1;
    while (numPregunta != 0) {
        imprimirEvaluacion();
        cout << "Ingrese la pregunta que quiera responder (0. Para terminar): ";
        cin >> numPregunta;
        if (numPregunta != 0) {
            if (numPregunta > 0 && numPregunta <= n_preguntas[0] + n_preguntas[1] + n_preguntas[2]) {
                listaPreguntas[numPregunta - 1]->responderPregunta();
            } else {
                cout << "Número de pregunta inválido.\n";
            }
        }
    }
}
void Evaluacion::revisarEvaluacion(){
    return;
}