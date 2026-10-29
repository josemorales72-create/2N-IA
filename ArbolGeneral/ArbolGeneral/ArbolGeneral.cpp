#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo* hijo;
    Nodo* hermano;
};

Nodo* CrearNodo(int valor) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = valor;
    nuevoNodo->hijo = nullptr;
    nuevoNodo->hermano = nullptr;
    return nuevoNodo;
}

Nodo* AgregarHijo(Nodo* padre, int valor) {
    Nodo* nuevoNodo = CrearNodo(valor);
    if (padre->hijo == nullptr) {
        padre->hijo = nuevoNodo;
    }
    else {
        Nodo* actual = padre->hijo;
        while (actual->hermano != nullptr) {
            actual = actual->hermano;
        }
        actual->hermano = nuevoNodo;
    }
    return nuevoNodo;
}

void ConstruirArbol(Nodo* nodo) {
    int cantidadHijos;
    cout << "Cuantos hijos tiene el nodo " << nodo->dato << "? ";
    cin >> cantidadHijos;
    for (int i = 0; i < cantidadHijos; i++) {
        int valor;
        cout << "Ingrese el valor del hijo " << i + 1 << " de " << nodo->dato << ": ";
        cin >> valor;
        Nodo* nuevo = AgregarHijo(nodo, valor);
        ConstruirArbol(nuevo);
    }
}

Nodo* BuscarNodo(Nodo* nodo, int valor) {
    if (nodo == nullptr) return nullptr;
    if (nodo->dato == valor) return nodo;
    Nodo* actual = nodo->hijo;
    while (actual != nullptr) {
        Nodo* encontrado = BuscarNodo(actual, valor);
        if (encontrado != nullptr) return encontrado;
        actual = actual->hermano;
    }
    return nullptr;
}

void MostrarHojas(Nodo* nodo, int& contador) {
    if (nodo == nullptr) return;
    if (nodo->hijo == nullptr) {
        cout << nodo->dato << " (Direccion: " << nodo << ")" << endl;
        contador++;
    }
    Nodo* actual = nodo->hijo;
    while (actual != nullptr) {
        MostrarHojas(actual, contador);
        actual = actual->hermano;
    }
}

void ImprimirArbol(Nodo* nodo, int nivel) {
    if (nodo == nullptr) return;
    for (int i = 0; i < nivel; i++) {
        cout << "  ";
    }
    cout << nodo->dato << "(Direccion: " << nodo << ")" << endl;
    Nodo* actual = nodo->hijo;
    while (actual != nullptr) {
        ImprimirArbol(actual, nivel + 1);
        actual = actual->hermano;
    }
}

void BorrarArbol(Nodo* nodo, int& contador) {
    if (nodo == nullptr) return;
    Nodo* actual = nodo->hijo;
    while (actual != nullptr) {
        Nodo* siguiente = actual->hermano;
        BorrarArbol(actual, contador);
        actual = siguiente;
    }
    cout << "Elemento borrado " << contador << " | Dato: " << nodo->dato << " | Direccion: " << nodo << endl;
    contador++;
    delete nodo;
}

int main() {
    Nodo* raiz = nullptr;
    int opc;
    cout << "Actividad 12 Arbol General\n" << endl;

    do {
        cout << "\nMenu Principal" << endl;
        cout << "1. Ingresar elementos" << endl;
        cout << "2. Mostrar hojas" << endl;
        cout << "3. Visualizar arbol" << endl;
        cout << "0. Salir" << endl;
        cout << "======================" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opc;

        switch (opc) {
        case 1: {
            if (raiz == nullptr) {
                int valorRaiz;
                cout << "Ingrese el valor de la raiz: ";
                cin >> valorRaiz;
                raiz = CrearNodo(valorRaiz);
                ConstruirArbol(raiz);
            }
            else {
                int valorPadre;
                cout << "Ingrese el valor del nodo padre: ";
                cin >> valorPadre;
                Nodo* padre = BuscarNodo(raiz, valorPadre);
                if (padre == nullptr) {
                    cout << "El nodo " << valorPadre << " no existe en el arbol" << endl;
                }
                else {
                    int cantidad;
                    cout << "Cuantos hijos nuevos tendra el nodo " << padre->dato << "? ";
                    cin >> cantidad;
                    for (int i = 0; i < cantidad; i++) {
                        int valor;
                        cout << "Ingrese el valor del hijo nuevo " << i + 1 << ": ";
                        cin >> valor;
                        Nodo* nuevo = AgregarHijo(padre, valor);
                        ConstruirArbol(nuevo);
                    }
                }
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
            cout << "Arbol (preorden):" << endl;
            ImprimirArbol(raiz, 0);
            break;
        }
        case 0: {
            cout << "Borrando arbol antes de salir:" << endl;
            int contador = 1;
            BorrarArbol(raiz, contador);
            raiz = nullptr;
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