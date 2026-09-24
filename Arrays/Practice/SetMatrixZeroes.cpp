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

void markRow(vector<vector<int>> &matrix, int rowNo)
{
    int cols = matrix[0].size();

    for (int colNo = 0; colNo < cols; colNo++)
    {
        if (matrix[rowNo][colNo] != 0)
        {
            matrix[rowNo][colNo] = -1;
        }
    }
}

void markCol(vector<vector<int>> &matrix, int colNo)
{
    int rows = matrix.size();

    for (int rowNo = 0; rowNo < rows; rowNo++)
    {
        if (matrix[rowNo][colNo] != 0)
        {
            matrix[rowNo][colNo] = -1;
        }
    }
}

// Time Complexity :~ O(N^3)
// Aux. Space Req. : O(1)
void setMatrixZeroes1(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                // Mark entire row

                markRow(matrix, i);

                // Mark entire col.

                markCol(matrix, j);
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

void setMatrixZeroes2(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<bool> markedRows(m, false), markedCols(n, false);

    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (matrix[row][col] == 0)
            {
                markedRows[row] = true;
                markedCols[col] = true;
            }
        }
    }

    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (markedRows[row] || markedCols[col])
            {
                matrix[row][col] = 0;
            }
        }
    }
}

void setMatrixZeroes3(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    bool firstRow = false, firstCol = false;

    // Traverse for marking
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (matrix[row][col] == 0 && row == 0)
            {
                firstRow = true;
            }
            if (matrix[row][col] == 0 && col == 0)
            {
                firstCol = true;
            }
            else if (matrix[row][col] == 0)
            {
                // mark first ele in top
                matrix[0][col] = 0;

                // mark first ele in left
                matrix[row][0] = 0;
            }
        }
    }

    // Traverse for setting inner matrix zeroes
    for (int row = 1; row < m; row++)
    {
        for (int col = 1; col < n; col++)
        {
            if (matrix[row][col] != 0)
            {
                if (matrix[0][col] == 0 || matrix[row][0] == 0)
                {
                    matrix[row][col] = 0;
                }
            }
        }
    }

    // Traverse first row
    for (int col = 0; col < n && firstRow == true; col++)
    {
        matrix[0][col] = 0;
    }

    // Traverse first col
    for (int row = 0; row < m && firstCol == true; row++)
    {
        matrix[row][0] = 0;
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4, 9}, {5, 0, 6, 7, 0}, {0, 8, 9, 1, 1}, {2, 3, 4, 5, 2}, {6, 7, 0, 8, 3}};

    cout << "Original Matrix : " << endl;
    display(matrix);

    setMatrixZeroes3(matrix);

    cout << "Matrix after setting zeroes : " << endl;

    display(matrix);

    return 0;
}