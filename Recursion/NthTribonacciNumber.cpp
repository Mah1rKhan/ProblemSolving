#include <iostream>
using namespace std;

int nthTribonacciNumber1(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1 || n == 2)
    {
        return 1;
    }
    int a = 0, b = 1, c = 1, d;

    for (int i = 3; i <= n; i++)
    {
        d = (a + b + c);
        a = b;
        b = c;
        c = d;
    }
    return d;
}

int nthTribonacciNumber2(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1 || n == 2)
    {
        return 1;
    }

    return nthTribonacciNumber2(n - 1) + nthTribonacciNumber2(n - 2) + nthTribonacciNumber2(n - 3);
}

int nthTribonacciNumber3(int n)
{
    vector<int> series(n + 1, 0);

    series[0] = 0, series[1] = series[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        series[i] = series[i - 1] + series[i - 2] + series[i - 3];
    }
    return series[n];
}

int main()
{
    int n;

    cout << "Enter n : ";
    cin >> n;

    cout << n << "th Tribonacci Number is : " << nthTribonacciNumber3(n);

    return 0;
}