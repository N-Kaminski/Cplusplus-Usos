#include <iostream>
#include <string.h>

using namespace std;


int main() {
    int numeros [100], n;

    cout << "Cuantos elementos va a tener el arreglo?";
    cin >> n;

    for(int i=0; i<n; i++){
        cout<<"Digite un numero: ";
        cin >> numeros[i]; // guardando todos los elementos del vector
    }

    cout <<"Mostrando elementos:"<<endl;
    for(int i=0; i<n; i++){
        cout <<i<<" -> "<<numeros[i]<<endl;
    }

    return 0;
}

