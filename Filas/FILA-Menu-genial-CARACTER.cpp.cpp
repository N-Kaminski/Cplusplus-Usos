#include <iostream>
#include <string> // para string
using namespace std;

struct Nodo {
    string dato; // cambiar a string para aceptar nombres con espacios
    Nodo *siguiente;
};

// Funciones para manipular la cola
void encolar(Nodo *&, Nodo *&, const string &);
void desencolar(Nodo *&, Nodo *&, string &);
bool frente(Nodo *, string &);
bool vacia(Nodo *);
void verCola(Nodo *);

int main() {
    Nodo *frente = NULL;
    Nodo *fin = NULL;
    int opcion;
    string dato;
    char rta;

    do {
        cout << "**** Menu de Usuario: ****\n";
        cout << " 1. Insertar elemento a la cola\n";
        cout << " 2. Quitar elemento de la cola\n";
        cout << " 3. Vaciar toda la cola\n";
        cout << " 4. Ver los elementos de la cola\n";
        cout << " 5. Salir\n";
        cout << " Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // limpiar el buffer de entrada
        cout << endl;

        switch (opcion) {
            case 1:
                do {
                    cout << "Digite un nombre: ";
                    getline(cin, dato); // usar getline para aceptar nombres con espacios
                    encolar(frente, fin, dato);

                    cout << "\nDeseas agregar mas elementos a la cola? (s/n): ";
                    cin >> rta;
                    cin.ignore(); // limpiar el buffer de entrada
                } while (rta == 's' || rta == 'S');
                break;
            case 2:
                do {
                    if (!vacia(frente)) {
                        desencolar(frente, fin, dato);
                        cout << "Elemento " << dato << " quitado de la cola\n";
                    } else {
                        cout << "La cola esta vacia\n";
                    }

                    cout << "\nDeseas quitar mas elementos de la cola? (s/n): ";
                    cin >> rta;
                    cin.ignore(); // limpiar el buffer de entrada
                } while ((rta == 's' || rta == 'S') && !vacia(frente));
                break;
            case 3:
                cout << "Vaciando la cola...\n";
                while (!vacia(frente)) {
                    desencolar(frente, fin, dato);
                    cout << "Elemento " << dato << " quitado de la cola\n";
                }
                break;
            case 4:
                verCola(frente);
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

// Función para insertar un elemento en la cola
void encolar(Nodo *&frente, Nodo *&fin, const string &dato) {
    Nodo *nuevoNodo = new Nodo(); // crear espacio en memoria para el Nodo
    nuevoNodo->dato = dato; // igualar el dato que envia el usuario y ponerlo en el nodo
    nuevoNodo->siguiente = NULL; // el nuevo nodo será el último, entonces su siguiente es NULL
    if (vacia(frente)) {
        frente = nuevoNodo; // si la cola está vacía, el nuevo nodo es el frente
    } else {
        fin->siguiente = nuevoNodo; // si no está vacía, enlazamos el último nodo actual al nuevo nodo
    }
    fin = nuevoNodo; // actualizamos el fin de la cola
    cout << "Elemento " << dato << " se agrego a la cola\n";
}

// Función para quitar un elemento de la cola
void desencolar(Nodo *&frente, Nodo *&fin, string &dato) {
    dato = frente->dato; // obtener el dato del nodo frente
    Nodo *aux = frente; // crear un auxiliar para liberar memoria
    if (frente == fin) { // si solo hay un nodo en la cola
        frente = NULL;
        fin = NULL;
    } else {
        frente = frente->siguiente; // el nuevo frente es el siguiente nodo
    }
    delete aux; // liberar el nodo antiguo frente
}

// Función para obtener el elemento en el frente de la cola
bool frente(Nodo *frente, string &dato) {
    if (frente != NULL) {
        dato = frente->dato;
        return true;
    }
    return false;
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
