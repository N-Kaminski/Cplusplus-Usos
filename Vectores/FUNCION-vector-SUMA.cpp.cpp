#include <iostream>

using namespace std;

//Prototipo de Funcion
void pedirDatos();
int calcularSuma(int vec[], int);

int vec[100], tam;

int main(){

    pedirDatos();

    return 0;
}

void pedirDatos(){
    cout<<"Digite el numeros de elementos del vector: ";
    cin>>tam;

    for(int i=0; i<tam; i++){
        cout<<i+1<<". Digite un numero: ";
        cin>>vec[i];
    }

    cout<<"\nLa suma es: "<<calcularSuma(vec, tam)<<endl;
}

int calcularSuma(int vec[], int tam){
    int suma=0;

    for(int i=0; i<tam; i++){
        suma+=vec[i];
    }

    return suma;
}
