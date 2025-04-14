#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
class loan
{
    int Loan_ID;
    string Applicant_Name;
    double Loan_Amount, Annual_Interest_Rate, EMI;
    int Loan_Tenure_Months;

public:
    loan() : Loan_ID(0), Applicant_Name(""), Loan_Amount(0.0), Annual_Interest_Rate(0.0), Loan_Tenure_Months(0), EMI(0.0) {}
    loan(int id, string name, double amount, double rate, int time, double emi)                                          
    {
        Loan_ID = id;
        Applicant_Name = name;
        Loan_Amount = amount;
        Annual_Interest_Rate = rate;
        Loan_Tenure_Months = time;
        EMI = emi;
    }
    double Calculate_Emi();     
    void Display_Loan_Details(); 
};
double loan::Calculate_Emi()
{
    double Monthly_Rate = (Annual_Interest_Rate / 12) / 100;
    double Emi_Value = (Loan_Amount * Monthly_Rate * pow(1 + Monthly_Rate, Loan_Tenure_Months)) /
                       (pow(1 + Monthly_Rate, Loan_Tenure_Months) - 1);
    return Emi_Value;
}
void loan::Display_Loan_Details()
{
    cout << endl
         << "The loan id is : " << Loan_ID;
    cout << endl
         << "Applicant's name is : " << Applicant_Name;
    cout << endl
         << "Amount of loan is Rs: " << Loan_Amount;
    cout << endl
         << "The annual interest rate is : " << Annual_Interest_Rate;
    cout << endl
         << "Loan tenure : " << Loan_Tenure_Months;
    cout << endl
         << "Monthly EMI : Rs" << EMI;
    cout << endl
         << "EMI value is : Rs" << Calculate_Emi();
}
int main()
{
    loan l[100];
    int choice, Number_Of_Applicants;
    cout << endl
         << "Enter number of applicants : ";
    cin >> Number_Of_Applicants;
    for (int i = 0; i < Number_Of_Applicants; i++)
    {
        int id, time;
        string name;
        double amount, rate, emi;
        cout << endl
             << "=====Enter applicant " << i + 1 << " details=====";
        cout << endl
             << "Enter loan id : ";
        cin >> id;
        cout << endl
             << "Enter applicant name : ";
        cin >> name;
        cout << endl
             << "Enter loan amount : Rs";
        cin >> amount;
        cout << endl
             << "Enter annual interest rate : ";
        cin >> rate;
        cout << endl
             << "Enter loan tenure : ";
        cin >> time;
        cout << endl
             << "Enter monthly emi : Rs";
        cin >> emi;
        l[i] = loan(id, name, amount, rate, time, emi);
        cout << endl
             << "=====The details of " << i + 1 << " applicant are=====" << endl;
        l[i].Display_Loan_Details();
        cout << endl;
    }
    cout<<"SHREEJAY_24CE117";
    return 0;
}
