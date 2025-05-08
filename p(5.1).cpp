#include <iostream>

class Calculator {
private:
    static const int MAX_RESULTS = 10;
    double results[MAX_RESULTS];
    int resultCount;

public:
    Calculator() : resultCount(0) {}

    void storeResult(double value) {
        if (resultCount < MAX_RESULTS) {
            results[resultCount++] = value;
        } else {
            std::cout << "Result storage limit reached.\n";
        }
    }

    // Overloaded add functions
    int add(int a, int b) {
        int result = a + b;
        storeResult(result);
        return result;
    }

    float add(float a, float b) {
        float result = a + b;
        storeResult(result);
        return result;
    }

    double add(double a, double b) {
        double result = a + b;
        storeResult(result);
        return result;
    }

    double add(int a, double b) {
        double result = a + b;
        storeResult(result);
        return result;
    }

    double add(double a, int b) {
        double result = a + b;
        storeResult(result);
        return result;
    }

    float add(int a, float b) {
        float result = a + b;
        storeResult(result);
        return result;
    }

    float add(float a, int b) {
        float result = a + b;
        storeResult(result);
        return result;
    }

    void displayResults() {
        std::cout << "\nStored Results:\n";
        for (int i = 0; i < resultCount; ++i) {
            std::cout << "Result " << i + 1 << ": " << results[i] << "\n";
        }
    }
};

int main() {
    Calculator calc;

    calc.add(5, 3);
    calc.add(3.2f, 4.8f);
    calc.add(2.5, 3.5);
    calc.add(10, 2.5);
    calc.add(7.5, 2);
    calc.add(4, 1.2f);
    calc.add(3.3f, 2);

    calc.displayResults();

    return 0;
}
