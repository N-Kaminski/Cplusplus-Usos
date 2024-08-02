#include <iostream>
using namespace std;

const int TAM = 3;

// Prototipos
void cargarMatriz(int p1[][TAM]);
void cargarSucursal(int p1[][TAM], int p2[TAM]);
void cargarArea(int p1[][TAM], int p2[TAM]);
void mostrarMatriz(int p1[][TAM]);
void mostrarVector(int p1[TAM]);


int main() {

    int cantEmpleados[TAM][TAM];
    int sucursal[TAM];
    int area[TAM];


    cargarMatriz(cantEmpleados);

    cargarSucursal(cantEmpleados, sucursal);
    cargarArea(cantEmpleados, area);


    mostrarMatriz(cantEmpleados);
    cout << "\nVector Sucursal: " << endl;
    mostrarVector(sucursal);
    cout << "\nVector Area: " << endl;
    mostrarVector(area);



    return 0;
}

// Funciones
// Carga Matriz
void cargarMatriz(int p1[][TAM]) {
    cout << "Ingrese los numeros para la matriz:" << endl;
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> p1[i][j];
        }
    }
}

// Carga Sucursal:
void cargarSucursal(int p1[][TAM], int p2[TAM]) {    //p1: matriz | p2: sucursal | uso fila i
    for (int i = 0; i < TAM; i++) {
        p2[i] = 0;
        for (int j = 0; j < TAM; j++) {
            p2[i] += p1[i][j];
        }
    }
}

// Carga Area:
void cargarArea(int p1[][TAM], int p2[TAM]) {   //p1: matriz | p2: area |  uso columna j
    for (int j = 0; j < TAM; j++) {
        p2[j] = 0;
        for (int i = 0; i < TAM; i++) {
            p2[j] += p1[i][j];
        }
    }
}

// Mostrar Matriz
void mostrarMatriz(int p1[][TAM]) {
    cout << "\nMatriz de empleados:" << endl;
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            cout << p1[i][j] << " ";
        }
        cout<<"\n";
    }
}

// Mostrar Vector
void mostrarVector(int p1[TAM]) {
    int i = 0;
    while (i < TAM) {
        cout << "[" << i << "]: " << p1[i] << endl;
        i++;
    }
}
