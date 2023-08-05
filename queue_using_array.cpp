#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int front, rear, size, *arr, count;
    Queue(int n)
    {
        front = rear = -1;
        size = n;
        count = 0;
        arr = new int[n];
    }
    bool isFull()
    {
        if (count == size)
            return true;
        return false;
    }
    bool isEmpty()
    {
        if (count == 0)
            return true;
        return false;
    }
    void Enqueue(int n)
    {
        if (isFull())
        {
            cout << "Queue is already full\n";
            return;
        }
        if (front == -1)
            front++, rear++, count++, arr[rear] = n;
        else
            rear = (rear + 1) % size, arr[rear] = n, count++;
    }
    void Dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is already empty\n";
            return;
        }
        if (count == 1)
            front = -1, rear = -1, count = 0;
        else
            count--, front = (front + 1) % size;
    }
    void front_element()
    {
        if (!isEmpty())
            cout << "Front is: ", cout << arr[front] << endl;
    }
    void printing()
    {
        if (!isEmpty())
        {
            for (int i = front; i <= rear; i = (i + 1) % size)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main()
{
    Queue q(5);
    while (1)
    {
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        int ch, val;
        cout << "Enter your choice: ", cin >> ch;
        if (ch == 1)
            cout << "Enter value to enqueue: ", cin >> val, q.Enqueue(val);
        else if (ch == 2)
            cout << "Element dequeueed\n", q.Dequeue();
        else if (ch == 3)
            q.front_element();
        q.printing();
    }
}