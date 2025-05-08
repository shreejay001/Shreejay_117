
#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    string name;
    int marks;
    char grade;
};

void directDisplay(const string &filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: Cannot open file!" << endl;
        return;
    }

    string name;
    int marks;
    char grade;

    cout << "Name\t\tMarks\tGrade" << endl;
    cout << "-------------------------------" << endl;

    while (file >> name >> marks >> grade) {
        cout << name << "\t\t" << marks << "\t" << grade << endl;
    }

    file.close();
}

void storedDisplay(const string &filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: Cannot open file!" << endl;
        return;
    }

    Student students[100]; 
    int count = 0;

    while (file >> students[count].name >> students[count].marks >> students[count].grade) {
        count++;
    }

    file.close();

    cout << "Name\t\tMarks\tGrade" << endl;
    cout << "-------------------------------" << endl;

    for (int i = 0; i < count; i++) {
        cout << students[i].name << "\t\t" << students[i].marks << "\t" << students[i].grade << endl;
    }
}

int main() {
    string filename = "student.txt";

    cout << "== Direct File Display ==" << endl;
    directDisplay(filename);

    cout << "\n== Stored in Array and Display ==" << endl;
    storedDisplay(filename);

    return 0;
}
