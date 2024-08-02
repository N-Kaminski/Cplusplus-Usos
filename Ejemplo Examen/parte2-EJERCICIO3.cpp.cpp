#include <iostream>
#include <queue>
#include <string>

using namespace std;


struct Vehiculo {
    string patente;
    string titular;
    int integrantes;
};

// Crear un vehiculo
Vehiculo crearVehiculo() {
    Vehiculo v;
    cout << "Ingrese la patente del vehiculo: ";
    cin >> v.patente;
    cin.ignore();
    cout << "Ingrese el nombre del titular: ";
    getline(cin, v.titular);
    cout << "Ingrese la cantidad de integrantes: ";
    cin >> v.integrantes;
    return v;
}

// Cola de entrada
void hacerColaEntrada(queue<Vehiculo>& FilaEntrada) {
    char ingresar;
    do {
        Vehiculo v = crearVehiculo();
        FilaEntrada.push(v);
        cout << "Ingresar otro vehiculo en la fila de entrada? (s/n): ";
        cin >> ingresar;
    } while (ingresar == 's' || ingresar == 'S');
}

// Derivar vehículos por zona
void derivarPorZona(queue<Vehiculo>& FilaEntrada, queue<Vehiculo>& ZonaEste, queue<Vehiculo>& ZonaOeste) {
    while (!FilaEntrada.empty()) {
        Vehiculo v = FilaEntrada.front();
        FilaEntrada.pop();
        char zona;
        cout << "Vehiculo con patente " << v.patente << ", titular " << v.titular << ": Desea acampar en Zona Este (E) u Oeste (O)? ";
        cin >> zona;
        if (zona == 'E' || zona == 'e') {
            ZonaEste.push(v);
        } else {
            ZonaOeste.push(v);
        }
    }
}

// Mostrar la fila de una zona
void mostrarFilaZona(queue<Vehiculo> Zona, string nombreZona) {
    cout << "Fila de la " << nombreZona << ":" << endl;
    while (!Zona.empty()) {
        Vehiculo v = Zona.front();
        Zona.pop();
        cout << "Patente: " << v.patente << ", Titular: " << v.titular << ", Integrantes: " << v.integrantes << endl;
    }
    cout << endl;
}

int main() {
    queue<Vehiculo> FilaEntrada; 
    queue<Vehiculo> ZonaEste;
    queue<Vehiculo> ZonaOeste;

    hacerColaEntrada(FilaEntrada);
    derivarPorZona(FilaEntrada, ZonaEste, ZonaOeste);
    
    cout << "Ocupacion del camping\n" << endl;
    
    mostrarFilaZona(ZonaEste, "Zona Este");
    mostrarFilaZona(ZonaOeste, "Zona Oeste");

    return 0;
}
