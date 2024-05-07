/* Programmer: Amna Asim Khan
   ID: 23K-0859
   OBJECT ORIENTED PROGRAMMING (OOP) [Theory] 
   Assignment 3
   Question 1
   Description: Times Medico is committed to providing customers with prescribed medicines
efficiently. With various categories of medicines and specialized staff roles, Times
Medico ensures smooth operations while maintaining revenue. Being a
programmer, You have to design classes with following details
1) Medicine Class: Attributes: name, formula, retail price, manufacture
date, expiration date.
• Functions:
• Constructor(s) to initialize attributes.

• Getters and setters for attributes.
• Virtual function for printing medicine details.

2) Tablet Class (Derived from Medicine): Additional Attribute: sucrose level
(0 to 1).
a. Functions:
i. Constructor(s) to initialize Tablet-specific attributes.
ii. Overridden function for printing tablet details.

3) Capsule Class (Derived from Medicine):
a. Additional Attribute: absorption percentage (1 to 100).
b. Functions:
i. Constructor(s) to initialize Capsule-specific attributes.
ii. Overridden function for printing capsule details.

4) Syrup Class (Derived from Medicine):
• Functions:
• Constructor(s) to initialize Syrup-specific attributes.
• Overridden function for printing syrup details.

5) Pharmacist Class
• Functions:
• Search_Medicine() to search and print medicine details based
on formula.
6) Counter Class
• Functions:
• Search_Medicine() to search and print medicine details based
on name.
• Update_Revenue() to update overall revenue.

• Flow of operation:
The customer enters the medico and presents a prescription to the counter
staff. The counter staff forwards this prescription to the pharmacist who
checks and recommends the appropriate medicine type. The counter staff
then collects the payment, hands over the medicines and updates the overall
revenue.
• Tasks to be performed:
• Identify all the classes, attributes and functions in the above scenario.
Only make a skeleton of classes and give prototypes of functions.
• Overload the "= =" operator to compare two medicines and find if
both are going to expire in the same year.
*/



#include <iostream>
#include <string>
using namespace std;

class Date {
public:
    Date(int day, int month, int year) : day(day), month(month), year(year) {}

    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }

    string toString() {
        return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
    }

private:
    int day;
    int month;
    int year;
};

class Medicine {
public:
    Medicine(string name, string formula, double retailPrice, Date manufactureDate, Date expirationDate)
        : name(name), formula(formula), retailPrice(retailPrice), manufactureDate(manufactureDate), expirationDate(expirationDate) {}

    virtual void printDetails() = 0;

    string getName() { return name; }
    string getFormula() { return formula; }
    double getRetailPrice() { return retailPrice; }
    Date getManufactureDate() { return manufactureDate; }
    Date getExpirationDate() { return expirationDate; }

    void setName(string name) { this->name = name; }
    void setFormula(string formula) { this->formula = formula; }
    void setRetailPrice(double retailPrice) { this->retailPrice = retailPrice; }
    void setManufactureDate(Date manufactureDate) { this->manufactureDate = manufactureDate; }
    void setExpirationDate(Date expirationDate) { this->expirationDate = expirationDate; }

    bool operator==(const Medicine& other) {
        return expirationDate.getYear() == other.expirationDate.getYear();
    }

private:
    string name;
    string formula;
    double retailPrice;
    Date manufactureDate;
    Date expirationDate;
};

