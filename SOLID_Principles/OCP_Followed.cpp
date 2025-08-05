#include <iostream>
#include <vector>

using namespace std;

class Product {
    public: 
        string name;
        double price;

        Product(string name, double price){
            this->name = name;
            this->price = price;

        }
};

class ShoppingCart {
    private:
        vector<Product*> products;

    public:
        void addProduct(Product* p){
            products.push_back(p);
        }

        const vector<Product*>& getProducts() {
            return products;
        }

        double calculateTotal() {
            double total = 0;
            for (auto p: products) {
                total += p->price;
            }
            return total;
        }
};

class ShopingCartPrinter {
    private:
        ShopingCart* cart;

    public:
        ShopingCartPrinter(ShoppingCart* cart) {
            this->cart = cart;
        }

        void printInvoice() {
            cout << "Shopping Cart INvoice:\n"
            for (auto p : cart->getProducts()) {
                cout << p->name << " - Rs " << p->price << endl;
            }

            cout << "Total: Rs " << cart->calculateTotal() << endl;
        }
};

class Persistance {
    private:
        ShoppingCart* cart;

    public:
        virtual void save(ShopingCart* cart) = 0;
};

class SQLPersistance : public Persistance {
    public: 
        void save(ShopingCart* cart)  override {
            cout << "Savinmg shoping cart to SQL DB..." << endl;
        }
};

class MongoPersistence : public Persistence {
public:
    void save(ShoppingCart* cart) override {
        cout << "Saving shopping cart to MongoDB..." << endl;
    }
};

class FilePersistance : public Persistance {
    public:
        void save(ShopingCart* cart) override {
            cout << "Saving shoppping cart to a file..." << endl;
        }
};

int main() {
    ShopingCart* car= new ShoppingCart();
    cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 2000));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    Persistence* db = new SQLPersistence();
    Persistence* mongo = new MongoPersistence();
    Persistence* file = new FilePersistence();

    db->save(cart);   // Save to SQL database
    mongo->save(cart); // Save to MongoDB
    file->save(cart);  // Save to File

    return 0;
}