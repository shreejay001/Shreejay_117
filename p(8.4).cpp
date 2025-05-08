#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Define a struct to hold student name and score
struct Student {
    string name;
    int score;
};

// Custom comparator to sort by descending score
bool compareByScoreDesc(const Student& a, const Student& b) {
    return a.score > b.score;
}

int main() {
    vector<Student> students;
    string name;
    int score;

    cout << "Enter student name and score (type 'done' to finish):\n";

    while (true) {
        cout << "Name: ";
        cin >> name;
        if (name == "done") break;

        cout << "Score: ";
        if (!(cin >> score)) {
            cerr << "Invalid score. Try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        students.push_back({name, score});
    }

    if (students.empty()) {
        cerr << "No student data entered.\n";
        return 1;
    }

    // Sort students by score descending
    sort(students.begin(), students.end(), compareByScoreDesc);

    // Display ranked list
    cout << "\n--- Ranked Student List ---\n";
    cout << left << setw(6) << "Rank" << setw(20) << "Name" << "Score\n";
    cout << "-------------------------------\n";

    int rank = 1;
    for (auto it = students.begin(); it != students.end(); ++it) {
        cout << left << setw(6) << rank++ << setw(20) << it->name << it->score << "\n";
    }

    return 0;
}
