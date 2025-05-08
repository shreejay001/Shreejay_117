#include<iostream>
#include<vector>
using namespace std;

class Fuel //bse 1 class
{
    string FuelType;
protected:

    Fuel(string f)
    {
        FuelType = f;
    }

    void DisplayFuel()
    {
        cout<<"\nFuel Type: "<<FuelType;
    }
};

class Brand //base 2 class
{
    string BrandName;
protected:

    Brand(string b)
    {
        BrandName = b;
    }

    void DisplayBrand()
    {
        cout<<"\nBrand Name: "<<BrandName;
    }
};

class Car : private Fuel, private Brand //derived class
{
public:

    Car(string f, string b): Fuel(f), Brand(b) {}

    void DisplayCar()
    {
        DisplayBrand();
        DisplayFuel();
    }
};

int main()
{
    vector<Car> Cars;
    int Choice=0, i=0;
    string brand, fuel;

    do
    {
        cout<<"\n\nCompany Car Database\nChoices:\n1. Enter New Car Information\n2. Display all Cars Information\n0. Exit System"
            <<"\n\nEnter your Choice: ";
        cin>>Choice;


        if(Choice==1)
        {
            cout<<"\nEnter Car Brand: ";
            cin.ignore();
            getline(cin, brand);
            cout<<"Enter Fuel Type: ";
            getline(cin, fuel);

            Cars.push_back(Car(fuel, brand));
            cout<<"\nNew Car Added!!";
        }
        else if(Choice==2)
        {
            cout<<"\nDisplaying all cars information:";
            for(Car &c : Cars)
            {
                cout<<"\n\nCar "<<++i;
                c.DisplayCar();
            }
        }
        else
            break;

    }
    while(Choice==1||Choice==2);

    cout<<"\n\nExiting System...";

    return 0;
}
