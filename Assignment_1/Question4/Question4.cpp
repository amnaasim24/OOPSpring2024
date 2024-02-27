/* Programmer: Amna Asim Khan
   ID: 23K-0859
   OBJECT ORIENTED PROGRAMMING (OOP) [Theory] 
   Assignment 1
   Question 4
   Description:You’re being hired to write an application for different rides in a Theme Park. You’re working on the Roller
Coaster(woohoo!!). The Theme Park has provided you with the relevant attributes for your Roller Coaster
class, and they are as follows:
? Name (of the attraction- some creative name)
? Height (maximum height that the roller coaster can reach)
? Length (total length of the roller coaster track)
? Speed (of the roller coaster)
? Capacity (amount of people that can be seated at once)
? CurrentNumRiders (number of passengers/riders currently seated in the roller coaster)
? RideInProgress (a Boolean flag, depicting whether the ride is currently in progress or not)
For the functionality, they have provided the following information:
? Constructors:
? Default – Should set the name to “roller coaster”, height to 500 meters, length to 2000 meters, and
capacity to 20 people. The ride should not be in progress by default.

? Parameterized – Should set the values as provided by the user. However, it should not accept a
Boolean to change the ride in progress flag. It should also verify if the capacity of people is in
multiples of two or three, if it is not a multiple of two or three, it should roundit to the closest
multiple of two. In addition to that, the capacity should always be greater than 3.
? Appropriate Getter and Setter functions for the available variables. The same checks should be
applied for the capacity variable, as applied in the parameterized constructor.
? A function to load/seat the riders into the roller coaster – Passengers/Riders can only be seated into
the roller coaster if the ride is not in progress, and if there is sufficient space for all the riders.In
case there is an excess number of riders compared to the available spaces, it should return the
number of riders that were not seated successfully, otherwise it should return 0.
? A function to start the ride – This function can only be called if a ride is not in progress, if a ride is
in progress, it should return -1. If a ride is not in progress, it needs to verify that all the seats have
been occupied by the riders. In case all the seats are not occupied, it should return the number of
empty seats.
? A function to stop the ride – This function can only be called if a ride is in progress. This will stop
the ride.
? A function to unload the riders from the roller coaster – Passengers/Riders can only be unloaded
from the roller coaster if they ride is not in progress.
? A function to accelerate the roller coaster – Every time this function is called, it should increase the
speed of the roller coaster by the last non-zero digit of your roll number (If your roll number is
2034 or 2040, it should increase the speed by 4)
? A function to apply brakes to slow down the roller coaster – Every time this function is called, it
should decrease the speed of the roller coaster by the first non-zero digit of your roll number. (If
your roll number is 2034 or 0203, it should decrease the speed by 2)
In your main function, create two roller coaster objects by using both the constructors. Use the second
object to demonstrate that your roller coaster adheres to all the conditions specified in this question.
*/



