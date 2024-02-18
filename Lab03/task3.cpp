/* Programmer: Amna Asim
   ID: 23K-0859
   Date: 16th February, 2024
   Lab 03
   Task # 3
   Description:Craft a class denominated "Calendar."
   This Calendar class should possess 12 arrays, each representing a month of the year, along
   with a variable storing information about the current year.
   Users can allocate tasks for each day, with one entry allowed per day.
   Incorporate the following methods within this class:
   • Addition of a task: This function accepts task details, date, and month as parameters
   and adds the task to the specified day.
   • Removal of a task: Accepts the date and month as parameters to eliminate the task.
   • Display tasks: This method traverses through all months and prints the allocated
   tasks.
   
   Instantiate a calendar object, input 5-6 tasks manually, demonstrate task removal, and display
   the updated task list.
*/



#include <iostream>
#include <string>
using namespace std;

class Calender{
private:
    static const int month = 12;
    static const int days = 31;
    string arr[month][days];
    int currentYear;

public:
    
    Calender(int year) : currentYear(year) {
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 31; j++){
                arr[i][j] = "";
            }
        }
    }

    void add(string task, int month, int day){
        if(month >= 1 && month <= 12 && day >= 1 && day <=31){
            arr[month-1][day-1] = task;
            cout << "-----------Task added successfully----------" << endl;
        } else {
            cout << "Invalid input!!!!" << endl;
        }
    }

    void remove(int month, int day){
        if(month >= 1 && month <= 12 && day >= 1 && day <=31){
            arr[month-1][day-1] = "";
            cout << "----------Task deleted successfully----------" << endl;
        } else {
            cout << "Invalid input" << endl;
        }
    }

    void display(){
        cout << "\nTasks are \n" ;
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 31; j++){
                string task = arr[i][j];
                if(!task.empty()){
                    cout << task << " on " << j + 1 << " - " << i + 1 << " - " << currentYear << endl;
                }
            }
        }
    }
};

int main(){
    Calender calendar1(2024);
	calendar1.display();
	//cout<<"-------------------------------------";
    calendar1.add("Car wash", 2, 4);
    calendar1.add("Hanging curtains", 4, 31);
    calendar1.add("to delete", 1, 2);
    calendar1.remove(1, 2);
    calendar1.add("Doing dishes", 5, 4);
	
    calendar1.display();

    return 0;
}
