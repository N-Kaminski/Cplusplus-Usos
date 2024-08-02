#include <iostream>

using namespace std;

int main() {
    int num[100][100], fil, col;

    cout<<"Ingrese en numero de filas: ";cin>>fil;
    cout<<"Ingrese en numero de columnas: ";cin>>col;

    //almacena en matriz
    for(int i=0; i<fil; i++){
        for(int j=0; j<col;j++){
            cout<<"digite un numero ["<<i<<"]["<<j<<"]";
            cin>> num[i][j];
        }
    }

    //imprime matriz
    for(int i=0; i<fil; i++){
        for(int j=0; j<col;j++){
            cout<<num[i][j];
        }
        cout<<endl;
    }


    return 0;
}

