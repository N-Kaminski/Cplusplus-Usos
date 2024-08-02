#include <iostream>

using namespace std;

struct Punto {
    int x;
    int y;
};

void mostrarPuntoPorReferencia(Punto &p) {
    p.x = 10;  // Modificación afecta al original
    cout << "Punto dentro de la funcion (por referencia): (" << p.x << ", " << p.y << ")" << endl;
}

int main() {
    Punto p1 = {1, 2};
    mostrarPuntoPorReferencia(p1);
    cout << "Punto despurs de la funcion (por referencia): (" << p1.x << ", " << p1.y << ")" << endl;
    return 0;
}
