# ==========================================
# UNACH - Licenciatura en LIDTS
# Asignatura: Estructura de Datos
# Proyecto: MisGustos_GabrielMorales
# Tema: Películas
# ==========================================

# 4. Arreglo estático de 6 valores STRING predefinidos
PELICULAS = ["Inception", "Interstellar", "Matrix", "Gladiator", "Avatar", "Titanic"]

# Variables globales para almacenar resultados
matriz_peliculas = []
pila_peliculas = []

# 5 y 6. Función para llenar la matriz de 2x3
def matriz(arreglo_origen):
    global matriz_peliculas
    matriz_peliculas = [[None for _ in range(3)] for _ in range(2)]
    indice = 0
    # Uso de ciclos for anidados
    for i in range(2):
        for j in range(3):
            matriz_peliculas[i][j] = arreglo_origen[indice]
            indice += 1
    print("\n[OK] Matriz de 2x3 generada correctamente.")

# 5 y 7. Función pila utilizando Listas
def pila(arreglo_origen):
    global pila_peliculas
    pila_peliculas = []
    
    # 8. Ciclo For para pasar los datos iniciales a la pila (Push)
    for peli in arreglo_origen:
        pila_peliculas.append(peli)
        
    # Agregamos dos valores adicionales
    pila_peliculas.append("Oppenheimer")
    pila_peliculas.append("Interestelar 2")
    print("\n[OK] Pila generada y 2 elementos adicionales agregados.")

# 9. Función para imprimir los valores finales
def imprimir_finales():
    print("\n" + "="*45)
    print("           RESULTADOS FINALES")
    print("="*45)
    
    # Condicional lógica para verificar si se procesó la matriz
    if len(matriz_peliculas) > 0:
        print("\n--- MATRIZ (2x3) ---")
        for i in range(len(matriz_peliculas)):
            fila = " | ".join(matriz_peliculas[i])
            print(f"Fila {i}: [ {fila} ]")
    else:
        print("\n[!] La matriz aun no ha sido generada.")

    # Condicional lógica para verificar si se procesó la pila
    if len(pila_peliculas) > 0:
        print("\n--- PILA (Elementos desde el tope) ---")
        # Mostramos en orden LIFO (último en entrar, primero en salir)
        for i in range(len(pila_peliculas) - 1, -1, -1):
            print(f"| {pila_peliculas[i]} |")
        print(" ---------- (Base)")
    else:
        print("\n[!] La pila aun no ha sido generada.")
    print("="*45)

# Función principal y menú interactivo
def main():
    opcion = 0
    # 3 y 8. Ciclo While para mantener en ejecución hasta elegir salir
    while opcion != 4:
        print("\n" + "*"*35)
        print("        MENÚ PRINCIPAL")
        print("*"*35)
        print("1. Llenar Matriz (2x3)")
        print("2. Llenar Pila (con 2 extras)")
        print("3. Imprimir Valores Finales")
        print("4. Salir")
        
        try:
            opcion = int(input("Seleccione una opción (1-4): "))
        except ValueError:
            print("[Error] Ingrese un valor numérico válido.")
            continue

        # 8. Estructuras de control y condicionales lógicas
        if opcion == 1:
            matriz(PELICULAS)
        elif opcion == 2:
            pila(PELICULAS)
        elif opcion == 3:
            imprimir_finales()
        elif opcion == 4:
            print("\nSaliendo del programa... ¡Hasta luego!")
        else:
            print("\n[Advertencia] Opción fuera de rango (elija de 1 a 4).")

if __name__ == "__main__":
    main()
