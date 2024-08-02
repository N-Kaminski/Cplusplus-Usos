#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

// Estructura Instantanea
struct Instantanea {
    int dia;
    int mes;
    int anio;
    int horas;
    int minutos;
    int segundos;
};

// Enum GrupoSanguineo
enum GrupoSanguineo { A, B, AB, O };

// Estructura Ciudadano
struct Ciudadano {
    int dni;
    char nombreCompleto[30];
    GrupoSanguineo grupo;
    float peso;
    Instantanea fechaNacimiento;
};

// Estructura Inmunizado
struct Inmunizado {
    Ciudadano ciudadano;
    int cantidadDosis;
    Instantanea fechaUltimaDosis;
};

// Funciones
void cargarCiudadano(Ciudadano &p1);
void mostrarCiudadano(const Ciudadano& p1);
void mostrarInmunizado(const Inmunizado& p1);


int main() {
    // Crear ciudadano Noelia
    Ciudadano noe;
    cout << "Ingrese los datos de Noelia Banegas:" << endl;
    cargarCiudadano(noe);

    // Crear ciudadano Matías Matonti
    Ciudadano matias;
    matias.dni = 35462731;
    strcpy(matias.nombreCompleto, "Matias Matonti");
    matias.grupo = O;
    matias.peso = 61.5;
    matias.fechaNacimiento = {4, 7, 2004, 0, 0, 0};

    // Mostrar ciudadanos
    cout << "\nDatos de Noelia Banegas:" << endl;
    mostrarCiudadano(noe);

    cout << "\nDatos de Matias Matonti:" << endl;
    mostrarCiudadano(matias);

    // Crear inmunizados
    Inmunizado matiasI = {matias, 2, {3, 1, 2023, 12, 37, 0}};
    Inmunizado noeI = {noe, 0, {0, 0, 0, 0, 0, 0}};

    // Arreglo de inmunizados
    const int TAM = 3;
    Inmunizado inmunes[TAM];

    inmunes[0] = matiasI;
    inmunes[1] = noeI;

    Ciudadano yo = {34563040, "Soy YO", B, 80.5, {28, 06, 1989, 23, 05, 0}};
    inmunes[2] = {yo, 1, {1, 1, 2024, 0, 0, 0}};


    // Mostrar los datos de los inmunizados
    cout << "\nDatos de los Inmunizados:\n";
    for (int i = 0; i < TAM; ++i) {
        cout << "\nInmunizado " << i + 1 << ":\n";
        mostrarInmunizado(inmunes[i]);
    }

    return 0;
}

// cargar ciudadano
void cargarCiudadano(Ciudadano &p1) {
    cout << "DNI: ";
    cin >> p1.dni;
    cin.ignore();
    cout << "Nombre Completo: ";
    cin.getline(p1.nombreCompleto, 30, '\n');
    cout << "Grupo Sanguineo (0: A, 1: B, 2: AB, 3: O): ";
    int grupo;
    cin >> grupo;
    p1.grupo = static_cast<GrupoSanguineo>(grupo);
    cout << "Peso: ";
    cin >> p1.peso;
    cout << "Fecha de Nacimiento (dd mm yyyy hh mm ss): ";
    cin >> p1.fechaNacimiento.dia >> p1.fechaNacimiento.mes >> p1.fechaNacimiento.anio
        >> p1.fechaNacimiento.horas >> p1.fechaNacimiento.minutos >> p1.fechaNacimiento.segundos;
}

// mostrar datos de ciudadano
void mostrarCiudadano(const Ciudadano& p1) {
    cout << "DNI: " << p1.dni << endl;
    cout << "Nombre: " << p1.nombreCompleto << endl;
    cout << "Grupo Sanguineo: ";
    switch(p1.grupo) {
        case A: cout << "A"; break;
        case B: cout << "B"; break;
        case AB: cout << "AB"; break;
        case O: cout << "O"; break;
    }
    cout << endl;
    cout << "Peso: " << p1.peso << " kg" << endl;
    cout << "Fecha de Nacimiento: " << p1.fechaNacimiento.dia << "/"
         << p1.fechaNacimiento.mes << "/" << p1.fechaNacimiento.anio << " "
         << p1.fechaNacimiento.horas << ":" << p1.fechaNacimiento.minutos
         << ":" << p1.fechaNacimiento.segundos << endl;
}

// mostrar los datos de un inmunizado
void mostrarInmunizado(const Inmunizado& p1) {
    mostrarCiudadano(p1.ciudadano);
    cout << "Cantidad de Dosis: " << p1.cantidadDosis << endl;
    cout << "Fecha de la Última Dosis: " << p1.fechaUltimaDosis.dia << "/"
         << p1.fechaUltimaDosis.mes << "/" << p1.fechaUltimaDosis.anio << " "
         << p1.fechaUltimaDosis.horas << ":" << p1.fechaUltimaDosis.minutos
         << ":" << p1.fechaUltimaDosis.segundos << endl;
}
