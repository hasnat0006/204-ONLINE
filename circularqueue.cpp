#include <bits/stdc++.h>
using namespace std;
class Queue
{
    int *arr;
    int size, front = -1, back = -1;

public:
    Queue()
    {
        arr = NULL;
        size = 0;
    }
    Queue(int n)
    {
        arr = new int[n];
        size = n;
    }
    int isEmpty()
    {
        if (front == -1 and back == -1)
            return 1;
        return 0;
    }
    int isFull()
    {
        if ((back + 1) % size == front)
            return 1;
        return 0;
    }
    void enqueue(int n)
    {
        if (isEmpty())
            front++, arr[++back] = n;
        else if (!isFull())
            back = (back + 1) % size, arr[back] = n;
        else
            cout << "Queue is full!" << endl;
    }
    void dequeue()
    {
        if (isEmpty())
            cout << "Queue is empty!";
        else if (front == back)
            front = back = -1;
        else
            front = (front + 1) % size;
    }
    void print()
    {
        if (isEmpty())
            cout << "Queue is empty!";
        else
        {
            int it = front;
            while (1)
            {
                cout << arr[it] << " ";
                if (it == back)
                    break;
                it = (it + 1) % size;
            }
            cout << endl;
        }
    }
};
int main()
{
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.print();
    q.enqueue(50);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.print();
    q.dequeue();
}