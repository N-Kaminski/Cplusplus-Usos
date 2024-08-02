
#include <iostream>
#include <string>
using namespace std;

int main () {
    int num, num2;

    cout<< "Digite 2 Numeros: " <<endl;
    cin>> num >> num2;

    if(num==num2){
        cout<< "Los numeros son iguales";
    }
    else if(num>num2){
        cout<< "El numero mayor es : " << num;
    }
    else{
        cout<< "El numero mayor es : " << num2;
    }

        //par impar
    if(num%2==0){
        cout<< "\nEl numero: "<<num<<"es par";<<endl;
    }
    else{
        cout<< "\nEl numero: "<<num<<"es Inpar";<<endl;
    }

    if(num2%2==0){
        cout<< "\nEl numero: "<<num2<<"es par";<<endl;
    }
    else{
        cout<< "\nEl numero: "<<num2<<"es Inpar";<<endl;
    }




return 0;
}

