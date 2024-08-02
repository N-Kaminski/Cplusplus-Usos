#include <iostream>

using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;  // 'ptr' apunta al primer elemento del array

    // Acceso a elementos usando aritmética de punteros
    cout << "Primer elemento: " << *ptr << endl;
    cout << "Segundo elemento: " << *(ptr + 1) << endl;
    cout << "Tercer elemento: " << *(ptr + 2) << endl;

    // Incrementar puntero para apuntar al siguiente elemento
    ptr++;
    cout << "Después de incrementar, segundo elemento: " << *ptr << endl;

    return 0;
}
