#include <iostream>
using namespace std;

void f(vector<int> &nums, int ind, int target, vector<int> &currSubsequence, int &count)
{
    if (ind == nums.size())
    {
        if (currSubsequence.empty())
        {
            return;
        }
        int i = 0, j = currSubsequence.size() - 1;
        if (currSubsequence[i] + currSubsequence[j] <= target)
        {
            count++;
        }
        return;
    }

    // pick condition
    currSubsequence.push_back(nums[ind]);
    f(nums, ind + 1, target, currSubsequence, count);

    // not pick codition
    currSubsequence.pop_back();
    f(nums, ind + 1, target, currSubsequence, count);
}
int numSubseq1(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int count = 0;
    vector<int> currSubsequence;

    f(nums, 0, target, currSubsequence, count);
    long long mod = 10e9 + 7;
    return (count) % mod;
}

int numSubseq2(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());

    long long count = 0;
    int ans = 0;
    int i = 0, j = arr.size() - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] <= target)
        {
            int n = j - i;
            ans += (1 << n);
            count++;
            i++;
        }
        else
        {
            j--;
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= target / 2)
        {
            ans++;
        }
    }

    ans = ans - count;
    return ans;
}

int main()
{
    vector<int> arr = {14, 4, 6, 6, 20, 8, 5, 6, 8, 12, 6, 10, 14, 9, 17, 16, 9, 7, 14, 11, 14, 15, 13, 11, 10, 18, 13, 17, 17, 14, 17, 7, 9, 5, 10, 13, 8, 5, 18, 20, 7, 5, 5, 15, 19, 14};
    int count = numSubseq2(arr, 22);

    cout << count;
    return 0;
}