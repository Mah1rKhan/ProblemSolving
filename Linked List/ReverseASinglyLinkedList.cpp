#include <iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int data, ListNode *next)
    {
        this->data = data;
        this->next = next;
    }

    ListNode(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void display(ListNode *head)
{
    ListNode *c = head;
    while (c)
    {
        cout << c->data << ' ';
        c = c->next;
    }
    cout << endl;
}

ListNode *arrToLinkedList(vector<int> &arr)
{
    if (arr.empty())
        return nullptr;

    ListNode *head = new ListNode(arr[0]);
    ListNode *c = head;

    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *temp = new ListNode(arr[i]);
        c->next = temp;
        c = c->next;
    }
    return head;
}

ListNode *reverseSinglyLinkedList1(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *c = head;
    stack<int> st;

    while (c != nullptr)
    {
        st.push(c->data);
        c = c->next;
    }
    c = head;
    while (c != nullptr)
    {
        int ele = st.top();
        st.pop();
        c->data = ele;
        c = c->next;
    }
    return head;
}

ListNode *reverseSinglyLinkedList2(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *lastNode = nullptr;
    ListNode *currNode = head;

    while (currNode != nullptr)
    {
        ListNode *nextNode = currNode->next;
        currNode->next = lastNode;
        lastNode = currNode;
        currNode = nextNode;
    }
    return lastNode;
}

int main()
{
    vector<int> arr = {6, 5, 4, 3, 2, 1};
    ListNode *head = arrToLinkedList(arr);

    display(head);

    head = reverseSinglyLinkedList1(head);
    display(head);

    return 0;
}