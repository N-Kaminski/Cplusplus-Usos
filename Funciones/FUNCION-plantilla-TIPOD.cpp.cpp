#include <iostream>

using namespace std;

//Prototipo de Funcion
template <class TIPOD>  //engloba diferentes tipos de datos
void mostrarDato(TIPOD p1);//evito usar int, float, etc


int main(){
    int d1=4;
    float d2=25.68;
    double d3=123.6598;
    char d4='a';

    mostrarDato(d1);
    mostrarDato(d2);
    mostrarDato(d3);
    mostrarDato(d4);

    return 0;
}

template <class TIPOD> //la funcion q viene debajo va a usar una plantilla de funcion
void mostrarDato(TIPOD p1){
    cout<<"El dato es: "<<p1<<endl;
}
