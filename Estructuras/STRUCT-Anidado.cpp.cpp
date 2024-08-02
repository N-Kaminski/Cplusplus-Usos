#include <iostream>
#include <string.h>

using namespace std;

struct InfoDireccion{
    char direccion[30];
    char ciudad[20];
    char pais[20];
};

struct Empleado{
    char nombre[20];
    struct InfoDireccion dirEmpleado;
    double salario;
}empleados[2];


int main() {

    for(int i=0; i<2; i++){
            fflush(stdin);//Vacia el Buffer
        cout<<"Nombre empleado: ";
        cin.getline(empleados[i].nombre, 20, '\n');
        cout<<"Direccion empleado: ";
        cin.getline(empleados[i].dirEmpleado.direccion, 30, '\n');
        cout<<"Ciudad empleado: ";
        cin.getline(empleados[i].dirEmpleado.ciudad, 20, '\n');
        cout<<"Pais empleado: ";
        cin.getline(empleados[i].dirEmpleado.pais, 20, '\n');
        cout<<"Salario empleado: ";
        cin>> empleados[i].salario;
        cout<<endl;
    }

    //Imprimir datos
    for(int i=0; i<2; i++){
        cout<<"Nombre :"<<empleados[i].nombre<<endl;
        cout<<"Direccion :"<<empleados[i].dirEmpleado.direccion<<endl;
        cout<<"Ciudad :"<<empleados[i].dirEmpleado.ciudad<<endl;
        cout<<"Pais :"<<empleados[i].dirEmpleado.pais<<endl;
        cout<<"Salario :"<<empleados[i].salario<<endl;
    }

    return 0;
}

