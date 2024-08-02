#include <iostream>
#include <string>

using namespace std;

struct Auto {
    string modelo;
    string patente;
};

struct TDApeaje {
    Auto via[2][5];
    int frente[2];
    int fin[2];
    int cuenta[2];
};

//Funciones
void inicializarPeaje(TDApeaje& peaje);
bool push(TDApeaje& peaje, int via, const string& modelo, const string& patente);
bool pop(TDApeaje& peaje, int via, Auto& vehiculo);
void mostrarVehiculo(const Auto& vehiculo);

int main() {
    TDApeaje peaje;
    inicializarPeaje(peaje);

    // Cargar vehiculos en la via comun (fila 0)
    push(peaje, 0, "Cronos", "AS 459 GT");
    push(peaje, 0, "Frontier", "BX 123 LT");
    push(peaje, 0, "Ka", "CZ 321 RT");
    push(peaje, 0, "Corolla", "DF 456 WQ");

    // Cargar un vehiculo en la via rapida (fila 1)
    push(peaje, 1, "Vento", "AZ 234 RT");

    // Sacar un vehiculo de cada via
    Auto vehiculo;
    cout << "Desencolando vehiculo de la via comun (fila 0):" << endl;
    if (pop(peaje, 0, vehiculo)) {
        mostrarVehiculo(vehiculo);
    } else {
        cout << "La via comun esta vacia." << endl;
    }

    cout << "Desencolando vehiculo de la via rapida (fila 1):" << endl;
    if (pop(peaje, 1, vehiculo)) {
        mostrarVehiculo(vehiculo);
    } else {
        cout << "La via rapida esta vacia." << endl;
    }

    return 0;
}

// Inicializar el peaje
void inicializarPeaje(TDApeaje& peaje) {
    for (int i = 0; i < 2; ++i) {
        peaje.frente[i] = 0;
        peaje.fin[i] = 0;
        peaje.cuenta[i] = 0;
    }
}

// Insertar vehiculo en una via especifica
bool push(TDApeaje& peaje, int via, const string& modelo, const string& patente) {
    if (peaje.cuenta[via] < 5) {
        peaje.via[via][peaje.fin[via]].modelo = modelo;
        peaje.via[via][peaje.fin[via]].patente = patente;
        peaje.fin[via] = (peaje.fin[via] + 1) % 5;
        peaje.cuenta[via]++;
        return true;
    } else {
        return false; // La via esta llena
    }
}

// Suprimir vehiculo de una via especifica
bool pop(TDApeaje& peaje, int via, Auto& vehiculo) {
    if (peaje.cuenta[via] > 0) {
        vehiculo = peaje.via[via][peaje.frente[via]];
        peaje.frente[via] = (peaje.frente[via] + 1) % 5;
        peaje.cuenta[via]--;
        return true;
    } else {
        return false; // La via esta vacia
    }
}

// Mostrar informacion del vehiculo
void mostrarVehiculo(const Auto& vehiculo) {
    cout << "Modelo: " << vehiculo.modelo << ", Patente: " << vehiculo.patente << endl;
}
