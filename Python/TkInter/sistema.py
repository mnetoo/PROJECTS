from tkinter import *
from tkinter.ttk import Combobox 
from tkinter import messagebox
from tkinter.ttk import Progressbar
from tkinter import filedialog
from tkinter import Menu





def evento_clique():
    mensagem["text"] = "texto: " + entrada.get()

def abrir_arquivo():
    arquivo = filedialog.askopenfilename()









janela = Tk()
janela.title("Sistema")
janela.geometry("800x600")



# Menu
menu = Menu(janela)
janela.config(menu=menu)
novo_item = Menu(menu)
novo_item.add_command(label="Novo")
novo_item.add_command(label="Abrir")
novo_item.add_command(label="Salvar")
novo_item.add_command(label="Salva como")
menu.add_cascade(label="Arquivo", menu=novo_item)
menu.add_cascade(label="Editar", menu=novo_item)
menu.add_cascade(label="Janela", menu=novo_item)




texto = Label(janela, text="Bem vindo ao sistema de planejamento do RXT Erasto Gaertner", font=("Arial", 12, "bold"))
texto.pack()



mensagem = Label(janela, text="teste", font=("Arial", 12))
mensagem.pack()



entrada = Entry(janela, font=("Arial", 12))
entrada.pack()
entrada.focus()



botao = Button(janela, text="Cadastrar Paciente", font=("Arial", 10), command=evento_clique)
botao.pack()



# Select
combo = Combobox(janela)
combo['values'] = (1, 2, 3, 4, 5, "Text")
combo.current(0)
combo.pack()


# Checkbox
flag = BooleanVar()
flag.set(False)
flag = Checkbutton(janela, text="Checkbox", var=flag)
flag.pack()


# Escolha
escolha = StringVar()
escolha.set(False)
escolha1 = Radiobutton(janela, text="Opção 1", value="1", variable=escolha)
escolha2 = Radiobutton(janela, text="Opção 2", value="2", variable=escolha)
escolha3 = Radiobutton(janela, text="Opção 3", value="3", variable=escolha)
escolha1.pack()
escolha2.pack()
escolha3.pack()


# Mensagens de Aviso
messagebox.showinfo('Aviso de Erro','Reveja as informações preenchidas')
questao = messagebox.askokcancel('Aviso','Deseja continuar?')



# Barra de Progresso
barra = Progressbar(janela, length=200)
barra['value'] = 50
barra.pack()



# Arquivo
arquivo =  Button(janela, text="Abrir arquivo", command=abrir_arquivo)
arquivo.pack()





janela.mainloop()