#include <iostream>

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class Cola {
private:
    Nodo* frente;
    Nodo* final;

public:
    Cola() {
        frente = nullptr;
        final = nullptr;
    }

    bool estaVacia() const {
        return frente == nullptr;
    }

    void encolar(int valor) {
        Nodo* nuevo = new Nodo();
        nuevo->dato = valor;
        nuevo->siguiente = nullptr;
        if (estaVacia()) {
            frente = nuevo;
        }
        else {
            final->siguiente = nuevo;
        }
        final = nuevo;
    }

    void desencolar() {
        if (estaVacia()) {
            std::cout << "Cola vacia\n";
            return;
        }
        Nodo* aux = frente;
        frente = frente->siguiente;
        if (frente == nullptr) {
            final = nullptr;
        }
        delete aux;
    }

    int verFrente() const {
        if (!estaVacia()) {
            return frente->dato;
        }
        throw std::runtime_error("Cola vacia");
    }

    ~Cola() {
        while (!estaVacia()) {
            desencolar();
        }
    }
};

int main() {
    Cola q;
    q.encolar(100);
    q.encolar(200);
    q.encolar(300);

    std::cout << "Frente: " << q.verFrente() << "\n"; // 100
    q.desencolar();
    std::cout << "Nuevo frente: " << q.verFrente() << "\n"; // 200
    return 0;
}