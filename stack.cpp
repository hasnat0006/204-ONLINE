#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    node *next;
    int val;
    node() {}
    node(int n) { val = n, next = NULL; }
};

class Stack
{
    node *head;
    int SIZE;

public:
    Stack() { head = NULL, SIZE = 0; }
    void push(int n)
    {
        node *newitem = new node(n);
        if (head == NULL)
            head = newitem;
        else
        {
            newitem->next = head;
            head = newitem;
        }
        SIZE++;
    }
    void pop()
    {
        if (!isEmpty())
            head = head->next;
    }
    int top()
    {
        if (!isEmpty())
            return head->val;
    }
    void print()
    {
        node *it = head;
        while (it != NULL)
            std::cout << it->val << " ", it = it->next;
    }
    bool isEmpty()
    {
        if (SIZE == 0)
            return true;
        return false;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.print();
    s.pop();
    std::cout << s.top() << endl;
    s.pop();
    std::cout << s.top() << endl;
    s.pop();
    std::cout << s.top() << endl;
    s.pop();
    std::cout << s.top() << endl;
    s.pop();
    std::cout << s.top() << endl;
}
