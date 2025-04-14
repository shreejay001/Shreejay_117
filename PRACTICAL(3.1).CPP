#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
class Employee_Details
{
    string Employee_Name;
    double Basic_Salary;
    double Bonus_Salary;

public:
    Employee_Details() : Employee_Name(""), Basic_Salary(0.0), Bonus_Salary(0.0) {}
    Employee_Details(string name, double salary, double bonus)
    {
        Employee_Name = name;
        Basic_Salary = salary;
        Bonus_Salary = bonus;
    }
    double Calculate_Total_Salary() const;
    void Display_Data();
};
inline double Employee_Details::Calculate_Total_Salary() const
{
    return Basic_Salary + Bonus_Salary;
}
void Employee_Details::Display_Data()
{
    cout << endl
         << "The employee name is : " << Employee_Name;
    cout << endl
         << "The employee's basic salary is : " << Basic_Salary;
    cout << endl
         << "The employee's bonus salary : " << Bonus_Salary;
    cout << endl
         << "The employee's total salary is : " << Calculate_Total_Salary();
}
int main()
{
    vector<Employee_Details> emp;
    string name;
    double salary, bonus;
    int Number_Of_Employees;
    cout << "Enter number of employees : ";
    cin >> Number_Of_Employees;
    for (int i = 0; i < Number_Of_Employees; i++)
    {
        cout << endl
             << "=====Enter details of " << i + 1 << " employee=====";
        cout << endl
             << "Enter employee name : ";
        cin >> name;
        cout << endl
             << "Enter employee's basic salary : ";
        cin >> salary;
        cout << endl
             << "Enter employee's bonus salary : ";
        cin >> bonus;
        emp.push_back(Employee_Details(name, salary, bonus));
    }
    cout << endl
         << "=====The employee details are given below=====";
    for (auto &i : emp)
    {
        i.Display_Data();
        cout << endl;
    }
    cout<<"SHREEJAY_24CE117";
    return 0;
}
