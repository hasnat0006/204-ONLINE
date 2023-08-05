
#include <bits/stdc++.h>
using namespace std;
const int size = 5;
int current_size = 0;
int arr[size];

void insert_first(int val)
{
    for (int i = min(current_size, size - 1); i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = val;
    current_size = min(++current_size, size);
}
void insert_last(int val)
{
    cout << current_size << endl;
    arr[min(current_size, size)-1] = val;
    current_size = min(++current_size, size);
}
void insert_any_position(int val, int pos)
{
    for (int i = pos + 1; i < current_size; i++)
        arr[i] = arr[i - 1];
    arr[pos] = val;
    if (current_size != size)
        current_size++;
}
void delete_first()
{
    for (int i = 1; i < current_size; i++)
        arr[i - 1] = arr[i];
    current_size--;
}
void delete_last()
{
    current_size--;
}
void delete_any_position(int pos)
{
    for (int i = pos; i < current_size - 1; i++)
        arr[i] = arr[i + 1];
    current_size--;
}
void printing_array()
{
    for (int i = 0; i < current_size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
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
            cout << "Enter your val: ", cin >> val, insert_first(val);
        else if (ch == 2)
            cout << "Enter your val: ", cin >> val, insert_last(val);
        else if (ch == 3)
            cout << "Enter your val and pos: ", cin >> val >> pos, insert_any_position(val, pos);
        else if (ch == 4)
            delete_first();
        else if (ch == 5)
            delete_last();
        else if (ch == 6)
            cout << "Enter your pos: ", cin >> pos, delete_any_position(pos);
        else if (ch == 7)
            printing_array();
        printing_array();
    }
}

/*
1
5
1
4
1
3
1
2
1
1
*/
