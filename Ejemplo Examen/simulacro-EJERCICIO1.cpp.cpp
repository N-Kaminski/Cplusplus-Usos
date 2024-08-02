#include <iostream>
#include <string>

using namespace std;

struct Hormiga {
    string tipo;
    string tamano;
    bool tieneHoja;
    Hormiga* siguiente;
};

// Declarando Funciones
void encolar(Hormiga*&, Hormiga*&, const Hormiga&);
void desencolar(Hormiga*&, Hormiga*&, Hormiga&);
bool vacia(Hormiga*);
void verCola(Hormiga*);
Hormiga crearHormiga();
void cargarHormigaASenderoA(Hormiga*&, Hormiga*&);
void derivarASenderoBoC(Hormiga*&, Hormiga*&, Hormiga*&, Hormiga*&, Hormiga*&, Hormiga*&);
void quitarHojaYRegresarASenderoA(Hormiga*&, Hormiga*&, Hormiga*&, Hormiga*&);
void mostrarYVaciarSenderoC(Hormiga*&, Hormiga*&);

int main() {
    Hormiga* senderoA_frente = nullptr;
    Hormiga* senderoA_fin = nullptr;
    Hormiga* senderoB_frente = nullptr;
    Hormiga* senderoB_fin = nullptr;
    Hormiga* senderoC_frente = nullptr;
    Hormiga* senderoC_fin = nullptr;

    int opcion;
    char rta;

    do {
        cout << "**** Menu de Usuario: ****\n";
        cout << " 1. Crear hormiga\n";
        cout << " 2. Cargar Hormiga a sendero A\n";
        cout << " 3. Derivar a sendero B o C\n";
        cout << " 4. Quitar hoja, Regresar de sendero B a A\n";
        cout << " 5. Mostrar y Vaciar sendero C\n";
        cout << " 6. Salir\n";
        cout << " Seleccione una opcion: ";
        cin >> opcion;
        cout << endl;

        switch (opcion) {
            case 1: {
                Hormiga h = crearHormiga();
                if (h.tipo == "recolectora") {
                    if (h.tieneHoja) {
                        encolar(senderoB_frente, senderoB_fin, h);
                    } else {
                        encolar(senderoC_frente, senderoC_fin, h);
                    }
                } else {
                    encolar(senderoA_frente, senderoA_fin, h);
                }
                cout << "Hormiga creada y agregada con exito!\n";
                break;
            }
            case 2:
                cargarHormigaASenderoA(senderoA_frente, senderoA_fin);
                break;
            case 3:
                derivarASenderoBoC(senderoA_frente, senderoA_fin, senderoB_frente, senderoB_fin, senderoC_frente, senderoC_fin);
                break;
            case 4:
                quitarHojaYRegresarASenderoA(senderoA_frente, senderoA_fin, senderoB_frente, senderoB_fin);
                break;
            case 5:
                mostrarYVaciarSenderoC(senderoC_frente, senderoC_fin);
                break;
            case 6:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida\n";
        }
        cout << endl;
    } while (opcion != 6);

    return 0;
}

void encolar(Hormiga*& frente, Hormiga*& fin, const Hormiga& h) {
    Hormiga* nuevaHormiga = new Hormiga(h);
    nuevaHormiga->siguiente = nullptr;
    if (vacia(frente)) {
        frente = nuevaHormiga;
    } else {
        fin->siguiente = nuevaHormiga;
    }
    fin = nuevaHormiga;
    cout << "Hormiga agregada al sendero\n";
}

void desencolar(Hormiga*& frente, Hormiga*& fin, Hormiga& h) {
    h = *frente;
    Hormiga* aux = frente;
    if (frente == fin) {
        frente = nullptr;
        fin = nullptr;
    } else {
        frente = frente->siguiente;
    }
    delete aux;
}

bool vacia(Hormiga* frente) {
    return frente == nullptr;
}

void verCola(Hormiga* frente) {
    if (vacia(frente)) {
        cout << "La cola esta vacia\n";
    } else {
        Hormiga* aux = frente;
        while (aux != nullptr) {
            cout << "Tipo: " << aux->tipo << ", Tamaño: " << aux->tamano << ", Tiene hoja: " << (aux->tieneHoja ? "Si" : "No") << " | ";
            aux = aux->siguiente;
        }
        cout << endl;
    }
}

Hormiga crearHormiga() {
    Hormiga h;
    int tipoSeleccionado;
    cout << "Seleccione el tipo de hormiga:\n";
    cout << "1. recolectora\n";
    cout << "2. excavadora\n";
    cout << "3. criadora\n";
    cout << "Seleccione una opcion: ";
    cin >> tipoSeleccionado;

    switch (tipoSeleccionado) {
        case 1:
            h.tipo = "recolectora";
            break;
        case 2:
            h.tipo = "excavadora";
            break;
        case 3:
            h.tipo = "criadora";
            break;
        default:
            cout << "Opcion no valida, asignando tipo 'recolectora'.\n";
            h.tipo = "recolectora";
            break;
    }

    cout << "Ingrese el tamaño de la hormiga: ";
    cin >> h.tamano;
    if (h.tipo == "recolectora") {
        char tieneHojaChar;
        cout << "¿Tiene hoja? (s/n): ";
        cin >> tieneHojaChar;
        h.tieneHoja = (tieneHojaChar == 's' || tieneHojaChar == 'S');
    } else {
        h.tieneHoja = false;
    }

    return h;
}

void cargarHormigaASenderoA(Hormiga*& frente, Hormiga*& fin) {
    if (vacia(frente)) {
        Hormiga h = crearHormiga();
        if (h.tipo != "recolectora") {
            encolar(frente, fin, h);
        } else {
            cout << "La hormiga es de tipo recolectora y no puede ser agregada al sendero A.\n";
        }
    } else {
        cout << "El sendero A ya tiene hormigas de tipo excavadora o criadora.\n";
    }
}

void derivarASenderoBoC(Hormiga*& frenteA, Hormiga*& finA, Hormiga*& frenteB, Hormiga*& finB, Hormiga*& frenteC, Hormiga*& finC) {
    if (!vacia(frenteA)) {
        Hormiga h;
        desencolar(frenteA, finA, h);
        if (h.tipo == "recolectora" && h.tieneHoja) {
            encolar(frenteB, finB, h);
        } else {
            encolar(frenteC, finC, h);
        }
    } else {
        cout << "El sendero A esta vacio.\n";
    }
}

void quitarHojaYRegresarASenderoA(Hormiga*& frenteA, Hormiga*& finA, Hormiga*& frenteB, Hormiga*& finB) {
    if (!vacia(frenteB)) {
        Hormiga h;
        desencolar(frenteB, finB, h);
        h.tieneHoja = false;
        encolar(frenteA, finA, h);
    } else {
        cout << "El sendero B esta vacio.\n";
    }
}

void mostrarYVaciarSenderoC(Hormiga*& frenteC, Hormiga*& finC) {
    if (!vacia(frenteC)) {
        cout << "Hormigas en el sendero C:\n";
        while (!vacia(frenteC)) {
            Hormiga h;
            desencolar(frenteC, finC, h);
            cout << "Tipo: " << h.tipo << ", Tamaño: " << h.tamano << ", Tiene hoja: " << (h.tieneHoja ? "Si" : "No") << endl;
        }
    } else {
        cout << "El sendero C esta vacio.\n";
    }
}
