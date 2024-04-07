/* Programmer: Amna Asim Khan
   ID: 23K-0859
   BS-AI 2A
   OBJECT ORIENTED PROGRAMMING
   ASSIGNMENT # 2
   Task 3
   Description:Daraz Loyalty Program System
In this scenario, Daraz is launching a loyalty program for its customers.
Design a class named DarazPersonData with the following member variables:
? lastName (string)
? firstName (string)
? address (string)
? city (string)
? state (string)
? zip (string)
? phone (string)
• Write the appropriate accessor and mutator functions for these member variables.
Next, design a class named DarazCustomerData. The DarazCustomerData class should have the
following member variables:
? customerNumber (an int)
? loyaltyPoints (an int)
The customerNumber variable will hold a unique integer for each customer. The loyaltyPoints
variable will track the loyalty points earned by the customer. Write appropriate accessor and
mutator functions for these member variables.
Design a class named DarazLoyaltyProgram to manage the loyalty program:
? Include functions to add loyalty points for purchases, redeem loyalty points for discounts,
and display the total loyalty points for a customer.
Demonstrate the classes in a program by creating objects and performing operations such as
adding loyalty points for purchases, redeeming loyalty points for discounts, and displaying total
loyalty points for a customer.
Input Validation: Do not accept negative values for loyalty points or invalid customer
numbers.
*/



#include<iostream>
using namespace std;

class DarazPersonData{
	protected:
		string lastName;
		string firstName;
		string address;
		string city;
		string state;
		string zip;
		string phone;		
	public:
		DarazPersonData(string last, string first, string address, string city, string state, string zip, string phone){
			this->lastName= last;
			this->firstName= first;
			this->address=address;
			this->city=city;
			this->state = state;
			this->zip=zip;
			this->phone =phone;
		}		
		string getLastName(){
			return lastName;
		}		
		string getFirstName(){
			return firstName;
		}
		string getAddress(){
			return address;
		}	
		string getcity(){
			return city;
		}		
		string getstate(){
			return state;
		}		
		string getZip(){
			return zip;
		}		
		string getPhone(){
			return phone;
		}
};
class DarazCustomerData:public DarazPersonData{
	protected:
		int customerNumber;
		int loyaltyPoints;		
	public:
		DarazCustomerData(string last, string first, string address, string city, string state, string zip, string phone, int customerNumber, int loyaltyPoints):DarazPersonData(last, first, address, city, state, zip, phone),customerNumber(customerNumber), loyaltyPoints(loyaltyPoints){}		
		int getCustomerNumber(){
			return customerNumber;
		}		
		int getLoyaltyPoints(){
			return loyaltyPoints;
		}	
		void setLoyaltyPoints(int newPoints){
			this->loyaltyPoints = newPoints;
		}
};
class DarazLoyaltyProgram{
	private:
		DarazCustomerData cust;
	public:
		DarazLoyaltyProgram(DarazCustomerData& customer) : cust(customer) {}		 
		void addLoyaltyPoints(int pointsToAdd){
			if(pointsToAdd>=0){
				int currPoints = cust.getLoyaltyPoints();
				cust.setLoyaltyPoints(pointsToAdd+currPoints);
			}			
			else{
				cout<<"Error: Negative points"<<endl;
			}
		}		
		void redeemPoints(int points){
			int currPoints= cust.getLoyaltyPoints();
			if(currPoints>=points){
				cust.setLoyaltyPoints(currPoints-points);
			}
			else{
				cout<<"Points can not be redeemed"<<endl;
			}
		}		
		void displayTotalLoyaltyPoints(){
			cout<<endl<<"-------DISPLAYING TOTAL LOYALTY POINTS---------"<<endl;
			cout<<cust.getFirstName()<<" "<<cust.getLastName()<<endl;
			cout<<"customer number: "<<cust.getCustomerNumber()<<endl;
			cout<<"LOYALTY POINTS: "<<cust.getLoyaltyPoints();
		}
};
int main(){
	cout<<"Amna Asim Khan"<<endl<<"23k-0859"<<endl;
	DarazCustomerData customer("Hussain","Anwar", "Main road, street 5", "Karachi","State","B1234", "034501568788", 45,1000);
	DarazLoyaltyProgram prog(customer);
	prog.displayTotalLoyaltyPoints();
	prog.addLoyaltyPoints(100);
	prog.displayTotalLoyaltyPoints();
	prog.redeemPoints(1100);
	prog.displayTotalLoyaltyPoints();
}
