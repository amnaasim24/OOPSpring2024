
#include <iostream>
#include <string>
using namespace std;

class Convert {
protected:
    double val1; 
    double val2; 
public:
    virtual void compute() = 0; 
    virtual ~Convert() {} 
    double getVal1(){
    	return val1;
	}
	double getVal2(){
    	return val2;
	}
};
class l_to_g : public Convert {
public:
    l_to_g(double liters) {
        val1 = liters;
    }
    void compute() override {
        val2 = val1 * 0.264172; 
    }
};
class f_to_c : public Convert {
public:
    f_to_c(double fahrenheit) {
        val1 = fahrenheit;
    }
    void compute() override {
        val2 = (val1 - 32) * 5 / 9; 
    }
};
int main() {
    Convert *converters[] = {
        new l_to_g(4),
        new f_to_c(70)
    };
    for (int i =0; i<2; i++) {
        converters[i]->compute();
        cout << "Initial value: " << converters[i]->getVal1() <<endl;
        cout << "Converted value: " << converters[i]->getVal2() <<endl;
        delete converters[i]; 
    }
    return 0;
}
