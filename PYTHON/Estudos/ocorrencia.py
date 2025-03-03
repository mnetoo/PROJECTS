vetor = []

print('Digite 10 números entre 1 e 5: ')
while len(vetor) < 10:
    num = int(input())
    if num < 1 or num > 5:
        print('Número inválido, digite um número entre 1 e 5')
    else:
        vetor.append(num)

histograma = {i: vetor.count(i) for i in range(1, 6)}

# Exibe o histograma
print('\nHistograma de ocorrências:')
for valor, ocorrencias in histograma.items():
    print(f"{valor}: {'*' * ocorrencias}")