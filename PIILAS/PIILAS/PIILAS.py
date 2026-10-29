class Nodo:
    def __init__(self, dato):
        self.dato = dato
        self.siguiente = None

class Pila:
    def __init__(self):
        self.cima = None

    def esta_vacia(self):
        return self.cima is None

    def apilar(self, valor):
        nuevo = Nodo(valor)
        nuevo.siguiente = self.cima
        self.cima = nuevo

    def desapilar(self):
        if self.esta_vacia():
            print("Pila vacia (Underflow)")
            return None
        valor = self.cima.dato
        self.cima = self.cima.siguiente
        return valor

    def ver_cima(self):
        if self.esta_vacia():
            return None
        return self.cima.dato

# Demostracion
if __name__ == "__main__":
    pila = Pila()
    pila.apilar(10)
    pila.apilar(20)
    pila.apilar(30)

    print(f"Cima: {pila.ver_cima()}")       # 30
    print(f"Desapilado: {pila.desapilar()}") # 30
    print(f"Nueva cima: {pila.ver_cima()}")  # 20
