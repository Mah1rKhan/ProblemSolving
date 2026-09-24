/*
Problem Name : Set Matrix Zeroes
Problem Description : Given a 2-D array consisting of M rows of N integers.
If any element in matrix is zero , set all the elements in its row to zero and set
all elements in its col to zero
*/

#include <iostream>
using namespace std;

void display(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
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

void setRowZeroes(vector<vector<int>> &arr, int i)
{
    int m = arr[i].size();
    for (int j = 0; j < m; j++)
    {
        if (arr[i][j] != 0)
        {
            arr[i][j] = -1;
        }
    }
}

void setColumnZeroes(vector<vector<int>> &arr, int j)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i][j] != 0)
        {
            arr[i][j] = -1;
        }
    }
}
void setMatrixZeroes1(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                setRowZeroes(arr, i);
                setColumnZeroes(arr, j);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == -1)
            {
                arr[i][j] = 0;
            }
        }
    }
}

void display2(vector<int> &arr)
{
    for (auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

void setMatrixZeroes2(vector<vector<int>> &arr)
{
    int m = arr.size();
    int n = arr[0].size();
    vector<int> row(m, 0);
    vector<int> col(n, 0);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (row[i] == 1 || col[j] == 1)
            {
                arr[i][j] = 0;
            }
        }
    }
}
void setMatrixZeroes3(vector<vector<int>> &arr)
{
    int m = arr.size();
    int n = arr[0].size();

    // arr[i][0] -> marks ith row
    // arr[0][j] -> marks jth column

    int col0 = 1;

    // STEP 1: Mark rows and columns
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
            {
                // Mark ith row
                arr[i][0] = 0;

                // Mark jth column
                if (j != 0)
                {
                    arr[0][j] = 0;
                }
                else
                {
                    col0 = 0;
                }
            }
        }
    }

    // STEP 2: Set inner matrix elements to zero
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                if (arr[i][0] == 0 || arr[0][j] == 0)
                {
                    arr[i][j] = 0;
                }
            }
        }
    }

    // STEP 3: Handle first row
    if (arr[0][0] == 0)
    {
        for (int j = 0; j < n; j++)
        {
            arr[0][j] = 0;
        }
    }

    // STEP 4: Handle first column
    if (col0 == 0)
    {
        for (int i = 0; i < m; i++)
        {
            arr[i][0] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> arr = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}};
    cout << "Original Matrix : " << endl;
    display(arr);

    // setMatrixZeroes1(arr);

    // setMatrixZeroes2(arr);

    setMatrixZeroes3(arr);

    cout << "Matrix after setting zeroes : " << endl;
    display(arr);
}