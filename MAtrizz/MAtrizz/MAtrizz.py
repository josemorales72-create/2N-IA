def inprimirNombre(Nombre):
    print("Nombre del alumno:",Nombre)

print("---Matriz---")
NombreUsuario = input("Nombre del Usuario")
inprimirNombre(NombreUsuario)
#Matriz 5x5
MatrizO = []
print ("Ingresar 25 valores para la matriz")
for i in range(5):
    fila = []
    for j in range(5):
        valor = float (input(f"Valor [{i}][{j}]:"))
        fila.append (valor)
    MatrizO.append(fila)
#Matriz inversa
print ("---Recorido Inverso---")
for i in range (4, -1, -1):
    for j in range (4, -1, -1):
        print (MatrizO[i][j], end ="")
print ()
#Matriz Elevada al cubo
MatrizC =[]
for i in range (5):
    fila=[]
    for j in range (5):
        Cubo = MatrizO[i][j] ** 3
        fila.append(Cubo)
    MatrizC.append(fila)
#Operaciones
Suma = 0
ListaPlana = []
for i in range (5):
    for j in range (5):
        Valo = MatrizC[i][j]
        Suma = Suma + Valo
        ListaPlana.append(Valo)

Promedio = Suma / 25
Mayor = ListaPlana [0]
Menor = ListaPlana[0]
for num in ListaPlana:
    if num > Mayor:
        Mayor = num
    if num < Menor:
        Menor = num

ListaPlana.sort()
Mediana = ListaPlana[12]

print ("---MatrizOriginal---")
for i in range(5):
    for j in range(5):
        print(MatrizO[i][j], end="  ")
print()

print ("---MatrizCubo---")
for i in range(5):
    for j in range(5):
        print(MatrizC[i][j], end= " ")
        print()

print(f'Examen primer parcial- usuario {NombreUsuario}, "Suma de todos lo valores Elevados al cubo: {Suma}, Suma total de los valores elevados al cubo:{Promedio}, Valor mas alto: {Mayor} y valor mas bajo:{Menor}" ')
