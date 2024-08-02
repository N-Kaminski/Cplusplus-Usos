#include <iostream>
#include <stdlib.h> // para new

using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

// Funciones para manipular la pila
void push(Nodo *&, int);
void pop(Nodo *&, int &);
bool top(Nodo *, int &);
bool empty(Nodo *);
void verPila(Nodo *);

int main() {
    Nodo *pila = NULL;
    int opcion, dato;
    char rta;

    do {
        cout << "**** Menu de Usuario:\n ****";
        cout << "1. Insertar elemento a la pila\n";
        cout << "2. Quitar elemento de la pila\n";
        cout << "3. Vaciar toda la pila\n";
        cout << "4. Ver los elementos de la pila\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << endl;

        switch (opcion) {
            case 1:
                do {
                    cout << "Digite un numero: ";
                    cin >> dato;
                    push(pila, dato);

                    cout << "\nDeseas agregar mas elementos a la pila? (s/n): ";
                    cin >> rta;
                } while (rta == 's' || rta == 'S');
                break;
            case 2:
                do {
                    if (!empty(pila)) {
                        pop(pila, dato);
                        cout << "Elemento " << dato << " quitado de la pila\n";
                    } else {
                        cout << "La pila esta vacia\n";
                    }

                    cout << "\nDeseas quitar mas elementos de la pila? (s/n): ";
                    cin >> rta;
                } while ((rta == 's' || rta == 'S') && !empty(pila));
                break;
            case 3:
                cout << "Vaciando la pila...\n";
                while (!empty(pila)) {
                    pop(pila, dato);
                    cout << "Elemento " << dato << " quitado de la pila\n";
                }
                break;
            case 4:
                verPila(pila);
                break;
            case 5:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida\n";
        }
        cout << endl;
    } while (opcion != 5);

    return 0;
}

// Función para insertar un elemento en la pila
void push(Nodo *&pila, int num) {
    Nodo *nuevoNodo = new Nodo(); // crear espacio en memoria para el Nodo
    nuevoNodo->dato = num; // igualar el dato que envia el usuario y ponerlo en el nodo
    nuevoNodo->siguiente = pila; // poner el puntero e igualarlo a pila
    pila = nuevoNodo; // igualar pila al nuevo nodo
    cout << "Elemento " << num << " se agrego a la pila\n";
}

// Función para quitar un elemento de la pila
void pop(Nodo *&pila, int &num) {
    Nodo *aux = pila; // crear variable aux e igualar a pila
    num = aux->dato; // aux tiene que tomar el valor de dato
    pila = aux->siguiente; // pila señala al siguiente nodo
    delete aux; // se borra el dato del nodo
}

// Función para obtener el elemento en la parte superior de la pila
bool top(Nodo *pila, int &num) {
    if (pila != NULL) {
        num = pila->dato;
        return true;
    }
    return false;
}

// Función para verificar si la pila está vacía
bool empty(Nodo *pila) {
    return (pila == NULL);
}

// Función para ver todos los elementos de la pila
void verPila(Nodo *pila) {
    if (empty(pila)) {
        cout << "La pila esta vacia\n";
    } else {
        cout << "Elementos de la pila: ";
        Nodo *aux = pila;
        while (aux != NULL) {
            cout << aux->dato << " | ";
            aux = aux->siguiente;
        }
        cout << endl;
    }
}
