#include <iostream>
using namespace std;

void display(vector<int> &arr)
{
    for (auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

void reverse(vector<int> &arr, int startInd, int endInd)
{
    if (startInd >= endInd)
    {
        return;
    }
    swap(arr[startInd], arr[endInd]);
    reverse(arr, startInd + 1, endInd - 1);
}

void reverseArray(vector<int> &arr)
{
    int startInd = 0, endInd = arr.size() - 1;
    reverse(arr, startInd, endInd);
}

int main()
{
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    display(arr);

    reverseArray(arr);

    display(arr);

    return 0;
}