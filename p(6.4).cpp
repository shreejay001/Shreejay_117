#include <iostream>
using namespace std;


class Base {
public:
    Base() {
        cout << "Base constructor\n";
    }
    virtual ~Base() {
        cout << "Base destructor\n";
    }
};


class Derived : public Base {
private:
    int* data;
public:
    Derived() {
        data = new int[10];
        cout << "Derived constructor\n";
    }

    ~Derived() {
        delete[] data;
        cout << "Derived destructor\n";
    }
};

int main() {
    Base* obj = new Derived();
    delete obj;

    return 0;
}
