#include <iostream>
#include <mutex>

using namespace std;

class Singleton {
    private:
        static Singleton* instance;
        static mutex mtx;

        Singleton() {
            cout << "Singleton Constructor called!" << endl;
        }

        public:
            static Singleton* getInstance() {
                lock_uard<mutex> lock(mtx); //lock for thread safety
                if(instance == nullptr) {
                    instance = new Singleton();
                }
                return instance;
            }
};

Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;
}