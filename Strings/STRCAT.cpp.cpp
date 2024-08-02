#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char palabra[]="Esto es una cadena";
    char palabra2[]=" de ejemplo";
    char palabra3[30];

    strcpy(palabra3, palabra);  //copio lo de palabra en palabra3
    strcat(palabra3, palabra2); //le agrego a palabra3 lo de palabra2

    cout<<palabra3<<endl;


    return 0;
}

