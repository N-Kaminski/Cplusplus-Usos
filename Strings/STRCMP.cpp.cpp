#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char palabra[]="banco";
    char palabra2[]="avion";

    if(strcmp(palabra, palabra2)>0){
         cout<<"la palabra: "<<palabra<<"esta despues alfabeticamente"<<endl;
    }


    return 0;
}

