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

/*
Intuition : For every cost price, find the highest sell price to maximize the profit using nested loop
Time Complexity : ~ O(N^2)
Aux. Space Req. : O(1)
*/

int maxProfit1(vector<int> &arr)
{
    int maxProfit = 0;
    int ansBuy = arr[0];
    int ansSell = arr[0];
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int cost = arr[i];
        int currProfit = 0;

        for (int j = i + 1; j < n; j++)
        {
            int sell = arr[j];
            currProfit = sell - cost;
            if (currProfit > maxProfit)
            {
                maxProfit = currProfit;
                ansBuy = cost;
                ansSell = sell;
            }
        }
    }
    cout << "Buy at price : " << ansBuy << endl;
    cout << "Sell at price : " << ansSell << endl;
    return maxProfit;
}

/*
2. Algorithm Used : Optimal
   Time Complexity : O(N)
   Auxiliary Space Requirement : O(1)
   Intuition : Start from left and keep updating minimum and profit
*/

int maxProfit2(vector<int> &arr)
{
    int maxProfit = 0;
    int ansBuy = arr[0], ansSell = arr[0];
    int n = arr.size();
    int mini = arr[0];
    for (int i = 1; i < n; i++)
    {
        int currProfit = arr[i] - mini;
        if (currProfit > maxProfit)
        {
            maxProfit = currProfit;
            ansBuy = mini;
            ansSell = arr[i];
        }
        mini = min(mini, arr[i]);
    }

    cout << "Buy at price : " << ansBuy << endl;
    cout << "Sell at price : " << ansSell << endl;
    return maxProfit;
}

int main()
{

    vector<int> arr = {4, 5, 1, 6, 8, 3, 9, 7, 2};
    cout << "Prices : ";
    display(arr);

    int maxProfit = maxProfit2(arr);
    cout << "Maximum Profit : " << maxProfit;
    return 0;
}