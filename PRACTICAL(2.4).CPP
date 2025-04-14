#include <iostream>
#include <cstring>
using namespace std;
class inventory
{
    int Product_ID;
    string Product_Name;
    double Product_Price;
    int Product_Quantity;

public:
    inventory() : Product_ID(0), Product_Name(""), Product_Price(0.0), Product_Quantity(0) {}
    inventory(int id, string name, double price, int quantity)
    {
        Product_ID = id;
        Product_Name = name;
        Product_Price = price;
        Product_Quantity = quantity;
    }
    void Adding_Stock(int quantity);
    void Edit_Price(int New_Price);
    void Display_Data() const;
};
void inventory::Display_Data() const
{
    cout << endl
         << "===THE PRODUCT DETAILS ARE GIVEN BELOW===";
    cout << endl
         << "Product ID is : " << Product_ID;
    cout << endl
         << "Product name is :" << Product_Name;
    cout << endl
         << "Product price is : " << Product_Price;
    cout << endl
         << "Product quantity is :" << Product_Quantity;
}
void inventory::Edit_Price(int New_Price)
{
    if (Product_Price > 0)
    {
        Product_Price = New_Price;
        cout << endl
             << "The price has been changed and new price has become : Rs" << Product_Price;
    }
    else
        cout << endl
             << "The new price has to be greater than zero!!!";
}
void inventory::Adding_Stock(int quantity)
{
    if (quantity > 0)
    {
        Product_Quantity += quantity;
        cout << endl
             << "The quantity " << quantity << " is added to the inventory and the new quantity has now bwcame : " << Product_Quantity;
    }
    else
        cout << endl
             << "The quantity should be greater than zero to add to the inventory.";
}
int main()
{
    inventory i1;
    int choice, id, quantity;
    string name;
    double price;
    cout << endl
         << "Enter product ID : ";
    cin >> id;
    cout << endl
         << "Enter product name : ";
    cin >> name;
    cout << endl
         << "Enter product price : ";
    cin >> price;
    cout << endl
         << "Enter product quantity : ";
    cin >> quantity;
    i1 = inventory(id, name, price, quantity);
    do
    {
        cout << endl
             << "===CHOOSE FROM THE BELOW OPTIONS===";
        cout << endl
             << "1.ADD QUANTITY";
        cout << endl
             << "2.EDIT PRICE";
        cout << endl
             << "3.DISPLAY DATA";
        cout << endl
             << "4.EXIT";
        cout << endl
             << "Choose from (1 to 4) options : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int New_Quantity;
            cout << endl
                 << "Enter the quantity of stocks to be added : ";
            cin >> New_Quantity;
            i1.Adding_Stock(New_Quantity);
            break;
        case 2:
            int New_Price;
            cout << endl
                 << "Enter the new price of products to be edited : ";
            cin >> New_Price;
            i1.Edit_Price(New_Price);
            break;
        case 3:
            i1.Display_Data();
            break;
        case 4:
            cout << endl
                 << "You are now being exited from the main screen!!!";
            break;
        default:
            cout << endl
                 << "You have selected an invalid option!!!";
            break;
        }
    }
    while (choice != 4);

    cout<<"SHREEJAY_24CE117";
    return 0;
}