#include<iostream>
using namespace std;
class RollerCoaster{
private:
	string name;
	float height;
	float length;
	float speed;
	int capacity;
	int CurrentNumRiders;
	bool RideInProgress;
public:
	RollerCoaster():name("ROller Coaster"), height(500), length(2000), capacity(20), RideInProgress(false){
	}
	RollerCoaster(string name, float height, float length, float speed, int capacity, int CurrentNumRiders){
		this->name = name;
		this->height =height;
		this->length = length;
		this->speed = speed;
		this->capacity = capacity;
		this->CurrentNumRiders = CurrentNumRiders;	
		if(capacity<3){
			cout<<"Initially the capcity is not suffiecient (it is less than 3)"<<endl;
			capacity = 4;
		}		
		if((capacity%2!=0) && (capacity%3!=0)){
			cout<<"Rounding the capacity of people to the closest multiple of 2"<<endl;
			capacity = ((capacity+1)/2)*2;
		}
	}		
    string getName(){
		return name;
	}
	float getHeight(){
		return height;
	}	
	float getLength(){
		return length;
	}	
	float getSpeed(){
		return speed;
	}	
	int getCapacity(){
		return capacity;
	}	
	int getCurrentNumRiders(){
		return CurrentNumRiders;
	}	
	bool getProgress(){
		return RideInProgress;
	}	
	void setName(string newName){
		this->name = newName;
	}
	void setHeight(float newHeight){
		this->height = newHeight;
	}
	void setLength(float newLength){
		this->length = newLength;
	}
	void setspeed(float newSpeed){
		this->speed = newSpeed;
	}	
	void setCapacity(int newCapacity){
		this->capacity = newCapacity;		
		if(capacity<3){
			cout<<"Initially the capcity is not suffiecient (it is less than 3)"<<endl;
			capacity = 4;
		}
		if((capacity%2!=0) && (capacity%3!=0)){
			cout<<"Rounding the capacity of people to the closest multiple of 2"<<endl;
			capacity = ((capacity+1)/2)*2;
		}
	}
	void setCurrentNumRiders(int moreRiders){
		this->CurrentNumRiders = moreRiders;
	}
	void setProgress(bool newState){
		this->RideInProgress = newState;
	}	
	int setRiders(int passengers){
		if(getProgress()==false){
			if(passengers>capacity){
				int remaining = passengers - capacity;
				setCurrentNumRiders(passengers-capacity);
				return remaining;
			}
			else{
				setCurrentNumRiders(passengers);
				cout<<"All passengers are seated successfully"<<endl;
				return 0;
			}
		}
		else{
			return 0;
		}
	}
	int startRide(){
		if(getProgress()==false){
			if(CurrentNumRiders==capacity){
				setProgress(true);
				cout<<"Ride started successfully"<<endl;
			}
			else{
				int emptySeats = capacity - CurrentNumRiders;
				return emptySeats;	
			}
		}
		else{
			return -1;
		}
	}
	void stopRide(){
		if(getProgress() == true){
			setProgress(false);
			cout<<"Ride stopped successfully"<<endl;
		}
		else{
			cout<<"Ride is not in progress yet"<<endl;
		}
	}	
	void unloadRiders(){
		if(getProgress()==false){
			this->CurrentNumRiders = 0;
			cout<<"Passengers unloaded successfully"<<endl;
		}
		else{
			cout<<"Passengers can not be unloaded because the ride is in progress"<<endl;
		}
	}
	void accelerate(int rollNumber) {
        int lastNonZero = rollNumber % 10;
        speed += lastNonZero;
        cout << "Accelerating! New speed: " << speed << endl;
    }
    void applyBrakes(int rollNumber) {     
        int firstNonZero;
        while (rollNumber >= 10) {
            rollNumber /= 10;
        }
        firstNonZero = rollNumber;
        speed -= firstNonZero;
        if (speed < 0) {
            speed = 0;
        }
        cout << "Applying brakes! New speed: " << speed <<endl;
    }
void display(){
	cout<<"Name: "<<name<<endl;
	cout<<"Height: "<<height<<endl;
	cout<<"Length: "<<length<<endl;
	cout<<"Speed: "<<speed<<endl;
	cout<<"Capacity: "<<capacity<<endl;
	cout<<"Current riders: "<<CurrentNumRiders<<endl;
	cout<<"Is the ride in progress: "<<RideInProgress<<endl;
}
};
int main(){
	cout<<"Name--> Aman Asim Khan"<<endl<<"Student ID --> 23k-0859"<<endl;
	RollerCoaster R1;	
	cout<<"Object made using the default constructor: "<<endl;
	R1.display();
	RollerCoaster R2("RideNRoll", 56.7, 78.9, 0, 20, 0);	
	cout<<endl<<"Object made by using parameterized constructor: "<<endl;
	R2.display();
	cout<<"-----------------------------------"<<endl;
	R2.setRiders(20);
	R2.startRide();
	R2.accelerate(1234);
	R2.applyBrakes(1234);
	int riders = R2.getCurrentNumRiders();
	cout<<riders<<endl;
	R2.stopRide();
	R2.unloadRiders();
}
