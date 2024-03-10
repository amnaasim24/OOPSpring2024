/* Programmer: Amna Asim Khan
   Date: 15th February, 2024
   LAB 04 
   Task 2
   Description:Revise the previous Book class by eliminating the parameterized constructor and enhancing the
   default constructor. The revised default constructor should initialize the page count to 1000
   and the pages read to 0 using a member initialization list. Generate setter methods for the
   remaining attributes and utilize them within the main function to update attribute values. Introduce
   a method called "showBookInfo" to exhibit all book details. Invoke this method from the main
   function for displaying book information.
*/



#include<iostream>
#include<cstdlib>
using namespace std;
class Book{
	string name;
	string author;
	string isbn;
	int totalpgs;
	int count;
	public:
		Book(): totalpgs(1000), count(0){
			name = "Unknown";
			author = "Unknown";
			isbn = "Unknown";
		}
		void setName(string name){
			this->name = name;
		}	
		void setAuthor(string author){
			this->author = author;
		}
		void setisbn(string number){
			this->isbn = number;
		}
		void setPages(int read){
			this->count = read;
		}
		int update(int pgs){
			count+=pgs;	
			if(count==totalpgs){
				cout<<"Name: "<<name<<endl;
				cout<<"Author: "<<author<<endl;
				cout<<"ISBN Number: "<<isbn<<endl;
				cout<<"Current pages read: "<<count<<endl;
				cout<<"Total pages: "<<totalpgs<<endl;
				cout<<"You have read all the pages";
			}	
			else if(count>totalpgs){
				cout<<"----------------------------------";
				cout<<"Invalid pages entered";
				cout<<"----------------------------------";
				return 0;
				exit(EXIT_FAILURE);
			}
		}
		int showBookInfo(){
			if(count>totalpgs){
				cout<<"----------------------------------";
				cout<<"Invalid pages entered";
				cout<<"----------------------------------";
				return 0;
				exit(EXIT_FAILURE);
			}
			else{
				cout<<"Name: "<<name<<endl;
				cout<<"Author: "<<author<<endl;
				cout<<"ISBN Number: "<<isbn<<endl;
				cout<<"Current pages read: "<<count<<endl;
				cout<<"Total pages: "<<totalpgs<<endl;
			}	
		}
};
int main(){
	Book b1;
	cout<<endl;
	b1.showBookInfo();
	b1.setName("To kill a mockingbird");
	b1.setAuthor("Anthony Hope Hawkins");
	b1.setisbn("009-987-778-0");
	b1.setPages(23);
	cout<<endl;
	b1.showBookInfo();
	b1.update(54);
	cout<<endl;
	b1.showBookInfo();	
}
