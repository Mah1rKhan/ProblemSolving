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

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4, 5},
                                  {6, 7, 8, 9, 0},
                                  {1, 2, 3, 4, 5},
                                  {6, 7, 8, 9, 0},
                                  {1, 2, 3, 4, 5}};

    // display(matrix);

    for (int i = 0; i <= 5; i++)
    {
        for (int j = i + 1; j <= 5; j++)
        {
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}