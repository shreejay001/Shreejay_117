#include <iostream>
#include <string>
using namespace std;

const int MAX_TRANSACTIONS = 100;

class BankAccount {
private:
    string accountHolder;
    double balance;
    string transactionHistory[MAX_TRANSACTIONS];
    int transactionCount;

    void logError(const string& functionName, const string& message) {
        string errorMsg = "ERROR in " + functionName + ": " + message;
        cout << errorMsg << endl;

        if (transactionCount < MAX_TRANSACTIONS) {
            transactionHistory[transactionCount++] = errorMsg;
        }
    }

    void logTransaction(const string& message) {
        if (transactionCount < MAX_TRANSACTIONS) {
            transactionHistory[transactionCount++] = message;
        }
    }

public:
    BankAccount(string name, double initialBalance = 0.0) {
        accountHolder = name;
        balance = initialBalance;
        transactionCount = 0;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            logError("deposit", "Deposit amount must be positive.");
            return;
        }
        balance += amount;
        logTransaction("Deposited ₹" + to_string(amount));
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            logError("withdraw", "Withdrawal amount must be positive.");
            return;
        }
        if (amount > balance) {
            logError("withdraw", "Insufficient balance.");
            return;
        }
        balance -= amount;
        logTransaction("Withdrew ₹" + to_string(amount));
    }

    double getBalance() const {
        return balance;
    }

    void printTransactionHistory() const {
        cout << "\nTransaction History for " << accountHolder << ":\n";
        for (int i = 0; i < transactionCount; ++i) {
            cout << i + 1 << ". " << transactionHistory[i] << endl;
        }
    }
};

int main() {
    BankAccount account("John Doe", 5000.0);

    account.deposit(2000);
    account.withdraw(1000);
    account.withdraw(8000);  
    account.deposit(-500);   

    cout << "\nCurrent Balance: ₹" << account.getBalance() << endl;

    account.printTransactionHistory();

    return 0;
}
