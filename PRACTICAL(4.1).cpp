#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
protected:
    double radius;

public:
    Shape(double r = 0.0) : radius(r) {}
    virtual ~Shape() {}

    void setRadius(double r)
    {
        radius = r;
    }

    double getRadius() const
    {
        return radius;
    }

    virtual double area() const = 0;
};


class Circle : public Shape
{
public:
    Circle(double r = 0.0) : Shape(r) {}

    double area() const override
    {
        return M_PI * radius * radius;
    }
};

int main()
{
    const int MAX_CIRCLES = 5;
    Circle circles[MAX_CIRCLES];

    cout << "Enter radius for " << MAX_CIRCLES << " circles:\n";
    for (int i = 0; i < MAX_CIRCLES; ++i)
    {
        double r;
        cout << "Circle " << i + 1 << " radius: ";
        cin >> r;
        circles[i].setRadius(r);
    }

    cout << "\nCircle Areas:\n";
    for (int i = 0; i < MAX_CIRCLES; ++i)
    {
        cout << "Circle " << i + 1 << ": " << circles[i].area() << endl;
    }

    return 0;
}
