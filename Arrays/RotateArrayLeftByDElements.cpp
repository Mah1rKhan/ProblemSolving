/*

Program Name : Rotate array left by D elements
Program Description : Given an array and an integer D , right rotate the array by D elements

for ex. : array = {1,2,3,4,5}, d = 2
output array = {3,4,5,1,2}

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
Intuition : Use another array to store D elements, push remaining elements to left , append the
stored D elements back to original array

Time Complexity : O(2N)
explaination : N-D for first reversal , N-(N-D) = D for second reversal , N for third reversal

Total = N-D + D + N = 2N

Aux. Space Req. : O(D)
*/

void leftRotateByDPlaces1(vector<int> &arr, int d)
{
    int n = arr.size();
    d = d % n;
    if (d == 0)
    {
        return;
    }
    vector<int> temp;
    for (int i = 0; i < d; i++)
    {
        temp.push_back(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[d + i];
    }

    for (int i = n - d; i < n; i++)
    {
        arr[i] = temp[i - (n - d)];
    }
}

/*
Intuition : Think of how you can divide array and rotate the different parts to get the result
This can also be solved mathematically (its lengthy but thats where this solution comes from)

Time Complexity : O(2N)
explaination : N-D for first reversal , N-(N-D) = D for second reversal , N for third reversal

Total = N-D + D + N = 2N

Aux. Space Req. : O(1)
*/

void leftRotateByDPlaces2(vector<int> &arr, int d)
{
    int n = arr.size();
    d = d % n;
    if (d == 0)
    {
        return;
    }
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    cout << "Array before rotation : ";
    display(arr);

    int d = 2;

    leftRotateByDPlaces2(arr, d);

    cout << "Array after left rotation by " << d << " elements : ";
    display(arr);

    return 0;
}