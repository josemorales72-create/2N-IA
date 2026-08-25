#include <iostream>

using namespace std;

// Prototipos de funciones
int leerDimension();
void capturarArreglo(int* arreglo, int n);
int calcularSumatoria(const int* arreglo, int n);
void mostrarArreglo(const int* arreglo, int n);

int main() {
    int n = leerDimension();

    // Asignación de memoria dinámica para el arreglo contiguo
    int* vector = new int[n];

    capturarArreglo(vector, n);
    mostrarArreglo(vector, n);

    int sumaTotal = calcularSumatoria(vector, n);
    cout << "\nSumatoria total de elementos: " << sumaTotal << "\n";

    // Liberación de memoria
    delete[] vector;
    vector = nullptr;

    return 0;
}

int leerDimension() {
    int n;
    do {
        cout << "Ingrese la cantidad de elementos (N > 0): ";
        cin >> n;
    } while (n <= 0);
    return n;
}

void capturarArreglo(int* arreglo, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el entero para la posición [" << i << "]: ";
        cin >> arreglo[i];
    }
}

int calcularSumatoria(const int* arreglo, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arreglo[i];
    }
    return total;
}

void mostrarArreglo(const int* arreglo, int n) {
    cout << "\n--- Elementos del Arreglo ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Índice [" << i << "] = " << arreglo[i] << "\n";
    }
}