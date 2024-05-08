
#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string make;
    string model;
    int speed;
public:
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void calculateFuelEfficiency() = 0;
    string getMake() {
        return make;
    }
    string getModel() {
        return model;
    }
    int getSpeed() {
        return speed;
    }
};
class Car : public Vehicle {
private:
    double fuelCapacity;
public:
    Car(string make, string model, int initialSpeed, double capacity) {
        this->make = make;
        this->model = model;
        speed = initialSpeed;
        fuelCapacity = capacity;
    }
    void accelerate() override {
        speed += 10;
    }
    void brake() override {
        speed -= 10;
    }
    void calculateFuelEfficiency() override {
        cout << "Fuel efficiency of the car is calculated based on its fuel capacity and speed." << std::endl;
    }
};
class Truck : public Vehicle {
private:
    int cargoCapacity;
public:
    Truck(string make, string model, int initialSpeed, int capacity) {
        this->make = make;
        this->model = model;
        speed = initialSpeed;
        cargoCapacity = capacity;
    }
    void accelerate() override {
        speed += 5;
    }
    void brake() override {
        speed -= 5;
    }
    void calculateFuelEfficiency() override {
        cout << "Fuel efficiency of the truck is calculated based on its cargo capacity and speed." <<endl;
    }
};
int main() {
    Car myCar("Toyota", "Camry", 0, 50.0);
    Truck myTruck("Ford", "F150", 0, 1000);
    myCar.accelerate();
    myTruck.accelerate();
    cout << "Car Make: " << myCar.getMake() << ", Model: " << myCar.getModel() << ", Speed: " << myCar.getSpeed() <<endl;
    cout << "Truck Make: " << myTruck.getMake() << ", Model: " << myTruck.getModel() << ", Speed: " << myTruck.getSpeed() <<endl;
    myCar.calculateFuelEfficiency();
    myTruck.calculateFuelEfficiency();
    return 0;
}
