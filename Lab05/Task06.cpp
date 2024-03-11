/* Programmer: Amna Asim Khan
   Due Date: 7th March, 2024
   LAB 05
   Task 6
   Description:Write a program that uses composition to implement a game engine. A game engine is madeup
of several components. For example:
a) Graphics rendering engine
b) Input handler
c) Physics engine
You don’t have to write the logic for how these individual components work.
*/



#include<iostream>
using namespace std;
class GraphicsRenderingEngine{
	public:
		void render(){
			cout<<"Rendering engine in process"<<endl;
		}
};
class InputHandler{
	public:
		void inputHandler(){
			cout<<"Input Handling in process"<<endl;
		}
};
class PhysicsEngine{
	public:
		void physicsEngine(){
			cout<<"Simulating Physics"<<endl;
		}
};
class GameEngine{
	private:
		GraphicsRenderingEngine gre;
		InputHandler IH;
		PhysicsEngine PE;
	public:
		GameEngine(){
			cout<<"---------GAME ENGINE----------"<<endl;	
		}		
		void startEngine(){
			gre.render();
			IH.inputHandler();
			PE.physicsEngine();
		}
};
int main(){
	cout<<"Amna Asim Khan"<<endl<<"23K-0859"<<endl;
	GameEngine G1;
	G1.startEngine();
}
