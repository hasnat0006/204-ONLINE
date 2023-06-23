#include <bits/stdc++.h>
using namespace std;

class linklist
{
    int val;
    linklist *head, *next;

public:
    linklist()
    {
        val = 0;
        head = next = NULL;
    }
    linklist(int n)
    {
        val = n;
        next = NULL;
    }
    void insert_first(int n)
    {
        linklist *newitem;
        newitem = new linklist;
        newitem->val = n;
        newitem->next = head;
        head = newitem;
    }
    void insert_last(int n)
    {
        linklist *newitem;
        newitem = new linklist(n);
        if (head == NULL)
            head = newitem;
        else
        {
            linklist *it = head;
            while (it->next != NULL)
                it = it->next;
            it->next = newitem;
        }
    }
    void insert_any_position(int n, int id)
    {
        linklist *newitem = new linklist(n);
        int c = 0;
        linklist *it = head, *pre = NULL;
        while (it != NULL and c != id)
        {
            pre = it;
            it = it->next;
            c++;
        }
        pre->next = newitem;
        newitem->next = it;
    }
    void delete_first()
    {
        head = head->next;
    }
    void delete_last()
    {
        linklist *it = head, *pre = NULL;
        while (it->next != NULL)
            pre = it, it = it->next;
        pre->next = NULL;
    }
    void delete_any(int n)
    {
        linklist *it = head, *pre = NULL;
        while (it->val != n)
        {
            pre = it;
            it = it->next;
        }
        pre->next = it->next;
    }
    void print()
    {
        linklist *it;
        it = head;
        while (it != NULL)
            cout << it->val << " ", it = it->next;
        cout << endl;
    }
};

int main()
{
    linklist l;
    l.insert_first(10);
    l.insert_first(5);
    l.insert_last(20);
    l.insert_last(30);
    l.insert_any_position(15, 2);
    l.print();
    l.delete_first();
    l.print();
    l.delete_last();
    l.print();
    l.delete_any(15);
    l.print();
}