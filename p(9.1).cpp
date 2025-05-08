#include <iostream>
#include <string>
#include <sstream>

using namespace std;

double getValidatedInput(const string& prompt) {
    double value;
    string input;

    while (true) {
        cout << prompt;
        getline(cin, input);

        stringstream ss(input);
        if (ss >> value) {
            char remaining;
            if (!(ss >> remaining)) {
                if (value < 0) {
                    cout << "Please enter a non-negative value.\n";
                } else {
                    return value;
                }
            } else {
                cout << "Invalid input. Please enter a numeric value without extra characters.\n";
            }
        } else {
            cout << "Invalid input. Please enter a numeric value.\n";
        }
    }
}

int main() {
    double loanAmount = getValidatedInput("Enter the loan amount: ");
    double annualIncome;

    while (true) {
        annualIncome = getValidatedInput("Enter your annual income: ");
        if (annualIncome == 0) {
            cout << "Annual income cannot be zero. Please enter a non-zero value.\n";
        } else {
            break;
        }
    }

    double ratio = loanAmount / annualIncome;
    cout << "Loan-to-Income Ratio: " << ratio << endl;

    return 0;
}
