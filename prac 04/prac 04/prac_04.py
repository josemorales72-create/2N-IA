import tkinter as tk
from tkinter import messagebox

def Limpiar():
    tbNombre.delete(0, tk.END)
    tbApellidos.delete(0, tk.END)
    tbEdad.delete(0, tk.END)
    tbEstatura.delete(0, tk.END)
    tbTelefono.delete(0, tk.END) 
    varGenero.set(0)

def borrar_fun():
    Limpiar()

def Guardar():
    nombres = tbNombre.get()
    apellidos = tbApellidos.get()
    edad = tbEdad.get()
    estatura = tbEstatura.get()
    telefono = tbTelefono.get()
    genero = ""
    if varGenero.get()==1:
        genero = "Hombre"
    elif varGenero.get()==2:
        genero = "Mujer"
    elif varGenero.get()==3:
        genero = "Otro"

    datos = "Nombres: " + nombres + "\n" + "Apellidos: " + apellidos + "\n" + "Edad: " + edad + "\n" + "Estatura: " + estatura + "\n" + "Telefono: " + telefono + "\n" + "Genero: " + genero + "\n"
    with open("3NAgoDic26.txt", "a") as archivo:
        archivo.write(datos + "\n\n")
   
    messagebox.showinfo("Información", "Datos guardados con éxito: \n\n" + datos)
    tbNombre.delete(0,tk.END)
    tbApellidos.delete(0,tk.END)
    tbEdad.delete(0,tk.END)
    tbEstatura.delete(0,tk.END)
    tbTelefono.delete(0,tk.END)
    varGenero.set(0) 

ventana = tk.Tk()
ventana.geometry("350x500")
ventana.config(bg = "#DBDBDB")
ventana.title("Actividad 04 - Formulario de Registro V.01")
varGenero = tk.IntVar()
lbNombre = tk.Label(ventana, text = "Nombre: ")
lbNombre.pack()
tbNombre = tk.Entry()
tbNombre.pack()
lbApellidos = tk.Label(ventana, text = "Apellidos: ")
lbApellidos.pack()
tbApellidos = tk.Entry()
tbApellidos.pack()
lbTelefono = tk.Label(ventana, text = "Teléfono: ")
lbTelefono.pack()
tbTelefono = tk.Entry()
tbTelefono.pack()
lbEdad = tk.Label(ventana, text = "Edad: ")
lbEdad.pack()
tbEdad = tk.Entry()
tbEdad.pack()
lbEstatura = tk.Label(ventana, text = "Estatura: ")
lbEstatura.pack()
tbEstatura = tk.Entry()
tbEstatura.pack()

groupBox = tk.LabelFrame(ventana, text = "Genero: ", padx= 12, pady = 12)
groupBox.pack()
rbMasculino = tk.Radiobutton(groupBox, text = "Masculino", variable = varGenero, value = 1)
rbMasculino.grid(row = 0,column = 0)
rbFemenino = tk.Radiobutton(groupBox, text = "Femenino", variable = varGenero, value = 2)
rbFemenino.grid(row = 0,column = 1)
rbOtro = tk.Radiobutton(groupBox, text = "Otro", variable = varGenero, value = 3)
rbOtro.grid(row = 0,column = 2)
btnGuardar = tk.Button(ventana, text = "Guardar",bg="#30B0E3", command = Guardar)
btnGuardar.pack()
btnLimpiar = tk.Button(ventana, text = "Limpiar", bg = "#C4C4C4", command = Limpiar)  
btnLimpiar.pack()
ventana.mainloop()