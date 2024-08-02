
#include<iostream>
using namespace std;

int main () {
    int x, y, aux;

    cout << "Digite el valor de X: "; cin >> x;
    cout << "Digite el valor de Y: "; cin >> y;

    cout << "X vale : "<<x<<endl;
    cout << "Y vale : "<<y<<endl;

    aux=x;
    x=y;
    y=aux;

    cout << "nueva X vale : "<<x<<endl;
    cout << "nuevo Y vale : "<<y<<endl;

return 0;
}
