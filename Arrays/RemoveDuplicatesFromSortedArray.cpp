/*
Problem Name : Remove Duplicates from a sorted Array
Problem Description : Given a sorted array of integers possibly containing duplicates.
Remove all the duplicates from the array without modifying the relative order of the elements
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
Intuition : Use two pointer approach to swap the elements, one pointer pointing to unique element
another pointer for traversal in array. When we find a first non duplicate element during traversal
we move i one place ahead and assign that unique element to the i index, this way , i again points to
unique element index
After finding unique elements , we can resize the array to remove duplicate elements

Time Complexity : O(N)
Aux. Space Req. : O(1)
*/

int countUniqueElements(vector<int> &arr)
{
    int i = 0;
    int n = arr.size();

    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}

void removeDuplicates(vector<int> &arr)
{
    int uniqueEle = countUniqueElements(arr);
    arr.resize(uniqueEle);
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5, 6};

    cout << "Array before duplicates removal : ";
    display(arr);

    removeDuplicates(arr);

    cout << "Array after duplicates removal : ";
    display(arr);
    return 0;
}