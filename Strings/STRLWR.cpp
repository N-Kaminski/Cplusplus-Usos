#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char palabra[]="Hola QUE Tal?";

    cout<<"\nLa palabra es: "<<palabra<<endl;

    strlwr(palabra);
    cout<<"\nLa palabra en minuscula es: "<<palabra<<endl;

    return 0;
}



