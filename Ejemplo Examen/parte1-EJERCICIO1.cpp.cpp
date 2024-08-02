#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
int main() {
	char miStarCafe[200]="CaramelCafeMacciato-mediano-RollChoco";
	char delimitador[]="-";
	char *token = strtok(miStarCafe,delimitador);
	cout<<"A------------------------------------"<<endl;
	cout<<"El token de cafe es: "<<token<< endl;
	
	int longitud = strlen(token);
	cout<<"B ------------------------------------"<<endl;
    cout << "Longitud del token: " << longitud << endl;
	cout<<"C i ------------------------------------"<<endl;
	if (strstr(strlwr(token), "cafe") != NULL) {
        cout << "El token contiene la palabra 'cafe'." << endl;
    } else {
        cout << "El token no contiene la palabra 'cafe'." << endl;
    }

	cout<<"C ii ------------------------------------"<<endl;
	 strcat(token, "Latte");
    cout << "Anexando 'Latte': " << token << endl;
    cout<<"D ------------------------------------"<<endl;
    char vocal;
	cout<<"ingrese una vocal : ";
	cin>>vocal;
	
if(vocal=='a' || vocal=='e' || vocal=='i' || vocal=='o' || vocal=='u' ||vocal=='A' || vocal=='E' || vocal=='I' || vocal=='O' || vocal=='U'){
           if (strchr(token, vocal) != NULL) {
            cout << "La letra '" << vocal << "' esta en el token." << endl;
            } else {
            cout << "La letra '" << vocal << "' no esta en el token." << endl;
            }
    }
    else{
        cout << "La letra no es una vocal";
    }
    
    
	return 0;
	
}
