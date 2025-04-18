#include <iostream>
#include <string>
#include <fstream>
#ifdef _WIN32
#include <windows.h>
#include <fcntl.h>
#include <io.h>
#endif

#include "Asignatura.h"
#include "Profesor.h"
#include "Estudiante.h"
#include "Persona.h"
#include "Pregunta.h"
#include "Evaluacion.h"
#include "P_VF.h"
#include "P_Alternativa.h"
#include "Universidad.h"

int main() {
#ifdef _WIN32
    // Configurar la consola como utf-8 en windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    Universidad universidad;
    int opcion = 3;
    string r;
    while(opcion != 0){
        cout << "Bienvenido a la " << universidad.getNombreUniversidad() << endl;
        cout << "1. Ingresar como Estudiante\n2. Ingresar como Profesor" << endl;
        cin >> opcion;
        if (opcion == 1){
            cout << "1. Estudiante nuevo\n2. Estudiante existente" << endl;
            cin >> opcion;
            cout << "Ingrese su rut: ";
            cin >> r;
            Estudiante estudiante = Estudiante();
            estudiante.AsignarEstudiante(opcion,r,universidad.getAsignaturas(), universidad.getNAsignaturas());
        } else if(opcion == 2){
            string ev;
            cout << "1. Profesor nuevo\n2. Profesor existente" << endl;
            cin >> opcion;
            cout << "Ingrese su rut: ";
            cin >> r;
            Profesor profesor = Profesor();
            profesor.AsignarProfesor(opcion,r);
            cout << "Ingrese la asignatura que desea ingresar: " << endl;
            for(int i = 0; i < universidad.getNAsignaturas(); i++){
                cout << i+1 << ". " << universidad.getAsignaturas()[i] << endl;
            }
            int asignaturaIndex;
            cin >> asignaturaIndex;
            cout << "Que desea hacer?" << endl;
            cout << "1. Crear evaluacion\n2. Ver evaluacion\n3. Editar evaluacion\n" << endl;
            int accion;
            cin >> accion;
            Evaluacion evaluacion = Evaluacion();
            if (accion == 1){
                evaluacion.crearEvaluacion(universidad.getAsignaturas()[asignaturaIndex-1], profesor.getNombre());
            } else if (accion == 2){
                cout << "Ingrese el nombre de la evaluacion que desea ver: " << endl;
                cin.ignore();
                getline(cin, r);
                evaluacion.leerEvaluacion("Universidad/"+universidad.getAsignaturas()[asignaturaIndex-1]+"/"+r+".txt");
                evaluacion.imprimirEvaluacion();
            } else if (accion == 3){
                cout << "Ingrese el nombre de la evaluacion que desea editar: " << endl;
                cin.ignore();
                getline(cin, r);
                evaluacion.leerEvaluacion("Universidad/"+universidad.getAsignaturas()[asignaturaIndex-1]+"/"+r+".txt");
                evaluacion.editarEvaluacion();
            }
        }
        cout << "Desea realizar otra accion?" << endl;
        int continuar;
        cout << "1. Si\n2. No" << endl;
        cin >> continuar;
        if (continuar == 2) {
            return 0;
        }
    }
    return 0;
}