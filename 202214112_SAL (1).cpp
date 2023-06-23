#include <bits/stdc++.h>
using namespace std;
int size = 10;
int arr[10];
int current_len = 0;
void print(int arr[])
{
    for (int i = 0; i < current_len; i++)
        cout << arr[i] << " ";
    cout << "\n\n";
}
void insert()
{
    cout << "Enter element to insert: ";
    int element, pos;
    if (current_len == size)
    {
        cout << "Array is already full\n";
        return;
    }
    cin >> element;
    cout << "Enter index position (between 0 to " << current_len << " ): ";
    cin >> pos;
    if (pos >= 0 and pos <= current_len)
    {
        if (pos == current_len + 1)
            arr[pos] = element;
        else
        {
            for (int i = current_len; i >= pos + 1; i--)
                arr[i] = arr[i - 1];
            arr[pos] = element;
            current_len++;
            // cout << "\nCurrent array length is: " << current_len << endl;
            cout << "Current array is: ";
            print(arr);
        }
    }
    else
        cout << "Value can't be insert in that position. Please try again!\n";
}
void del()
{
    if (current_len == 0)
    {
        cout << "Array is already empty!\n\n";
        return;
    }
    cout << "Current array is: ";
    for (int i = 0; i < current_len; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "Enter index which you want to delete(between 0 to " << current_len - 1 << " ): ";
    int pos;
    cin >> pos;
    if (pos >= 0 and pos <= current_len)
    {
        for (int i = pos; i <= current_len; i++)
            arr[i] = arr[i + 1];
        current_len--;
        cout << "After deleting the array is: ";
        print(arr);
    }
    else
        cout << "Your entered address isn't valid. Please try again!\n\n";
}
void search()
{
    int find;
    cout << "Which element you want to search: ";
    cin >> find;
    for (int i = 0; i < current_len; i++)
    {
        if (arr[i] == find)
        {
            cout << "The search key " << find << " is at idex " << i << "\n\n";
            return;
        }
    }
    cout << "The search key isn't present in the current array\n\n";
}
void print()
{
    cout << "Current array is: ";
    print(arr);
}
int main()
{
    while (1)
    {
        cout << "MENU:\n\n1. Insert New Element\n2. Delete Element\n3. Search for an Element\n4. Print Current Array\n5. Exit\n\nEnter Choice: ";
        int x;
        cin >> x;
        if (x == 1)
            insert();
        else if (x == 2)
            del();
        else if (x == 3)
            search();
        else if (x == 4)
            print();
        else if (x == 5)
            break;
        else
        {
            cout << "Please enter a valid input.\n";
            continue;
        }
    }
}