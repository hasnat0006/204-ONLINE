#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next, *pre;
    Node() { val = 0, next = NULL, pre = NULL; }
    Node(int n) { val = n, next = NULL, pre = NULL; }
};

class Linklist
{
public:
    Node *head, *tail;
    Linklist() { head = tail = NULL; }
    void insert_first(int n)
    {
        Node *newitem = new Node(n);
        if (head == NULL)
            head = newitem, tail = newitem;
        else
        {
            Node *temp = head;
            head = newitem;
            newitem->next = temp;
            temp->pre = newitem;
        }
    }
    void insert_last(int n)
    {
        Node *newitem = new Node(n);
        if (head == NULL)
            head = newitem, tail = newitem;
        else
        {
            tail->next = newitem;
            newitem->pre = tail;
            tail = newitem;
        }
    }
    void insert_any_position(int val, int pos)
    {
        Node *newitem = new Node(val);
        if (head == NULL)
            head = newitem;
        int c = 2;
        Node *it = head;
        while (it != NULL and c != pos)
            it = it->next, c++;
        Node *temp = it->next;
        it->next = newitem;
        newitem->pre = it;
        newitem->next = temp;
        temp->pre = newitem;
    }
    void delete_first()
    {
        if (head != NULL)
            head = head->next, head->pre = NULL;
    }
    void delete_last()
    {
        if (head != NULL)
            tail = tail->pre, tail->next = NULL;
    }
    void delete_any_position(int pos)
    {
        Node *it = head, *previous = NULL;
        int c = 1;
        while (it->next != NULL and c != pos)
            previous = it, it = it->next, c++;
        if (it->next == NULL)
            tail = tail->pre, tail->next = NULL;
        else
        {
            previous->next = it->next;
            it->next->pre = previous;
        }
    }
    void printing_linklist_forward()
    {
        if (head == NULL)
        {
            cout << "LINK LIST IS EMPTY :(\n";
            return;
        }
        cout << "Forward: ";
        Node *it = head;
        while (it != NULL)
            cout << it->val << " ", it = it->next;
        cout << endl;
    }
    void printing_linklist_backward()
    {
        if (head == NULL)
        {
            cout << "LINK LIST IS EMPTY :(\n";
            return;
        }
        cout << "backward: ";
        Node *it = tail;
        while (it != NULL)
            cout << it->val << " ", it = it->pre;
        cout << endl;
    }
};

int main()
{
    Linklist l;
    while (1)
    {
        cout << "1.Insert first\n";
        cout << "2.Insert last\n";
        cout << "3.Insert any position\n";
        cout << "4.Delet first\n";
        cout << "5.Delet last\n";
        cout << "6.Delete any position\n";
        cout << "7.Print the array\n";
        cout << "\nEnter your choice: ";
        int ch, val, pos;
        cin >> ch;
        if (ch == 1)
            cout << "Enter your val: ", cin >> val, l.insert_first(val);
        else if (ch == 2)
            cout << "Enter your val: ", cin >> val, l.insert_last(val);
        else if (ch == 3)
            cout << "Enter your val and pos: ", cin >> val >> pos, l.insert_any_position(val, pos);
        else if (ch == 4)
            l.delete_first();
        else if (ch == 5)
            l.delete_last();
        else if (ch == 6)
            cout << "Enter your pos: ", cin >> pos, l.delete_any_position(pos);
        else
            l.printing_linklist_forward();
        l.printing_linklist_forward();
        l.printing_linklist_backward();
    }
}