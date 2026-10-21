
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double p, e;
    double x;

    cin >> p >> e;

    if (p < 0 || e <= 0)
    {
        cout << "error" << endl;
        return 0;
    }

    if (p == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    x = p;

    while (abs(x * x - p) > e)
    {
        x = (x + p / x) / 2.0;
    }

    cout << x << endl;

    return 0;
}
