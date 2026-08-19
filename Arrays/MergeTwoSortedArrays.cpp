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

vector<int> merge(vector<int> &arr1, vector<int> &arr2)
{
    int m = arr1.size(), n = arr2.size();
    vector<int> ans;

    int i = 0, j = 0;

    while (i < m && j < n)
    {
        if (arr1[i] <= arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
        }
        else
        {
            ans.push_back(arr2[j]);
            j++;
        }
    }

    while (i < m)
    {
        ans.push_back(arr1[i]);
        i++;
    }

    while (j < n)
    {
        ans.push_back(arr2[j]);
        j++;
    }

    return ans;
}

int main()
{
    vector<int> arr1 = {2, 4, 6, 7, 10, 12, 13};
    cout << "Array 1 : ";
    display(arr1);

    vector<int> arr2 = {1, 3, 5, 6, 7, 8, 9, 11};
    cout << "Array 2 : ";
    display(arr2);

    vector<int> arr = merge(arr1, arr2);
    cout << "Merged array : ";
    display(arr);

    return 0;
}