
/*Write a program to overload decrement operator -- in such a way that when it is
used as a prefix, it multiplies a number by 4 and when it is used as a postfix then it
divides the number by 4.*/
#include<iostream>
using namespace std;

class Base{
public:
    int num;
    Base(int x){
    	this->num = x;
	}
    Base operator--(){
        return num * 4;
    } 
    Base operator--(int){
        return num / 4;
    } 
    void display(){
        cout<<"Value is: "<<num;
    }

};
int main(){
    Base b1(20);
    b1 = --b1;
    cout<<"Displaying the prefix operator"<<endl;
    b1.display();
    cout<<endl;
    b1 = b1--;
    cout<<"Displaying the postfix operator"<<endl;
    b1.display();
}
