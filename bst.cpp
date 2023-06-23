#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *right, *left, *parent;
    int val;
    Node()
    {
        right = left = parent = NULL;
        val = 0;
    }
    Node(int n)
    {
        right = left = parent = NULL;
        val = n;
    }
};

class BST
{
    Node *root;

public:
    BST() { root = NULL; }
    void insert(int n)
    {
        Node *newitem = new Node(n);
        if (root == NULL)
            root = newitem;
        else
        {
            Node *next = root, *pre = NULL;
            while (next != NULL)
            {
                pre = next;
                if (n < next->val)
                    next = next->left;
                else
                    next = next->right;
            }
            newitem->parent = pre;
            if (n < pre->val)
                pre->left = newitem;
            else
                pre->right = newitem;
        }
    }
    void print_in_order(Node *it)
    {
        if (it == NULL)
            return;
        print_in_order(it->left);
        cout << it->val << " ";
        print_in_order(it->right);
    }
    Node *find_minimum(Node *it)
    {
        while (it != NULL)
            it = it->left;
        return it;
    }
    Node *delete_element(int n, Node *it)
    {
        if (it == NULL)
            return it;
        else if (it->val == n)
        {
            // no child
            if (it->left == NULL and it->right == NULL)
            {
                delete it;
                return NULL;
            }
            else if (it->left != NULL and it->right == NULL)
            {
                Node *temp = it->left;
                delete it;
                return temp;
            }
            else if (it->right != NULL and it->left == NULL)
            {
                Node *temp = it->right;
                delete it;
                return temp;
            }
            else
            {
                int min_val = find_minimum(it->right)->val;
                it->val = min_val;
                it->right = delete_element(min_val, it->right);
                return it;
            }
        }
        else if (n < it->val)
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
    Node *get_root() { return root; }
};

int main()
{
    BST b;
    b.insert(10);
    b.insert(7);
    b.insert(2);
    b.insert(5);
    b.insert(20);
    b.insert(15);
    b.insert(25);
    b.print_in_order(b.get_root());
    return 0;
}