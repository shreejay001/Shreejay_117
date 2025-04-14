#include <iostream>

using namespace std;

const int maxproduct = 100;

struct Product
{
    int id;
    string name;
    int quantity;
    float price;
};

Product inventory[maxproduct];
int productcount = 0;

void addproduct(int id, string name, int quantity, float price)
{
    if (productcount >= maxproduct)
    {
        cout << "Inventory is full!!!" << endl;
    }
    inventory[productcount] = {id, name, quantity, price};
    productcount++;
    cout << "Product: " << name << " Add" << endl;
}

void updatequantity(int id, int newquantity)
{
    for (int i = 0; i < productcount; i++)
    {
        if (inventory[i].id == id)
        {
            inventory[i].quantity = newquantity;
            cout << "Quantity updated!!!" << endl
                 << "ID: " << id << endl;
        }
    }
}
int calculate_total_value()
double total = 0;
for (int i = 0; i < productcount; i++)
{
    total += inventory[i].quantity * inventory[i].price;
}
return total;
}
void display_inventory()
{
    cout << endl
         << "Details of Inventory: " << endl;
    cout << "ID\tNAME\t\tQUANTITY\tPRICE" << endl;
    for (int i = 0; i < productcount; i++)
    {
        cout << inventory[i].id << "\t"
             << inventory[i].name << "\t\t"
             << inventory[i].quantity << "\t\t"
             << inventory[i].price << "\t" << endl;
    }
}
int main()
{
    addproduct(1, "IPhone", 7, 149000.00);
    addproduct(2, "Samsung", 10, 223000.00);
    addproduct(3, "Vivo", 5, 100000.00);

    updatequantity(3, 2);

    display_inventory();

    cout << "Total inventory value: " << calculate_total_value() << endl;

    cout << "SHREEJAY_24CE117";

    return 0;
