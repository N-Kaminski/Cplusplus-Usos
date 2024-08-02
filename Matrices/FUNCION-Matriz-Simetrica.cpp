#include <iostream>

using namespace std;

//Prototipo de Funcion
void pedirDatos();
void comprobarSimetria(int p1[][100], int, int);
void mostrarMatriz(int p1[][100], int, int);

int matriz[100][100],fil, col;

int main(){

    pedirDatos();
    mostrarMatriz(matriz, fil, col);
    comprobarSimetria(matriz, fil, col);


    return 0;
}

void pedirDatos(){
    cout<<"Digite el numero de filas: ";
    cin>>fil;
    cout<<"Digite el numero de columnas: ";
    cin>>col;

    for(int i=0; i<fil; i++){
        for(int j=0; j<col; j++){
            cout<<"Digite el numero ["<<i<<"]["<<j<<"]: ";
            cin>>matriz[i][j];
        }
    }
}

void comprobarSimetria(int p1[][100], int p2, int p3){
    int cont=0;

    if(p2==p3){
        for(int i=0; i<p2; i++){
            for(int j=0; j<p3; j++){
                if(p1[i][j]== p1[j][i]){
                    cont ++;
                }
            }
        }
    }

    if(cont == p2*p3){
        cout<<"\nLa matriz es simetrica";
    }
    else{
        cout<<"\nLa matriz NO es simetrica";
    }
}

void mostrarMatriz(int p1[][100], int p2, int p3){    //p1: matriz, p2: fila, p3: columna
    for(int i=0; i<p2; i++){
        for(int j=0; j<p3; j++){
            cout<<p1[i][j]<<" ";
        }
        cout<<"\n";
    }
}


