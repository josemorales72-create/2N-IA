class Nodo:
    def __init__(self, dato):
        self.dato = dato
        self.siguiente = None

class Cola:
    def __init__(self):
        self.frente = None
        self.final = None

    def esta_vacia(self):
        return self.frente is None

    def encolar(self, valor):
        nuevo = Nodo(valor)
        if self.esta_vacia():
            self.frente = nuevo
        else:
            self.final.siguiente = nuevo
        self.final = nuevo

    def desencolar(self):
        if self.esta_vacia():
            print("Cola vacia")
            return None
        valor = self.frente.dato
        self.frente = self.frente.siguiente
        if self.frente is None:
            self.final = None
        return valor

    def ver_frente(self):
        if self.esta_vacia():
            return None
        return self.frente.dato

# Demostracion
if __name__ == "__main__":
    cola = Cola()
    cola.encolar(100)
    cola.encolar(200)
    cola.encolar(300)

    print(f"Frente: {cola.ver_frente()}")       # 100
    print(f"Desencolado: {cola.desencolar()}")  # 100
    print(f"Nuevo frente: {cola.ver_frente()}") # 200
