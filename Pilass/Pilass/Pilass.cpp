#include <iostream>

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class Pila {
private:
    Nodo* cima;

public:
    Pila() {
        cima = nullptr;
    }

    bool estaVacia() const {
        return cima == nullptr;
    }

    void apilar(int valor) {
        Nodo* nuevo = new Nodo();
        nuevo->dato = valor;
        nuevo->siguiente = cima;
        cima = nuevo;
    }

    void desapilar() {
        if (estaVacia()) {
            std::cout << "Pila vacia (Underflow)\n";
            return;
        }
        Nodo* aux = cima;
        cima = cima->siguiente;
        delete aux;
    }

    int verCima() const {
        if (!estaVacia()) {
            return cima->dato;
        }
        throw std::runtime_error("Pila vacia");
    }

    ~Pila() {
        while (!estaVacia()) {
            desapilar();
        }
    }
};

int main() {
    Pila p;
    p.apilar(10);
    p.apilar(20);
    p.apilar(30);

    std::cout << "Cima: " << p.verCima() << "\n"; // 30
    p.desapilar();
    std::cout << "Nueva cima: " << p.verCima() << "\n"; // 20
    return 0;
}