import string

def palindromo(palavra):
    texto = ''.join(c.lower() for c in palavra if c.isalnum())
    return texto == texto[::-1]

texto = input('Digite uma palavra: ')

if palindromo(texto):
    print('É um palíndromo')
else:
    print('Não é um palíndromo')