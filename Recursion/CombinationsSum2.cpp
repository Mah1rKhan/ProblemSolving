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

void display(vector<vector<int>> &arr)
{
    for (auto row : arr)
    {
        display(row);
    }
}

void findCombinations1(int index, vector<int> &arr, int target, vector<int> &currCombination,
                       set<vector<int>> &st)
{
    // Base condition
    if (index >= arr.size())
    {
        if (target == 0)
        {
            st.insert(currCombination);
        }
        return;
    }

    // pick condition
    if (arr[index] <= target)
    {
        currCombination.push_back(arr[index]);

        findCombinations1(index + 1, arr, target - arr[index], currCombination, st);

        // remove the picked up element
        currCombination.pop_back();
    }

    // not pick condition
    findCombinations1(index + 1, arr, target, currCombination, st);
}

// Time Complexity O(2^n * k log (set size))
// Aux. Space Req. O(2^n)

vector<vector<int>> combinationSum2_1(vector<int> &arr, int target)
{
    set<vector<int>> st;
    vector<int> currCombination;

    sort(arr.begin(), arr.end());

    findCombinations1(0, arr, target, currCombination, st);

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

void findCombinations2(int index, vector<int> &arr, int target, vector<int> &currCombination,
                       vector<vector<int>> &ans)
{
    // Base condtion
    if (target == 0)
    {
        ans.push_back(currCombination);
    }

    for (int i = index; i < arr.size(); i++)
    {
        if (i > index && arr[i] == arr[i - 1])
        {
            continue;
        }

        if (arr[i] > target)
        {
            break;
        }

        // pick condition
        currCombination.push_back(arr[i]);

        findCombinations2(i + 1, arr, target - arr[i], currCombination, ans);

        // remove picked element

        currCombination.pop_back();
    }
}

// Time Complexity : O(2^n * k)
// Aux. Space Req. : O(no. of combinations)
vector<vector<int>> combinationSum2_2(vector<int> &arr, int target)
{
    vector<vector<int>> ans;
    vector<int> currCombination;

    sort(arr.begin(), arr.end());

    findCombinations2(0, arr, target, currCombination, ans);

    return ans;
}

int main()
{
    vector<int> arr = {2, 5, 3, 4, 5, 4, 1};
    cout << "Array : ";
    display(arr);

    int target = 8;

    vector<vector<int>> combinations = combinationSum2_2(arr, target);

    cout << "Combinations having sum = " << target << endl;
    display(combinations);

    return 0;
}