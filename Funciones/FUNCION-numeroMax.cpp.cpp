#include <iostream>

using namespace std;

//Prototipo de Funcion
int encontrarMax(int x, int y);

int main(){
    int n1, n2;

    cout <<"Digite 2 numeros: ";
    cin>>n1>>n2;

    cout <<"\nEl numero max es: "<<encontrarMax(n1, n2)<<endl;

    return 0;
}

int encontrarMax(int x, int y){
    int numMax;

    if(x>y){
        numMax=x;
    }
    else{
        numMax=y;
    }

    return numMax;
}


