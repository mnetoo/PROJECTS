def multiplica_matrizes(A, B):
    # Obtém o número de linhas e colunas das matrizes
    linhas_A, colunas_A = len(A), len(A[0])
    linhas_B, colunas_B = len(B), len(B[0])
    
    # Verifica se a multiplicação é possível
    if colunas_A != linhas_B:
        raise ValueError("Número de colunas da primeira matriz deve ser igual ao número de linhas da segunda matriz")
    
    # Inicializa a matriz resultante com zeros
    resultado = [[0 for _ in range(colunas_B)] for _ in range(linhas_A)]
    
    # Multiplicação de matrizes
    for i in range(linhas_A):
        for j in range(colunas_B):
            for k in range(colunas_A):
                resultado[i][j] += A[i][k] * B[k][j]
    
    return resultado

# Exemplo de uso
A = [[1, 2, 3], [4, 5, 6]]
B = [[1, 2], [3, 4], [5, 6]]

resultado = multiplica_matrizes(A, B)
for linha in resultado:
    print(linha)