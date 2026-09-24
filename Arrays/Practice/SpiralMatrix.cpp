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

void display(vector<vector<int>> &matrix)
{
    for (auto row : matrix)
    {
        display(row);
    }
}

// Steps
// 1. i -> left to right, arr[top][i], top++

// 2. i-> top to bottom, arr[i][left], right--

// 3. i-> right to left, arr[bottom][i], bottom--

// 4. i-> bottom to top, arr[i][left], left++

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int m = matrix.size(), n = matrix[0].size();
    int top = 0, left = 0;
    int bottom = m - 1, right = n - 1;

    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
        }

        top++;

        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        for (int i = right; i >= left; i--)
        {
            ans.push_back(matrix[bottom][i]);
        }
        bottom--;

        for (int i = bottom; i >= top; i--)
        {
            ans.push_back(matrix[i][left]);
        }
        left++;
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};

    cout << "Matrix is : " << endl;
    display(matrix);

    vector<int> result = spiralOrder(matrix);
    display(result);

    return 0;
}