/* Programmer: Amna Asim Khan
   Due Date: 23rd March, 2024
   LAB 08
   Task 1
   Description:You are designing a library system using C++. You have a class called "Book" with attributes
like title, author, and publisher. Now, you want to create a derived class called
"FictionBook" which inherits from the "Book" class and has additional attributes like genre
and protagonist.
a) Define the "Book" class with the following attributes:
? title (string)
? author (string)
? publisher (string)
? Define the constructor for the "Book" class which initializes the attributes.
? Define a function called "display" inside the "Book" class which displays the
details of the book.

b) Create a derived class called "FictionBook" which inherits from the "Book" class and
has the following additional attributes:
? genre (string)
? protagonist (string)
? Define the constructor for the "FictionBook" class which initializes the
attributes of the base class as well as the derived class.
? Define a function called "display" inside the "FictionBook" class which
displays the details of the book, including the additional attributes.
? In the main function, create an object of the "FictionBook" class and display its
details.
*/



#include<iostream>
using namespace std;
class Book{
	protected:
		string title;
		string author;
		string publisher;
	public:
		Book(string title, string author, string publisher):title(title),author(author),publisher(publisher){
		}		
		void display(){
			cout<<"Title: "<<title<<endl;
			cout<<"Author: "<<author<<endl;
			cout<<"Publisher: "<<publisher<<endl;
        }
};
class FictionBook:public Book{
	private:
		string genre;
		string protagonist;	
	public:
		FictionBook(string ttl, string atr, string pbl, string genre, string protagonist):Book(ttl, atr, pbl), genre(genre), protagonist(protagonist){}		
		void display(){
			cout<<"Title: "<<title<<endl;
			cout<<"Author: "<<author<<endl;
			cout<<"Publisher: "<<publisher<<endl;
			cout<<"Genre: "<<genre<<endl;
			cout<<"Protagonist: "<<protagonist<<endl;	
		}		
};
int main(){
	FictionBook f1("Animal Farm"," George Orwell","Jane smith","Fiction","Markus Zusac");
	f1.display();
}
