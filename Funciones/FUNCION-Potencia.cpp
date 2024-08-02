#include <iostream>

using namespace std;

//Prototipo de Funcion
int potencia(int, int);


int main(){
    int base, exponente;

    cout<<"Digite la base: ";
    cin>>base;
    cout<<"Digite el Exponente: ";
    cin>>exponente;

    cout<<"\nLa potencia es: "<<potencia(base, exponente);

    return 0;
}

int potencia(int p1, int p2){
    int pot;

    if(p2==1){
        pot=p1;
    }
    else{
        pot= p1*potencia(p1, p2-1);
    }

    return pot;
}



