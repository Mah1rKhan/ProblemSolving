/*
Problem Name : Length of longest subarray with sum k
Problem Description : Given an array of Positive integers, and an integer k
Find the length of longest subarray whose sum is equal to k

Note :
A subarray is a continuous part of the array
The array itself is a subarray
An empty array is also a subarray
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

/*
Intuition : Find the sum of all subarrays using nested loops and maximize the length
Time Complexity : ~ O(N^2)
Aux. Space Req. : O(1)
*/
int longestSubarray1(vector<int> &arr, int k)
{

    int max = 0;
    for (int i = 0; i < arr.size(); i++)
    {

        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            if (sum == k && (j - i + 1) > max)
            {
                max = j - i + 1;
            }
        }
    }
    return max;
}

/*
Intuition : Use a hash map to store the prefix sums of all the indexes, and check at each step
if there exists combination of prefix sum which make upto k and maximize the length

Time Complexity : O(N)
Aux. Space Req. : O(N)
*/

int longestSubarray2(vector<int> &arr, int k)
{
    unordered_map<long long, int> prefixSum;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        if (sum == k)
        {
            maxLen = i + 1;
        }

        long long rem = sum - k;
        if (prefixSum.find(rem) != prefixSum.end())
        {
            int len = i - prefixSum[rem];
            maxLen = max(len, maxLen);
        }
        if (prefixSum.find(sum) == prefixSum.end())
        {
            prefixSum[sum] = i;
        }
    }
    return maxLen;
}

/*
Intuition : Use two pointer approach , whenever the sum goes above k , start decreasing from left
end and maximize the length

Time Complexity : O(N)
Aux. Space Req. : O(1)
*/

int longestSubarray3(vector<int> &arr, int k)
{
    int maxLen = 0;
    int n = arr.size();
    int i = 0, j = 0;
    int currSum = arr[0];

    while (i < n)
    {
        while (j <= i && currSum > k)
        {
            currSum -= arr[j];
            j++;
        }

        if (currSum == k)
        {
            maxLen = max(maxLen, i - j + 1);
        }

        i++;
        if (i < n)
        {
            currSum += arr[i];
        }
    }
    return maxLen;
}

int main()
{

    vector<int> arr = {2, 3, 1, 1, 2, 3, 1, 2};
    int k = 4;

    cout << "Array : ";
    display(arr);
    cout << "Length of longest subarray with sum " << k << " : " << longestSubarray3(arr, k) << endl;

    return 0;
}