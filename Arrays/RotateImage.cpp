/*
Problem Name : Rotate Image/Matrix
Problem Description : Given a n x n matrix , rotate the matrix 90 degrees clockwise
Do this in place of original elements
*/
#include <iostream>
using namespace std;

void display(vector<vector<int>> &matrix)
{
    for (auto row : matrix)
    {
        for (auto x : row)
        {
            cout << x << ' ';
        }
        cout << endl;
    }
}

void rotate1(vector<vector<int>> &matrix)
{
    vector<vector<int>> result;
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        vector<int> col;
        for (int j = 0; j < n; j++)
        {
            col.push_back(matrix[j][i]);
        }
        reverse(col.begin(), col.end());
        result.push_back(col);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = result[i][j];
        }
    }
}

void rotateMinus90(vector<vector<int>> &matrix)
{
    rotate1(matrix);
    rotate1(matrix);
    rotate1(matrix);
}

void rotate2(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[j][n - i - 1] = matrix[i][j];
        }
    }

    display(result);
}

void rotate3(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    cout << "Original Matrix : " << endl;
    display(matrix);

    rotate3(matrix);

    cout << "Rotated Matrix : " << endl;
    display(matrix);

    return 0;
}