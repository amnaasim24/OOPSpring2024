/* Programmer: Amna Asim Khan
   Due Date: 23rd March, 2024
   LAB 08
   Task 5
   Description:Suppose you are creating a program to represent different types of vehicles. You want to create
a base class called Vehicle that has member variables for the make, model, and year, as well
as a constructor to initialize these variables. You then want to create a derived class called Car
that inherits from Vehicle and adds member variables for the number of doors and the fuel
efficiency. Finally, you want to create a derived class called ElectricCar that inherits from
Car and adds a member variable for the battery life.
Write the code to define the Vehicle, Car, and ElectricCar classes, including constructors
to initialize the member variables. In each derived class constructor, make sure to call the
appropriate base class constructor using an initialization list. Also, demonstrate how to create
and use an object of the ElectricCar class.
*/



#include<iostream>
using namespace std;
class Vehicle{
	protected:
		string make;
		string model;
		int year;		
	public:
		Vehicle(string make, string model, int year){
			this->make=make;
			this->model=model;
			this->year = year;
		}
};
class Car:protected Vehicle{
	protected:
		int doors;
		double fuelEfficiency;		
	public:
		Car(int doors, double fuelEfficiency, string make, string model, int year):Vehicle(make, model,year){
			this->doors=doors;
			this->fuelEfficiency=fuelEfficiency;
		}
};
class ElectricCar:protected Car{
	protected:
		int batteryLife;		
	public:
		ElectricCar(int doors, double fuelEfficiency, string make, string model, int year,int batteryLife):batteryLife(batteryLife),Car(doors,fuelEfficiency,make,model,year){}
		void display(){
			cout<<"-------------Displaying information for the Electric car--------------"<<endl;
			cout<<"Number of doors: "<<doors<<endl;
			cout<<"Fuel status: "<<fuelEfficiency<<endl;
			cout<<"Company: "<<make<<endl;
			cout<<"Model: "<<model<<endl;
			cout<<"Year of manufacturing: "<<year<<endl;
			cout<<"Battery life: "<<batteryLife<<endl;
		}
};
int main(){
	ElectricCar car1(4, 56.88, "Toyota", "Corolla", 2018,90);
	car1.display();
}
