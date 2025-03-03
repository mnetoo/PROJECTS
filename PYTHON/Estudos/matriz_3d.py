matriz = [[[0 for _ in range(3)] for _ in range(3)] for _ in range(3)]

print("Matriz inicial:")
print(matriz)


for i in range(3):
    for j in range(3):
        for k in range(3):
            matriz[i][j][k] = i * j * k

print("Matriz final:")
for camada in matriz:
    for linha in camada:
        print(linha)
    print()
