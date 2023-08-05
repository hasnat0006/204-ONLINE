#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node() { val = 0, next = NULL; }
    Node(int n) { val = n, next = NULL; }
};

class Linklist
{
public:
    Node *head;
    Linklist() { head = NULL; }
    void insert_first(int n)
    {
        Node *newitem = new Node(n);
        if (head == NULL)
            head = newitem;
        else
        {
            Node *temp = head;
            head = newitem;
            newitem->next = temp;
        }
    }
    void insert_last(int n)
    {
        Node *newitem = new Node(n);
        if (head == NULL)
            head = newitem;
        Node *it = head;
        while (it->next != NULL)
            it = it->next;
        it->next = newitem;
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
        newitem->next = temp;
    }
    void delete_first()
    {
        if (head != NULL)
            head = head->next;
    }
    void delete_last()
    {
        Node *it = head, *pre = NULL;
        while (it->next != NULL)
            pre = it, it = it->next;
        pre->next = NULL;
    }
    void delete_any_position(int pos)
    {
        Node *it = head, *pre = NULL;
        int c = 1;
        while (it->next != NULL and c != pos)
            pre = it, it = it->next, c++;
        pre->next = it->next;
    }
    void printing_linklist()
    {
        Node *it = head;
        while (it != NULL)
            cout << it->val << " ", it = it->next;
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
        else if (ch == 7)
            l.printing_linklist();
        l.printing_linklist();
    }
}