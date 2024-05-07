/* Programmer: Amna Asim Khan
   ID: 23K-0859
   OBJECT ORIENTED PROGRAMMING (OOP) [Theory] 
   Assignment 3
   Question 2
   Description: Design a C++ program for managing a collection of pets using specialized templates
and generic programming concepts. The program should include a base Pet class
and specialized pet classes (Cat, Dog, Bird) to demonstrate inheritance,
polymorphism, and template specialization.
Pet Class Template: Implement a template Pet class that serves as the base for all
pet types.
Use a template parameter T to make the Pet class generic.
Include the following features in the Pet class:
Constructor to initialize the pet's name and age.
A pure virtual function makeSound() to represent the pet's unique sound.
B. Specialized Pet Classes: Define specialized pet classes (Cat, Dog, Bird) that inherit
from the Pet<T> class.
Each specialized pet class should implement the makeSound() function to produce
a specific sound (Meow, Woof, Chirp).
C. Write a main() function to demonstrate the functionality of the pet system.
Create instances of different pet types (Cat, Dog, Bird) and interact with them using
polymorphism.
Display each pet's information (name, age) and make them produce their unique
sound using the makeSound() method.
*/

/*Took help from a youtube video, but did not copy exact code.*/

#include<iostream>
#include<string>
using namespace std;

template <class T> class Pet{
    protected:
        string name; 
        int age;
    public:
        Pet (const string& N, int A): name(N), age(A){}
        virtual void makesound()=0;
        void displayInfo()const{
            cout<<"Pet's Name:"<<name<<endl;
            cout<<"Pet's Age:"<<age<<endl;
        }        
};
class Cat : public Pet<Cat>{
    public:
        Cat(const string& N, int A):Pet<Cat>(N,A){} 
        void makesound() override{
            cout<<"Pet Goes: Meow"<<endl;
        }
};
class Dog : public Pet<Dog>{
    public:
        Dog(const string& N, int A): Pet<Dog>(N,A){}
        void makesound()override{
            cout<<"Pet Goes: Woof woof"<<endl;
        }
};
class Bird : public Pet<Bird>{
    public:
        Bird(const string& N, int A): Pet<Bird>(N,A){}
        void makesound() override{
            cout<<"Pet Goes: Tweet tweet"<<endl<<endl;
        }
};
int main(){
    Cat c1("Cookie", 2);
    Dog d1 ("Toto", 3);
    Bird b1 ("Tweety", 1);
    Pet<Cat>* p1= &c1;
    Pet<Dog>* p2= &d1;
    Pet<Bird>* p3= &b1;
    p1->displayInfo(); p1->makesound();
    p2->displayInfo(); p2->makesound();
    p3->displayInfo(); p3->makesound();
    return 0;
} 