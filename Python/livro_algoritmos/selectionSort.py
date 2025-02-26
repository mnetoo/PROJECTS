import random

def buscaMenor(v):
    menor = v[0]
    indice_menor = 0
    trocas = 0
    comparacoes = 0

    for i in range(1, len(v)):
        comparacoes += 1
        if v[i] < menor:
            menor = v[i]
            indice_menor = i
            trocas += 1
    
    return indice_menor, comparacoes, trocas

#----------------------------------------------

def selectionSort(v):
    novoVetor = []
    total_comparacoes = 0
    total_trocas = 0
    for i in range(len(v)):
        menor, comparacoes, trocas = buscaMenor(v)
        total_comparacoes += comparacoes
        total_trocas += trocas
        novoVetor.append(v.pop(menor))
    
    print(f"Total de comparações: {total_comparacoes}")
    print(f"Total de trocas: {total_trocas}")
    return novoVetor

#----------------------------------------------

def geraVetor (v, n):
    for i in range(n):
        v.append(random.randint(1, 100))

#----------------------------------------------

def imprimeVetor (v):
    for i in range(len(v)):
        print(v[i], end = " ")
    print()

#----------------------------------------------

v = []
geraVetor(v, 1024)
print()
imprimeVetor(v)
print()
v = selectionSort(v.copy())
print()
imprimeVetor(v)
print()