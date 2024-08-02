#include <iostream>

using namespace std;

//Prototipo de Funcion
int mayor(int, int);


int main(){
    int n1, n2;

    cout<<"Digite 2 numeros: ";
    cin>>n1>>n2;

    cout<<"El mayor es: "<<mayor(n1, n2)<<endl;

    return 0;
}

int mayor(int p1, int p2){
    int max;

    if(p1>p2){
        max=p1;
    }
    else{
        max=p2;
    }

    return max;
}
