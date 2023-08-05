#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *pre;
    Node(int n) { val = n, pre = NULL; }
};

class Stack
{
public:
    Node *head;
    Stack() { head = NULL; }
    bool isEmpty()
    {
        if (head == NULL)
            return true;
        return false;
    }
    void push(int val)
    {
        Node *newitem = new Node(val);
        if (isEmpty())
            head = newitem;
        else
        {
            newitem->pre = head;
            head = newitem;
        }
    }
    void top_element()
    {
        if (isEmpty())
            cout << "Stack is already empty" << endl;
        else
            cout << "Top element is: " << head->val << endl;
    }
    void pop()
    {
        if (isEmpty())
            cout << "Stack is already empty" << endl;
        else
            head = head->pre;
    }
    void printing_stack()
    {
        Node *it = head;
        while (it != NULL)
            cout << it->val << " ", it = it->pre;
        cout << endl;
    }
};

int main()
{
    Stack st;
    while (1)
    {
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        int ch, val;
        cout << "Enter your choice: ", cin >> ch;
        if (ch == 1)
            cout << "Enter value to push: ", cin >> val, st.push(val);
        else if (ch == 2)
            cout << "Element poped\n", st.pop();
        else if (ch == 3)
            st.top_element();
        st.printing_stack();
    }
}