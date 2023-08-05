#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int n) { val = n, next = NULL; }
};

class Queue
{
public:
    Node *head, *tail;
    Queue() { head = tail = NULL; }
    bool isEmpty()
    {
        if (head == NULL)
            return true;
        return false;
    }
    void enqueue(int val)
    {
        Node *newitem = new Node(val);
        if (isEmpty())
            head = tail = newitem;
        else
        {
            tail->next = newitem;
            tail = newitem;
        }
    }
    void front_element()
    {
        if (isEmpty())
            cout << "Queue is already empty" << endl;
        else
            cout << "Top element is: " << head->val << endl;
    }
    void Dequeue()
    {
        if (isEmpty())
            cout << "Queue is already empty" << endl;
        else
            head = head->next;
    }
    void printing_queue()
    {
        Node *it = head;
        while (it != NULL)
            cout << it->val << " ", it = it->next;
        cout << endl;
    }
};

int main()
{
    Queue st;
    while (1)
    {
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        int ch, val;
        cout << "Enter your choice: ", cin >> ch;
        if (ch == 1)
            cout << "Enter value to enqueue: ", cin >> val, st.enqueue(val);
        else if (ch == 2)
            cout << "Element poped\n", st.Dequeue();
        else if (ch == 3)
            st.front_element();
        st.printing_queue();
    }
}