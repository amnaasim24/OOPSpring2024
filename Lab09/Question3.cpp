/*Programmer: Amna Asim Khan
   LAB 09
   Question 3
   Description:You are tasked with creating a payroll management system for a small company. The system
needs to handle two types of employees: full-time employees and part-time employees. Each
type of employee has different attributes and methods associated with them. Full-time
employees receive a fixed salary per month, while part-time employees are paid based on the
number of hours they work.
Define a base class named Employee with the following attributes and methods:
Attributes:
employee ID, employee name.
Methods:
virtual double calculatePay() const: This method calculates and returns the pay for the
employee. Since this method's implementation depends on the type of employee, it should be
declared as virtual and have a default implementation (e.g., returning 0.0).
virtual void displayDetails() const: This method displays the details of the employee
(ID and name).
Implement two derived classes: FullTimeEmployee and PartTimeEmployee.
FullTimeEmployee should inherit from the Employee class and have an additional attribute
for the monthly salary.
PartTimeEmployee should also inherit from the Employee class and have attributes for the
hourly wage and the number of hours worked.
Override the calculatePay() method in both derived classes:
In FullTimeEmployee, calculate the pay by simply returning the monthly salary.
In PartTimeEmployee, calculate the pay by multiplying the hourly wage with the number of
hours worked.
Override the displayDetails() method in both derived classes to display the additional
attributes along with the base class attributes.

In the main function:
 Create instances of FullTimeEmployee and PartTimeEmployee.
 Call the displayDetails() method for each instance to display their details.
 Call the calculatePay() method for each instance to calculate and display their pay.

 Demonstrate early or static binding by calling the calculatePay() method using a base
class pointer.
Approach:
1. Define the Employee base class with the required attributes and virtual methods.
2. Implement derived classes (FullTimeEmployee and PartTimeEmployee) inheriting
from the Employee class and override their virtual methods.
3. Use dynamic polymorphism to handle different types of employees by using base class
pointers.
4. In the main function, create instances of both derived classes and call their methods to
demonstrate polymorphic behavior.
5. Use a base class pointer to call the calculatePay() method and observe early or static
binding in action.
*/



#include<iostream>
using namespace std;
class Employee{
	protected:
		string employeeID, employeeName;
	public:
		Employee(string ID, string name){
			this->employeeID=ID;
			this->employeeName= name;
		}		
		virtual double calculatePay() const{return 0.0;}		
		virtual void displayDetails() const{}
};
class FullTimeEmployee: public Employee{
	private:
		int monthlysalary;		
	public:
		FullTimeEmployee(string Id, string name, int monthlysalary):Employee(Id, name), monthlysalary(monthlysalary){}
		double calculatePay() const{
		    return monthlysalary;
		}
		void displayDetails() const{
			cout<<"Name of the employee: "<<employeeName<<endl;
			cout<<"Employee ID: "<<employeeID<<endl;
			cout<<"Type: Full time employee"<<endl;
			cout<<"Monthly Salary: "<<calculatePay()<<endl;
		}
};
class PartTimeEmployee:public Employee{
	private:
		int hourlyWage;
		int hours;
		double calculatePay() const{
		    return hourlyWage*hours;
		}
	public:
		PartTimeEmployee(string id, string name, int wage, int hours):Employee(id, name),hourlyWage(wage),hours(hours){}
		void displayDetails() const{
			cout<<"Name of the employee: "<<employeeName<<endl;
			cout<<"Employee ID: "<<employeeID<<endl;
			cout<<"Type: Part-time employee"<<endl;
			cout<<"Hourly pay: "<<hourlyWage<<endl;
			cout<<"Hours worked: "<<hours<<endl;
			cout<<"Total pay: "<<calculatePay()<<endl;
		}
};
int main(){
	FullTimeEmployee Anwar("23k-0001", "Anwar", 25000);
	PartTimeEmployee Sajid("23i-0090","Sajid",200, 4);	
	cout<<"Full time employee details: "<<endl;
	Anwar.displayDetails();
	cout<<endl<<endl;
	cout<<"Part time employee details: "<<endl;
	Sajid.displayDetails();	
	cout<<endl<<"USING BASE CLASS POINTER:"<<endl;
	Employee* emp1;
	Employee* emp2;	
	emp1=&Anwar;
	emp2=&Sajid;
	cout<<"Full time employee payment: "<<emp1->calculatePay()<<endl;
	cout<<"Part time employee payment: "<<emp2->calculatePay()<<endl;	
}