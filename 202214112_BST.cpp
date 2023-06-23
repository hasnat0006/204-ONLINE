#include <bits/stdc++.h>
#define int long long
using namespace std;
class Node
{
public:
    Node *left, *right, *parent;
    int isbn, quantity;
    string title, author;
    float price;
    Node() {}
    Node(int isbn, int quantity, string title, string author, float price)
    {
        this->left = this->right = this->parent = NULL;
        this->isbn = isbn;
        this->quantity = quantity;
        this->title = title;
        this->author = author;
        this->price = price;
    }
    int getIsbn() { return isbn; }
    void print()
    {
        cout << "ISBN: " << isbn << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << endl;
    }
};
class BST
{
    friend class Node;
    Node *root;

public:
    BST() { root = NULL; }
    Node *getroot() { return root; }
    void insert_in_BST(int isbn, int quantity, string title, string author, float price)
    {
        Node *newitem;
        newitem = new Node(isbn, quantity, title, author, price);
        if (root == NULL)
            root = newitem;
        else
        {
            Node *next = root, *pre = NULL;
            while (next != NULL)
            {
                pre = next;
                if (isbn < next->isbn)
                    next = next->left;
                else
                    next = next->right;
            }
            newitem->parent = pre;
            // setting previous left node to newitem.
            if (isbn < pre->isbn)
                pre->left = newitem;
            // setting previous right node to newitem.
            else
                pre->right = newitem;
        }
    }
    void printing_inorder(Node *it)
    {
        if (it == NULL)
            return;
        // going to left side.
        printing_inorder(it->left);
        it->print();
        // going to right side.
        printing_inorder(it->right);
    }
    void printing_level_order(Node *it)
    {
        queue<Node *> q;
        q.push(it);
        while (!q.empty())
        {
            Node *temp = q.front();
            temp->print();
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
    Node *finding_element(int n, Node *it)
    {
        if (it == NULL)
            return it;
        // searching in left side;
        if (n < it->isbn)
            return finding_element(n, it->left);
        // searching in right side;
        else if (n > it->isbn)
            return finding_element(n, it->right);
        else
            return it;
    }
    Node *finding_minimum(Node *it)
    {
        while (it->left != NULL)
            it = it->left;
        return it;
    }
    Node *delete_element(int n, Node *it)
    {
        if (it == NULL)
            return it;
        if (it->isbn == n)
        {
            // Node has 0 child.
            if (it->left == NULL and it->right == NULL)
            {
                delete it;
                return NULL;
            }
            // Node has 1 child
            //-->left child.
            if (it->left != NULL and it->right == NULL)
            {
                Node *temp = it->left;
                delete it;
                return temp;
            }
            //-->right child.
            else if (it->left == NULL and it->right != NULL)
            {
                Node *temp = it->right;
                delete it;
                return temp;
            }
            // Node has 2 child.
            else
            {
                Node *temp = finding_minimum(it->right);
                int min_isbn = temp->isbn;
                it->isbn = min_isbn;
                it->author = temp->author;
                it->title = temp->title;
                it->price = temp->price;
                it->quantity = temp->quantity;
                it->right = delete_element(min_isbn, it->right);
                return it;
            }
        }
        else if (n < it->isbn)
        {
            it->left = delete_element(n, it->left);
            return it;
        }
        else
        {
            it->right = delete_element(n, it->right);
            return it;
        }
    }
};
int32_t main()
{
    BST bst;
    cout << "\t\t\t----------------------------------------------------------------\n";
    cout << "\t\t\t\tWelcome to Bookstore Inventory Management System!\n";
    cout << "\t\t\t----------------------------------------------------------------\n\n";

    while (1)
    {
        cout << "\t1.Add a book to the inventory.\n";
        cout << "\t2.Remove a book from a inventory.\n";
        cout << "\t3.Update the quantity of a book.\n";
        cout << "\t4.Search for a book by ISBN.\n";
        cout << "\t5.Display all the book in inventory.\n";
        cout << "\t6.Exit.\n\n";
        cout << "Enter your choice: ";
        int ch, x, y;
        cin >> ch;
        cout << endl;
        if (ch == 1)
        {
            int isbn, quantity;
            string title, author;
            float price;
            cout << "Enter the book's ISBN: ", cin >> isbn;
            cin.ignore();
            cout << "Enter the book's title: ", getline(cin, title);
            cout << "Enter the book's author: ", getline(cin, author);
            cout << "Enter the book's price: ", cin >> price;
            cout << "Enter the book's quantity: ", cin >> quantity;
            bst.insert_in_BST(isbn, quantity, title, author, price);
            cout << "Book added to the inventory successfully.\n\n";
        }
        else if (ch == 2)
        {
            cout << "Enter the ISBN of the book to remove: ", cin >> x;
            bst.delete_element(x, bst.getroot());
            cout << "Book removed from the inventory succesfully.\n\n";
        }
        else if (ch == 3)
        {
            cout << "Enter the ISBN of the book to add new quantity: ", cin >> x;
            cout << "New quantity of ISBN " << x << " :", cin >> y;
            Node *it = bst.finding_element(x, bst.getroot());
            if (it != NULL)
                it->quantity = y, cout << "New quantity of ISBN " << x << " is " << y << "\n\n";
            else
                cout << "ISBN not found!\n";
        }
        else if (ch == 4)
        {
            cout << "Enter the ISBN of the book to search: ", cin >> x;
            Node *it = bst.finding_element(x, bst.getroot());
            if (it != NULL)
                it->print();
            else
                cout << "Book isnot present in the inventory!\n\n";
        }
        else if (ch == 5)
        {
            cout << "Inventory: \n\n";
            // bst.printing_inorder(bst.getroot());
            // cout << "LEVEL ORDER TRAVERSEL: \n\n";
            bst.printing_level_order(bst.getroot());
        }
        else
            break;
    }
}
//! 20 10 30 5 15 27 40 3 6 21 35 45
/*
1
20
AAAA
Raisul
39.99
10
1
10
BBBB
Hasnat
49.99
5
1
30
CCCC
Zaima
20
1
1
5
DDDD
Nabiha
32
0
1
15
EEEE
Progga
2
0
1
27
FFFF
Ifrit
3
0
1
40
GGGG
Hridi
4
0
1
3
HHHH
Reefa
5
0
1
6
IIII
Pallob
6
0
1
21
JJJJJ
Iftee
7
0
1
35
kkkk
Aref
8
0
1
45
LLLL
Arik
9
0
*/