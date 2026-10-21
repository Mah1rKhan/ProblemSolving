#include <iostream>
using namespace std;

void display(vector<vector<int>> &arr)
{
    for (auto row : arr)
    {
        for (auto x : row)
        {
            cout << x << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

long long nCr(int n, int r)
{
    long long ans = 1;

    for (int i = 1; i <= r; i++)
    {
        ans *= (n - i + 1);
        ans /= i;
    }
    return ans;
}

vector<vector<int>> pascalsTriangle(int numRows)
{
    vector<vector<int>> triangle;

    for (int row = 1; row <= numRows; row++)
    {
        vector<int> currRow;
        for (int col = 1; col <= row; col++)
        {
            int ele = nCr(row - 1, col - 1);
            currRow.push_back(ele);
        }
        triangle.push_back(currRow);
    }
    return triangle;
}

int main()
{

    int numRows = 5;

    cout << "No. of rows : " << numRows << endl;

    cout << "Pascal's Triangle : " << endl;
    vector<vector<int>> triangle = pascalsTriangle(numRows);
    display(triangle);

    return 0;
}