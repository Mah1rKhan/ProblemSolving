/*
Problem Name : Power Set
Problem Description : Given an array of integers , generate a power set of all the elements of the array

A power set is the set of all possible subsets
*/

#include <iostream>
using namespace std;

void display(vector<int> &arr)
{
    if (arr.empty())
    {
        cout << "{}";
    }
    for (auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

void display(vector<vector<int>> &arr)
{
    for (auto row : arr)
    {
        display(row);
    }
}

/*
Intuition : Use pick and not pick method recursively on all elements of the set to generate power set
Time Complexity : O(2^N)
Aux. Space Req. : O(2^N) for answer
*/

void generate(int ind, vector<int> &arr, vector<int> &currSubset, vector<vector<int>> &ans)
{
    // Base condition
    if (ind == arr.size())
    {
        ans.push_back(currSubset);
        return;
    }

    // Pick condition
    currSubset.push_back(arr[ind]);
    generate(ind + 1, arr, currSubset, ans);

    // Not pick condition
    currSubset.pop_back();
    generate(ind + 1, arr, currSubset, ans);
}

vector<vector<int>> powerSet(vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> currSubset;

    generate(0, arr, currSubset, ans);

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3};

    cout << "Original Set is : ";
    display(arr);

    vector<vector<int>> powSet = powerSet(arr);
    cout << "Power Set : " << endl;
    display(powSet);

    return 0;
}