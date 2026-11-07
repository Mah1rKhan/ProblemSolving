#include <iostream>
using namespace std;

/*
Problem Name : Power(X, N)
Problem Description : Given a base X and an integer exponent N , calculate the value of X^N
*/
double power(double base, int exponent)
{
    if (exponent == 0)
    {
        return 1;
    }

    double A = power(base, exponent / 2);

    if (exponent % 2 == 0)
    {
        return A * A;
    }
    else
    {
        return base * A * A;
    }
}


double calculatePower(double base, int exponent)
{
    long long N = exponent;
    if (N < 0)
    {
        base = 1 / base;
        N = -N;
    }
    return power(base, N);
}

/*
Intuition : X^N can be broken into X^(N/2) * X^(N/2),
*/

int main()
{
    double x = 4;
    int n = 7;

    cout << calculatePower(x, n);

    return 0;
}
