#include <iostream>
using namespace std;

// Functional way
int sumUptoN(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + sumUptoN(n - 1);
}

int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;

    int sum = sumUptoN(n);

    cout << "Sum is : " << sum;

    return 0;
}