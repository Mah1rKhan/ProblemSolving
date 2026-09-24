/*
Problem Name : Rotate Image/Matrix
Problem Description : Given an n x n 2D matrix representing an image, rotate the image by 90 degrees
(clockwise).

Note : Do this in place
*/
#include <iostream>
using namespace std;

void display(vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (const auto &elem : row)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
}

/*
Intuition : To rotate the matrix by 90 degrees clockwise,
we can first transpose the matrix and then reverse each row.

Time Complexity : O(N^2)
Aux. Space Req. : O(1)
*/

void rotateMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // Transpose the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row of the transposed matrix
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    cout << "Original Matrix:" << endl;
    display(matrix);

    rotateMatrix(matrix);

    cout << "Matrix after 90-degree clockwise rotation:" << endl;
    display(matrix);

    return 0;
}