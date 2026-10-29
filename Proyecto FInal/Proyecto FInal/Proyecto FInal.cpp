// Proyecto FInal.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>

using namespace std;

struct NodoContacto {
	string nombre;
	int telefono;
	string correo;
	NodoContacto* izquierdo;
	NodoContacto* derecho;
};

NodoContacto* insertar(NodoContacto* raiz, string nuevo_nombre, int nuevo_telefono, string nuevo_correo) {
	if (raiz == nullptr) {
		NodoContacto* nuevo = new NodoContacto();
		nuevo->nombre = nuevo_nombre;
		nuevo->telefono = nuevo_telefono;
		nuevo->correo = nuevo_correo;
		nuevo->izquierdo = nullptr;
		nuevo->derecho = nullptr;
		return nuevo;
	}

	if (nuevo_nombre < raiz->nombre) {
		raiz->izquierdo = insertar(raiz->izquierdo, nuevo_nombre, nuevo_telefono, nuevo_correo);
	}
	else {
		raiz->derecho = insertar(raiz->derecho, nuevo_nombre, nuevo_telefono, nuevo_correo);
	}

	return raiz;
}
int main() {
	NodoContacto* raiz = nullptr;
	raiz = insertar(raiz, "Carlos Gomez", 961123456, "carlos@gmail.com");
	raiz = insertar(raiz, "Angel Dominguez", 961125459, "angeldom@gmail.com");

	cout << "Arbol Binario De Contactos Inicializado." << endl;
	return 0;

}
