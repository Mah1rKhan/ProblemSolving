/*
Program to check if a string is Palindrome or not
*/
#include <iostream>
#include <string>
using namespace std;

bool check(int start, string &s)
{
    // 1. Base case
    if (start >= s.size() / 2)
    {
        return true;
    }

    // 2. Base case
    if (s[start] != s[s.size() - start - 1])
    {
        return false;
    }
    return check(start + 1, s);
}

bool checkPalindrome(string &s)
{
    return check(0, s);
}

int main()
{
    // string s = "MADAAM";
    // cout << "String is : " << s << endl;
    string s;
    cout << "Enter the string : ";
    cin >> s;

    bool isPalindrome = checkPalindrome(s);

    if (isPalindrome)
    {
        cout << "String is a Palindrome";
    }
    else
    {
        cout << "String is NOT a Palindrome";
    }

    return 0;
}