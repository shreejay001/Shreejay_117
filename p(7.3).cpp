#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Product {
    string name;
    int quantity;
    double price;
};

vector<Product> inventory;

void loadInventory(const string& filename) {
    inventory.clear();
    ifstream file(filename);
    if (!file) {
        cerr << "Could not open file. Starting with an empty inventory.\n";
        return;
    }

    Product p;
    while (file >> quoted(p.name) >> p.quantity >> p.price) {
        inventory.push_back(p);
    }

    file.close();
}

void saveProductToFile(const Product& p, const string& filename) {
    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "Error opening file for writing.\n";
        return;
    }

    file << quoted(p.name) << " " << p.quantity << " " << p.price << endl;
    file.close();
}

void addProduct(const string& filename) {
    Product p;
    cout << "Enter product name: ";
    cin.ignore();
    getline(cin, p.name);
    cout << "Enter quantity: ";
    cin >> p.quantity;
    cout << "Enter price: ";
    cin >> p.price;

    inventory.push_back(p);
    saveProductToFile(p, filename);
    cout << "Product added successfully.\n";
}

void viewInventory() {
    if (inventory.empty()) {
        cout << "Inventory is empty.\n";
        return;
    }

    cout << left << setw(20) << "Product Name" << setw(10) << "Quantity" << setw(10) << "Price" << endl;
    cout << "--------------------------------------------------\n";
    for (const auto& p : inventory) {
        cout << left << setw(20) << p.name << setw(10) << p.quantity << setw(10) << p.price << endl;
    }
}

void searchProduct() {
    string searchName;
    cout << "Enter product name to search: ";
    cin.ignore();
    getline(cin, searchName);

    bool found = false;
    for (const auto& p : inventory) {
        if (p.name == searchName) {
            cout << "Product found: " << p.name << ", Quantity: " << p.quantity << ", Price: " << p.price << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Product not found.\n";
    }
}

int main() {
    const string filename = "inventory.txt";
    loadInventory(filename);

    int choice;
    do {
        cout << "\nInventory Management System\n";
        cout << "1. Add Product\n";
        cout << "2. View Inventory\n";
        cout << "3. Search Product\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addProduct(filename); break;
            case 2: viewInventory(); break;
            case 3: searchProduct(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
