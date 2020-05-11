##pip3 install mood.mqueue

from tkinter import *
from tkinter import messagebox
import mood.mqueue
import os

window = Tk()

window.title("Controlador de actuadores ")
window.geometry('300x100')

lbl1 = Label(window, text="Ingrese actuador")
lbl2 = Label(window, text="Ingrese tiempo")

lbl1.grid(column=0, row=0)
lbl2.grid(column=0, row=4)

def enviando():
    print ("poner la logica para mandar");
    nro_actuador = txt1.get()
    tiempo = txt2.get()
    print (nro_actuador , tiempo);
    cola = mood.mqueue.MessageQueue("/api-control" , os.O_WRONLY)
    cadena = "01"+str(nro_actuador) + str(tiempo)
    datos_api = bytearray (cadena,"utf-8")
    res = cola.send(datos_api)
    if res > 0 :
        messagebox.showinfo('Mensaje', 'Enviado correctamente')
    
def saliendo():
    window.quit()

def validate(new_text): 
    if not new_text: # the field is being cleared 
        entered_number = 0 
        return True 

    try: 
        entered_number = int(new_text) 
        return True 
    except ValueError: 
        return False 

btn1 = Button(window, text="Enviar", command=enviando)
btn1.grid(column=6, row=0)

btn2 = Button(window, text="Salir", command=saliendo)
btn2.grid(column=6, row=4)

vcmd = window.register(validate)
txt1 = Entry(window,width=3,validate = 'key', validatecommand = (vcmd, '%P'))
txt1.grid(column=2, row=0)


txt2 = Entry(window,width=3,validate = 'key', validatecommand = (vcmd, '%P'))
txt2.grid(column=2, row=4)

window.mainloop()
