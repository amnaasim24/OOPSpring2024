/* Programmer: Amna Asim Khan
   Due Date: 23rd March, 2024
   LAB 08
   Task 2
   Description:Suppose you are developing a game that has different types of characters. You have a base
class called "Character" which has attributes like health and damage. Now, you want to
create two derived classes - "Enemy" and "Player" - which inherit from the "Character"
class. Further, you want to create another class called "Wizard" which inherits from the
"Player" class and has additional attributes like magic power and spells.
a) Define the "Character" class with the following attributes:
? health (integer)
? damage (integer)
? Define the constructor for the "Character" class which initializes the attributes.
? Define a function called "display" inside the "Character" class which displays
the details of the character.
b) Create a derived class called "Enemy" which inherits from the "Character" class.
? Define the constructor for the "Enemy" class which initializes the attributes of the
base class.
? Define a function called "display" inside the "Enemy" class which displays the
details of the enemy.
c) Create a derived class called "Player" which inherits from the "Character" class.
? Define the constructor for the "Player" class which initializes the attributes of
the base class.
? Define a function called "display" inside the "Player" class which displays the
details of the player.
d) Create another derived class called "Wizard" which inherits from the "Player" class
and has the following additional attributes:
? magic power (integer)
? spells (string)
? Define the constructor for the "Wizard" class which initializes the attributes of
the base classes as well as the derived class.
? Define a function called "display" inside the "Wizard" class which displays the
details of the wizard, including the additional attributes.
In the main function, create an object of the "Wizard" class and display its details.
*/



#include<iostream>
using namespace std;
class Character{
	protected:
		int health;
		int damage;
	public:
		Character(int health, int damage): health(health), damage(damage){}		
		void display(){
			cout<<"Health: "<<health<<endl;
			cout<<"Damage: "<<damage<<endl;
        }		
};
class Enemy:public Character{
	public:
		Enemy(int health, int damage):Character(health, damage){
		}
		void display(){
			cout<<"Health: "<<health<<endl;
			cout<<"Damage: "<<damage<<endl;
		}
};			
class Player:public Character{
	public:
		Player(int health, int damage):Character(health, damage){}
		void display(){
			cout<<"Health: "<<health<<endl;
			cout<<"Damage: "<<damage<<endl;		
        }
};	
class Wizard:protected Player{
	private:
		int magicPower;
		string spells;		
	public:
		Wizard(int magicPower, string spells, int health, int damage):Player(health, damage), magicPower(magicPower), spells(spells){}		
		void display(){
			cout<<"------------Displaying the information for wizard---------"<<endl;
			cout<<"Health: "<<health<<endl;
			cout<<"Damage: "<<damage<<endl;	
			cout<<"Magic Power: "<<magicPower<<endl;
			cout<<"Spells: "<<spells<<endl;
		}
};	
int main(){
	Wizard w1(2, "Abra ka dabra",100, 20);
	w1.display();
}
