/*

Program Name : Rotate array right by D elements
Program Description : Given an array and an integer D , right rotate the array by D elements

for ex. : array = {1,2,3,4,5}, d = 2
output array = {4,5,1,2,3}

*/

#include <iostream>
using namespace std;

void display(vector<int> &v)
{
    for (auto x : v)
    {
        cout << x << ' ';
    }
    cout << endl;
}

/*
Intuition : Think of how you can divide array and rotate the different parts to get the result
This can also be solved mathematically (its lengthy but thats where this solution comes from)

Time Complexity : O(2N)
explaination : N-D for first reversal , N-(N-D) = D for second reversal , N for third reversal

Total = N-D + D + N = 2N

Aux. Space Req. : O(1)
*/

void rightRotateByDPlaces(vector<int> &arr, int d)
{
    int n = arr.size();
    d = d % n;
    if (d == 0)
    {
        return;
    }
    reverse(arr.begin(), arr.begin() + n - d);
    reverse(arr.begin() + n - d, arr.end());
    reverse(arr.begin(), arr.end());
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};

    cout << "Array before rotation : ";
    display(arr);

    int d = 2;

    rightRotateByDPlaces(arr, d);

    cout << "Array after right rotation by " << d << " elements : ";
    display(arr);

    return 0;
}