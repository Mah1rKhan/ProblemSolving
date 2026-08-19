/*
Problem Name : Move Zeroes to end
Problem Description : Given an array of zeroes and positive integers , move all the zeroes to end
without changing the order of positive integers
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
Intuition : Use a temporary array to store the positive elements in order
Push the positive elements first in the original array , then push the remaining number of zeroes

Time Complexity : O(2N)
N for first traversal , N-x for second traversal , N-(N-x) = x for third traversal
total = 2N

Aux. Space Req. : O(N) in worst case
*/

void moveZeroesToEnd1(vector<int> &arr)
{
    vector<int> temp;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            temp.push_back(arr[i]);
        }
    }

    for (int i = 0; i < temp.size(); i++)
    {
        arr[i] = temp[i];
    }
    for (int i = temp.size(); i < arr.size(); i++)
    {
        arr[i] = 0;
    }
}

/*
Intuition : Use two pointer approach, one pointer pointing to first zero, second pointer for traversal
whenever we find non zero element , we swap with values at first pointer and second pointer

Time Complexity : O(N)
Aux. Space Req. : O(1)
*/

void moveZeroesToEnd2(vector<int> &arr)
{
    int j = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    for (int i = j + 1; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 0, 0, 2, 0, 3};

    cout << "Original Array : ";
    display(arr);

    cout << "Array after moving zeroes to end : ";
    moveZeroesToEnd2(arr);
    display(arr);
}