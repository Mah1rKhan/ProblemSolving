/*
Problem Name : Check Subsequences Sum
Problem Description : Given an array of integers and an integer value K, return true if there exists a
subsequence (subset) of array whose sum is equal to K , otherwise return false
*/

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

bool check(int ind, vector<int> &arr, int sum, int k)
{
    // Base case
    if (ind == arr.size())
    {
        if (sum == k)
        {
            return true;
        }
        return false;
    }

    // Pick condition
    sum += arr[ind];

    if (check(ind + 1, arr, sum, k) == true)
    {
        return true;
    }

    // Not pick condition

    sum -= arr[ind];

    if (check(ind + 1, arr, sum, k) == true)
    {
        return true;
    }

    return false;
}

bool checkSubsequenceSum(vector<int> &arr, int k)
{
    int sum = 0;
    return check(0, arr, sum, k);
}

int main()
{
    vector<int> arr = {1, 2, 4, 8, 16};

    cout << "Array is : ";
    display(arr);

    int k = 32;

    if (checkSubsequenceSum(arr, k))
    {
        cout << "There exists a subsequence with sum " << k;
    }
    else
    {
        cout << "There is No possible subsequence with sum " << k;
    }

    return 0;
}