/*
Problem Name : Combination Sum
Problem Description : Given an array and an integer target, find all the possible combinations possible
in the array whose sum == target
Note : A single array element can be used multiple times
e.g. arr = [1,2,3], target = 8
valid combinations are [1,1,1,1,1,1,1,1],[2,2,2,2],[2,3,3]......
*/
#include <iostream>
using namespace std;

/*
Intuition : Use pick and not pick concept to find all the possible subsequences

1. If element <= target , we pick it and reduce target for next recursive call, and do not go ahead , as we can use same element
multiple times
2. When coming back from recurive call of pick conditon , we remove the picked element for next combination
3. Otherwise we do not pick element, move to next index , and do not reduce target
4. When we picked
*/

void display(vector<int> &arr)
{
    for (auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

void f(int index, vector<int> &arr, vector<int> &currSubsequence, vector<vector<int>> &ans, int sum, int target)
{
    if (index == arr.size())
    {
        if (sum == target)
        {
            ans.push_back(currSubsequence);
        }
        return;
    }

    // Pick condition
    sum += arr[index];
    currSubsequence.push_back(arr[index]);
    f(index + 1, arr, currSubsequence, ans, sum, target);

    // Not pick condition
    sum -= arr[index];
    currSubsequence.pop_back();
    f(index + 1, arr, currSubsequence, ans, sum, target);
}

vector<vector<int>> combinationSum(vector<int> &arr, int target)
{
    // Find all the combinations of arr whose sum equals to target
    vector<vector<int>> ans;
    vector<int> currSubsequence;
    int sum = 0;
    f(0, arr, currSubsequence, ans, sum, target);
    return ans;
}

void display(vector<vector<int>> &subsequences)
{
    for (auto subsequence : subsequences)
    {
        display(subsequence);
    }
}

int main()
{
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};

    cout << "Array : ";
    display(arr);

    int target = 8;
    cout << "Target : " << target << endl;

    cout << "Combinations having sum = " << target << " :" << endl;
    vector<vector<int>> ans = combinationSum(arr, target);

    display(ans);

    return 0;
}