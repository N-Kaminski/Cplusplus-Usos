#include <iostream>

using namespace std;

int main() {
    char palabra[]="Nicolas";
    char palabra2[]={'N','i','c','o','l','a','s'};
    char nombre[20];
    char nombre2[20];

    cout<<palabra<<endl;
    cout<<palabra2<<endl;

    cout<<"\nDigite su nombre"<<endl;
    gets(nombre); //usa memoria que no le pertenece

    cout<<nombre<<endl;

    cout<<"\nDigite su nombre"<<endl;
    cin.getline(nombre2, 20, '\n');  // variable|tamaño|cuando termina.

    cout<<nombre2<<endl;

    return 0;
}

