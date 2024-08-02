#include <iostream>

using namespace std;

//Prototipo de Funcion
void mostrarMatriz(int p1[][3], int, int);
void calcularCuadrado(int [][3],int, int);

int main(){
    const int fil=2;
    const int col=3;
    int mat[fil][col]={{1,2,3},{4,5,6}};

    cout<<"Mostrando matriz original\n";
    mostrarMatriz(mat, fil, col);
    calcularCuadrado(mat, fil, col);
    cout<<"Mostrando matriz elevada al cuadrado\n";
    mostrarMatriz(mat, fil, col);


    return 0;
}

void mostrarMatriz(int p1[][3], int p2, int p3){    //p1: matriz, p2: fila, p3: columna
    for(int i=0; i<p2; i++){
        for(int j=0; j<p3; j++){
            cout<<p1[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void calcularCuadrado(int p1[][3], int p2, int p3){ //p1: matriz, p2: fila, p3: columna
    for(int i=0; i<p2; i++){
        for(int j=0; j<p3; j++){
            p1[i][j]*=p1[i][j];
        }
        cout<<"\n";
    }
}
