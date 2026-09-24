/*
Problem Name : Longest consecutive sequence
Problem Description : Given an array of integers, find the length of longest subsequence of
consecutive integers

Note : In a subsequence of any array , we can take elements in any order
*/
#include <iostream>
#include <unordered_set>
using namespace std;

void display(vector<int> &arr)
{
    for (auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

bool linearSearch(int n, vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == n)
        {
            return true;
        }
    }
    return false;
}

/*
Intuition : Check for all consecutive integer subsequenses using linear search and keep updating
maximum length

Time Complexity : O(N^2)
Aux. Space Req. : O(1)
*/

int longestConsecutiveSequence1(vector<int> &arr)
{
    int longestLen = 1;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        vector<int> sequence;
        int a = arr[i];
        int currLen = 1;
        while (linearSearch(a + 1, arr) == true)
        {
            currLen++;
            a++;
        }
        if (currLen > longestLen)
        {
            longestLen = currLen;
        }
    }
    return longestLen;
}

/*
Intuition : Instead of counting length of all consecutive integer subsequences, we sort the array
and then we start counting the length of the consecutive integers

Time Complexity : O(N + N logN)
Aux. Space Req. : O(N logN) for sorting
*/

int longestConsecutiveSequence2(vector<int> &arr)
{
    int n = arr.size();
    int maxLen = 1;
    int currLen = 0, lastEle = INT_MIN;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        if (lastEle == arr[i] - 1)
        {
            currLen++;
            lastEle = arr[i];
        }
        else if (arr[i] != lastEle)
        {
            currLen = 1;
            lastEle = arr[i];
        }
        maxLen = max(maxLen, currLen);
    }
    return maxLen;
}
/*
Intuition : Use a hash set (unordered set) for storing elements and finding consecutive elements
Time Complexity : O(N)
Aux. Space Req. : O(N)
*/
int longestConsecutiveSequence3(vector<int> &arr)
{
    int n = arr.size();
    int maxLen = 1;
    int currLen = 0;
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    for (auto a : s)
    {
        // If an element does not have predecessor , we check for consecutive subsequence from that
        // element only , otherwise the elements have already been iterated and subsequence length has
        // been found
        if (s.find(a - 1) == s.end())
        {
            currLen = 1;
            int x = a;

            // This loop is the find the length
            while (s.find(x + 1) != s.end())
            {
                x++;
                currLen++;
            }
        }
        maxLen = max(currLen, maxLen);
    }
    return maxLen;
}

int main()
{
    vector<int> arr = {102, 4, 100, 1, 101, 3, 2, 1, 1};
    display(arr);

    cout << longestConsecutiveSequence3(arr);

    return 0;
}