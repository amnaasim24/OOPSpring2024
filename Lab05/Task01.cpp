/* Programmer: Amna Asim Khan
   Due Date: 7th March, 2024
   LAB 05
   Task 1
   Description:Create a class called Square with the following attributes:
• sideLength – float variable
• area – float variable
• allareas – static float variable
Create the following methods for your class:
• Constructors (default and parameterized (only takes sideLength as input))
• Function to calculate area, the calculated area should always be added to the allareas
variable each time an area is calculated. (assume it’s called only once for each object)
• Getters and Setters for all variables
In your main function create 3 Squares with different sideLength. Call the area method for
each of those Square objects. After each time the area method is called, call that square’s
getters for area and allareas to display the updated values.
*/ 



#include<iostream>
using namespace std;
class Square{
	private:
		float sideLength;
		float area;
		static float allareas;	
	public:
		Square():sideLength(0){
		}		
		Square(int length):sideLength(length){
		}		
	    float calculateArea(){
			area = sideLength*sideLength;
			allareas+=area;
		}
		float getLength(){
			return sideLength;
		}
		float getArea(){
			return area;
		}
		static float getallareas(){
			return allareas;
		}
		void setlength(float newLength){
			this->sideLength=newLength;
		}
		void setarea(float newarea){
			this->area=newarea;
		}
		static void setallareas(float value){
			allareas=value;
		}
};
float Square::allareas =0;
int main(){
	cout<<"Amna Asim Khan"<<endl<<"23K-0859"<<endl;
	cout<<"--------------------Displaying the information for square 1--------------------"<<endl;
	Square s1(32);
	s1.calculateArea();
	cout<<"Side length"<<s1.getLength()<<endl;
	cout<<"Area: "<<s1.getArea()<<endl;
	cout<<"All areas value: "<<s1.getallareas()<<endl;
	cout<<"--------------------Displaying the information for square 2--------------------"<<endl;
	Square s2(2);
	s2.calculateArea();
	cout<<"Side length"<<s2.getLength()<<endl;
	cout<<"Area: "<<s2.getArea()<<endl;
	cout<<"All areas value: "<<s2.getallareas()<<endl;
	cout<<"--------------------Displaying the information for square 3--------------------"<<endl;
	Square s3(3);
	s3.calculateArea();
	cout<<"Side length"<<s3.getLength()<<endl;
	cout<<"Area: "<<s3.getArea()<<endl;
	cout<<"All areas value: "<<s3.getallareas()<<endl;
	
}
