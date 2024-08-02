#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char palabra[]="Hola que tal?";
    char palabra2[20];

    strcpy(palabra2, palabra);

    cout<<"la palabra es : "<<palabra<<endl;
    cout<<"la palabra 2 es : "<<palabra2<<endl;

    return 0;
}

