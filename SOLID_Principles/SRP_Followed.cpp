#include <iostream>
#include <vector>

using namespace std;

//Product class representing any item in ecommerce
class Product {
    public: 
        string name;
        double price;

        Product(string name, double price) {
            this->name = name;
            this->price = price;
        }
};

//1. ShoppingCart: Only responsible for cart realted buisness logic
class ShopingCart {
    private:
        vector<Product*> products;

    public:
        void addProduct(Product* p) {
            products.push_back(p);
        }

        const vector<Product*>& getProducts() {
            return products;
        }

        //calculate total price in cart
        double calculateTotal() {
            double total = 0;
            for (auto p : products) {
                total += p-> price;
            }
            return total;
        }

};

class ShoppingCartPrinter {
    private:
        ShoppingCart* cart;

    public:
        ShoppingCartPrinter(ShoppingCart* cart) {
            this->cart = cart;
        }

        void printInvoice() {
            cout << "Shopping cart Invoice:\n";
            for(auto p : cart->getProducts()) {
                cout << p->name << " - Rs " << p->price << endl;
            }
            cout << " Total: Rs " << cart->calculateTotal() << endl;
        }
};

class ShoppingCartStorage {
    private:
        ShoppingCart* cart;

    public:
        ShoppingCartStorage(ShopingCart* cart) {
            this->cart = cart;
        }

        void saveToDatabase() {
            cout << "Saving shopping cart to database..." << endl;
        }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 2000));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartStorage* db = new ShoppingCartStorage(cart);
    db->saveToDatabase();

    return 0;
}




