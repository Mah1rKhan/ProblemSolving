#include <iostream>
using namespace std;

void display(vector<int> &row)
{
    for (auto x : row)
    {
        cout << x << ' ';
    }
    cout << endl;
}

void display(vector<vector<int>> &triangle)
{
    for (auto row : triangle)
    {
        display(row);
    }
}

long long nCr(int n, int r)
{
    long long ans = 1;

    for (int i = 0; i < r; i++)
    {
        ans *= (n - i);
        ans /= (i + 1);
    }
    return ans;
}

vector<vector<int>> pascalsTriangle(int numRows)
{
    vector<vector<int>> ans;
    for (int row = 1; row <= numRows; row++)
    {
        vector<int> currRow;
        for (int col = 1; col <= row; col++)
        {
            int ele = nCr(row - 1, col - 1);
            currRow.push_back(ele);
        }
        ans.push_back(currRow);
    }
    return ans;
}

int main()
{
    int numRows = 5;

    cout << "No. of rows : " << numRows << endl;

    vector<vector<int>> triangle = pascalsTriangle(numRows);

    cout << "Pascal's Triangle : " << endl;

    display(triangle);

    return 0;
}