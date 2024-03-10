/* Programmer: Amna Asim Khan
   Date: 15th February, 2024
   LAB 04 
   Task 5
   Description:Transform the Office class by replacing the furniture array with a pointer. Modify the
   constructor to accept the size of the furniture array instead of the array itself, dynamically
   allocating memory for the furniture array within the constructor. Implement a destructor to
   deallocate memory allocated for the furniture pointer. In the main function, dynamically allocate
   an Office object, pass required values to the constructor, and then delete the dynamically
   allocated object to ensure proper invocation of the destructor.
*/



#include<iostream>
#include<vector>
#include<limits>
using namespace std;
class Office{
	private:
		string location;
		int SeatingCapacity;
		string* furniture;
		int size;		
	public:
		Office(string loc=" ", int Seating = 0, int size =0): location(loc), SeatingCapacity(Seating),size(size){
			int i;
			furniture = new string[size];
			cout<<"Start entering the furniture for your object: "<<endl;
			for( i =0; i< size; i++){
				cin>>furniture[i];
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}	
		~Office(){
			delete[] furniture;
	    }
		void display(){
			cout<<"-------------------------------------------------"<<endl;
			cout<<"Location: "<<location<<endl;
			cout<<"Seating capacity: "<<SeatingCapacity<<endl;
			cout<<"Furniture: "<<endl;
			for(int i =0; i<size; i++){
				cout<<furniture[i]<<endl;
			}
			cout<<"-------------------------------------------------"<<endl;
		}
};
int main(){
	Office *o1 = new Office("Main road", 50, 3);
	cout<<"Office 1 "<<endl;
	o1->display();
	Office *o2 = new Office("Shah faisal colony", 100, 2);
	cout<<"Office 2 "<<endl;
	o2->display();
	Office *o3 = new Office("Muslim Colony, Qasimabad", 20,3);
	cout<<"Office 3 "<<endl;
	o3->display();	
	delete o1;
	delete o2;
	delete o3;	
}
