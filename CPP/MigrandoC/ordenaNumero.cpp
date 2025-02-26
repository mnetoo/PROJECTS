#include <iostream>


using namespace std;


int main ()
{
    int num1, num2, aux;

    cout << "Digite dois número: " << endl;
    cin >> num1 >> num2;

    if (num1 > num2)
        {
            aux = num1;
            num1 = num2;
            num2 = aux;
        }
    
    cout << "Números ordenados: " << num1 <<  " " <<num2 << endl;
    return 0;
}
