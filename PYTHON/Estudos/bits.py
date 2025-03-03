num = int(input("Digite um número inteiro: "))

vetor = [0] * 4

for i in range(4):
    vetor[3 - i] = (num >> i) & 1  # Desloca o bit e faz um AND com 1 para extrair o bit certo

print("Vetor de bits:", vetor)