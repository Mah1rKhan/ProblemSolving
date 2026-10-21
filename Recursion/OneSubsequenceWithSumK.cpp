/*
Problem Name : One Subsequence with sum K
Problem Description : Given an array of +ve integers and an integer k, one the subsequence
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

/*
Intuition : Use the concept of 1. pick (add element to sum and subseq.) ,
 2. Not pick (pick, add, remove, subtract) to find the all the subsequences with sum == k

 use bool return type , whenever we find the first subseq with sum == k, we return true

 and whenever we get true during recursion, we break the recursion by returning true

Time Complexity : O(2^N) in worst case
as we may have to generate all subsequences
Aux. Space Req. : O(2^N)
*/

bool f(int index, vector<int> &arr, int sum, int k, vector<int> &subseq)
{
    if (index == arr.size())
    {
        if (sum == k)
        {
            return true;
        }
        return false;
    }

    // pick condition
    subseq.push_back(arr[index]);
    sum += arr[index];

    if (f(index + 1, arr, sum, k, subseq) == true)
    {
        // Answer stored in subseq
        return true;
    }

    // Not pick condition
    subseq.pop_back();
    sum -= arr[index];

    if (f(index + 1, arr, sum, k, subseq) == true)
    {
        // Answer stored in subseq
        return true;
    }

    // If all recursive calls return false , then
    return false;
}

vector<int> subsequenceWithSumK(vector<int> &arr, int k)
{
    int sum = 0;
    vector<int> subseq;

    f(0, arr, sum, k, subseq);

    return subseq;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    cout << "Array is : ";
    display(arr);

    int k = 200;
    vector<int> subseq = subsequenceWithSumK(arr, k);

    if (!subseq.empty())
    {
        cout << "The subsequence with sum " << k << " is : ";
        display(subseq);
    }

    else
    {
        cout << "There is no subsequence with sum " << k;
    }

    return 0;
}