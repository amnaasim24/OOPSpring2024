/* Programmer: Amna Asim
   ID: 23K-0859
   Date: 9th February, 2024
   Lab 03
   Task # 2
   Description:Establish a class termed "WaterBottle."
               This class encompasses attributes like company (manufacturer), color, and water
               capacity. The water capacity is recorded in both litres (l) and millilitres (ml).
               Define variables and methods for this class, incorporating getters and setters. Additionally,
               introduce a method to update the water capacity (both in litters and millilitres) after
               prompting the user regarding the amount of water consumed, presuming the input is
               consistently in millilitres.
               Exhibit the functionality of the water bottle within the main method.
*/

#include <iostream>
#include <string>

using namespace std;

class WaterBottle {
private:
    string company;
    string color;
    int capacityLiters;
    int capacityMilliliters;

public:
    
    WaterBottle(string company, string color, int capacityLiters, int capacityMilliliters)
        : company(company), color(color), capacityLiters(capacityLiters), capacityMilliliters(capacityMilliliters) {}


    string getCompany()  {
        return company;
    }

    void setCompany(const string& newCompany) {
        company = newCompany;
    }

    string getColor()  {
        return color;
    }

    void setColor(const string& newColor) {
        color = newColor;
    }

    int getCapacityLiters()  {
        return capacityLiters;
    }

    void setCapacityLiters(int newCapacityLiters) {
        capacityLiters = newCapacityLiters;
    }

    int getCapacityMilliliters()  {
        return capacityMilliliters;
    }

    void setCapacityMilliliters(int newCapacityMilliliters) {
        capacityMilliliters = newCapacityMilliliters;
    }

    
    void consumeWater(int consumedMilliliters) {
        if (consumedMilliliters <= capacityMilliliters) {
            capacityMilliliters -= consumedMilliliters;
            cout << "Water consumed. Remaining capacity: " << capacityLiters << " liters and " << capacityMilliliters << " milliliters." << endl;
        } else {
            cout << "Not enough water in the bottle to consume." << endl;
        }
    }


    void updateCapacityFromUserInput() {
        int consumedMilliliters;
        cout << "Enter the amount of water consumed in milliliters: ";
        cin >> consumedMilliliters;

        consumeWater(consumedMilliliters);
    }
};

int main() {

    WaterBottle bottle("Aquafina", "Blue", 1, 1000);

    cout << "Water Bottle Details:" << endl;
    cout << "Company: " << bottle.getCompany() << endl;
    cout << "Color: " << bottle.getColor() << endl;
    cout << "Capacity: " << bottle.getCapacityLiters() << " liters and " << bottle.getCapacityMilliliters() << " milliliters." << endl;

    bottle.updateCapacityFromUserInput();

    cout << "\nUpdated Water Bottle Details:" << endl;
    cout << "Company: " << bottle.getCompany() << endl;
    cout << "Color: " << bottle.getColor() << endl;
    cout << "Capacity: " << bottle.getCapacityLiters() << " liters and " << bottle.getCapacityMilliliters() << " milliliters." << endl;

    return 0;
}
