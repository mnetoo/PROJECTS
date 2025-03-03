m1 = [[0 for _ in range(2)] for _ in range(2)]
m2 = [[0 for _ in range(2)] for _ in range(2)]
soma = [[0 for _ in range(2)] for _ in range(2)]


for i in range(2):
    for j in range(2):
        m1[i][j] = int(input(f'Digite um número para a matriz 1 na posição [{i}][{j}]: '))
print()

for i in range(2):
    for j in range(2):
        m2[i][j] = int(input(f'Digite um número para a matriz 2 na posição [{i}][{j}]: '))
print()

print("Matriz 1:")
for linha in m1:
    print(linha)
print()

print("Matriz 2:")
for linha in m2:
    print(linha)
print()

for i in range(2):
    for j in range(2):
        soma[i][j] = m1[i][j] + m2[i][j]

print("Matriz soma:")
for linha in m2:
    print(linha)
print()