#include <iostream>
#include <set>
using namespace std;

void display(vector<int> &arr)
{
    for (auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

void display(vector<vector<int>> combinations)
{
    for (auto combination : combinations)
    {
        display(combination);
    }
}

void f1(int index, vector<int> &arr, int target, vector<int> &currSubsequece, set<vector<int>> &st)
{
    // Base condition

    if (index == arr.size())
    {
        if (target == 0)
        {
            st.insert(currSubsequece);
        }
        return;
    }

    if (arr[index] <= target)
    {
        // pick current element
        currSubsequece.push_back(arr[index]);

        // move forward
        f1(index + 1, arr, target - arr[index], currSubsequece, st);

        // remove picked element
        currSubsequece.pop_back();
    }
    // Do not pick current element
    f1(index + 1, arr, target, currSubsequece, st);
}

vector<vector<int>> combinationSum2_1(vector<int> &arr, int target)
{
    set<vector<int>> st;

    vector<int> currSubsequence;
    f1(0, arr, target, currSubsequence, st);

    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
}

void f2(int index, vector<int> &arr, int target, vector<int> &currSubsequence, vector<vector<int>> &ans)
{

    if (target == 0)
    {
        ans.push_back(currSubsequence);
        // return;
    }

    for (int i = index; i < arr.size(); i++)
    {
        // Skip conditon for element at same index in subsequence
        if (i > index && arr[i] == arr[i - 1])
        {
            continue;
        }

        // Skip further recursions for current subsequence
        if (arr[i] > target)
        {
            break;
        }

        // pick current element
        currSubsequence.push_back(arr[i]);

        // move ahead for other elements
        f2(i + 1, arr, target - arr[i], currSubsequence, ans);

        // remove picked element
        currSubsequence.pop_back();
    }
}

vector<vector<int>> combinationSum2_2(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());

    vector<int> currSubsequence;
    vector<vector<int>> ans;

    f2(0, arr, target, currSubsequence, ans);

    return ans;
}

int main()
{
    vector<int> arr = {2, 5, 3, 4, 5, 4, 1};
    cout << "Array : ";
    display(arr);

    int target = 8;
    cout << "Target : " << target << endl;

    vector<vector<int>> combinations = combinationSum2_2(arr, target);

    cout << "Combinations having sum = " << target << " :" << endl;
    display(combinations);

    return 0;
}