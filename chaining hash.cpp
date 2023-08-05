#include <bits/stdc++.h>
using namespace std;

template <class A, class B>
class Data
{
public:
    A key;
    B value;
    Data *next;
    Data(A key, B value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
};

template <class A, class B>
class HashTable
{
public:
    Data<A, B> **table;
    int mx, size;
    HashTable(int sz = 10)
    {
        table = new Data<A, B> *[sz];
        mx = sz;
        for (int i = 0; i < mx; i++)
            table[i] = NULL;
        size = 0;
    }
    int HashFunction(string &s)
    {
        int index = 0;
        for (auto i : s)
            index = (index + i) % mx;
        return index;
    }
    int HashFunction(int n)
    {
        int index = 0;
        while (n > 0)
            index = (index + n % 10) % mx, n /= 10;
        return index;
    }
    void insert(Data<A, B> *data)
    {
        if (data == NULL)
            return;
        int index = HashFunction(data->key);
        if (table[index] == NULL)
            table[index] = data, size++;
        else
            insert_in_chain(data, index);
    }
    void insert_in_chain(Data<A, B> *data, int index)
    {
        Data<A, B> *current = table[index];
        if (current->key == data->key)
        {
            cout << "Same key found \n";
            current->value = data->value;
            return;
        }
        while (current->next != NULL)
        {
            if (current->key == data->key)
            {
                cout << "Same key found \n";
                current->value = data->value;
                return;
            }
            current = current->next;
        }
        current->next = data;
        size++;
    }
    Data<A, B> *find(A a)
    {
        int index = HashFunction(a);
        Data<A, B> *current = table[index];
        while (current != NULL)
        {
            if (current->key == a)
                return current;
            current = current->next;
        }
        return NULL;
    }
    void erase(A a)
    {
        if (find(a) != NULL)
        {
            Data<A, B> *curr = table[HashFunction(a)];
            Data<A, B> *prev = NULL;
            while (curr->key != a)
                prev = curr, curr = curr->next;
            if (prev == NULL)
                table[HashFunction(a)] = NULL;
            else
                prev->next = curr->next;
            size--;
            cout << "Key is deleted\n";
        }
        else
            cout << "Key isnot present in hashtable.\n";
    }
    void print()
    {
        for (int i = 0; i < mx; i++)
        {
            if (table[i] != NULL)
            {
                Data<A, B> *temp = table[i];
                if (temp->next != NULL)
                {
                    Data<A, B> *it = temp;
                    while (it != NULL)
                        cout << it->key << " " << it->value << endl, it = it->next;
                }
                else
                    cout << temp->key << " " << temp->value << endl;
            }
        }
    }
};

int main()
{
    HashTable<string, int> h;
    while (1)
    {
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Find\n";
        cout << "4. Size\n";
        cout << "5. Print\n";
        cout << "Choice: ";
        int ch, val;
        string s;
        cin >> ch;
        if (ch == 1)
        {
            cout << "Enter your key and value: ", cin >> s >> val;
            Data<string, int> *d = new Data<string, int>(s, val);
            h.insert(d);
        }
        if (ch == 2)
        {
            cout << "Enter key to delete: ", cin >> s;
            h.erase(s);
        }
        else if (ch == 3)
        {
            cout << "Enter key to find: ", cin >> s;
            if (h.find(s) != NULL)
                cout << h.find(s)->key << " " << h.find(s)->value << endl;
            else
                cout << "Key not found\n";
        }
        else if (ch == 4)
            cout << h.size << endl;
        h.print();
    }
}
/*
1
hasnat 112
1
zaima 114
1
pallob 62
1
nabiha 74
1
raisul 52
*/