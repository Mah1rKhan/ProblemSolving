/*
Problem Name : Rearrange array elements by sign
Problem Description : Given an array of even size ( >= 2) containing positive and negative elements in random order
Rearrange the array elements in order such that every alternate element is positive and every other element is negative
do this without changing the relative order of elements
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
Intuition : Use two separate containers to store positive and negative elements in order, then reassign the elements in alter-
-nating order

Time Complexity : O(N)
Aux. Space Req. : O(N)
*/

vector<int> reArrangeArray1(vector<int> &arr)
{
    vector<int> positives;
    vector<int> negatives;
    int s = arr.size();
    for (int i = 0; i < s; i++)
    {
        if (arr[i] > 0)
        {
            positives.push_back(arr[i]);
        }
        else
        {
            negatives.push_back(arr[i]);
        }
    }

    int p = 0, n = 0;
    for (int i = 0; i < s; i += 2)
    {
        arr[i] = positives[p];
        p++;
        arr[i + 1] = negatives[n];
        n++;
    }
    return arr;
}

/*
Intuition : Use two pointer approach to assign the alternating elements in a new container

Time Complexity : O(N)
Aux. Space Req. : O(N)
*/

vector<int> reArrangeArray2(vector<int> &arr)
{
    int n = arr.size();
    int countP = 0, countN = 1;

    vector<int> result(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            result[countP] = arr[i];
            countP += 2;
        }
        else
        {
            result[countN] = arr[i];
            countN += 2;
        }
    }
    return result;
}

int main()
{
    vector<int> arr = {-1, 2, 3, -4, 5, -6, -7, 8};
    cout << "Original array : ";
    display(arr);

    vector<int> result = reArrangeArray1(arr);
    cout << "Array after re-arranging : ";
    display(result);
}