#include <iostream>

using namespace std;

int main() {
    int var = 10;
    int *ptr = &var;  // 'ptr' ahora almacena la dirección de 'var'

    cout << "Valor de var: " << var << endl;           // Imprime el valor de 'var'
    cout << "Dirección de var: " << &var << endl;      // Imprime la dirección de 'var'
    cout << "Valor de ptr: " << ptr << endl;           // Imprime la dirección almacenada en 'ptr' (dirección de 'var')
    cout << "Valor al que apunta ptr: " << *ptr << endl; // Imprime el valor al que apunta 'ptr' (valor de 'var')

    *ptr = 20;  // Modifica el valor de 'var' a través de 'ptr'

    cout << "Nuevo valor de var: " << var << endl;     // Imprime el nuevo valor de 'var'

    return 0;
}
