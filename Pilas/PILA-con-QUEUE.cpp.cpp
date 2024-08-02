#include <iostream>
#include <queue>

using namespace std;

class PilaConCola {
private:
    queue<int> cola;

public:
    void push(int x) {
        cola.push(x);

        // Rotar la cola para que el nuevo elemento quede al frente
        for (int i = 0; i < cola.size() - 1; ++i) {
            cola.push(cola.front());
            cola.pop();
        }
    }

    void pop() {
        cola.pop();
    }

    int top() {
        return cola.front();
    }

    bool vacia() {
        return cola.empty();
    }
};

int main() {
    PilaConCola p;
    p.push(1);
    p.push(2);
    p.push(3);

    cout << "Elemento en el tope: " << p.top() << endl;
    p.pop();
    cout << "Elemento en el tope después de pop: " << p.top() << endl;

    return 0;
}
