#include <iostream>
#include <vector>
#include <cmath> // for abs()
using namespace std;

class Complex {
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << (c.imag >= 0 ? " + " : " - ") << abs(c.imag) << "i";
        return out;
    }
};

void batchAdd(const vector<Complex>& nums) {
    Complex sum;
    for (const auto& c : nums)
        sum = sum + c;
    cout << "Sum of complex numbers: " << sum << endl;
}

int main() {
    Complex c1, c2;
    cout << "--- Input Complex Numbers ---\n";
    cin >> c1;
    cin >> c2;

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    cout << "\n--- Results ---\n";
    cout << "First:  " << c1 << endl;
    cout << "Second: " << c2 << endl;
    cout << "Sum:    " << sum << endl;
    cout << "Diff:   " << diff << endl;

    // Optional: Batch operations
    vector<Complex> vec = {c1, c2, Complex(1, 1)};
    cout << "\n--- Batch Addition ---\n";
    batchAdd(vec);

    return 0;
}
