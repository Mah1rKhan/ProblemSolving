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
    int count = 1;
    for (auto v : arr)
    {
        cout << count << " : ";
        display(v);
        count++;
    }
}

void generateAllPermutations(vector<int> &arr, vector<int> &currPermutation,
                             vector<vector<int>> &allPermutations, vector<int> &freq)
{
    if (currPermutation.size() == arr.size())
    {
        allPermutations.push_back(currPermutation);
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (freq[i] == 0)
        {
            currPermutation.push_back(arr[i]);
            freq[i] = 1;

            generateAllPermutations(arr, currPermutation, allPermutations, freq);

            freq[i] = 0;
            currPermutation.pop_back();
        }
    }
}

vector<int> nextPermutationHelper(vector<int> &arr)
{
    int n = arr.size();
    vector<int> copyArr = arr;
    sort(copyArr.begin(), copyArr.end());
    vector<int> freq(n, 0);
    vector<int> currPermutation;
    vector<vector<int>> allPermutations;
    generateAllPermutations(copyArr, currPermutation, allPermutations, freq);

    // S = total no. of permutations
    int s = allPermutations.size();

    // sort(allPermutations.begin(), allPermutations.end());

    display(allPermutations);

    for (int i = 0; i < s; i++)
    {
        if (allPermutations[i] == arr && i != s - 1)
        {
            while (allPermutations[i] == allPermutations[i + 1] && i < s)
            {
                i++;
            }
            if (i == s - 1)
            {
                break;
            }
            return allPermutations[i + 1];
        }
    }
    return allPermutations[0];
}

void nextPermutation1(vector<int> &arr)
{
    arr = nextPermutationHelper(arr);
}

/*
Steps
1. Find the break point from the right
2. Find the smallest element which is bigger than the break point element
3. Swap both the elements
4. Reverse from next of break point to end
*/
void nextPermutation2(vector<int> &arr)
{
    int n = arr.size();
    int ind = -1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            ind = i;
            break;
        }
    }

    if (ind == -1)
    {
        reverse(arr.begin(), arr.end());
        return;
    }

    for (int i = n - 1; i >= ind; i--)
    {
        if (arr[i] > arr[ind])
        {
            swap(arr[i], arr[ind]);
            break;
        }
    }

    reverse(arr.begin() + ind + 1, arr.end());
}

int main()
{
    vector<int> arr1 = {1, 4, 3};

    cout << "Array : ";
    display(arr1);

    nextPermutation1(arr1);

    cout << "Next Permutation : ";
    display(arr1);

    vector<int> arr2 = {1, 4, 3};
    nextPermutation2(arr2);

    cout << "Next Permutation : ";
    display(arr2);

    return 0;
}