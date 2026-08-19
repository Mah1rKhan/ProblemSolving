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

int main()
{

    vector<int> arr1 = {1, 3, 5, 7, 0, 0, 0, 0, 0};
    cout << "Array 1 : ";
    display(arr1);

    vector<int> arr2 = {2, 4, 6, 8, 10};
    cout << "Array 2 : ";
    display(arr2);

    return 0;
}