#include <iostream>

using namespace std;

void llenarMatriz(int [][10],int, int);
void mostrarMatriz(int [][10], int, int);
void sumarMatriz(int [][10],int [][10], int, int);
void restarMatriz(int [][10],int [][10], int, int);

int main() {
    int matrizA[10][10], matrizB[10][10], fil, col;

    //tamaño
    cout<<"Ingrese en numero de filas: ";cin>>fil;
    cout<<"Ingrese en numero de columnas: ";cin>>col;

    //rellenado matriz
    cout<<"\nRellene la matriz A: "<<endl;
    llenarMatriz(matrizA, fil, col);
    cout<<"\nRellene la matriz B: "<<endl;
    llenarMatriz(matrizB, fil, col);

    //impresion matriz
    cout<<"\nLa matriz A es: "<<endl;
    mostrarMatriz(matrizA, fil, col);
    cout<<"\nLa matriz B es: "<<endl;
    mostrarMatriz(matrizB, fil, col);

    //Suma matriz
    cout<<"\nLa suma es: "<<endl;
    sumarMatriz(matrizA, matrizB, fil, col);

    //Resta Matriz
    cout<<"\nLa resta es: "<<endl;
    restarMatriz(matrizA, matrizB, fil, col);


    return 0;
}

//Funsion LLENAR
void llenarMatriz(int p1[][10],int p2, int p3){
    for(int i=0; i<p2; i++){
        for(int j=0; j<p3;j++){
            cout<<"digite un numero ["<<i<<"]["<<j<<"]: ";
            cin>> p1[i][j];
        }
    }
    cout<<endl;
}

//Funsion MOSTRAR
void mostrarMatriz(int p1[][10], int p2, int p3){
    for(int i=0; i<p2; i++){
        for(int j=0; j<p3; j++){
            cout<<p1[i][j]<<" ";
        }
        cout<<"\n";
    }
}

//Funsion SUMAR
void sumarMatriz(int p1[][10],int p4[][10], int p2, int p3){
    for(int i=0; i<p2; i++){
        for(int j=0; j<p3; j++){
            cout<<(p1[i][j]+p4[i][j])<<" ";
        }
        cout<<"\n";
    }
}

//Funsion RESTAR
void restarMatriz(int p1[][10],int p4[][10], int p2, int p3){
    for(int i=0; i<p2; i++){
        for(int j=0; j<p3; j++){
            cout<<(p1[i][j]-p4[i][j])<<" ";
        }
        cout<<"\n";
    }
}
