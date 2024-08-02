#include <iostream>

using namespace std;

void llenarMatriz(int [][10],int, int);
void mostrarMatriz(int [][10], int, int);
void productoMatriz(int [][10],int [][10],int [][10], int, int, int);


int main() {
    int matrizA[10][10], matrizB[10][10], matrizC[10][10], filA, colA, filB, colB;

    //tamaño
    cout<<"Ingrese en numero de filas para A: ";cin>>filA;
    cout<<"Ingrese en numero de columnas para A: ";cin>>colA;
    cout<<"Ingrese en numero de filas para B: ";cin>>filB;
    cout<<"Ingrese en numero de columnas para B: ";cin>>colB;

    if(colA==filB){
        //rellenado matriz
        cout<<"\nRellene la matriz A: "<<endl;
        llenarMatriz(matrizA, filA, colA);
        cout<<"\nRellene la matriz B: "<<endl;
        llenarMatriz(matrizB, filB, colB);

        //impresion matriz
        cout<<"\nLa matriz A es: "<<endl;
        mostrarMatriz(matrizA, filA, colA);
        cout<<"\nLa matriz B es: "<<endl;
        mostrarMatriz(matrizB, filB, colB);

        //Producto matriz
        cout<<"\nEl producto es: "<<endl;
        productoMatriz(matrizA, matrizB, matrizC, colA, filA, colB);
    }
    else{
        cout<<"No se pueden multiplicar las matrices"<<endl;
    }

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

//Funsion multiplicar
void productoMatriz(int p1[][10],int p4[][10],int p5[][10],int p6, int p2, int p3){    // p1:MatrizA | p4:matrizB| p5:matrizC | p6:colA | p2:filA | p3:colB

    for(int i=0; i<p2; i++){    //filA
        for(int j=0; j<p3; j++){    //colB
            p5[i][j]=0;
        }
    }

    for(int i=0; i<p2; i++){    //filA
        for(int j=0; j<p3; j++){    //colB
            for(int k=0; k<p6; k++){  //colA
                p5[i][j]=(p5[i][j]+(p1[i][k]*p4[k][j]));
            }
        }
    }

    for(int i=0; i<p2; i++){    //filA
        for(int j=0; j<p3; j++){    //colB
            cout<<p5[i][j]<<" ";
        }
        cout<<"\n";
    }
}



