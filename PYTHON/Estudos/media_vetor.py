vetor = []
media = 0
soma = 0

print('Digite 10 números: ')
for i in range(10):
    vetor.append(int(input()))

print(", ".join(map(str, vetor)))

media = sum(vetor) / len(vetor)
soma = sum(vetor)

print('A soma dos valores do vetor é:', soma)
print('A média dos números é:', media)

print('Os valores que são maiores ou iguais à média são:')

maiores = [str(num) 
           for num in vetor 
            if num >= media
        ]

print(", ".join(maiores))