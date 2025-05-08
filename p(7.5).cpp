#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

struct Student {
    string name;
    int marks;
    double tuition;
};

ostream& currency(ostream& os) {
    os << "Rupees ";
    return os;
}

int main() {
    vector<Student> students = {
        {"hey", 92, 50000.50},
        {"hii", 85, 45500.00},
        {"hello", 78, 47000.75},
        {"yukk", 88, 52000.25}
    };


    cout << left << setw(15) << "Name"
         << right << setw(10) << "Marks"
         << right << setw(20) << "Tuition Fee" << endl;

    cout << setfill('-') << setw(45) << "-" << setfill(' ') << endl;


    for (const auto& student : students) {
        cout << left << setw(15) << student.name
             << right << setw(10) << student.marks
             << right << setw(9) << currency << fixed << setprecision(2) << student.tuition << endl;
    }

    return 0;
}
