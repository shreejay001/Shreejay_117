#include <iostream>
using namespace std;

template <typename T>
void displayCollection(T* arr, int size, int index = 0)
{
    if (index >= size) return;
    cout << arr[index] << " ";
    displayCollection(arr, size, index + 1);
}

template <typename T>
T findMax(T* arr, int size)
{
    if (size == 1) return arr[0];
    T maxRest = findMax(arr, size - 1);
    return (arr[size - 1] > maxRest) ? arr[size - 1] : maxRest;
}

template <typename T>
void reverseCollection(T* arr, int start, int end)
{
    if (start >= end) return;
    T temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    reverseCollection(arr, start + 1, end - 1);
}

template <typename T>
void handleCollection(int size)
{
    T* arr = new T[size];

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    cout << "\nOriginal Collection: ";
    displayCollection(arr, size);

    T maxVal = findMax(arr, size);
    cout << "\nMaximum Value: " << maxVal << endl;

    reverseCollection(arr, 0, size - 1);
    cout << "Reversed Collection: ";
    displayCollection(arr, size);
    cout << endl;

}

int main()
{
    int choice, size;

    do
    {
        cout << "\n--- Collection Manager Menu ---\n";
        cout << "1. Integer Collection\n";
        cout << "2. Float Collection\n";
        cout << "3. Character Collection\n";
        cout << "0. Exit\n";
        cout << "Choose data type: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3)
        {
            cout << "Enter number of elements: ";
            cin >> size;

            switch (choice)
            {
            case 1:
                handleCollection<int>(size);
                break;
            case 2:
                handleCollection<float>(size);
                break;
            case 3:
                handleCollection<char>(size);
                break;
            }
        }
        else if (choice != 0)
        {
            cout << "Invalid choice. Try again.\n";
        }

    }
    while (choice != 0);

    cout << "Program exited.\n";
    cout<<"SHREEJAY_24CE117";
    return 0;
}
