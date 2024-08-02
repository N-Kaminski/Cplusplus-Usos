#include <iostream>

using namespace std;

void llenarMatriz(int [][10],int, int);
void mostrarMatriz(int [][10], int, int);
int mayorMatriz(int [][10], int, int);

int main() {
    int matriz[10][10], fil, col;

    //tamaño
    cout<<"Ingrese en numero de filas: ";cin>>fil;
    cout<<"Ingrese en numero de columnas: ";cin>>col;

    //rellenado matriz
    cout<<"\nRellene la matriz: "<<endl;
    llenarMatriz(matriz, fil, col);

    //impresion matriz
    cout<<"\nLa matriz es: "<<endl;
    mostrarMatriz(matriz, fil, col);


    //Mayor matriz
    cout<<"\nEl mayor elemento es: "<<mayorMatriz(matriz, fil, col)<<endl;

    return 0;
}

//Funsion LLENAR
void llenarMatriz(int p1[][10],int p2, int p3){
    for(int i=0; i<p2; i++){
        for(int j=0; j<p3;j++){
            cout<<"Digite un numero ["<<i<<"]["<<j<<"]: ";
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

//Funsion MAYOR
int mayorMatriz(int p1[][10], int p2, int p3){
    int mayor=p1[0][0];

    for(int i=0; i<p2; i++){
        for(int j=0; j<p3; j++){
            if(mayor<p1[i][j]){
                mayor=p1[i][j];
            }
        }
    }
    return mayor;
}

