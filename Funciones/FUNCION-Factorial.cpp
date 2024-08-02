#include <iostream>

using namespace std;

//Prototipo de Funcion
int factorial(int);


int main(){

    cout<<"Factorial: "<<factorial(5)<<endl;

    return 0;
}

int factorial(int p1){
    if(p1==0){
        p1=1;
    }
    else{
        p1*=factorial(p1-1);    //funsion recursiva - se llama a si misma.
    }

    return p1;
}


