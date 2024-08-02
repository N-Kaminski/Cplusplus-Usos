#include <iostream>
#include <stdlib.h> // para new

using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

void agregarFila(Nodo *&,Nodo *&, int); //Nodo *&= parametro de tipo Nodo puntero pasado por referencia
bool filaVacia(Nodo *);
void quitarFila(Nodo *&,Nodo *&, int &);

int main(){
    Nodo *frente=NULL;
    Nodo *fin=NULL;
    char rta;

    int dato;

    do{
        cout<<"Digite un numero: ";
        cin>>dato;
        agregarFila(frente, fin, dato);

        cout<<"\nDeseas agregar mas elementos a la pila? (s/n)";
        cin>>rta;
    }while((rta=='s')||(rta=='S'));

    //Eliminar datos de fila
    cout<<"\nSe quitaran elementos de la fila"<<endl;

    while(frente!=NULL){
        quitarFila(frente, fin, dato);

        if(frente!=NULL){
            cout<<dato<<" , ";
        }
        else{
            cout<<dato<<".";
        }
    }




    return 0;
}

//Funcion para agregar elementos a FILA

void agregarFila(Nodo *&p1,Nodo *&p2, int p3){  //p1=frente | p2=fin
    Nodo *nuevoNodo= new Nodo(); //crear espacio en memoria para el Nodo
    nuevoNodo->dato=p3;    // igualar el dato que envia el usuario y ponerlo en el nodo
    nuevoNodo->siguiente=NULL;  // poner el puntero e igualarlo a pila

    if(filaVacia(p1)){
        p1 = nuevoNodo;
    }
    else{
        p2->siguiente = nuevoNodo;
    }

    p2=nuevoNodo;

    cout<<"El Elemmento "<<p3<<" se inserto correctamente\n";
}


//Funcion para saber si esta vacia o no

bool filaVacia(Nodo *p1){
    if(p1==NULL){   //p1=frente
        return true;
    }
    else {
        return false;
    }
}

//Funcion quitar elementos de fila

void quitarFila(Nodo *&p1,Nodo *&p2, int &p3){  //p1=frente | p2=fin
    p3= p1->dato;   //El dato se iguala al frente de la fila
    Nodo *aux = p1;

    if(p1==p2){
        p1=NULL;
        p2=NULL;
    }
    else{
        p1=p1->siguiente;
    }

    delete aux;

}
