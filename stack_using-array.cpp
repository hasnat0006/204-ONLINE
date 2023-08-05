#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int *arr, top, size;
    Stack(int n)
    {
        arr = new int[n];
        size = n;
        top = -1;
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        return false;
    }
    bool isFull()
    {
        if (top + 1 == size)
            return true;
        return false;
    }
    void push(int val)
    {
        if (isFull())
        {
            cout << "Stack is already full\n";
            return;
        }
        arr[++top] = val;
    }
    void top_element()
    {
        cout << "Top element is " << arr[top] << endl;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is already empty\n";
            return;
        }
        top--;
    }
    void printing_stack()
    {
        /*
        reverse loop because loop start with last insert
        element and continue untill the stack isnot empty
         */
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    Stack st(5);
    while (1)
    {
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        int ch, val;
        cout << "Enter your choice: ", cin >> ch;
        if (ch == 1)
            cout << "Enter value to push: ", cin >> val, st.push(val);
        else if (ch == 2)
            cout << "Element poped\n", st.pop();
        else if (ch == 3)
            st.top_element();
        st.printing_stack();
    }
}