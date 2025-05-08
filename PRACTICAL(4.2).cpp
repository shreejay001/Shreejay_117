#include<iostream>
#include<vector>
using namespace std;

class Person
{
    string Name;
    int Age;
protected:

    Person(string n, int a)
    {
        Name = n;
        Age = a;
    }

    void DisplayP()
    {
        cout<<"\nName: "<<Name;
        cout<<"\nAge: "<<Age;
    }
};

class Employee : private Person
{
    float ID;
public:

    Employee(string n, int a, float id) : Person(n, a)
    {
        ID = id;
    }

    void DisplayE()
    {
        DisplayP();
        cout<<"\nEmployee ID: "<<ID;
    }
};

class Manager : private Employee
{
    string Department;
public:

    Manager(string n, int a, float id, string d) : Employee(n, a, id)
    {
        Department = d;
    }

    void DisplayM()
    {
        DisplayE();
        cout<<"\nDepartment: "<<Department;
    }
};

int main()
{
    vector<Manager> Mngr;
    vector<Employee> Emp;
    int Choice = 0, i = 0, age;
    float id;
    string name, dept;

    do
    {
        cout<<"\n\nEmployee Record Management System\nChoices:-\n1. Enter New Employee\n2. Enter New Manager"
            <<"\n3. Display All Employees\n0. Exit System\n\nEnter your choice: "; //choice based system
        cin>>Choice;

        if(Choice==1)
        {
            cout<<"\nEnter Employee Details:";
            cout<<"\nName: ";
            cin.ignore();
            getline(cin, name);
            cout<<"Age: "; //input
            cin>>age;
            cout<<"Employee ID: ";
            cin>>id;

            Emp.push_back(Employee(name, age, id));
        }
        else if(Choice==2)
        {
            cout<<"\nEnter Manager Details:";
            cout<<"\nName: ";
            cin.ignore();
            getline(cin, name);
            cout<<"Age: ";
            cin>>age;
            cout<<"Employee ID: ";
            cin>>id;
            cout<<"Department: ";
            cin.ignore();
            getline(cin, dept);

            Mngr.push_back(Manager(name, age, id, dept));
        }
        else if(Choice==3)
        {
            cout<<"\n\nDisplaying all Employees Details:-";
            for(Employee &E: Emp)
            {
                cout<<"\n\nEmployee "<<++i;
                E.DisplayE();
            }
            i=0;
            cout<<"\n\nDisplaying all Managers Details:-";
            for(Manager &M: Mngr)
            {
                cout<<"\n\nManager "<<++i;
                M.DisplayM();
            }
        }
        else
            break;

    }
    while(Choice>0 && Choice<4);

    cout<<"\n\nExiting System....";

    return 0;
}
