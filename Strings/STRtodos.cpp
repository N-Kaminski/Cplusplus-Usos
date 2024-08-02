#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char palabra1[] = "Hola";
    char palabra2[] = " Mundo";
    char palabra3[50];

    cout<<"la 1er palabra es: "<<palabra1<< endl;
    cout<<"la 2da palabra es: "<<palabra2<< endl;
    cout<<"la 3ra palabra es: "<<palabra3<< endl;

    // strcpy: copia palabra1 en palabra3
    strcpy(palabra3, palabra1);
    cout << "Resultado de strcpy (1 a 3): " << palabra3 << endl;

    // strcat: concatena palabra2 a palabra3
    strcat(palabra3, palabra2);
    cout << "Resultado de strcat (2 a 3): " << palabra3 << endl;

    // strlen: longitud de palabra3
    cout << "Longitud de palabra3: " << strlen(palabra3) << endl;

    // strcmp: compara palabra1 y palabra2
    int resultado = strcmp(palabra1, palabra2);
    if (resultado == 0) {
        cout << "palabra1 y palabra2 son iguales" << endl;
    } else if (resultado < 0) {
        cout << "palabra1 es menor que palabra2" << endl;
    } else {
        cout << "palabra1 es mayor que palabra2" << endl;
    }

    // strupr: convierte palabra3 a minúsculas
    cout << "Palabra3 en mayuscula: " << strupr(palabra3) << endl;

    // strlwr: convierte palabra3 a minúsculas
    cout << "Palabra3 en minusculas: " << strlwr(palabra3) << endl;

    // strrev: invierte palabra3
    cout << "Palabra3 invertida: " << strrev(palabra3) << endl;

    //  strchr: verifica letra en palabra
    char letra;
    cout << "Ingrese una letra: ";
    cin >> letra;

    if (strchr(palabra1, letra) != nullptr) {
        cout << "La letra '" << letra << "' si esta en la cadena '" << palabra1 << "'\n";
    } else {
        cout << "La letra '" << letra << "' no esta en la cadena '" << palabra1 << "'\n";
    }

    return 0;
}
