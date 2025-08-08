#include <iostream>
#include <string>

using namespace std;

//Implementation Hierarchy: Engine Interface (LLL)
class Engine {
    public:
        virtual void start() = 0;
        virtual ~Engine() {}
};

//Concrete Implementors (LLL)
class PetrolEngine : public Engine {
    public:
        void start() override {
            cout << "Petrol engine starting with ignition!" << endl;
        }
};

class DieselEngine : public Engine {
    public:
        void start() override {
            cout << "Diesel engine roaring to life!" << endl;
        }
};

class ElectricEngine : public Engine {
public:
    void start() override {
        cout << "Electric engine powering up silently!" << endl;
    }
};


//Avstraction Hierarchy: Car (HLL) 
class Car {
    protected:
        Engine* engine;
    public:
        Car(Engine* e) {
            engine  = e;
        }
        virtual void drive() = 0;
};

//Refined Abstraction : Sedan
class Sedan : public Car {
    public:
        Sedan(Engine* e) : Car(e) {}

        void drive() override {
            engine->start();
            cout << "Driving a sedan on the highway." << endl;
        }
};

// Refined Abstraction: SUV
class SUV : public Car {
public:
    SUV(Engine* e) : Car(e) {}

    void drive() override {
        engine->start();
        cout << "Driving an SUV off-road." << endl;
    }
};

int main() {
    //Create Engine implementation on the heap
    Engine* petrolEng = new PetrolEngine();
    Engine* dieselEng = new DieselEngine();
    Engine* electricEng = new ElectricEngine();

    //Create Car abstarction, injecting Engine implementation
    Car* mySedan = new Sedan(petrolEng);
    Car* mySUV = new SUV(electricEng);
    Car* yourSUV = new SUV(dieselEng);

    //Use the cars
    mySedan->drive(); //petrol engine + sedan
    mySUV->drive();
    yourSUV->drive();

    // Clean up
    delete mySedan;
    delete mySUV;
    delete yourSUV;

    return 0;
}