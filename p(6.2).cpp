#include <iostream>
using namespace std;

class Point {
private:
    float x, y;

public:
    Point(float x = 0, float y = 0) : x(x), y(y) {}

    Point* moveBy(float dx, float dy) {
        x += dx;
        y += dy;
        return this;
    }


    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }


    static void updatePoint(Point* p, float dx, float dy) {
        if (p) p->moveBy(dx, dy);
    }
};

int main() {

    Point* p1 = new Point(10, 20);

    cout << " Initial Position " << endl;
    p1->display();

    cout << " Moving Point " << endl;
    p1->moveBy(5, -3)->moveBy(2, 2);
    p1->display();

    cout << " Moving Using Static Update " << endl;
    Point::updatePoint(p1, -4, 1);
    p1->display();

    delete p1;
    return 0;
}
