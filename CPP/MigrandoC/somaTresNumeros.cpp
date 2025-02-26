#include <iostream>


using namespace std;


int soma (int x, int y, int z)
{
    int soma = x + y + z;
    return soma;
}

int produto (int x, int y, int z)
{
    int produto = x *  y * z;
    return produto;
}

float media (int x, int y, int z)
{
    float media = (x+ y + z)/3;
    return media;
}




int main ()
{
    int a, b, c;

    cout << "Digite três números inteiros: " << endl;
    cin >> a >> b >> c;

    cout << "A soma é: "<< soma(a, b, c) << endl;
    cout << "O produto é: " << produto(a, b, c) << endl;
    cout << "A média é: " << media(a, b, c) << endl;

    return 0;
}
