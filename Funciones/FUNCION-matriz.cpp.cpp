#include <iostream>

using namespace std;

//Prototipo de Funcion
void mostrarMatriz(int p1[][3], int, int);//la fila puede quedar vacia pero columnas no

int main(){
    const int fil=2;
    const int col=3;
    int mat[fil][col]={{1,2,3},{4,5,6}};

    mostrarMatriz(mat, fil, col);

    return 0;
}

void mostrarMatriz(int p1[][3], int p2, int p3){
    cout<<"Mostrando matriz original\n";
    for(int i=0; i<p2; i++){
        for(int j=0; j<p3; j++){
            cout<<p1[i][j]<<" ";
        }
        cout<<"\n";
    }

}


