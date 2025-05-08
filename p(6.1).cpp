#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;       // Pointer to dynamic array
    int size;        // Current number of elements
    int capacity;    // Total allocated space

    // Resize when needed
    void resize(int newCapacity) {
        int* newData = new int[newCapacity];
        for (int i = 0; i < size; i++)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    DynamicArray(int initCapacity = 2) {
        size = 0;
        capacity = initCapacity;
        data = new int[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    // Add element at the end
    void insert(int value) {
        if (size == capacity)
            resize(capacity * 2);  // double the capacity
        data[size++] = value;
    }

    // Delete element at given index
    void remove(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index.\n";
            return;
        }
        for (int i = index; i < size - 1; i++)
            data[i] = data[i + 1];
        size--;

        // Optional: shrink if too much unused space
        if (size < capacity / 4 && capacity > 2)
            resize(capacity / 2);
    }

    // Display elements
    void display() const {
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << endl;
    }

    // Get current size
    int getSize() const {
        return size;
    }
};

int main() {
    DynamicArray arr;

    cout << " Inserting Elements " << endl;
    arr.insert(10);
    arr.insert(20);
    arr.insert(30);
    arr.insert(40);
    arr.display(); // 10 20 30 40

    cout << " Removing Element at Index 1 " << endl;
    arr.remove(1);
    arr.display(); // 10 30 40

    cout << " Adding More Elements " << endl;
    arr.insert(50);
    arr.insert(60);
    arr.display(); // 10 30 40 50 60

    return 0;
}
