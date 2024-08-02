#include <iostream>
#include <stdlib.h> // para new
#include <string>
using namespace std;

//Estructura
struct Persona{
    string nombre;
    int edad;
}p1;

//Prototipo de Funcion
void pedirDatos();
void mostrarDatos(Persona);

// Main
int main(){

    pedirDatos();
    mostrarDatos(p1);


    return 0;
}

void pedirDatos(){
    cout<<"Ingrese el nombre: ";
    getline(cin, p1.nombre);
    cout<<"Ingrese la edad: ";
    cin>>p1.edad;
}

void mostrarDatos(Persona p){
    cout<<"\nNombre: "<<p.nombre;
    cout<<"\nEdad: "<<p.edad;
}
