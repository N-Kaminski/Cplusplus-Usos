#include <iostream>

using namespace std;


int main(){
    int num[]={1,2,3,4,5}, *puntNum;

    puntNum=num;

    cout<<"Posicion de memoria"<<endl;
    for(int i=0; i<5;i++){
        cout<<"Elemento del vector ["<<i<<"]: "<<puntNum<<endl;//imprime la posicion de memoria de cada numero del vector
    }

    cout<<"Numero en vector"<<endl;
     for(int i=0; i<5;i++){
        cout<<"Elemento del vector ["<<i<<"]: "<<*puntNum++<<endl;//imprime lo que tiene la memoria
    }


    return 0;
}



