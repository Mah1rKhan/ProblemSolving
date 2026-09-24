// Program to check if a given string is a palindrome or not using recursion
#include <iostream>
using namespace std;

bool check(int index, string &s)
{
    if (index >= s.size() / 2)
    {
        return true;
    }

    if (s[index] != s[s.size() - index - 1])
    {
        return false;
    }
    return check(index + 1, s);
}

bool checkPalindrome(string &s)
{
    return check(0, s);
}

int main()
{
    string s;
    cout << "Enter String here : ";
    cin >> s;

    bool isPalindrome = checkPalindrome(s);
    if (isPalindrome)
    {
        cout << "Given string is a Palindrome";
    }
    else
    {
        cout << "Given string is NOT a Palindrome";
    }

    return 0;
}