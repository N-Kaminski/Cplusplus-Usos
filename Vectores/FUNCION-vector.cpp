#include <iostream>

using namespace std;

//Prototipo de Funcion
void cuadrado(int vec[], int);//los corchetes van vacios
void imprime (int vec[], int);

int main(){
    const int TAM=5;
    int vec[TAM]={1,2,3,4,5};

    cuadrado(vec, TAM);
    imprime(vec, TAM);

    return 0;
}

void cuadrado(int vec[], int tam){
    for(int i=0; i<tam; i++){
        vec[i]*=vec[i];
    }
}

void imprime(int vec[], int tam){
    for(int i=0; i<tam; i++){
        cout<<vec[i]<<" ";
    }
}
