class Nodo:
    def __init__(self, dato):
        self.dato = dato
        self.siguiente = None

class ListaEnlazada:
    def __init__(self):
        self.cabeza = None

    def insertar_inicio(self, valor):
        nuevo = Nodo(valor)
        nuevo.siguiente = self.cabeza
        self.cabeza = nuevo

    def insertar_final(self, valor):
        nuevo = Nodo(valor)
        if self.cabeza is None:
            self.cabeza = nuevo
            return
        actual = self.cabeza
        while actual.siguiente is not None:
            actual = actual.siguiente
        actual.siguiente = nuevo

    def mostrar(self):
        actual = self.cabeza
        elementos = []
        while actual is not None:
            elementos.append(str(actual.dato))
            actual = actual.siguiente
        print(" -> ".join(elementos) + " -> None")


if __name__ == "__main__":
    lista = ListaEnlazada()
    lista.insertar_inicio(15)
    lista.insertar_inicio(5)
    lista.insertar_final(25)

    lista.mostrar() # 5 -> 15 -> 25 -> None