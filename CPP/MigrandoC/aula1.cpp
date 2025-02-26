#include <iostream>

using namespace std;

int main ()
{
    int x, y;

    cin >> x >> y;
    cout << x + y << endl;

    if (x == y)
        cout << "São iguais!" << endl;
    else
        cout << "São diferentes!" << endl;
    

    return 0;
}