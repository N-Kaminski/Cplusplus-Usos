
#include <iostream>
#include <string>
using namespace std;

int main () {
    int num[]={1,2,3,4,5};
    int suma=0;

    for(int i=0; i<5; i++){
        suma += num[i];
    }

    cout<<"la suma es: "<<suma<<endl;


return 0;
}

