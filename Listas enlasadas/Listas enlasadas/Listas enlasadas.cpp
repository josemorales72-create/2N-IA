#include <iostream>

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class ListaEnlazada {
private:
    Nodo* cabeza;

public:
    ListaEnlazada() {
        cabeza = nullptr;
    }

    void insertarInicio(int valor) {
        Nodo* nuevo = new Nodo();
        nuevo->dato = valor;
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }

    void insertarFinal(int valor) {
        Nodo* nuevo = new Nodo();
        nuevo->dato = valor;
        nuevo->siguiente = nullptr;
        if (cabeza == nullptr) {
            cabeza = nuevo;
            return;
        }
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }

    void mostrar() const {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            std::cout << actual->dato << " -> ";
            actual = actual->siguiente;
        }
        std::cout << "NULL\n";
    }

    ~ListaEnlazada() {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            Nodo* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
    }
};

int main() {
    ListaEnlazada lista;
    lista.insertarInicio(15);
    lista.insertarInicio(5);
    lista.insertarFinal(25);

    lista.mostrar(); // 5 -> 15 -> 25 -> NULL
    return 0;
}