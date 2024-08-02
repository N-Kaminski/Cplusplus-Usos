#include <iostream>
#include <stack> // Biblioteca est�ndar para usar pilas

using namespace std;

int main() {
    stack<int> pila;

    // A�adir elementos a la pila (push)
    pila.push(10);
    pila.push(20);
    pila.push(30);

    // Mostrar el elemento en la parte superior de la pila (top)
    cout << "Elemento en la parte superior: " << pila.top() << endl; // Deber�a imprimir 30

    // Eliminar el elemento en la parte superior de la pila (pop)
    pila.pop();

    // Mostrar el nuevo elemento en la parte superior
    cout << "Nuevo elemento en la parte superior: " << pila.top() << endl; // Deber�a imprimir 20

    // Vaciar la pila
    while (!pila.empty()) {
        cout << "Eliminando elemento: " << pila.top() << endl;
        pila.pop();
    }

    return 0;
}
