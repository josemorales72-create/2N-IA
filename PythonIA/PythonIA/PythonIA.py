def leer_dimension() -> int:
    while True:
        try:
            n = int(input("Ingrese la cantidad de elementos (N > 0): "))
            if n > 0:
                return n
            print("El tamaño debe ser mayor a 0.")
        except ValueError:
            print("Entrada inválida. Debe ser un número entero.")


def capturar_arreglo(n: int) -> list:
    # Preasignación de memoria/tamaño fijo para el vector
    arreglo = [0] * n
    for i in range(n):
        while True:
            try:
                arreglo[i] = int(input(f"Ingrese el entero para la posición [{i}]: "))
                break
            except ValueError:
                print("Entrada inválida. Intente de nuevo.")
    return arreglo


def calcular_sumatoria(arreglo: list, n: int) -> int:
    total = 0
    for i in range(n):
        total += arreglo[i]
    return total


def mostrar_arreglo(arreglo: list, n: int) -> None:
    print("\n--- Elementos del Arreglo ---")
    for i in range(n):
        print(f"Índice [{i}] = {arreglo[i]}")


def main():
    n = leer_dimension()
    vector = capturar_arreglo(n)
    
    mostrarArreglo = mostrar_arreglo(vector, n)
    suma_total = calcular_sumatoria(vector, n)
    
    print(f"\nSumatoria total de elementos: {suma_total}")


if __name__ == "__main__":
    main()
