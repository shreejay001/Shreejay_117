#include <iostream>

using namespace std;

const int MAX_PRODUCTS = 100;

struct Product
{
    int id;
    string name;
    int quantity;
    double price;
};

int main()
{
    Product inventory[MAX_PRODUCTS];
    int count = 0;
    int choice;

    do
    {
        cout << "1. Add Product\n";
        cout << "2. Update Quantity\n";
        cout << "3. Show Total Inventory Value\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            if (count < MAX_PRODUCTS)
            {
                cout << "Enter ID: ";
                cin >> inventory[count].id;
                cout << "Enter Name: ";
                cin >> inventory[count].name;
                cout << "Enter Quantity: ";
                cin >> inventory[count].quantity;
                cout << "Enter Price: ";
                cin >> inventory[count].price;
                count++;
            }
            else
            {
                cout << "Inventory full\n";
            }
        }
        else if (choice == 2)
        {
            int id, found = 0;
            cout << "Enter Product ID to update: ";
            cin >> id;
            for (int i = 0; i < count; i++)
            {
                if (inventory[i].id == id)
                {
                    cout << "Enter new Quantity: ";
                    cin >> inventory[i].quantity;
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                cout << "Product not found\n";
            }
        }
        else if (choice == 3)
        {
            double total = 0;
            for (int i = 0; i < count; i++)
            {
                total += inventory[i].quantity * inventory[i].price;
            }
            cout << "Total Inventory Value: " << total << "\n";
        }

    }
    while (choice != 4);
    cout << "SHREEJAY_24CE117";

    return 0;
}
