#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char palabra[]="Hola que tal?";
    int longitud=0;

    longitud = strlen(palabra);

    cout<<"El numero de caracteres es: "<<longitud<<endl;

    return 0;
}

