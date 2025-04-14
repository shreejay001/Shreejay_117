#include <iostream>
#include <string>
using namespace std;

const int MAX_ACCOUNTS = 100;

struct Account
{
    int accountNumber;
    string holderName;
    double balance;
};

Account accounts[MAX_ACCOUNTS];
int totalAccounts = 0;

void createAccount()
{
    if (totalAccounts >= MAX_ACCOUNTS)
    {
        cout << "Account limit reached.\n";
        return;
    }

    cout << "Enter Account Number: ";
    cin >> accounts[totalAccounts].accountNumber;
    cin.ignore();
    cout << "Enter Account Holder Name: ";
    getline(cin, accounts[totalAccounts].holderName);
    cout << "Enter Initial Balance: ";
    cin >> accounts[totalAccounts].balance;

    totalAccounts++;
    cout << "Account created successfully.\n";
}

void displayAccounts(int index = 0)
{
    if (index >= totalAccounts) return;

    cout << "Account Number: " << accounts[index].accountNumber
         << ", Name: " << accounts[index].holderName
         << ", Balance: $" << accounts[index].balance << endl;

    displayAccounts(index + 1);
}

int findAccountIndex(int accNo)
{
    for (int i = 0; i < totalAccounts; i++)
    {
        if (accounts[i].accountNumber == accNo)
        {
            return i;
        }
    }
    return -1;
}

void transferMoney()
{
    int fromAcc, toAcc;
    double amount;

    cout << "Enter Sender's Account Number: ";
    cin >> fromAcc;
    cout << "Enter Receiver's Account Number: ";
    cin >> toAcc;
    cout << "Enter Amount to Transfer: ";
    cin >> amount;

    int fromIndex = findAccountIndex(fromAcc);
    int toIndex = findAccountIndex(toAcc);

    if (fromIndex == -1 || toIndex == -1)
    {
        cout << "Invalid account number.\n";
        return;
    }

    if (accounts[fromIndex].balance >= amount)
    {
        accounts[fromIndex].balance -= amount;
        accounts[toIndex].balance += amount;
        cout << "Transfer successful.\n";
    }
    else
    {
        cout << "Insufficient funds in sender's account.\n";
    }
}
int countAccounts(int index = 0)
{
    if (index >= totalAccounts) return 0;
    return 1 + countAccounts(index + 1);
}

int main()
{
    int choice;

    do
    {
        cout << "\n--- Bank Menu ---\n";
        cout << "1. Create Account\n";
        cout << "2. Display All Accounts\n";
        cout << "3. Transfer Money\n";
        cout << "4. Show Total Accounts (using recursion)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createAccount();
            break;
        case 2:
            if (totalAccounts == 0)
                cout << "No accounts available.\n";
            else
                displayAccounts();
            break;
        case 3:
            transferMoney();
            break;
        case 4:
            cout << "Total Accounts: " << countAccounts() << endl;
            break;
        case 0:
            cout << "Exiting system.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }

    }
    while (choice != 0);
    cout<<"SHREEJAY_24CE117";
    return 0;
}
