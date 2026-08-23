/*
Program Name : Maximum Subarray sum
Program Description : Return Maximum sum possible in subarray
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
1. Algorithm Used : Brute Force
   Time Complexity : O(N^3)
   Auxiliary Space Requirement : O(1)
   Intuition : Generate all subarrays and find sum of each subarray
*/
int maxSubarraySum1(vector<int> &arr)
{
    int maxSum = INT_MIN;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int currSum = 0;
            for (int k = i; k <= j; k++)
            {
                currSum += arr[k];
            }
            maxSum = max(currSum, maxSum);
        }
    }
    return maxSum;
}

/*
2. Algorithm Used : Better
   Time Complexity : O(N^2)
   Auxiliary Space Requirement : O(1)
   Intuition : Optimization of 1st algorithm
*/
int maxSubarraySum2(vector<int> &arr)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        int currSum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            currSum += arr[j];
            if (currSum > maxSum)
            {
                maxSum = currSum;
            }
        }
    }
    return maxSum;
}

/*
3. Algorithm Used : Optimal - Kadane's Algorithm
   Time Complexity : O(N)
   Auxiliary Space Requirement : O(1)
   Intuition : Choose only positive subarray sum for considering max. sum
*/
int maxSubarraySum3(vector<int> &arr)
{
    int n = arr.size();
    int maxSum = INT_MIN;
    int currSum = 0;
    int ansStart = -1, ansEnd = -1;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        if (currSum == 0)
        {
            start = i;
        }
        currSum += arr[i];
        if (currSum > maxSum)
        {
            maxSum = currSum;
            ansStart = start;
            ansEnd = i;
        }
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    cout << "Array with Maximum sum : ";
    for (int i = ansStart; i <= ansEnd; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return maxSum;
}

int main()
{

    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << "Array : ";
    display(arr);

    int maxSum = maxSubarraySum3(arr);
    cout << "Maximum sum of the subarray : ";
    cout << maxSum << endl;

    return 0;
}