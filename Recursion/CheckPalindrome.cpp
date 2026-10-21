// Program to check if a given string is a palindrome or not using recursion
#include <iostream>
using namespace std;

/*
Intuition : Think of matching the characters from both ends simultanously , when we reach the centre
(n/2). we have matched all the characters

Time Complexity : O(N/2)
Aux. Space Req. : O(1)
*/

bool check(string &s, int startInd, int endInd)
{
    if (startInd >= endInd)
    {
        return true;
    }
    else if (s[startInd] != s[endInd])
    {
        return false;
    }

    return check(s, startInd + 1, endInd - 1);
}

bool checkPalindrome(string &s)
{
    return check(s, 0, s.size() - 1);
}

int main()
{
    string s;
    cout << "Enter String here : ";
    cin >> s;

    bool isPalindrome = checkPalindrome(s);
    if (isPalindrome)
    {
        cout << "Given string " << "\"" << s << "\"" << " is a Palindrome ";
    }
    else
    {
        cout << "Given string " << "\"" << s << "\"" << " is NOT a Palindrome ";
    }

    return 0;
}