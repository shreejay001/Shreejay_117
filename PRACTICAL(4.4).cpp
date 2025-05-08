#include<iostream>
#include<fstream>
using namespace std;

class BankAccount
{
protected:
    int AccNum;
    float Balance, PrevBal;
    string FileName;
    fstream HistoryFile;

public:
    BankAccount(int an, float bal)
    {
        AccNum = an;
        PrevBal = bal;
        Balance = bal;
    }

    void Deposit(float diff)
    {
        PrevBal = Balance;
        Balance+=diff;

        HistoryFile.open(FileName, ios::app);
        HistoryFile.seekp(SEEK_END);
        if(!HistoryFile.is_open())
        {
            cerr<<endl<<"Unable to open file!";
        }
        HistoryFile<<"\nDeposited Rs. "<<diff<<" | Current Balance: Rs. "<<Balance;
        HistoryFile.close();
    }

    void PrintHistory()
    {
        HistoryFile.open(FileName, ios::in);
        if(!HistoryFile.is_open())
        {
            cerr<<endl<<"Unable to open file!";
        }

        cout<<"\n\nPrinting All Transaction History:\n";
        string line;
        while(getline(HistoryFile, line))
        {
            cout<<endl<<line;
        }
        HistoryFile.close();
    }

    void UndoLast()
    {
        Balance = PrevBal;

        HistoryFile.open(FileName, ios::app|ios::in);
        HistoryFile.seekp(SEEK_SET);
        if(!HistoryFile.is_open())
        {
            cerr<<endl<<"Unable to open file!";
        }

        HistoryFile<<"\nUndid Last Transaction | Current Balance: Rs. "<<Balance;
        HistoryFile.close();
    }

    ~BankAccount() {}
};

class SavingsAccount : public BankAccount
{
    float InterestRate;
public:

    SavingsAccount(int an, float bal, float ir) : BankAccount(an, bal)
    {
        InterestRate = ir;
        FileName = "SavAccHistory.txt";

        HistoryFile.open(FileName, ios::out | ios::trunc);
        HistoryFile.close();

        HistoryFile.open(FileName, ios::app);
        HistoryFile.seekp(SEEK_END);
        HistoryFile<<"Savings Account No. "<<AccNum<<" Transaction History | Initial Balance: Rs. "<<Balance;
        HistoryFile.close();
    }

    int Withdraw(float diff)
    {
        if(diff<=Balance)
        {
            PrevBal = Balance;
            Balance-=diff;

            HistoryFile.open(FileName, ios::app);
            HistoryFile.seekp(SEEK_END);
            if(!HistoryFile.is_open())
            {
                cerr<<endl<<"Unable to open file!";
            }

            HistoryFile<<"\nWithdrew Rs."<<diff<<" | Current Balance: Rs. "<<Balance;
            HistoryFile.close();

            return 0;
        }
        else
            return 1;
    }

    void DisplayDetails()
    {
        cout<<"\nAccount Number: "<<AccNum;
        cout<<"\nInterest Rate: "<<InterestRate;
        cout<<"\nCurrent Balance: Rs. "<<Balance;
    }

    ~SavingsAccount() {}
};

class CurrentAccount : public BankAccount
{
    float OverdraftLimit;
public:

    CurrentAccount(int an, float bal, float ol) : BankAccount(an, bal)
    {
        OverdraftLimit = ol;
        FileName = "CurAccHistory.txt";

        HistoryFile.open(FileName, ios::out | ios::trunc);
        HistoryFile.close();

        HistoryFile.open(FileName, ios::app);
        HistoryFile.seekp(SEEK_END);
        HistoryFile<<"Current Account No. "<<AccNum<<" Transaction History | Initial Balance: Rs. "<<Balance;
        HistoryFile.close();
    }

    int Withdraw(float diff)
    {
        if(diff<=Balance+OverdraftLimit)
        {
            PrevBal = Balance;
            Balance-=diff;

            HistoryFile.open(FileName, ios::app);
            HistoryFile.seekp(SEEK_END);
            if(!HistoryFile.is_open())
            {
                cerr<<endl<<"Unable to open file!";
            }

            HistoryFile<<"\nWithdrew Rs."<<diff<<" | Current Balance: Rs. "<<Balance;
            HistoryFile.close();

            return 0;
        }
        else
            return 1;
    }

    void DisplayDetails()
    {
        cout<<"\nAccount Number: "<<AccNum;
        cout<<"\nOverDraft Limit: "<<OverdraftLimit;
        cout<<"\nCurrent Balance: Rs. "<<Balance;
    }

    ~CurrentAccount() {}
};



