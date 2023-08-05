#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left, *right, *parent;
    Node(int n)
    {
        val = n;
        left = right = parent = NULL;
    }
    int getValue() { return val; }
};

class BST
{
public:
    Node *root;
    BST() { root = NULL; }
    Node *getroot() { return root; }
    void insert_in_BST(int n)
    {
        Node *newitem = new Node(n);
        if (root == NULL)
            root = newitem;
        else
        {
            Node *it = root, *pre = NULL;
            while (it != NULL)
            {
                pre = it;
                if (it->val < newitem->val)
                    it = it->right;
                else
                    it = it->left;
            }
            newitem->parent = pre;
            // now we need to check wether it will be place on left or on right
            if (pre->val < newitem->val)
                pre->right = newitem;
            else
                pre->left = newitem;
        }
    }
    void printing_preorder(Node *it)
    {
        if (it == NULL)
            return;
        cout << it->val << " ";
        printing_preorder(it->left);
        printing_preorder(it->right);
    }
    void printing_postorder(Node *it)
    {
        if (it == NULL)
            return;
        printing_postorder(it->left);
        printing_postorder(it->right);
        cout << it->val << " ";
    }
    void printing_inorder(Node *it)
    {
        if (it == NULL)
            return;
        printing_inorder(it->left);
        cout << it->val << " ";
        printing_inorder(it->right);
    }
    bool finding_element(int val, Node *it)
    {
        if (it == NULL)
            return false;
        if (it->val == val)
            return true;
        if (it->val < val)
            finding_element(val, it->right);
        else
            finding_element(val, it->left);
    }
    Node *finding_minimum(Node *it)
    {
        while (it->left != NULL)
            it = it->left;
        return it;
    }
    Node *finding_maximum(Node *it)
    {
        while (it->right != NULL)
            it = it->right;
        return it;
    }
    Node *delete_element(int val, Node *it)
    {
        if (it == NULL)
            return NULL;
        if (it->val == val)
        {
            //! no child case
            if (it->left == NULL and it->right == NULL)
            {
                delete it;
                return NULL;
            }
            //!  1 left child
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
                int min_val = finding_minimum(it->right)->getValue();
                it->val = min_val;
                it->right = delete_element(min_val,it->right);
                return it;
            }
        }
        else if (it->val < val)
        {
            it->right = delete_element(val, it->right);
            return it;
        }
        else
        {
            it->left = delete_element(val, it->left);
            return it;
        }
    }
};

int main()
{
    BST bst;
    while (1)
    {
        cout << "MENU:\n";
        cout << "\t1.Insert in BST.\n";
        cout << "\t2.Pre order traversing.\n";
        cout << "\t3.Post order traversing.\n";
        cout << "\t4.In order traversing.\n";
        cout << "\t5.Find an element is present or not.\n";
        cout << "\t6.Find the minimum value.\n";
        cout << "\t7.Find the maximum value.\n";
        cout << "\t8.Delete any element.\n";
        cout << "\t9.Exit\n";
        cout << "Enter your choice: ";
        int ch, val, x;
        cin >> ch;
        if (ch == 1)
        {
            cout << "Enter element which you want to Insert in BST: ", cin >> val;
            bst.insert_in_BST(val);
            cout << "Successfully inserted in BST\n";
        }
        else if (ch == 2)
        {
            cout << "Pre order traversing: ";
            bst.printing_preorder(bst.getroot());
            cout << endl;
        }
        else if (ch == 3)
        {
            cout << "Post order traversing: ";
            bst.printing_postorder(bst.getroot());
            cout << endl;
        }
        else if (ch == 4)
        {
            cout << "In order traversing: ";
            bst.printing_inorder(bst.getroot());
            cout << endl;
        }
        else if (ch == 5)
        {
            cout << "Which element you want to find: ", cin >> x;
            // Node *it = bst.finding_element(x, bst.getroot());
            if (bst.finding_element(x, bst.getroot()))
                cout << "Element is present in BST.\n";
            else
                cout << "Element isnot present in BST.\n";
        }
        else if (ch == 6)
        {
            cout << "Minimum value in BST is: " << bst.finding_minimum(bst.getroot())->getValue() << endl;
        }
        else if (ch == 7)
            cout << "Minimum value in BST is: " << bst.finding_maximum(bst.getroot())->getValue() << endl;
        else if (ch == 8)
        {
            cout << "Enter element you want to delete: ", cin >> x;
            bst.delete_element(x, bst.getroot());
            cout << "Element succesfully deleted.";
        }
        else
            break;
    }
}
/*
1 25
1 15
1 50
1 10
1 22
1 35
1 70
1 4
1 12
1 18
1 24
1 31
1 44
1 66
1 90
*/