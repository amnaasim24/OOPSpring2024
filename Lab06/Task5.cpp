/* Programmer: Amna Asim Khan
   Due Date: 21st March, 2024
   LAB 06
   Task 5
   Description:Consider a School Management System. You are required to create two classes,
Student and Course. Each student can enroll in multiple courses. The Course class
should have the following properties: course code (string), course name (string), and
course credit hours (integer). The Student class should have the following properties:
student ID (string), student name (string), and a list of enrolled courses (an array of
Course objects).

The Student class should have the following member functions:
A constructor that initializes the student ID and name.

A function named "enroll" that takes a Course object as input and adds it to the list
of enrolled courses for the student.
A function named "drop" that takes a Course object as input and removes it from the
list of enrolled courses for the student.
A function named "getTotalCreditHours" that returns the total number of credit hours
for all courses the student is currently enrolled in.
A function named "printEnrolledCourses" that prints out the course code, name, and
credit hours for all courses the student is currently enrolled in.
*/



#include<iostream>
using namespace std;
class Courses{
	string code;
	string name;
	int creditHours;	
	public:
	       Courses(string code, string name, int creditHours) : code(code), name(name), creditHours(creditHours){}
	       int getCreditHours() const {
               return creditHours;
           }
           string getCode() const {
               return code;
           }	
};
class Student{
	private:
		string ID;
		string name;
		int curr = 0;
		Courses* courses[10];		
	public:
		Student(string ID, string newName){
			this->ID=ID;
			this->name = newName;
		}		
		void enroll(Courses& course){
			courses[curr] = new courses();
			courses[curr] = &course;
			curr++;
		}		
		void drop(Courses& course){
			bool found = false;
			for (int i = 0; i<curr; ++i){
				if (courses[i]->getCode() == course.code){
					delete *courses[i];
					for(int j = i; j < curr - 1; j++)
                    courses[j] = courses[j + 1];
                    curr--;
                    break;
                }
            }
            if(!found){
                cout << "This course was not enrolled." << endl;
            }			
            int getTotalCreditHours (){
			int total;			
			for (int i = 0; i<curr; i++)
				total += courses[i]->creditHours;
			return total;
		}		
		void printEnrolledCourses(){
			for (int i = 0; i<curr; i++)
				 cout << courses[i]->creditHours << endl;
		}
		~Student(){
			for (int i = 0; i<curr; i++)
				delete *courses[i];	
		}
};
int main(){
	Courses c1("EW", "el1002", 2);
	Courses c2("CAAG", "mt1003", 3);
	Courses c3("oop-lab", "cs11919", 1);	
	Student s1("23k-0022", "Arwa");
	s1.enroll(c1);
	s1.enroll(c2);
	s1.enroll(c3);
	s1.printEnrolledCourses();
	s1.drop(c1);
	s1.printEnrolledCourses();
}
