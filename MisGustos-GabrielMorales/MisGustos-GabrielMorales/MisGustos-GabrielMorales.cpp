#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 4. Arreglo estático de 6 valores STRING predefinidos (Tema: Tecnologías)
string tecnologias[6] = { "Python", "C++", "C#", "Git", "Docker", "Linux" };

// Variables para almacenar la matriz y la pila
string matrizTec[2][3];
vector<string> pilaTec;

// 5 y 6. Función matriz: distribuye el arreglo en 2x3
void matriz() {
    int indice = 0;
    // 8. Ciclos for anidados
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            matrizTec[i][j] = tecnologias[indice];
            indice++;
        }
    }
    cout << "\n[OK] Matriz 2x3 generada con exito.\n";
}

// 5 y 7. Función pila: toma los 6 valores iniciales y agrega 2 adicionales
void pila() {
    pilaTec.clear();

    // Agregamos los 6 elementos del arreglo usando un for
    for (int i = 0; i < 6; i++) {
        pilaTec.push_back(tecnologias[i]);
    }

    // Condicional lógica y agregamos dos valores adicionales
    if (pilaTec.size() == 6) {
        pilaTec.push_back("Arduino");
        pilaTec.push_back("PostgreSQL");
    }

    cout << "\n[OK] Pila generada y 2 elementos adicionales agregados.\n";
}

// 9. Función para imprimir los valores finales
void imprimirValoresFinales() {
    cout << "\n=============================================\n";
    cout << "              RESULTADOS FINALES             \n";
    cout << "=============================================\n";

    // Mostrar Matriz (2x3)
    cout << "\n--- MATRIZ (2x3) ---\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "[" << matrizTec[i][j] << "]\t";
        }
        cout << "\n";
    }

    // Mostrar Pila (LIFO)
    cout << "\n--- PILA (Desde la cima hacia la base) ---\n";
    if (pilaTec.empty()) {
        cout << "[!] La pila esta vacia. Llenala primero con la opcion 2.\n";
    }
    else {
        vector<string> copiaPila = pilaTec;
        // Uso de ciclo While para desapilar
        while (!copiaPila.empty()) {
            cout << "| " << copiaPila.back() << " |\n";
            copiaPila.pop_back();
        }
        cout << " ---------- (Base)\n";
    }
    cout << "=============================================\n";
}

int main() {
    int opcion = 0;

    // 3 y 8. Ciclo While hasta que el usuario decida salir
    while (opcion != 4) {
        cout << "\n*********************************************\n";
        cout << "   MisGustos TuNombre - Menu de Opciones     \n";
        cout << "*********************************************\n";
        cout << "1. Llenar Matriz (2x3)\n";
        cout << "2. Llenar Pila (6 base + 2 adicionales)\n";
        cout << "3. Imprimir Valores Finales\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion (1-4): ";
        cin >> opcion;

        // Validación y condicionales lógicas
        if (opcion == 1) {
            matriz();
        }
        else if (opcion == 2) {
            pila();
        }
        else if (opcion == 3) {
            imprimirValoresFinales();
        }
        else if (opcion == 4) {
            cout << "\nSaliendo del programa... Fin de la ejecucion.\n";
        }
        else {
            cout << "\n[!] Opcion no valida. Selecciona un numero del 1 al 4.\n";
        }
    }

    return 0;
}