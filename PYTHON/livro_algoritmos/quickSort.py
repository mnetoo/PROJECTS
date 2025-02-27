import random


def particiona(v, inicio, fim):
    pivot = v[fim]  
    i = inicio - 1  
    comparacoes = 0
    trocas = 0

    for j in range(inicio, fim):
        comparacoes += 1
        if v[j] <= pivot:
            i += 1
            v[i], v[j] = v[j], v[i]  
            trocas += 1

    v[i + 1], v[fim] = v[fim], v[i + 1]
    trocas += 1
    return i + 1, comparacoes, trocas

#----------------------------------------------

def quickSort(v, inicio, fim):
    total_comparacoes = 0
    total_trocas = 0

    if inicio < fim:
        p, comparacoes, trocas = particiona(v, inicio, fim)
        total_comparacoes += comparacoes
        total_trocas += trocas

        comparacoes_esq, trocas_esq = quickSort(v, inicio, p - 1)
        comparacoes_dir, trocas_dir = quickSort(v, p + 1, fim)

        total_comparacoes += comparacoes_esq + comparacoes_dir
        total_trocas += trocas_esq + trocas_dir

    return total_comparacoes, total_trocas

#----------------------------------------------

def geraVetor(v, n):
    for i in range(n):
        v.append(random.randint(1, 100))

#----------------------------------------------

def imprimeVetor(v):
    for i in range(len(v)):
        print(v[i], end=" ")
    print()

#----------------------------------------------



v = []
geraVetor(v, 1024)
print("Vetor original:")
imprimeVetor(v)
print()



v_copia = v.copy()  # Cópia para preservar o original
comparacoes, trocas = quickSort(v_copia, 0, len(v_copia) - 1)
print("\nVetor ordenado com QuickSort:")
imprimeVetor(v_copia)

print(f"\nTotal de comparações: {comparacoes}")
print(f"Total de trocas: {trocas}")