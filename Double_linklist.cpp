#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *prev, *next;
    Node()
    {
        prev = NULL, next = NULL;
        val = 0;
    }
    Node(int n)
    {
        prev = NULL, next = NULL;
        val = n;
    }
};
class doublelist
{
    Node *head, *tail;

public:
    doublelist() { head = NULL, tail = NULL; }
    void print()
    {
        cout << "Forward: ";
        Node *it = head;
        while (it != NULL)
            cout << it->val << " ", it = it->next;
        cout << endl;
        cout << "Backward: ";
        it = tail;
        while (it != NULL)
            cout << it->val << " ", it = it->prev;
        cout << endl;
        cout << endl;
    }
    void insert_last(int n)
    {
        Node *newitem;
        newitem = new Node(n);
        if (head == NULL)
            head = newitem, tail = newitem;
        else
        {
            tail->next = newitem;
            newitem->prev = tail;
            tail = newitem;
        }
    }
    void insert_first(int n)
    {
        Node *newitem;
        newitem = new Node(n);
        if (head == NULL)
            head = newitem, tail = newitem;
        else
        {
            head->prev = newitem;
            newitem->next = head;
            head = newitem;
        }
    }
    void insert_after_val(int fnd, int rep)
    {
        Node *newitem;
        newitem = new Node(rep);
        if (head == NULL)
            cout << "Double linked list is empty.\n";
        else
        {
            Node *it = head, *it2;
            while (it != NULL and it->val != fnd)
                it = it->next;
            if (it != NULL)
            {
                it2 = it->next;
                it->next = newitem;
                newitem->prev = it;
                newitem->next = it2;
                it2->prev = newitem;
            }
            else
                cout << "Value not found.\n";
        }
    }
    void delete_first() { head = head->next, head->prev = NULL; }
    void delete_last() { tail = tail->prev, tail->next = NULL; }
    void delete_any_val(int n)
    {
        Node *it = head, *pore, *age;
        while (it != NULL and it->val != n)
            it = it->next;
        if (it->next == NULL)
            delete_last();
        else if (it->prev == NULL)
            delete_first();
        else if (it != NULL)
        {
            pore = it->next;
            age = it->prev;
            age->next = pore;
            pore->prev = age;
        }
        else
            cout << "Value not found.\n";
    }
    // create a new list from the avg value of two link list.
    void avg(doublelist a, doublelist b)
    {
        Node *it1 = NULL, *it2 = NULL;
        it1 = a.head;
        it2 = b.head;
        while (it1 != NULL and it2 != NULL)
        {
            insert_last((it1->val + it2->val) / 2);
            it1 = it1->next;
            it2 = it2->next;
        }
        if (it1 != NULL)
        {
            while (it1 != NULL)
            {
                insert_last((it1->val) / 2);
                it1 = it1->next;
            }
        }
        else if (it2 != NULL)
        {
            while (it2 != NULL)
            {
                insert_last((it2->val) / 2);
                it2 = it2->next;
            }
        }
    }
    // marge link list then sort the list
    void sorting(doublelist a, doublelist b)
    {
        Node *it1 = a.tail, *it2 = b.head;
        it1->next = it2;
        it2->prev = it1;
        head = a.head;
        tail = b.tail;
        it1 = head;
        it2 = head;
        while (it1 != NULL)
        {
            it2 = head;
            while (it2 != NULL)
            {
                if (it1->val < it2->val)
                    swap(it1->val, it2->val);
                it2 = it2->next;
            }
            it1 = it1->next;
        }
    }
    // delete all the odd numbers
    void delete_odd()
    {
        Node *it1 = head, *age, *pore;
        while (it1 != NULL)
        {
            if (it1->val & 1)
            {
                if (it1->prev == NULL)
                    delete_first();
                else if (it1->next == NULL)
                    delete_last();
                else
                {
                    pore = it1->next;
                    age = it1->prev;
                    age->next = pore;
                    pore->prev = age;
                    it1 = age;
                }
            }
            it1 = it1->next;
        }
    }
    // delete duplicate element.
    void delete_duplicate()
    {
        Node *it1 = head, *it2 = head, *age, *pore;
        while (it1 != NULL)
        {
            it2 = it1->next;
            while (it2 != NULL)
            {
                if (it2->val == it1->val)
                {
                    if (it2->next == NULL)
                        delete_last();
                    else
                    {
                        pore = it2->next;
                        age = it2->prev;
                        age->next = pore;
                        pore->prev = age;
                        age = it2;
                    }
                }
                it2 = it2->next;
            }
            it1 = it1->next;
        }
    }
    // delete from first link list
    void delete_form_list(doublelist b)
    {
        Node *it1, *it2, *age, *pore;
        it1 = head;
        it2 = b.head;
        while (it1 != NULL)
        {
            it2 = b.head;
            while (it2 != NULL)
            {
                if (it1->val == it2->val)
                {
                    if (it1->next == NULL)
                        delete_last();
                    else if (it1->prev == NULL)
                        delete_first();
                    else
                    {
                        pore = it1->next;
                        age = it1->prev;
                        age->next = pore;
                        pore->prev = age;
                        it1 = age;
                    }
                }
                it2 = it2->next;
            }
            it1 = it1->next;
        }
    }
};
int main()
{
    doublelist dl1, dl2, av, st;
    dl1.insert_last(10);
    dl1.insert_last(20);
    dl1.insert_last(30);
    dl1.insert_last(40);
    dl1.insert_last(40);
    dl1.insert_last(40);
    dl1.insert_last(40);
    // dl1.insert_last(0);
    dl1.delete_any_val(10);
    dl1.print();
    dl2.insert_last(10);
    dl2.insert_last(25);
    dl2.insert_last(30);
    dl2.insert_last(40);
    dl2.insert_last(55);
    dl2.print();
    av.avg(dl1, dl2);
    av.print();
    st.sorting(dl1, dl2);
    st.print();
    dl2.delete_odd();
    dl2.print();
    dl1.delete_duplicate();
    dl1.print();
    // for problem 6;
    doublelist a, b;
    // 1 9 2 4 10
    a.insert_last(1);
    a.insert_last(9);
    a.insert_last(2);
    a.insert_last(4);
    a.insert_last(10);
    b.insert_last(4);
    b.insert_last(1);
    b.insert_last(9);
    a.print();
    b.print();
    a.delete_form_list(b);
    a.print();
    b.print();
}