#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char palabra1[]="palabra";
    char palabra2[20];
    char palabra3[30];

    cout<<"Ingrese otra palabra: ";
    cin.getline(palabra2, 20, '\n');

    strcpy(palabra3, palabra1);
    strcat(palabra3, palabra2);

    cout<<palabra3<<endl;

    int opcion;e
    do {
        cout << "\nMenu de opciones:\n";
        cout << "1. Determinar la longitud de la cadena\n";
        cout << "2. Solicitar otra cadena\n";
        cout << "3. Solicitar otra letra\n";
        cout << "4. Comparar con 'Examen de EDA'\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                int longitud = strlen(palabra3);
                cout << "Longitud de la cadena: " << longitud << endl;
                break;
            }
            case 2: {
                char otraCadena[30];
                cout << "Ingrese otra cadena: ";
                cin.ignore();
                cin.getline(otraCadena, 30, '\n');

                            // Verificar si es una subcadena de la primera
                if (strstr(palabra1, otraCadena) != nullptr) {
                    cout << "\nLa cadena '" << otraCadena << "' es una subcadena de '" << palabra1 << "'\n";
                } else {
                    cout << "\nLa cadena '" << otraCadena << "' no es una subcadena de '" << palabra1 << "'\n";
                }

                            // Unirla a la primera separarla por un guion, y comparar cuál es la cadena más larga
                char palabraConGuion[100];
                strcpy(palabraConGuion, palabra1);
                strcat(palabraConGuion, "-");
                strcat(palabraConGuion, otraCadena);

                cout << "\nEl resultado es: " << palabraConGuion << endl;

                if (strlen(palabra1) > strlen(palabraConGuion)) {
                    cout << "La cadena original es + larga.\n";
                } else {
                    cout << "La cadena nueva es + larga.\n";
                }
                break;
            }
            case 3: {
                char letra;
                cout << "Ingrese una letra: ";
                cin >> letra;

                if (strchr(palabra1, letra) != nullptr) {
                    cout << "La letra '" << letra << "' si esta en la cadena '" << palabra1 << "'\n";
                } else {
                    cout << "La letra '" << letra << "' no esta en la cadena '" << palabra1 << "'\n";
                }
                break;
            }
            case 4: {
                char cadena[] = "Examen de EDA";
                char cadenaIngresada[100];
                cout << "Ingrese una cadena para comparar: ";
                cin.ignore();
                cin.getline(cadenaIngresada, 100, '\n');

                if(strcasecmp(cadena, cadenaIngresada)==0){
                    cout<<"\nLas cadenas son iguales"<<endl;
                }
                else{
                    cout<<"\nLas cadenas son distintas"<<endl;
                }
                break;
            }
            case 5:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida\n";
        }
    } while (opcion != 5);

    return 0;
}
