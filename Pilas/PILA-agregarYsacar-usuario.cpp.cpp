#include <iostream>
#include <stdlib.h> // para new

using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

void agregarPila(Nodo *&, int); //Nodo *&= parametro de tipo Nodo puntero pasado por referencia
void sacarPila(Nodo *&, int &);

int main(){
    Nodo *pila=NULL;
    int dato;
    char rta;

    do{
        cout<<"Digite un numero: ";
        cin>>dato;
        agregarPila(pila, dato);

        cout<<"\nDeseas agregar mas elementos a la pila? (s/n)";
        cin>>rta;
    }while((rta=='s')||(rta=='S'));


    cout<<"\nSacando los lementos de la pila: ";
    while(pila!=NULL){  //mientras no sea el final de la pila
        sacarPila(pila, dato);
        if(pila != NULL){
            cout<<dato<<" , ";
        }
        else{
            cout<<dato<<".";
        }
    }

    return 0;
}

void agregarPila(Nodo *&pila, int num){
    Nodo *nuevoNodo= new Nodo(); //crear espacio en memoria para el Nodo
    nuevoNodo->dato=num;    // igualar el dato que envia el usuario y ponerlo en el nodo
    nuevoNodo->siguiente=pila;  // poner el puntero e igualarlo a pila
    pila=nuevoNodo; //igualar pila al nuevo nodo

    cout<<"\nElemento "<<num<<" se agrego a la pila";
}

void sacarPila(Nodo *&pila, int &num){
    Nodo *aux=pila; // crear variable aux e igualar a pila
    num= aux->dato; // aux tiene que tomar el valor de dato
    pila=aux->siguiente;    // pila señala al siguiente nodo
    delete aux; // se borra el dato del nodo
}
