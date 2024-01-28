#include <iostream>
#include <vector>

using namespace std;

class Product {
public:
    Product(string name, double price) : name(name), price(price) {}

    string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

private:
    string name;
    double price;
};

class ShoppingCart {
public:
    void addItem(const Product& product, int quantity) {
        items.push_back({product, quantity});
    }

    double calculateTotal() const {
        double total = 0.0;
        for (size_t i = 0; i < items.size(); ++i) {
            total += items[i].product.getPrice() * items[i].quantity;
        }
        return total;
    }

    void displayItems() const {
        cout << "Shopping Cart Contents:\n";
        for (size_t i = 0; i < items.size(); ++i) {
            cout << items[i].product.getName() << " x " << items[i].quantity << "\n";
        }
    }

private:
    struct ShoppingCartItem {
        Product product;
        int quantity;
    };

    vector<ShoppingCartItem> items;
};

int main() {
    // Create some products
    Product laptop("Laptop", 999.99);
    Product phone("Smartphone", 499.99);
    Product headphones("Headphones", 99.99);

    // Create a shopping cart
    ShoppingCart cart;

    // Display product information
    cout << "Available Products:\n";
    cout << "1. " << laptop.getName() << " - $" << laptop.getPrice() << "\n";
    cout << "2. " << phone.getName() << " - $" << phone.getPrice() << "\n";
    cout << "3. " << headphones.getName() << " - $" << headphones.getPrice() << "\n";

    // User adds items to the cart
    char addMore;
    do {
        int productChoice, quantity;
        cout << "Enter the product number (1-3): ";
        cin >> productChoice;

        if (productChoice < 1 || productChoice > 3) {
            cout << "Invalid product number. Please choose again.\n";
            continue;
        }

        cout << "Enter the quantity: ";
        cin >> quantity;

        switch (productChoice) {
            case 1:
                cart.addItem(laptop, quantity);
                break;
            case 2:
                cart.addItem(phone, quantity);
                break;
            case 3:
                cart.addItem(headphones, quantity);
                break;
        }

        cout << "Item added to the cart.\n";
        cout << "Do you want to add more items? (y/n): ";
        cin >> addMore;

    } while (addMore == 'y' || addMore == 'Y');

    // Display the shopping cart contents using a traditional for loop
    cart.displayItems();

    // Calculate and display the total price
    double total = cart.calculateTotal();
    cout << "\nTotal Price: $" << total << "\n";

    return 0;
}

