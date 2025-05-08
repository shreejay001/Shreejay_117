#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Base class
class Shape {
public:
    virtual float Area() = 0; // Pure virtual function
    virtual ~Shape() {}       // Virtual destructor
};

// Rectangle class
class Rectangle : public Shape {
    float length, width;

public:
    Rectangle(float l, float w) : length(l), width(w) {}

    float Area() override {
        return length * width;
    }
};

// Circle class
class Circle : public Shape {
    float radius;

public:
    Circle(float r) : radius(r) {}

    float Area() override {
        return 3.14159f * radius * radius;
    }
};

// Display area using base class pointer
void displayArea(Shape* s) {
    cout << "Area: " << s->Area() << endl;
}

int main() {
    // --- Dynamic management using vector ---
    vector<Shape*> shapeList;

    shapeList.push_back(new Rectangle(5, 4));
    shapeList.push_back(new Circle(3));

    cout << "--- Dynamic Shape List ---" << endl;
    for (Shape* shape : shapeList) {
        displayArea(shape);
        delete shape; // Clean up memory
    }
    shapeList.clear();

    // --- Static management using array ---
    Shape* staticShapes[2];
    staticShapes[0] = new Rectangle(2, 6);
    staticShapes[1] = new Circle(4);

    cout << "\n--- Static Shape Array ---" << endl;
    for (int i = 0; i < 2; i++) {
        displayArea(staticShapes[i]);
        delete staticShapes[i];
    }

    return 0;
}
