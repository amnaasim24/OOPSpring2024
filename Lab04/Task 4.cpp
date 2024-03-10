/* Programmer: Amna Asim Khan
   Date: 15th February, 2024
   LAB 04 
   Task 4
   Description:Instantiate a class named Office to represent attributes of an office space, including Location
   (default value: " "), SeatingCapacity (default value: 0), and Furniture (a string array with a
   size of 3, default: {"", "", ""}). Implement a parameterized constructor assigning default values to
   all attributes using a member initialization list. Create multiple instances of the Office class using
   different numbers of constructor arguments.
*/



#include<iostream>
using namespace std;
class Office{
	private:
		string location;
		int SeatingCapacity;
		string furniture[3];	
	public:
		Office(string loc=" ", int Seating = 0, string furn1 = " ", string furn2 = " ", string furn3 = " "): location(loc), SeatingCapacity(Seating), furniture{furn1, furn2, furn3}{};		
		void display(){
			cout<<"-------------------------------------------------"<<endl;
			cout<<"Location: "<<location<<endl;
			cout<<"Seating capacity: "<<SeatingCapacity<<endl;
			cout<<"Furniture: "<<endl;
			for(int i =0; i<3; i++){
				cout<<furniture[i]<<endl;
			}
			cout<<"-------------------------------------------------"<<endl;
		}
};
int main(){
	Office o1("Main road", 50, "Table", "Chairs", "Fans");
	Office o2("Shah faisal colony", 100, "Shelves","Chairs","Sofas");
	Office o3("Muslim Colony, Qasimabad", 20, "Clock","Tables","Cabinets");	
	o1.display();
	o2.display();
	o3.display();
}
