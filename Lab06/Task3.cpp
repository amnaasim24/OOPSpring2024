/* Programmer: Amna Asim Khan
   Due Date: 21st March, 2024
   LAB 06
   Task 3
   Description:You have been hired to develop a program for a hair salon that keeps track of
appointments made, total earnings, and the average cost per appointment using
static members and functions.,
Your task is to define a class that represents an appointment at the salon. The class
should have private data members that store information about the appointment, and
static data members that keep track of the total number of appointments made and
the total earnings from all appointments.
Define a constructor for the appointment class that takes arguments for the
appointment details and updates the static data members accordingly. Additionally,
you should define public member functions that allow access to the appointment
details.
Finally, you should define a static function that calculates and returns the average
cost of all the appointments made. This function should use the static data members
to perform the calculation.
In the main function, you should create several instances of the appointment class
with different appointment details, and then call the static function to calculate the
average cost of all the appointments made. This will allow you to verify that the
program is correctly keeping track of appointments and earnings
*/



#include <iostream>
using namespace std;
class Appointment{  
      static int total_appointments;
      static double total_earning;
             string app_type;
      public:
             Appointment(string app,double cost){
                    this->app_type=app;
                    total_earning+=cost;
                    total_appointments++;
             }

             static float Avg_Cost(){    
                    float avg_cost;
                    if(total_appointments==0)
                    return 0;
                    avg_cost=total_earning/total_appointments;
                    return avg_cost;
             }
             void change_app(string app){
                  this->app_type=app;
             }
};
int Appointment::total_appointments=0;
double Appointment::total_earning=0;
int main(){
Appointment App1("hair wash",3040);
Appointment App2("hair dye",565);
cout<<"Avrage Cost is "<<Appointment::Avg_Cost()<<endl;
return 0;
}
