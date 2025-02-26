from tkinter import *

# Funções da calculadora
def adicionar_no_display(valor):
    display["text"] += str(valor)

def calcular():
    try:
        resultado = eval(display["text"])
        display["text"] = str(resultado)
    except Exception:
        display["text"] = "Erro"

def limpar_display():
    display["text"] = ""

# Configuração da janela principal
janela = Tk()
janela.title("Calculadora")
janela.geometry("300x400")

# Display da calculadora
display = Label(janela, text="", anchor=E, font=("Arial", 24), bg="white", fg="black", relief="sunken", width=14, height=2)
display.grid(row=0, column=0, columnspan=4, padx=10, pady=10)

# Botões da calculadora
botoes = [
    ('7', 1, 0), ('8', 1, 1), ('9', 1, 2), ('/', 1, 3),
    ('4', 2, 0), ('5', 2, 1), ('6', 2, 2), ('*', 2, 3),
    ('1', 3, 0), ('2', 3, 1), ('3', 3, 2), ('-', 3, 3),
    ('0', 4, 0), ('.', 4, 1), ('+', 4, 2), ('=', 4, 3)
]

# Criação e posicionamento dos botões
for (texto, linha, coluna) in botoes:
    if texto == '=':
        botao = Button(janela, text=texto, command=calcular, height=2, width=4, font=("Arial", 14))
    else:
        botao = Button(janela, text=texto, command=lambda t=texto: adicionar_no_display(t), height=2, width=4, font=("Arial", 14))
    botao.grid(row=linha, column=coluna, padx=5, pady=5)

# Botão para limpar o display
botao_limpar = Button(janela, text="C", command=limpar_display, height=2, width=4, font=("Arial", 14), fg="red")
botao_limpar.grid(row=4, column=2, padx=5, pady=5)

# Inicialização da interface
janela.mainloop()