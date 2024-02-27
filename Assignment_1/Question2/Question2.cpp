/* Programmer: Amna Asim Khan
   ID: 23K-0859
   OBJECT ORIENTED PROGRAMMING (OOP) [Theory] 
   Assignment 1
   Question 2
   Description:You’re bored!
You’re looking at the students going in and out of the seating at the dhaba at FAST. You decide to think of
it as an OOP Scenario! You’re looking at the group of students arriving at the tables outside of the dhaba,
and making mental note of how long each group of student stays at a table. For the above scenario, let’s
write a program about the tables at the dhaba.
1. Each table has some properties:
? Total available seats per table (A table can only have 4 or 8 seats)
? Seats currently occupied at a table (assume only one person can occupy one seat)
? Free seats at a table
? Clean (Boolean flag representing the cleanliness of the table)
2. Each table can have some functionality associated with them:
? A default constructor – which should set the default table capacity to 4. Initially, a table will be
clean and no one will be seated on it.
? A parameterized constructor – which should set the capacity to the capacity sent as parameter. If
the number is not 4 or 8, it should be rounded to 4 or 8 (whichever is closest).
? Initially, a table will be clean and no one will be seated on it.
? Encapsulate the parameters of your class properly. The capacity should not be editable once it has
been set by the constructor.
? A table can be used by a group of friends – In order for the table to be used, the table must first be
clean. Whenever a group of friends is using the table, they will decide to use the table that can fit a
group of that size. (A group of 4 will be seated at a table with 4 seats, meanwhile a group of 6 will
be seated at a table with 8 seats).
? People can have lunch on the table – once the lunch is finished, the table will no longer be clean.
? People can leave the table with or without having lunch.
? Someone can clean the table – the table can only be cleaned when no one is seated at the table.
3. Create a global function called “OccupyTable” that accepts a Table array and size of the group of friends.
It should find a table that is not occupied and assign a table to those people. It should mention which table
has been assigned the group, and the seating capacity of the table.
4. Create a global function called “EmptyTable” that accepts a table number and sets it to empty. This
should make proper changes to the variables present within that table object.
5. In your main function, you are required to perform the following actions with your Table class:
? Create an array of 5 tables.
? Two tables should be of capacity 8, and 3 should be of capacity 4.
? Call the function OccupyTable and pass the array and 4 as its parameters. (Assume this is table 1)
? Call the function OccupyTable and pass the array and 6 as its parameters. (Assume this is table 2)

? For table 1, call the functions for:
? Using the table
? Having lunch on the table
? Leaving the table
? Cleaning the table
? Call the function EmptyTable and pass the index of table 2 as its parameter.
*/



#include <iostream>
using namespace std;
class Table {
private:
    const static int defaultCapacity = 4;
    int capacity;
    int freeSeats;
    int occupiedSeats;
    bool clean;
public:
    Table() {
        capacity = defaultCapacity;
        occupiedSeats = 0;
        freeSeats = defaultCapacity;
        clean = true;
    }
    Table(int capacity) {
        if (capacity < 6) {
            this->capacity = 4;
        } else {
            this->capacity = 8;
        }
        occupiedSeats = 0;
        freeSeats = this->capacity;
        clean = true;
    }
    int getCapacity(){
        return capacity;
    }
    int getFreeSeats(){
        return freeSeats;
    }
    int getOccupiedSeats(){
        return occupiedSeats;
    }
    bool isClean() {
        return clean;
    }
    bool useTable(int groupSize) {
        if (!clean || groupSize > capacity || groupSize > freeSeats) {
            cout << "Table cannot be used." <<endl;
            return false;
        }
        occupiedSeats = groupSize;
        freeSeats -= groupSize;
        clean = false;
        cout << "Table with capacity " << capacity << " has been occupied by a group of " << groupSize << "." <<endl;
        return true;
    }
    bool haveLunch() {
        if (!occupiedSeats || clean) {
            cout << "No one is seated or the table is already clean." << endl;
            return false;
        }
        cout << "Having lunch on the table..." <<endl;
        clean = false;
        return true;
    }
    bool leaveTable() {
        if (!occupiedSeats) {
            cout << "No one is seated at the table." <<endl;
            return false;
        }
        cout << "Leaving the table with " << occupiedSeats << " occupied seats." << endl;
        freeSeats += occupiedSeats;
        occupiedSeats = 0;
        return true;
    }
    bool cleanTable() {
        if (occupiedSeats) {
            cout << "Cannot clean the table while someone is seated." << endl;
            return false;
        }
        cout << "Cleaning the table..." << endl;
        clean = true;
        return true;
    }
};
void occupyTable(Table tableArray[], int groupSize) {
    for (int i = 0; i < 5; ++i) {
        if (tableArray[i].useTable(groupSize)) {
            return;
        }
    }
}
void emptyTable(Table& table) {
    table.leaveTable();
    table.cleanTable();
}
int main() {
	cout<<"Amna Asim Khan"<<"23k-0859"<<endl<<endl;
    Table tableArray[5];
    tableArray[0] = Table(8);
    tableArray[1] = Table(8);
    tableArray[2] = Table(4);
    tableArray[3] = Table(4);
    tableArray[4] = Table(4);
    occupyTable(tableArray, 4); 
    occupyTable(tableArray, 6);    
    tableArray[0].useTable(4);
    tableArray[0].haveLunch();
    tableArray[0].leaveTable();
    tableArray[0].cleanTable();
    emptyTable(tableArray[1]);
    return 0;
}
