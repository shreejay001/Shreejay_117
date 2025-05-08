#include <iostream>
#include <queue>
#include <cmath> // Needed for abs with floating point numbers
using namespace std;

class Fahrenheit; // Forward declaration

class Celsius {
    float temp;

public:
    Celsius(float t = 0) : temp(t) {}

    // Convert to Fahrenheit
    operator Fahrenheit();

    float getTemp() const { return temp; }

    // Compare with Fahrenheit
    bool operator==(const Fahrenheit& f) const;
};

class Fahrenheit {
    float temp;

public:
    Fahrenheit(float t = 32) : temp(t) {}

    // Convert to Celsius
    operator Celsius() {
        return Celsius((temp - 32) * 5 / 9);
    }

    float getTemp() const { return temp; }

    // Compare with Celsius
    bool operator==(const Celsius& c) const {
        return fabs(temp - (c.getTemp() * 9 / 5 + 32)) < 0.01;
    }
};

// Convert Celsius to Fahrenheit
Celsius::operator Fahrenheit() {
    return Fahrenheit(temp * 9 / 5 + 32);
}

// Compare Celsius with Fahrenheit
bool Celsius::operator==(const Fahrenheit& f) const {
    return fabs(temp * 9 / 5 + 32 - f.getTemp()) < 0.01;
}

// Main program
int main() {
    Celsius c1(0), c2(100);
    Fahrenheit f1 = c1; // Implicit conversion
    Fahrenheit f2 = c2;

    cout << "--- Conversions ---" << endl;
    cout << "0 C = " << f1.getTemp() << " F" << endl;
    cout << "100 C = " << f2.getTemp() << " F" << endl;

    // Comparison
    cout << "--- Comparison ---" << endl;
    if (c2 == Fahrenheit(212))
        cout << "100 C equals 212 F" << endl;

    // Queue example
    queue<Fahrenheit> tempQueue;
    tempQueue.push(Fahrenheit(c1)); // convert and push

    cout << "--- Queue ---" << endl;
    cout << "Front of queue: " << tempQueue.front().getTemp() << " F" << endl;

    return 0;
}
