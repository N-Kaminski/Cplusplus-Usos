#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

struct Fecha{
    int dia;
    int mes;
    int anio;
};

struct Persona{
    char nombre[20];
    int edad;
    float peso;
    struct Fecha fechaNac;
};

struct Empleado {
    struct Persona personaX;
    float salario;
    struct Fecha fechaContratacion;
};

//Funciones
void mostrarPersona(const Persona& persona);
void mostrarEmpleado(const Empleado& empleado);


int main() {

        //Se carga a Veronica, 20, 45.0, 2/12/1997

        Persona veronica;

        cout<<"CARGANDO A VERONICA\n";
        cout<<"Nombre Persona: ";
        cin.ignore();
        cin.getline(veronica.nombre, 20, '\n');
        cout<<"Edad Persona: ";
        cin>> veronica.edad;
        cout<<"Peso Persona: ";
        cin>> veronica.peso;
        cout<<"Fecha Nacimiento\n";
        cout<<"Dia: ";
        cin>>veronica.fechaNac.dia;
        cout<<"Mes: ";
        cin>>veronica.fechaNac.mes;
        cout<<"Año: ";
        cin>>veronica.fechaNac.anio;
        cout<<endl;

            //Empleado: Nombre-edad-peso-fecha nacimiento-salario-fecha contratacion
        Empleado esteban = {{"Esteban", 19, 60.0, {22, 7, 1998}}, 351667.19, {1, 1, 2022}};

        //Mostrar Datos
        cout << "Datos de Veronica:\n";
        mostrarPersona(veronica);
        cout << endl;

        cout << "Datos de Esteban:\n";
        mostrarEmpleado(esteban);
        cout << endl;

        //arreglo de trabajadores
        Empleado trabajadores[3] = {
            esteban,
            {{"Mariana", 25, 55.0, {15, 5, 1995}}, 400000.00, {15, 3, 2021}},
            {{"Juan", 30, 70.0, {10, 10, 1990}}, 500000.00, {20, 8, 2020}}
        };

        //mostrar todos los trabajadores
        cout << "Datos de los trabajadores:\n";
        for (int i = 0; i < 3; ++i) {
            cout << "\nTrabajador " << i + 1 << ":\n";
            mostrarEmpleado(trabajadores[i]);
        }


    return 0;
}

// Funcion para mostrar los datos de una persona
void mostrarPersona(const Persona& persona) {
    cout << "Nombre: " << persona.nombre << endl;
    cout << "Edad: " << persona.edad << endl;
    cout << "Peso: " << persona.peso << " kg" << endl;
    cout << "Fecha de Nacimiento: " << persona.fechaNac.dia<< "/"
         << persona.fechaNac.mes << "/" << persona.fechaNac.anio << endl;
}

// Funcion para mostrar los datos de un empleado
void mostrarEmpleado(const Empleado& empleado) {
    mostrarPersona(empleado.personaX);
    cout << "Salario: $" << fixed << setprecision(2) << empleado.salario << endl;
    cout << "Fecha de Contratación: " << empleado.fechaContratacion.dia << "/"
         << empleado.fechaContratacion.mes << "/" << empleado.fechaContratacion.anio << endl;
}