int main()
{

    int Choice=1, accn, choyis;
    float interest, bal, limit;
    SavingsAccount *SA = nullptr;
    CurrentAccount *CA = nullptr;

    while(Choice>0 && Choice<8)
    {
        cout<<"\n\nBanking System\nChoices:\n1. Create Savings Account\n2. Create Current Account\n3. Withdraw Money"
            <<"\n4. Deposit Money\n5. View Transaction History\n6. Display Account Details\n7. Undo Last Transaction"
            <<"\n0. Exit System\n\nEnter your Choice: "; //multiple choice based
        cin>>Choice;

        switch(Choice)
        {
        case 1:
            cout<<"\nEnter Details of Savings Account: ";
            cout<<"\nAccount Number: ";
            cin>>accn;
            cout<<"Interest Rate: ";
            cin>>interest;
            cout<<"Initial Balance: Rs. ";
            cin>>bal;
            SA = new SavingsAccount(accn, bal, interest); //creating dynamic object usinng "new" keyword
            break;

        case 2:
            cout<<"\nEnter Details of Current Account: ";
            cout<<"\nAccount Number: ";
            cin>>accn;
            cout<<"OverDraft Limit: ";
            cin>>limit;
            cout<<"Initial Balance: Rs. ";
            cin>>bal;
            CA = new CurrentAccount(accn, bal, limit);
            break;

        case 3:
            cout<<"\nPick Account to Withdraw money from:\n1. Savings Account\n2. Current Account\nChoice: ";
            cin>>choyis;

            if(choyis==1 && SA!=nullptr)
            {
                cout<<"Enter amount to Withdraw from Savings Account: ";
                cin>>bal;

                if(!SA->Withdraw(bal))
                {
                    cout<<"\nRs. "<<bal<<" withdrawn from savings account";
                }
                else
                    cout<<"\nNot Enough Balance to withdraw";
            }
            else if(choyis==2 && CA!=nullptr)
            {
                cout<<"Enter amount to Withdraw from Current Account: ";
                cin>>bal;

                if(!CA->Withdraw(bal))
                {
                    cout<<"\nRs. "<<bal<<" withdrawn from current account";
                }
                else
                    cout<<"\nNot Enough Balance to withdraw";
            }
            else
            {
                cout<<"\nNo such bank account found!";
            }
            break;

        case 4:
            cout<<"\nPick Account to Deposit money into:\n1. Savings Account\n2. Current Account\nChoice: ";
            cin>>choyis;

            if(choyis==1 && SA!=nullptr)
            {
                cout<<"Enter amount to Deposit into Savings Account: ";
                cin>>bal;

                SA->Deposit(bal);
                cout<<"\nRs. "<<bal<<" deposited into savings account";
            }
            else if(choyis==2 && CA!=nullptr)
            {
                cout<<"Enter amount to Deposit into Current Account: ";
                cin>>bal;

                CA->Deposit(bal);
                cout<<"\nRs. "<<bal<<" deposited into current account";
            }
            else
            {
                cout<<"\nNo such bank account found!";
            }
            break;

        case 5:
            cout<<"\nPick Account to view transaction history:\n1. Savings Account\n2. Current Account\nChoice: ";
            cin>>choyis;

            if(choyis==1 && SA!=nullptr)
            {
                SA->PrintHistory();
            }
            else if(choyis==2 && CA!=nullptr)
            {
                CA->PrintHistory();
            }
            else
            {
                cout<<"\nNo such bank account found!";
            }
            break;

        case 6:
            cout<<"\nPick Account to display details:\n1. Savings Account\n2. Current Account\nChoice: ";
            cin>>choyis;

            if(choyis==1 && SA!=nullptr)
            {
                cout<<"\nSavings Account Details:";
                SA->DisplayDetails();
            }
            else if(choyis==2 && CA!=nullptr)
            {
                cout<<"\nCurrent Account Details:";
                CA->DisplayDetails();
            }
            else
            {
                cout<<"\nNo such bank account found!";
            }
            break;

        case 7:
            cout<<"\nPick Account to undo last Transaction:\n1. Savings Account\n2. Current Account\nChoice: ";
            cin>>choyis;

            if(choyis==1)
            {
                if(SA!=nullptr)
                {
                    SA->UndoLast();
                    cout<<"\nUndid Last Transaction in Savings Account";
                }
                else
                    cout<<"\nNo Transactions to Undo";
            }
            else if(choyis==2)
            {
                if(CA!=nullptr)
                {
                    CA->UndoLast();
                    cout<<"\nUndid Last Transaction in Current Account";
                }
                else
                    cout<<"\nNo Transactions to Undo";
            }
            else
            {
                cout<<"\nNo such bank account found!";
            }

        default:
            break;
        }
    }
    cout<<"\n\nExiting System...";

    delete SA;
    delete CA;
    return 0;
}
