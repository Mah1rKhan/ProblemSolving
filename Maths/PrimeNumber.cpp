/*
Problem Name : Check Prime Number
Problem Description : Given a positive integer number, check whether the number is prime or not
*/
#include <iostream>
using namespace std;

/*
Intuition : Count the number of factors of n using sqrt(n) approach, if the count == 2, return true
otherwise return false
*/
bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n = 14;

    if (isPrime(n))
    {
        cout << n << " is a Prime Number";
    }
    else
    {
        cout << n << " is NOT a Prime Number";
    }

    return 0;
}