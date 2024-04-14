/*Programmer: Amna Asim Khan
   LAB 09
   Question 2
   Description:Suppose you are tasked with developing a geometry application that helps users calculate
properties of various shapes. You are required to implement classes for different shapes such
as Circle, Rectangle, Square, Triangle, and EquilateralTriangle. Each shape class
should inherit from a base class called Shape. Additionally, the EquilateralTriangle class
should inherit from the Triangle class. Your implementation should utilize method overriding
and pointers to ensure polymorphic behavior.
Implement the base class Shape with the following virtual functions:
virtual double area() const: This function should calculate and return the area of the
shape. Override this function in each derived class to provide the specific implementation for
that shape.
virtual double perimeter() const: This function should calculate and return the perimeter
of the shape. Override this function in each derived class to provide the specific implementation
for that shape.
virtual void displayProperties() const: This function should display the properties of
the shape. Override this function in each derived class to provide the specific display for that
shape.
Implement the derived classes Circle, Rectangle, Square, and Triangle, each inheriting
from the base class Shape. For each derived class:
Override the virtual functions area(), perimeter(), and displayProperties() to provide
the specific implementations for that shape.

Ensure to use pointers to the base class Shape when implementing the functions.
Implement the EquilateralTriangle class, inheriting from the Triangle class. For this
class:
Override the virtual functions area(), perimeter(), and displayProperties() to provide
the specific implementations for an equilateral triangle.
Ensure to use pointers to the base class Triangle when implementing the functions.
In the main function:
Allow users to select a shape and provide input for the required parameters (e.g., radius for
Circle, length and width for Rectangle, etc.).
Dynamically allocate memory for the selected shape using pointers to the appropriate base
class (Shape or Triangle).
Call the appropriate functions using the base class pointers to display the properties of the
selected shape.
Ensure proper memory management by deallocating memory when it is no longer needed.
Approach:
1. Start by defining the Shape base class with the required virtual functions.
2. Implement derived classes (Circle, Rectangle, Square, Triangle) inheriting from the
Shape class and override their respective virtual functions.
3. Implement the EquilateralTriangle class, inheriting from the Triangle class, and
override its virtual functions.
4. Use pointers to the appropriate base class (Shape or Triangle) to achieve polymorphic
behavior.
5. In the main function, prompt the user to select a shape and provide necessary input.
6. Dynamically allocate memory for the selected shape using pointers.
7. Call functions using the appropriate base class pointers to display shape properties.
8. Ensure proper memory deallocation to prevent memory leaks.
*/



#include<iostream>
#include<cmath>
using namespace std;
double pi = 3.142;
class Shape{
    public:
        Shape(){}
        virtual double area() const{
            return 0;
        }
        virtual double perimeter() const{
            return 0;
        }
        virtual void displayProperties() const{
        }
};
class Circle:public Shape{
    double r;
    public:
        Circle(){}
        Circle(double r):r(r){}
        double area() const{
            return pi*r*r;
        }
        double perimeter() const{
            return 2*pi*r;
        }
        void displayProperties() const{
            cout<<"AREA: "<<area()<<endl;
            cout<<"PERIMETER: "<<perimeter()<<endl;
            cout<<"DIAMETER: "<< r*2<<endl;
        }
};
class Rectangle:public Shape{
    double L;
    double W;
    public:
        Rectangle(){}
        Rectangle(double L,double W):L(L),W(W){}
        double area() const{
            return L*W;
        }
        double perimeter() const{
            return 2*(L+W);
        }
        void displayProperties() const{
            cout<<"AREA: "<<area()<<endl;
            cout<<"PERIMETER: "<<perimeter()<<endl;
            cout<<"DIAGONAL: "<<sqrt((L*L)+(W*W))<<endl;
        }
};
class Square:public Shape{
    double L;
    public:
        Square(){}
        Square(double L):L(L){}
        double area() const{
            return L*L;
        }
        double perimeter() const{
            return 4*(L);
        }
        void displayProperties() const{
            cout<<"AREA: "<<area()<<endl;
            cout<<"PERIMETER: "<<perimeter()<<endl;
            cout<<"DIAGONAL: "<<sqrt(2)*L<<endl;
        }
};
class Triangle:public Shape{
    protected:
        double B;
        double H;
        double S;
    public:
        Triangle(){}
        Triangle(double B,double H,double S):B(B),H(H),S(S){}
        double perimeter() const{
            return B + H + S;
        }
        double area() const{
            return sqrt(perimeter()*(perimeter()-B)*(perimeter()-H)*(perimeter()-S));
        }
        void displayProperties() const{
            cout<<"AREA: "<<area()<<endl;
            cout<<"PERIMETER: "<<perimeter()<<endl; 
        }
};
class Equilateraltriangle:public Triangle{
    public:
        Equilateraltriangle(){}
        Equilateraltriangle(double B):Triangle(B,B,B){}
        double area() const{
            return B * B * B;
        }
        void displayProperties() const{
            cout<<"AREA: "<<area()<<endl;
        }
};
int main(){
    int choice;
    cout<<"Welcome to the Geometry Competition Calculator! "<<endl;
    cout<<endl;
    Shape *shp;
    do{
        cout<<"Please select a shape: "<<endl;
        cout<<"1.Circle\n2.Rectangle\n3.Square\n4.Triangle\n"<<endl;
        cin>>choice;
        switch (choice){
            case 1:{
                double radius;
                cout<<"Enter the radius of the circle:";
                cin>>radius;
                Circle cir(radius);
                shp = &cir;
                shp->displayProperties(); 
                break;
            }
            case 2:{
                double L,W;
                cout<<"Enter the length of the rectangle: ";
                cin>>L;
                cout<<"Enter the width of the rectangle:";
                cin>>W;
                Rectangle rec(L,W);
                shp = &rec;
                shp->displayProperties(); 
                break;
            }
            case 3:{
                double L;
                cout<<"Enter the side length of the square: ";
                cin>>L;
                Square sqr(L);
                shp = &sqr;
                cout<<"Properties of the Squar"<<endl;
                shp->displayProperties(); 
                break;
            }
            case 4:{
                double B, H, S;
                cout<<"Enter the lengths of the three sides of the triangle:";
                cin>>B;
                cin>>H;
                cin>>S;
                Triangle tri(B,H,S);
                shp = &tri;
                if(B==H==S){
                	cout<<"Displaying the properties of the equilateral triangle: ";
                	shp->displayProperties();
				}
				else{
					cout<<"Displaying the properties of the triangle: "<<endl;
					 shp->displayProperties(); 
				}
                break;
            }
            default:
            	cout<<"Invalid choice "<<endl;
            	break;
        }
        string select;
        cout<<endl<<"Do you want to calculate properties for another shape? (yes/no): ";
        cin>>select;
        if (select != "yes"){
            return 0;
        }
    }while(1);
}
