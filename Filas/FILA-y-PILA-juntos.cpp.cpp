#include <iostream>
#include <stdlib.h>

using namespace std;

// Definición del nodo para estructuras de datos
struct Nodo {
    int dato;
    Nodo *siguiente;    //puntero al siguiente nodo
};

// Funciones para la *PILA*
void push(Nodo *&, int);    //agrega elementos
void pop(Nodo *&, int &);   //elimina elementos
bool top(Nodo *, int &);    //elemento superior (ultimo en entrar)
bool empty(Nodo *);         // esta vacia?
void verPila(Nodo *);       //muestra elementos

// Funciones para la *FILA*
void encolar(Nodo *&, Nodo *&, int);        //agrega elemento
void desencolar(Nodo *&, Nodo *&, int &);   //elimina elemento
bool frente(Nodo *, int &);                 //elemento que esta al frente (primero que entro)
bool vacia(Nodo *);                         //esta vacia?
void verCola(Nodo *);                       //muestra elementos

int main() {
    Nodo *pila = NULL;
    Nodo *frenteCola = NULL;
    Nodo *finCola = NULL;
    int opcion, dato;
    char rta;

    do {
        cout << "**** Menu de Usuario ****\n";
        cout << " PILA:\n";
        cout << "1. Insertar elemento a la Pila\n";
        cout << "2. Quitar elemento de la Pila\n";
        cout << "3. Vaciar toda la Pila\n";
        cout << "4. Ver los elementos de la Pila\n";
        cout << " FILA:\n";
        cout << "5. Insertar elemento a la Fila\n";
        cout << "6. Quitar elemento de la Fila\n";
        cout << "7. Vaciar toda la Fila\n";
        cout << "8. Ver los elementos de la Fila\n";
        cout << " JUNTOS:\n";
        cout << "9. Pasar un objeto de la PILA a la FILA\n";
        cout << "10. Pasar un objeto de la FILA a la PILA\n";
        cout << "11. Pasar todos los objetos de la PILA a la FILA\n";
        cout << "12. Pasar todos los objetos de la FILA a la PILA\n";
        cout << "13. Salir\n";
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
                do {
                    cout << "Digite un numero: ";
                    cin >> dato;
                    encolar(frenteCola, finCola, dato);

                    cout << "\nDeseas agregar mas elementos a la cola? (s/n): ";
                    cin >> rta;
                } while (rta == 's' || rta == 'S');
                break;
            case 6:
                do {
                    if (!vacia(frenteCola)) {
                        desencolar(frenteCola, finCola, dato);
                        cout << "Elemento " << dato << " quitado de la cola\n";
                    } else {
                        cout << "La cola esta vacia\n";
                    }

                    cout << "\nDeseas quitar mas elementos de la cola? (s/n): ";
                    cin >> rta;
                } while ((rta == 's' || rta == 'S') && !vacia(frenteCola));
                break;
            case 7:
                cout << "Vaciando la cola...\n";
                while (!vacia(frenteCola)) {
                    desencolar(frenteCola, finCola, dato);
                    cout << "Elemento " << dato << " quitado de la cola\n";
                }
                break;
            case 8:
                verCola(frenteCola);
                break;
            case 9:
                if (!empty(pila)) {
                    pop(pila, dato);
                    encolar(frenteCola, finCola, dato);
                    cout << "Elemento " << dato << " pasado de la pila a la cola\n";
                } else {
                    cout << "La pila esta vacia, no se puede pasar elementos\n";
                }
                break;
            case 10:
                if (!vacia(frenteCola)) {
                    desencolar(frenteCola, finCola, dato);
                    push(pila, dato);
                    cout << "Elemento " << dato << " pasado de la cola a la pila\n";
                } else {
                    cout << "La cola esta vacia, no se puede pasar elementos\n";
                }
                break;
            case 11:
                while (!empty(pila)) {
                    pop(pila, dato);
                    encolar(frenteCola, finCola, dato);
                    cout << "Elemento " << dato << " pasado de la pila a la cola\n";
                }
                break;
            case 12:
                while (!vacia(frenteCola)) {
                    desencolar(frenteCola, finCola, dato);
                    push(pila, dato);
                    cout << "Elemento " << dato << " pasado de la cola a la pila\n";
                }
                break;
            case 13:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida\n";
        }
        cout << endl;
    } while (opcion != 13);

    return 0;
}

//******* PILA *********
// Función para insertar un elemento en la pila
void push(Nodo *&pila, int num) {
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->dato = num;
    nuevoNodo->siguiente = pila;
    pila = nuevoNodo;
}

// Función para quitar un elemento de la pila
void pop(Nodo *&pila, int &num) {
    Nodo *aux = pila;
    num = aux->dato;
    pila = aux->siguiente;
    delete aux;
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

//******* FILA *********
// Función para insertar un elemento en la cola
void encolar(Nodo *&frente, Nodo *&fin, int num) {
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->dato = num;
    nuevoNodo->siguiente = NULL;
    if (vacia(frente)) {
        frente = nuevoNodo;
    } else {
        fin->siguiente = nuevoNodo;
    }
    fin = nuevoNodo;
}

// Función para quitar un elemento de la cola
void desencolar(Nodo *&frente, Nodo *&fin, int &num) {
    num = frente->dato;
    Nodo *aux = frente;
    if (frente == fin) {
        frente = NULL;
        fin = NULL;
    } else {
        frente = frente->siguiente;
    }
    delete aux;
}

// Función para verificar si la cola está vacía
bool vacia(Nodo *frente) {
    return (frente == NULL);
}

// Función para ver todos los elementos de la cola
void verCola(Nodo *frente) {
    if (vacia(frente)) {
        cout << "La cola esta vacia\n";
    } else {
        cout << "Elementos de la cola: ";
        Nodo *aux = frente;
        while (aux != NULL) {
            cout << aux->dato << " | ";
            aux = aux->siguiente;
        }
        cout << endl;
    }
}
