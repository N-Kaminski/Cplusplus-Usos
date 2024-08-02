#include <iostream>
#include <stdlib.h> // para new

using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

void agregarPila(Nodo *&, int); //Nodo *&= parametro de tipo Nodo puntero pasado por referencia

int main(){
    Nodo *pila=NULL;

    int n1, n2;
    cout<<"Digite un numero: ";
    cin>>n1;

    agregarPila(pila, n1);

    cout<<"Digite otro numero: ";
    cin>>n2;

    agregarPila(pila, n2);

    return 0;
}

void agregarPila(Nodo *&pila, int num){
    Nodo *nuevoNodo= new Nodo(); //crear espacio en memoria para el Nodo
    nuevoNodo->dato=num;    // igualar el dato que envia el usuario y ponerlo en el nodo
    nuevoNodo->siguiente=pila;  // poner el puntero e igualarlo a pila
    pila=nuevoNodo; //igualar pila al nuevo nodo
}


