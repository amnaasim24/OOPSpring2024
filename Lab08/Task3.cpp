/* Programmer: Amna Asim Khan
   Due Date: 23rd March, 2024
   LAB 08
   Task 3
   Description:Suppose you are developing a game engine that involves a variety of game objects, such as
characters, enemies, and items. You want to implement a system to keep track of the position
of these objects in 3D space, as well as their health status.
To accomplish this, you decide to create two base classes: Position and Health. The
Position class will have three member variables to store the x, y, and z coordinates of an
object, and the Health class will have a single member variable to store the health of an object.
You also want to create a Character class that inherits from both Position and Health. This
class will represent characters in the game, and will have additional member variables and
member functions to handle character-specific actions.
Write the code to define the Position, Health, and Character classes, and demonstrate how
to create and use an object of the Character class.
*/



#include<iostream>
using namespace std;
class Position{
	protected:
		int x,y,z;
	public:
		Position(int x, int y, int z):x(x),y(y),z(z){}	
};
class Health{
	protected:
		int health;		
	public:
		Health(int health):health(health){}
};
class Character:public Health, public Position{
	private:
		string name;
		float height;
		int weight;		
	public:
		Character(int health, int x, int y, int z, string name, double height, int weight):Position(x,y,z),Health(health){
			this->name = name;
			this->height=height;
			this->weight = weight;
		}		
		void display(){
			cout<<"-----------Displaying the character's data-------------"<<endl;
			cout<<"Name: "<<name<<endl;
			cout<<"Height: "<<height<<endl;
			cout<<"Weight: "<<weight<<endl;
			cout<<"Position: ("<<x<<", "<<y<<", "<<z<<")"<<endl;
			cout<<"Health: "<<health<<endl;
		}		
		void updateHealth(int health){
			this->health=health;
		}		
		void updateWeight(int weightToAdd){
			this->weight+=weight;
		}		
		void changePosition(int a, int b, int c){
			this->x=a;
			this->y=b;
			this->z=c;
		}
};
int main(){
	Character c1(78, 2, 4, 12, "Goblin", 2.5, 20);
	c1.display();
	cout<<"Updating the information"<<endl;
	c1.updateHealth(50);
	c1.updateWeight(12);
	c1.changePosition(12, 3, -9);	
	c1.display();
}
