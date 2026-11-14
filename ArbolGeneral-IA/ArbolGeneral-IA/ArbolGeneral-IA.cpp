#include <iostream>
#include <string>
using namespace std;

struct NodoGeneral {
    string dato;
    int cantidadHijos;
    NodoGeneral** hijos;
};

NodoGeneral* CrearNodo(string valor, int maxHijos) {
    NodoGeneral* nuevoNodo = new NodoGeneral;
    nuevoNodo->dato = valor;
    nuevoNodo->cantidadHijos = 0;
    nuevoNodo->hijos = new NodoGeneral * [maxHijos];
    for (int i = 0; i < maxHijos; i++) {
        nuevoNodo->hijos[i] = nullptr;
    }
    return nuevoNodo;
}

NodoGeneral* BuscarNodo(NodoGeneral* nodo, string nombre) {
    if (nodo == nullptr) return nullptr;
    if (nodo->dato == nombre) return nodo;

    for (int i = 0; i < nodo->cantidadHijos; i++) {
        NodoGeneral* encontrado = BuscarNodo(nodo->hijos[i], nombre);
        if (encontrado != nullptr) return encontrado;
    }
    return nullptr;
}

void AgregarNodo(NodoGeneral*& raiz, string nombrePadre, string valor, int maxHijos) {
    if (raiz == nullptr) {
        raiz = CrearNodo(valor, maxHijos);
        cout << "Raiz creada correctamente" << endl;
        return;
    }

    NodoGeneral* padre = BuscarNodo(raiz, nombrePadre);
    if (padre == nullptr) {
        cout << "El nodo padre no existe" << endl;
        return;
    }

    if (padre->cantidadHijos >= maxHijos) {
        cout << "El nodo padre alcanzo el maximo de hijos" << endl;
        return;
    }

    padre->hijos[padre->cantidadHijos] = CrearNodo(valor, maxHijos);
    padre->cantidadHijos++;
    cout << "Nodo hijo agregado correctamente" << endl;
}

void MostrarHojas(NodoGeneral* nodo, int& contador) {
    if (nodo == nullptr) return;
    if (nodo->cantidadHijos == 0) {
        cout << nodo->dato << " (Direccion: " << nodo << ")" << endl;
        contador++;
        return;
    }
    for (int i = 0; i < nodo->cantidadHijos; i++) {
        MostrarHojas(nodo->hijos[i], contador);
    }
}

void ImprimirArbol(NodoGeneral* nodo, int nivel, string etiqueta) {
    if (nodo == nullptr) return;
    for (int i = 0; i < nivel; i++) {
        cout << "   ";
    }
    cout << etiqueta << nodo->dato
        << " | Direccion: " << nodo
        << " | Hijos: " << nodo->cantidadHijos << endl;

    for (int i = 0; i < nodo->cantidadHijos; i++) {
        ImprimirArbol(nodo->hijos[i], nivel + 1, "H- ");
    }
}

void BorrarArbol(NodoGeneral*& nodo, int& contador) {
    if (nodo == nullptr) return;
    for (int i = 0; i < nodo->cantidadHijos; i++) {
        BorrarArbol(nodo->hijos[i], contador);
    }
    cout << "Elemento borrado " << contador
        << " | Dato: " << nodo->dato
        << " | Direccion: " << nodo << endl;
    contador++;
    delete[] nodo->hijos;
    delete nodo;
    nodo = nullptr;
}

int main() {
    NodoGeneral* raiz = nullptr;
    int opc;
    int maxHijos;

    cout << "Examen IA - Arbol General\n" << endl;
    cout << "Ingrese el maximo de hijos por nodo: ";
    cin >> maxHijos;

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
                string datoRaiz;
                cout << "Ingrese el dato de la raiz: ";
                cin >> datoRaiz;
                AgregarNodo(raiz, "", datoRaiz, maxHijos);
            }
            else {
                string padre, dato;
                cout << "Ingrese el dato del nodo padre: ";
                cin >> padre;
                cout << "Ingrese el dato del nuevo hijo: ";
                cin >> dato;
                AgregarNodo(raiz, padre, dato, maxHijos);
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
            cout << "Estructura del arbol (R = raiz, H = hijo):" << endl;
            ImprimirArbol(raiz, 0, "R- ");
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