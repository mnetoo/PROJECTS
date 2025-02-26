#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14159




int main () 
{
    int raio;
    float area, perim;

    cout << "Digite o valor do raio: ";
    cin >> raio;

    perim = 2 * PI * raio;
    area = PI * pow(raio, 2);

    cout << "O perímetro  da circunferência de raio:" << raio << " é: " << perim << endl;
    cout << "A área é: " << area << endl;
}