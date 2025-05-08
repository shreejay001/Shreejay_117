#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverseWithStdFunction(vector<int>& sequence) {
    cout << "\n[Method 1] Using std::reverse():\n";
    vector<int> reversed = sequence;
    reverse(reversed.begin(), reversed.end());

    cout << "Reversed sequence: ";
    for (const int& num : reversed)
        cout << num << " ";
    cout << endl;
}

void reverseWithIterators(vector<int>& sequence) {
    cout << "\n[Method 2] Manual reversal using iterators:\n";
    vector<int> reversed(sequence.size());


    auto front = sequence.begin();
    auto back = reversed.rbegin();

    while (front != sequence.end()) {
        *back = *front;
        ++front;
        ++back;
    }

    cout << "Reversed sequence: ";
    for (const int& num : reversed)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> sequence;
    int num;

    cout << "Enter integers (type any non-integer to end input): ";

    while (cin >> num)
        sequence.push_back(num);

    if (sequence.empty()) {
        cerr << "No valid input received. Exiting.\n";
        return 1;
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nOriginal sequence: ";
    for (const int& n : sequence)
        cout << n << " ";
    cout << endl;

    reverseWithStdFunction(sequence);
    reverseWithIterators(sequence);

    return 0;
}
