#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, value;
    set<int> transactionIDs;

    cout << "Enter number of transaction IDs: ";
    cin >> n;

    cout << "Enter the transaction IDs:\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        transactionIDs.insert(value); // automatically skips duplicates
    }

    // Display unique, sorted transaction IDs
    cout << "\nUnique Transaction IDs (sorted):\n";
    for (auto it = transactionIDs.begin(); it != transactionIDs.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
