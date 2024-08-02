#include <iostream>

using namespace std;


int main(){
    int num, *puntNum;

    num=20;
    puntNum=&num;  //le agrego la posicion de memoria de num al puntero

    cout<<"Numero: "<<num<<endl;
    cout<<"Direccion de numero: "<<&num<<" --- se usa &num"<<endl;// & es la direccion de memoria del numero
    cout<<"El numero con puntero: "<<*puntNum<<" --- se usa *num"<<endl;// *apunta a la dir de memoria y trae lo que tiene (osea el numero)
    cout<<"Direccion de numero con puntero: "<<puntNum<<" --- se usa la variable"<<endl; // apunta a la dir de memoria, pero como no tiene * trae la dir de memoria


    cout<<"\nRes: "<<puntNum<<endl;
    puntNum=puntNum+1;

    cout<<"Res: "<<puntNum<<endl;

    cout<<"tamaño que ocupa de memoria"<<endl;

    return 0;
}



