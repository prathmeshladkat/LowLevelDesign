#include <iostream>
#include <string>

using namespace std;

/*
Encapsulation says 2 things:
1. An Object's Characteristics and its behaviour are encapsulated together
within that Object.
2. All the characteristics or behaviours are not for everyone to access.
Object should provide data security.

We follow above 2 pointers about Object of real world in programming by:
1. Creating a class that act as a blueprint for Object creation. Class contain
all the characteristics (class variable) and behaviour (class methods) in one block,
encapsulating it together.
2. We introduce access modifiers (public, private, protected) etc to provide data
security to the class members.
*/

class SportsCar {
    private:
        string brand;
        string model;
        bool isEngineOn;
        int currentGear;
        int currentSpeed;

        string tyreCompany;

    public: 
        SportsCar(string b, string m) {
            this->brand = b;
            this->model = m;
            isEngineOn = false;
            currentGear = 0;
            currentSpeed = 0;
            tyreCompany = "MRF";
        }

        int getSpeed() {
            return currentSpeed;
        }

        string gettyreCompany() {
            return tyreCompany
        }

        void setTyreCompany(string tyreCompany) {
        this->tyreCompany = tyreCompany;
    }

        void startEngine() {
        isEngineOn = true;
        cout << brand << " " << model << " : Engine starts with a roar!" << endl;
        }

        void shiftGear(int gear) {
            if (!isEngineOn) {
                cout << brand << " " << model << " : Engine is off! Cannot Shift Gear." << endl;
                return;
            }
            currentGear = gear;
            cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
        }

        void accelerate() {
            if (!isEngineOn) {
                cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
                return;
            }
            currentSpeed += 20;
            cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
        }

        void brake() {
            currentSpeed -= 20;
            if (currentSpeed < 0) currentSpeed = 0;
            cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
        }

        void stopEngine() {
            isEngineOn = false;
            currentGear = 0;
            currentSpeed = 0;
            cout << brand << " " << model << " : Engine turned off." << endl;
        }

        ~SportsCar() {}
  
};

int main() {
    SportsCar* mySportsCar = new SportsCar("Ford", "mustang") {

    mySportsCar->startEngine();
    mySportsCar->shiftGear(1);
    mySportsCar->accelerate();
    mySportsCar->shiftGear(2);
    mySportsCar->accelerate();
    mySportsCar->brake();
    mySportsCar->stopEngine();

    cout << "Current Speed of My Sports Car is " << mySportsCar->getSpeed() << endl;

    delete mySportsCar;    

    return 0;


    }
}