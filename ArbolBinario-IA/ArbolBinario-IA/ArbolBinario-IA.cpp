#include <iostream>
#include <string>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izquierdo;
    Nodo* derecho;
};

Nodo* CrearNodo(int valor) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = valor;
    nuevoNodo->izquierdo = nullptr;
    nuevoNodo->derecho = nullptr;
    return nuevoNodo;
}

Nodo* BuscarNodo(Nodo* nodo, int valor) {
    if (nodo == nullptr) return nullptr;
    if (nodo->dato == valor) return nodo;

    Nodo* encontrado = BuscarNodo(nodo->izquierdo, valor);
    if (encontrado != nullptr) return encontrado;

    return BuscarNodo(nodo->derecho, valor);
}

void AgregarNodo(Nodo*& raiz, int valorPadre, int lado, int valor) {
    if (raiz == nullptr) {
        raiz = CrearNodo(valor);
        cout << "Raiz creada correctamente" << endl;
        return;
    }

    Nodo* padre = BuscarNodo(raiz, valorPadre);
    if (padre == nullptr) {
        cout << "El nodo padre no existe" << endl;
        return;
    }

    if (lado == 1) {
        if (padre->izquierdo == nullptr) {
            padre->izquierdo = CrearNodo(valor);
            cout << "Nodo agregado a la izquierda" << endl;
        }
        else {
            cout << "El hijo izquierdo ya esta ocupado" << endl;
        }
    }
    else if (lado == 2) {
        if (padre->derecho == nullptr) {
            padre->derecho = CrearNodo(valor);
            cout << "Nodo agregado a la derecha" << endl;
        }
        else {
            cout << "El hijo derecho ya esta ocupado" << endl;
        }
    }
    else {
        cout << "Lado no valido" << endl;
    }
}

void MostrarHojas(Nodo* nodo, int& contador) {
    if (nodo == nullptr) return;
    if (nodo->izquierdo == nullptr && nodo->derecho == nullptr) {
        cout << nodo->dato << " (Direccion: " << nodo << ")" << endl;
        contador++;
        return;
    }
    MostrarHojas(nodo->izquierdo, contador);
    MostrarHojas(nodo->derecho, contador);
}

void Preorden(Nodo* nodo) {
    if (nodo == nullptr) return;
    cout << nodo->dato << " ";
    Preorden(nodo->izquierdo);
    Preorden(nodo->derecho);
}

void Inorden(Nodo* nodo) {
    if (nodo == nullptr) return;
    Inorden(nodo->izquierdo);
    cout << nodo->dato << " ";
    Inorden(nodo->derecho);
}

void Postorden(Nodo* nodo) {
    if (nodo == nullptr) return;
    Postorden(nodo->izquierdo);
    Postorden(nodo->derecho);
    cout << nodo->dato << " ";
}

void ImprimirArbol(Nodo* nodo, int nivel, string lado) {
    if (nodo == nullptr) return;
    for (int i = 0; i < nivel; i++) {
        cout << "   ";
    }
    cout << lado << nodo->dato
        << " | Direccion: " << nodo
        << " | Izq: " << nodo->izquierdo
        << " | Der: " << nodo->derecho << endl;

    ImprimirArbol(nodo->izquierdo, nivel + 1, "I- ");
    ImprimirArbol(nodo->derecho, nivel + 1, "D- ");
}

void BorrarArbol(Nodo*& nodo, int& contador) {
    if (nodo == nullptr) return;
    BorrarArbol(nodo->izquierdo, contador);
    BorrarArbol(nodo->derecho, contador);
    cout << "Elemento borrado " << contador
        << " | Dato: " << nodo->dato
        << " | Direccion: " << nodo << endl;
    contador++;
    delete nodo;
    nodo = nullptr;
}

int main() {
    Nodo* raiz = nullptr;
    int opc;

    cout << "Examen IA - Arbol Binario sin Validacion\n" << endl;

    do {
        cout << "\nMenu Principal" << endl;
        cout << "1. Ingresar elementos" << endl;
        cout << "2. Mostrar hojas" << endl;
        cout << "3. Visualizar arbol" << endl;
        cout << "0. Salir" << endl;
        cout << "==================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opc;

        switch (opc) {
        case 1: {
            if (raiz == nullptr) {
                int valorRaiz;
                cout << "Ingrese el valor de la raiz: ";
                cin >> valorRaiz;
                AgregarNodo(raiz, 0, 0, valorRaiz);
            }
            else {
                int padre, lado, valor;
                cout << "Ingrese el valor del nodo padre: ";
                cin >> padre;
                cout << "Seleccione lado (1 = Izquierdo, 2 = Derecho): ";
                cin >> lado;
                cout << "Ingrese el valor del nuevo nodo: ";
                cin >> valor;
                AgregarNodo(raiz, padre, lado, valor);
            }
            break;
        }
        case 2: {
            if (raiz == nullptr) {
                cout << "El arbol esta vacio" << endl;
                break;
            }
            int totalHojas = 0;
            cout << "Hojas del arbol:" << endl;
            MostrarHojas(raiz, totalHojas);
            cout << "Total de hojas: " << totalHojas << endl;
            break;
        }
        case 3: {
            if (raiz == nullptr) {
                cout << "El arbol esta vacio" << endl;
                break;
            }
            cout << "Estructura del arbol (R = raiz, I = izquierdo, D = derecho):" << endl;
            ImprimirArbol(raiz, 0, "R- ");
            cout << "\nPreorden: "; Preorden(raiz);
            cout << "\nInorden: "; Inorden(raiz);
            cout << "\nPostorden: "; Postorden(raiz);
            cout << endl;
            break;
        }
        case 0: {
            cout << "Borrando arbol antes de salir:" << endl;
            int contador = 1;
            BorrarArbol(raiz, contador);
            cout << "Total de elementos borrados: " << contador - 1 << endl;
            cout << "Saliendo del programa..." << endl;
            break;
        }
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    } while (opc != 0);

    return 0;
}