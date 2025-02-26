#include <iostream>


using namespace std;


int main ()
{
    int num;

    cout << "Digite um número: ";
    cin >> num;

    if (num % 2 == 0)
        cout << "O número digitado é par!" << endl;
    else
        cout << "O número digitao é impar!" << endl;

    return 0;
}
