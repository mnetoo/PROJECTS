def soma (x, y):
    return x + y

def subtracao (x, y):
    return x - y

def multiplicacao (x, y):
    return x * y

def divisao (x, y):
    if y == 0:
        return "Não é possível dividir por zero"
    return x / y


print("Selecione a operação desejada:")
print("1 - Soma")
print("2 - Subtração")
print("3 - Multiplicação")
print("4 - Divisão")

while True:
    escolha = input("Digite sua opção (1/2/3/4): ")

    if escolha in ('1', '2', '3', '4'):
        num1 = float(input("Digite o primeiro número: "))
        num2 = float(input("Digite o segundo número: "))

        if escolha == '1':
            print("Resultado: ", soma(num1, num2))

        elif escolha == '2':
            print("Resultado: ", subtracao(num1, num2))

        elif escolha == '3':
            print("Resultado: ", multiplicacao(num1, num2))

        elif escolha == '4':
            print("Resultado: ", divisao(num1, num2))
        break
    else:
        print("Opção inválida")