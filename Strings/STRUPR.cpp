#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char palabra[]="Hola que tal?";

    cout<<"\nLa palabra es: "<<palabra<<endl;

    strupr(palabra);
    cout<<"\nLa palabra en mayuscula es: "<<palabra<<endl;

    return 0;
}



