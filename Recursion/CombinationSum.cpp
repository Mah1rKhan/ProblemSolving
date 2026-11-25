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

void display(vector<vector<int>> &arr)
{
    for (auto row : arr)
    {
        display(row);
    }
}

void f(vector<int> &arr, int index, int target, vector<int> &currCombination, vector<vector<int>> &ans)
{
    // base condition
    if (index >= arr.size())
    {
        if (target == 0)
        {
            ans.push_back(currCombination);
        }
        return;
    }

    // pick current index element
    if (arr[index] <= target)
    {
        currCombination.push_back(arr[index]);
        f(arr, index, target - arr[index], currCombination, ans);

        // remove the picked element
        currCombination.pop_back();
    }

    // do not pick current index element
    f(arr, index + 1, target, currCombination, ans);
}

vector<vector<int>> combinationSum(vector<int> &arr, int target)
{
    vector<vector<int>> ans;
    vector<int> currCombination;

    f(arr, 0, target, currCombination, ans);

    return ans;
}

int main()
{
    vector<int> arr = {2, 5, 3, 4, 5};
    int target = 8;

    cout << "Array : ";
    display(arr);

    vector<vector<int>> combinations = combinationSum(arr, target);

    cout << "Combinations having sum = " << target << endl;
    display(combinations);

    return 0;
}