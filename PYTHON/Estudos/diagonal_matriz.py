def criar_matriz(n):
    matriz = [[i * n + j for j in range(n)] for i in range(n)]
    return matriz

def diagonal_principal(matriz):
    return [matriz[i][i] for i in range(len(matriz))]

def diagonal_secundaria(matriz):
    n = len(matriz)
    return [matriz[i][n - 1 - i] for i in range(n)]

def triangulo_superior(matriz):
    n = len(matriz)
    triangulo = []
    for i in range(n):
        linha = []
        for j in range(i, n):
            linha.append(matriz[i][j])
        triangulo.append(linha)
    return triangulo

def imprimir_triangulo(triangulo):
    for linha in triangulo:
        print(" ".join(map(str, linha)))

n = int(input("Digite o valor de N: "))
matriz = criar_matriz(n)

print("Matriz:")
for linha in matriz:
    print(linha)

print("\nDiagonal Principal:")
print(diagonal_principal(matriz))

print("\nDiagonal Secundária:")
print(diagonal_secundaria(matriz))

print("\nTriângulo Superior:")
imprimir_triangulo(triangulo_superior(matriz))