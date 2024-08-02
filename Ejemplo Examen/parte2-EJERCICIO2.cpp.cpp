#include <iostream>
#include <vector>

using namespace std;

enum PREMIO { VIDA, COIN, FLOR, HONGO };

struct Cubo {
    int nro;
    PREMIO premio;
};

string premioToString(PREMIO premio) {
    switch (premio) {
        case VIDA: return "VIDA";
        case COIN: return "COIN";
        case FLOR: return "FLOR";
        case HONGO: return "HONGO";
        default: return "";
    }
}

// Definicion de la clase para la Pila
class Pila {
private:
    Cubo TuboCubo[5];  // Arreglo para almacenar los elementos
    int tope;          // Indice del tope de la pila

public:
    // Constructor para inicializar la pila
    Pila() : tope(-1) {}

    // Funcion para insertar un elemento en la pila
    bool push(Cubo elemento) {
        if (tope < 4) {
            TuboCubo[++tope] = elemento;
            return true;
        } else {
            cout << "El tubo está lleno, no se puede agregar más elementos." << endl;
            return false;
        }
    }

    // Funcion para eliminar un elemento de la pila
    bool pop(Cubo& elemento) {
        if (tope >= 0) {
            elemento = TuboCubo[tope--];
            return true;
        } else {
            cout << "El tubo está vacío, no se puede eliminar elementos." << endl;
            return false;
        }
    }

    // Funcion para mostrar el contenido de la pila en forma de columna
    void mostrar() const {
        for (int i = tope; i >= 0; --i) {
            cout << "[ " << TuboCubo[i].nro << " - " << premioToString(TuboCubo[i].premio) << " ]" << endl;
        }
        cout << endl;
    }

    // Funcion para verificar si la pila esta vacia
    bool vacia() const {
        return tope == -1;
    }

    // Funcion para verificar si la pila esta llena
    bool llena() const {
        return tope == 4;
    }

    // Funcion para obtener el Indice del tope
    int obtenerTope() const {
        return tope;
    }

    // Funcion para obtener el valor de un elemento en una posicion especifica
    Cubo obtenerElemento(int indice) const {
        return TuboCubo[indice];
    }
} TuboA, TuboV, TuboR;  // Declaracion global de las pilas

vector<Cubo> Vidas;  // Vector para almacenar las vidas 1Up

// Funcion para cargar la pila TuboA
void cargarTuboA() {
    TuboA.push({1, VIDA});
    TuboA.push({2, COIN});
    TuboA.push({3, FLOR});
    TuboA.push({4, VIDA});
    TuboA.push({5, HONGO});
}

// Funcion para pasar los elementos de TuboA a TuboR y luego a TuboV
void pasarTuboA_TuboV() {
    Cubo temp;
    while (!TuboA.vacia()) {
        TuboA.pop(temp);
        TuboR.push(temp);
    }
    while (!TuboR.vacia()) {
        TuboR.pop(temp);
        TuboV.push(temp);
    }
}

// Funcion para guardar las vidas en el vector Vidas
void guardarVidas() {
    Cubo temp;
    while (!TuboV.vacia()) {
        TuboV.pop(temp);
        if (temp.premio == VIDA) {
            Vidas.push_back(temp);
        }
    }
}

// Funcion para mostrar las vidas en el vector Vidas
void mostrarVidas() {
    for (const auto& vida : Vidas) {
        cout << "Vida " << vida.nro << ": " << premioToString(vida.premio) << endl;
    }
}

int main() {
    cargarTuboA();
    cout << "Contenido de TuboA:" << endl;
    TuboA.mostrar();

    pasarTuboA_TuboV();
    cout << "Contenido de TuboV:" << endl;
    TuboV.mostrar();

    guardarVidas();
    cout << "Vidas guardadas en Vidas:" << endl;
    mostrarVidas();

    return 0;
}
