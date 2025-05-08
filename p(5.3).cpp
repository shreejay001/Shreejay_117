
#include <iostream>
#include <stack>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}


    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }


    Point operator-() const {
        return Point(-x, -y);
    }


    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};


class PointStack {
private:
    stack<Point> s;

public:
    void push(const Point& p) {
        s.push(p);
    }

    bool undo(Point& p) {
        if (!s.empty()) {
            p = s.top();
            s.pop();
            return true;
        }
        return false;
    }

    bool isEmpty() const {
        return s.empty();
    }
};

int main() {
    Point p1(2, 3), p2(4, -1), current;
    PointStack history;


    current = p1;
    history.push(current);


    current = current + p2;
    history.push(current);


    current = -current;
    history.push(current);

    cout << "--- Current Point State ---" << endl;
    current.display();


    cout << "\n--- Undoing Steps ---" << endl;
    for (int i = 0; i < 2; ++i) {
        if (history.undo(current)) {
            cout << "After undo: ";
            current.display();
        } else {
            cout << "Nothing to undo.\n";
        }
    }


    cout << "\n--- Comparison ---" << endl;
    cout << "Current == p1? " << (current == p1 ? "Yes" : "No") << endl;

    return 0;
}
