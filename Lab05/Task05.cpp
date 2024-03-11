/* Programmer: Amna Asim Khan
   Due Date: 7th March, 2024
   LAB 05
   Task 5
   Description:Keeping in mind our previous car example, write a class that represents a car, and use
aggregation and composition to combine different components like engine, wheels,
headlights and steering to create the car object.

Hint: create the individual classes first before performing the composition.
Remember that for aggregation, you will need pointers! You’ll be needing
constructors and setters to set these values in case of aggregation. Same hint
applies to other questions.
*/



#include<iostream>
#include<string.h>
using namespace std;
class Engine{
	private:
		string name;
	public:
		Engine(string Aname):name(Aname){
			cout<<"Engine started..."<<endl;
		}
		void startEngine(){
			cout<<"Engine started..."<<endl;
		}
};
class Wheels{
	private:
		int count;		
	public:
		Wheels(int count):count(count){
		}		
		void move(){
			cout<<"wheels rotating"<<endl;
		}		
};
class Headlights{
	private:
		int count;
	public:
		Headlights(int num):count(num){
			cout<<"Headlights: "<<endl;
		}
		void turnOn(){
			cout<<"Headlights on"<<endl;
		}
		void turnOff(){
			cout<<"Headlights off"<<endl;
		}
};
class Steering{
	private:
		string type;
	public:
		Steering(string name):type(name){
			cout<<"Steering type: "<<type<<endl;
		}	
		void steer(){
			cout<<"Steering the Car"<<endl;
		}
};
class Car{
	private:
		Engine* engine;
		Steering* steering;
		Wheels wheels;
		Headlights headlights;
	public:	
		void setEngine(Engine* engine{
			this->engine = engine;
		}
		void setSteering(Steering* steering){
			this->steering = steering;
		}
		Car(int wheelCount, int headlightCount):wheels(wheelCount), headlights(headlightCount){}
			void start(){
				if(engine){
					engine->startEngine();
				}
			}	
			void drive(){	
					wheels.move();			
					headlights.turnOn();
				if(steering){
					steering->steer();
				}
			}		
};
int main(){
	cout<<"Amna Asim Khan"<<endl<<"23K-0859"<<endl;
	Engine engine("Power Engine");
	Steering steering1("Power steerings");	
	Car car1(4, 2);
	car1.setEngine(&engine);
	car1.setSteering(&steering1);
	car1.start();
	car1.drive();	
	return 0;
}
