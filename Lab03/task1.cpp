/* Programmer: Amna Asim
   ID: 23K-0859
   Date: 9th February, 2024
   Lab 03
   Task # 1
   Description:Develop a class named "BoardMarker" possessing the subsequent characteristics:
• Brand (such as Dollar, etc.)
• Shade (black, red, etc.)
• Refillable (Boolean - indicating whether it can be refilled or not)
• Ink Status (Boolean - indicating if the ink is depleted or not)
Formulate appropriate getter and setter methods for the attributes of this class.
Additionally, implement the following methods:
• A writing method with a check to verify if the ink has run out. This method should
exhibit an appropriate message based on the ink status.
• A refill method for the board marker. This method should first confirm if the marker
is refillable or not and then display a relevant message.
Illustrate the class functionality by creating an object, setting the values, and then invoking the
methods.
*/

#include <iostream>
#include <string>

using namespace std;

class BoardMarker {
private:
    string brand;
    string shade;
    bool refillable;
    bool inkStatus;

public:
    
    BoardMarker(string brand, string shade, bool refillable, bool inkStatus) {
        this->brand = brand;
        this->shade = shade;
        this->refillable = refillable;
        this->inkStatus = inkStatus;
    }

    string getBrand()  {
        return brand;
    }

    void setBrand(const string& newBrand) {
        brand = newBrand;
    }

    string getShade()  {
        return shade;
    }

    void setShade(const string& newShade) {
        shade = newShade;
    }

    bool isRefillable() {
        return refillable;
    }

    void setRefillable(bool isRefillable) {
        refillable = isRefillable;
    }

    bool isInkEmpty() {
        return !inkStatus;
    }

    void setInkStatus(bool newInkStatus) {
        inkStatus = newInkStatus;
    }

    // Writing method
    void write() const {
        if (isInkEmpty()) {
        	cout<<"Writing with "<<shade<<" "<<brand<<" "<<" board marker "<<endl;
            cout << "The " << shade << " " << brand << " board marker is empty. Refill required." << endl;
        } else {
            cout << "Writing with the " << shade << " " << brand << " board marker." << endl;
        }
    }
    void refill() {
        if (refillable) {
            cout << "Refilling the " << shade << " " << brand << " board marker." << endl;
            setInkStatus(true);
        } else {
            cout << "The " << shade << " " << brand << " board marker is not refillable." << endl;
        }
    }
};

int main() {
    
    BoardMarker marker("Dollar", "Black", true, false);

    marker.write();
    marker.refill();
    marker.write();

    return 0;
}
