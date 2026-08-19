/*
Problem Name : Union of two sorted arrays
Problem Description : Given two sorted array A and B , find the union of the elements of both arrays
in the sorted manner only
*/
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

/*
Intuition : Mathematically a (A U B) union does not contain duplicates (contains unique elements only)
which are present in either set A , either set B or in both sets A and B
Think of using a data structure which can store unique , sorted elements

Time Complexity : ~O(2(N1+N2))
Aux. Space Req. : O(N1 + N2)
*/

vector<int> unionOfTwoSortedArrays1(vector<int> &arr1, vector<int> &arr2)
{
    set<int> s;
    for (int i = 0; i < arr1.size(); i++)
    {
        s.insert(arr1[i]);
    }
    for (int i = 0; i < arr2.size(); i++)
    {
        s.insert(arr2[i]);
    }
    vector<int> result;
    for (auto x : s)
    {
        result.push_back(x);
    }
    return result;
}

/*
Intuition : Use

Time Complexity : ~O(2(N1+N2))
Aux. Space Req. : O(N1 + N2)
*/

vector<int> unionOfTwoSortedArrays2(vector<int> &arr1, vector<int> &arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i = 0, j = 0;
    vector<int> result;
    while (i < n1 && j < n2)
    {
        // For arr1 elements
        if (arr1[i] <= arr2[j])
        {
            if (result.size() == 0 || result.back() != arr1[i])
            {
                result.push_back(arr1[i]);
            }
            i++;
        }

        // For arr2 elements
        if (arr2[j] <= arr1[i])
        {
            if (result.size() == 0 || result.back() != arr2[j])
            {
                result.push_back(arr2[j]);
            }
            j++;
        }
    }

    // For remaining elements
    while (i < n1)
    {
        if (result.size() == 0 || result.back() != arr1[i])
        {
            result.push_back(arr1[i]);
        }
        i++;
    }
    while (j < n2)
    {
        if (result.size() == 0 || result.back() != arr2[j])
        {
            result.push_back(arr2[j]);
        }
        j++;
    }
    return result;
}

int main()
{
    vector<int> arr1 = {0, 1, 2, 2, 3, 5, 7, 8, 9, 11, 12, 13};
    vector<int> arr2 = {0, 2, 2, 4, 6, 8, 9, 12, 14, 16};

    display(arr1);
    display(arr2);

    vector<int> arr3 = unionOfTwoSortedArrays2(arr1, arr2);
    display(arr3);

    return 0;
}