lista = []
for i in range(4):
    lista.append(int(input('Digite um número: ')))

print(", ".join(map(str, lista)))

print(", ".join(map(str, lista[::-1])))