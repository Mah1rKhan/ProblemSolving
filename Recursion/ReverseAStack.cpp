#include <iostream>
using namespace std;

void display(stack<int> &st)
{
    stack<int> temp = st;
    while (!temp.empty())
    {
        int x = temp.top();
        temp.pop();
        cout << x << ' ';
    }
    cout << endl;
}

stack<int> arrayToStack(vector<int> &arr)
{
    stack<int> st;
    for (auto x : arr)
    {
        st.push(x);
    }
    return st;
}

void insertAtBottom(std::stack<int> &st, int item)
{
    // Base case: if stack is empty, push the item
    if (st.empty())
    {
        st.push(item);
        return;
    }

    // Hold the top element in the function call stack
    int topElement = st.top();
    st.pop();

    // Recursively travel down to the bottom
    insertAtBottom(st, item);

    st.push(topElement);
}

void reverseStack(stack<int> &st)
{
    // Base case
    if (st.empty())
    {
        return;
    }

    // Pop the top element and hold it in the function call stack
    int topElement = st.top();
    st.pop();

    // Recursively reverse the remaining stack
    reverseStack(st);

    // Insert the held element at the bottom
    insertAtBottom(st, topElement);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    stack<int> st = arrayToStack(arr);

    cout << "Original Stack is : ";
    display(st);

    reverseStack(st);

    cout << "Reversed Stack : ";
    display(st);

    return 0;
}