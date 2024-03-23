/* Programmer: Amna Asim Khan
   Due Date: 23rd March, 2024
   LAB 08
   Task 4
   Description:Suppose you are developing a program for a school that needs to keep track of its students
and teachers. Both students and teachers have a name and an age, but they have different
properties beyond that. Students have a student ID number and a grade level, while
teachers have a subject they teach and a room number.
You want to create a set of classes to represent these objects, using hybrid inheritance.
Specifically, you want to create a base class called Person that has member variables for the
name and age, a derived class called Student that inherits from Person and adds member
variables for the student ID and grade level, and a derived class called Teacher that
inherits from Person and adds member variables for the subject and room number.

You also want to create a derived class called GraduateStudent that inherits from both
Student and Teacher, representing a student who is also a teacher's assistant.
Write the code to define the Person, Student, Teacher, and GraduateStudent classes, and
demonstrate how to create and use an object of the GraduateStudent class.
*/



#include<iostream>
using namespace std;
class Person{
	protected:
		string name;
		int age;
	public:
		Person(string name, int age){
			this->name = name;
			this->age = age;
		}
};
class Student:protected Person{
	protected:
		string StudentID;
		string gradeLevel;
	public:
		Student(string name, string StudentID, string gradeLevel, int age):Person(name, age){
			this->StudentID=StudentID;
			this->gradeLevel=gradeLevel;
		}
};
class Teacher:protected Person{
	protected:
		string subject;
		int room;
	public:
		Teacher(string subject, int room, string name, int age):Person(name, age){
			this->subject=subject;
			this->room = room;
		}
};
class  GraduateStudent:protected Student, protected Teacher{
	public: 
		GraduateStudent(string name1, string name2, int age1, int age2, int room, string subject, string StudentID, string gradeLevel):Student(name1, StudentID, gradeLevel,age1),Teacher(subject,room,name2,age2){}		
		void display(){
			cout<<"-------------Displaying student's information------------"<<endl<<endl;
			cout<<"Name of the student: "<<Student::name<<endl;
			cout<<"Student ID: "<<StudentID<<endl;
			cout<<"Age: "<<Student::age<<endl;
			cout<<"Grade Level: "<<gradeLevel<<endl;
			cout<<"-------------Displaying teacher's information------------"<<endl<<endl;
			cout<<"Name of the teacher: "<<Teacher::name<<endl;
			cout<<"Room number: "<<room<<endl;
			cout<<"Age: "<<Teacher::age<<endl;
			cout<<"Subject: "<<subject<<endl;			
		}
};
int main(){
	GraduateStudent student1("Awesh Kumar", "Farooq Zaidi",22, 35, 2, "Programming Fundamentals", "k21-2322", "BSAI-4A");
	student1.display();
}
