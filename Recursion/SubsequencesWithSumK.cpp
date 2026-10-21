/*
Problem Name : Subsequences with sum K
Problem Description : Given an array of +ve integers and an integer k, find all the subsequences
whose sum is equal to k
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

void display(vector<vector<int>> &arr)
{
    for (auto row : arr)
    {
        display(row);
    }
}

/*
Intuition : Use the concept of 1. pick and 2. not pick (pick and then remove) to generate all subsequences
keep a sum variable to store sum, if at any point sum equals k, we push that subsequence in our answer
when doing step 2. not pick, we subtract the element from sum so that way we dont pick in subseq. and
sum also

Do this recursively to get all possible subsequences and all valid subsequences that satisfy condition
of sum == k

Time Complexity : O(2^N)
The total number of ordered subsequences possible for array of size N = 2^N

Aux. Space Req. : O(2^N)

*/

void generate(vector<int> &arr, int ind, int sum, int k, vector<vector<int>> &subsequences,
              vector<int> &currSubsequence)
{
    if (ind == arr.size())
    {
        if (sum == k)
        {
            subsequences.push_back(currSubsequence);
        }
        return;
    }

    // Pick condition
    currSubsequence.push_back(arr[ind]);
    // sum += arr[ind];
    generate(arr, ind + 1, sum + arr[ind], k, subsequences, currSubsequence);

    // Not pick condition
    currSubsequence.pop_back();
    // sum -= arr[ind];
    generate(arr, ind + 1, sum, k, subsequences, currSubsequence);
}

vector<vector<int>> subsequencesWithSumK(vector<int> &arr, int k)
{
    int sum = 0;
    vector<int> currSubsequence;
    vector<vector<int>> subsequences;

    generate(arr, 0, sum, k, subsequences, currSubsequence);

    return subsequences;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    cout << "Array is : ";
    display(arr);

    int k = 7;

    vector<vector<int>> ans = subsequencesWithSumK(arr, k);

    cout << "Subsequences with sum " << k << " are :" << endl;

    display(ans);

    return 0;
}