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

// Merge sort algorithm

// Divide into n/2 and apply merge sort both halves recursively
// merge the result of both in sorted manner

void merge(vector<int> &arr, int start, int mid, int end)
{
    int left = start, right = mid + 1;

    vector<int> temp;
    while (left <= mid && right <= end)
    {
        if (arr[left] < arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= end)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[i - start];
    }
}

void mS(vector<int> &arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    mS(arr, start, mid);
    mS(arr, mid + 1, end);

    merge(arr, start, mid, end);
}

void mergeSort(vector<int> &arr)
{
    int n = arr.size();
    mS(arr, 0, n - 1);
}

int main()
{
    vector<int> arr = {1, 4, 2, 5, 6, 7, 3, 0, 9, 8};

    cout << "Array before sorting : ";
    display(arr);

    mergeSort(arr);

    cout << "Array after sorting  : ";
    display(arr);

    return 0;
}