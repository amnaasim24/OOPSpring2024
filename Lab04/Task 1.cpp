/* Programmer: Amna Asim Khan
   Date: 15th February, 2024
   LAB 04 
   Task 1
   Description:Construct a class representing a Book, encompassing attributes like name, author, ISBN number,
		and total page count, along with a variable tracking the number of pages read. Tasks include
		defining constructors for the Book class - one default constructor and another parameterized
		constructor initializing all attributes. Values can be hardcoded within the main function.
		Additionally, implement a method to update the pages read, triggering a display of "You have
		finished the book" when all pages are read. This method should be called from the main
		function to monitor reading progress.
*/




#include <iostream>
using namespace std;

class Book {
	string name;
	string author;
	int ISBN;
	int total_page_count;
	int pages_read;
	
	public:
		Book(){
			name = "Amna";
			author = "Dan Brown";
			ISBN = 012345;
			total_page_count = 300;
			pages_read = 150;
		}
		void PagesUpdate(int NewPages){
			
		}
};

int main() {

	return 0;
}








