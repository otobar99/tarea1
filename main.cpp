#include <iostream>
#include <string>
#include <fstream>

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
            cout << "1. Crear evaluacion\n2. Revisar evaluacion\n3. Editar evaluacion\n" << endl;
            int accion;
            cin >> accion;
            Evaluacion evaluacion = Evaluacion();
            if (accion == 1){
                evaluacion.crearEvaluacion(universidad.getAsignaturas()[asignaturaIndex-1], profesor.getNombre());
            } else if (accion == 2){
                cout << "Ingrese el nombre de la evaluacion que desea revisar: " << endl;
            } else if (accion == 3){
                cout << "Ingrese el nombre de la evaluacion que desea editar: " << endl;
            }
        }
    }
    return 0;
}