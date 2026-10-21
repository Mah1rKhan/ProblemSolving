#include <iostream>
using namespace std;

// Parametrized way

void sumUptoN(int i, int sum)
{
    if (i < 1)
    {
        cout << "Sum is : " << sum;
        return;
    }

    return sumUptoN(i - 1, sum + i);
}

int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;

    sumUptoN(n, 0);

    return 0;
}