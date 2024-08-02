#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char palabra[]="Hola que tal?";

    cout<<"\nLa palabra es: "<<palabra<<endl;

    strrev(palabra);
    cout<<"\nLa palabra invertida es: "<<palabra<<endl;

    return 0;
}


