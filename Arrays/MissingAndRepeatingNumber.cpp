/*
Program Name : Find missing and repeating number
Program Description : Given an array of size N.
The elements of array are numbers from 1 to N in any order
but one element is missing , and one number is repeating.
Find missing and repeating number
*/

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
Intuition : For each number in range [1, N] find the frequency of the number using nested loop
if frequency = 2 , the number is repeating , if frequency = 0 the number is missing
1. Algorithm Used : Brute Force
   Time Complexity : O(N^2)
   Auxiliary Space Requirement : O(1)
*/

vector<int> findMissingAndRepeating1(vector<int> &arr)
{
    int n = arr.size();
    int missing = -1, repeating = -1;

    for (int i = 1; i <= n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == i)
            {
                count++;
            }
            if (count == 2)
            {
                repeating = i;
                break;
            }
        }
        if (count == 0)
        {
            missing = i;
        }
        if (missing != -1 && repeating != -1)
        {
            break;
        }
    }
    return {missing, repeating};
}

/*
Intuition : For each number in range [1, N] find the frequency of the number
if frequency = 2 , the number is repeating , if frequency = 0 the number is missing
Use hashmap(array as we have fixed length and continuous values) to store the frequency instead of manually counting for each
number
2. Algorithm Used : Better
   Time Complexity : O(N)
   Auxiliary Space Requirement : O(N)
*/

vector<int> findMissingAndRepeating2(vector<int> &arr)
{
    int n = arr.size();
    vector<int> freq(n, 0);
    int missing, repeating;
    for (int i = 0; i < n; i++)
    {
        freq[arr[i] - 1]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (freq[i] == 0)
        {
            missing = i + 1;
        }
        if (freq[i] == 2)
        {
            repeating = i + 1;
        }
    }
    return {missing, repeating};
}

/*
   Intuition : Use two equations and hidden relation between them to find two variables
   (1)  Sum of N natural numbers Sn = N*(N+1)/2
   (2)  Sum of Squares of N natural numbers Sn2 = (N*(N+1)*(2N+1))/6

3. Algorithm Used : Optimal
   Time Complexity : O(N)
   Auxiliary Space Requirement : O(1)
*/

vector<int> findMissingAndRepeating3(vector<int> &arr)
{
    int n = arr.size();
    int s = 0;
    int sn = n * (n + 1) / 2;
    int s2 = 0;
    int sn2 = (n * (n + 1) * (2 * n + 1)) / 6;
    int x; // Repeating Number
    int y; // Missing Number

    for (int i = 0; i < n; i++)
    {
        s += arr[i];
        s2 += (arr[i] * arr[i]);
    }

    x = ((s - sn) + ((s2 - sn2) / (s - sn))) / 2;
    y = x - s + sn;

    return {y, x};
}

/*
Use properties of ^ (xor) and & (and) to compare bits and find the missing and repeating numbers
4. Algorithm Used : Optimal
   Time Complexity : O(N)
   Auxiliary Space Requirement : O(1)
*/

vector<int> findMissingAndRepeating4(vector<int> &arr)
{
    // steps
    // 1. xr1 = xor of all array element
    // 2. xr2 = xor of 1 to n
    // 3. xr3 = xor of xr1 and xr2
    // 4. bitNo = first set bit of xr3 (from right)
    // 5. zero = xor of elements from array and 1 to n in which the bitNo bit is set
    // 6. one = xor of elements from array and 1 to n in which the bitNo is not set
    // either zero or one is repeating number , the other one is missing number
    // 7. Iterate once again to find which one is repeating number from {zero, one}

    int xr = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        xr = xr ^ arr[i];
        xr = xr ^ (i + 1);
    }

    int bitNo = 0;

    while (1)
    {
        if ((xr & (1 << bitNo)) != 0)
        {
            break;
        }
        bitNo++;
    }

    int zero = 0;
    int one = 0;

    for (int i = 0; i < n; i++)
    {
        // bitNo set
        if (((arr[i]) & (1 << bitNo)) != 0)
        {
            one = one ^ arr[i];
        }

        // bitNo not set
        else
        {
            zero = zero ^ arr[i];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        // bitNo set
        if (((i) & (1 << bitNo)) != 0)
        {
            one = one ^ i;
        }

        // bitNo not set
        else
        {
            zero = zero ^ i;
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == zero)
        {
            count++;
        }
    }
    if (count == 2)
    {
        return {one, zero};
    }
    return {zero, one};
}

int main()
{
    vector<int> arr = {6, 5, 8, 7, 1, 4, 1, 3, 2};

    cout << "Array : ";
    display(arr);

    vector<int> missingAndRepeating = findMissingAndRepeating4(arr);

    cout << "Missing Number : " << missingAndRepeating[0] << endl;
    cout << "Repeating Number : " << missingAndRepeating[1] << endl;

    return 0;
}