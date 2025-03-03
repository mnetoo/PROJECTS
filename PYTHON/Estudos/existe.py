# Função para ler os 5 primeiros números
def ler_numeros():
    numeros = []
    for i in range(5):
        numero = int(input(f"Digite o número {i+1}: "))
        numeros.append(numero)
    return numeros

# Função para verificar se um número está na lista
def verificar_presenca(lista, numero):
    if numero in lista:
        return "Está presente na lista."
    else:
        return "Não está presente na lista."

# Leitura dos 5 números
lista1 = ler_numeros()

# Leitura da segunda lista terminada por 0
lista2 = []
while True:
    numero = int(input("Digite um número para a segunda lista (digite 0 para terminar): "))
    if numero == 0:
        break
    lista2.append(numero)

# Verificando se os números da segunda lista estão na primeira lista
for numero in lista2:
    resultado = verificar_presenca(lista1, numero)
    print(f"O número {numero}: {resultado}")
