#include <iostream>
#include <string.h>

using namespace std;

struct Persona{
    char nombre[20];
    int edad;
}persona1;



int main() {

    cout<<"Nombre: ";
    cin.getline(persona1.nombre, 20, '\n');
    cout<<"Edad: ";
    cin>>persona1.edad;

    cout<<"\nImprimiendo Datos\n";
    cout<<"Nombre: "<<persona1.nombre;
    cout<<"Edad: "<<persona1.edad;


    return 0;
}

