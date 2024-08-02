#include <iostream>

using namespace std;

//Prototipo de Funcion
template <class TIPOD>
void mostrarAbsoluto(TIPOD numero);

int main(){
    int num1=-4;
    float num2=56.67;
    double num3=-123.5689;

    mostrarAbsoluto(num1);
    mostrarAbsoluto(num2);
    mostrarAbsoluto(num3);


    return 0;
}

template <class TIPOD>
void mostrarAbsoluto(TIPOD numero){
    if (numero<0){
            numero=numero*-1;
    }

    cout<<"El valor absoluto es: "<<numero<<endl;
}


