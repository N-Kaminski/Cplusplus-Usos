#include <iostream>
#include <stack>

using namespace std;

class ColaConPila {
private:
    stack<int> pila1;
    stack<int> pila2;

public:
    void encolar(int x) {
        // Movemos todos los elementos de pila a una nueva pila temporal
        while (!pila1.empty()) {
            pila2.push(pila1.top());
            pila1.pop();
        }

        // Insertamos el nuevo elemento al final de la pila
        pila1.push(x);
        while (!pila2.empty()) {
            pila1.push(pila2.top());
            pila2.pop();
        }
    }

    void desencolar() {
        if (!pila1.empty()) {
            pila1.pop();
        }
    }

    int frente() {
        return pila1.top();
    }

    bool vacia() {
        return pila1.empty();
    }
};

int main() {
    ColaConPila c;
    c.encolar(1);
    c.encolar(2);
    c.encolar(3);

    cout << "Frente de la cola: " << c.frente() << endl;
    c.desencolar();
    cout << "Frente de la cola después de desencolar: " << c.frente() << endl;

    return 0;
}
