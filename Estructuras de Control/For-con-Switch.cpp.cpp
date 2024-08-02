#include <iostream>

using namespace std;

int main(){

    char frase[30];
    int va=0, ve=0, vi=0, vo=0, vu=0;

    cout<<"Digite una frase: ";
    cin.getline(frase, 30, '\n');

    for(int i=0; i<30; i++){
        switch(frase[i]){
            case 'a': va++;
            break;
            case 'e': ve++;
            break;
            case 'i': vi++;
            break;
            case 'o': vo++;
            break;
            case 'u': vu++;
            break;
        }
    }

    cout<<"La vocal A se encontro: "<<va<<" veces"<<endl;
    cout<<"La vocal E se encontro: "<<ve<<" veces"<<endl;
    cout<<"La vocal I se encontro: "<<vi<<" veces"<<endl;
    cout<<"La vocal O se encontro: "<<vo<<" veces"<<endl;
    cout<<"La vocal U se encontro: "<<vu<<" veces"<<endl;

    return 0;
}

