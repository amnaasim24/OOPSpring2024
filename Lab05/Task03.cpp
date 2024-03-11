/* Programmer: Amna Asim Khan
   Due Date: 7th March, 2024
   LAB 05
   Task 3
   Description:Create a class called ValidateString. The purpose of this class will be check if the given
characters in a string are alphabet only. Numbers and symbols will mean that the string is
invalid. By using a parameterized constructor, create multiple objects for your class that accept
different strings. Create a constant function that checks whether the string variable is valid or
not.
What happens if you do not make your function constant? Add a comment right above your
function explaining why we make a function constant.
*/



#include<iostream>
#include<string.h>
using namespace std;
class ValidateString{
	private:
		char* ptr;
		char* str;	
	public:
		ValidateString(char* sentence){
			str = new char[strlen(sentence)+1];
			strcpy(str, sentence);
		}
		~ValidateString(){
			delete[] str;
		}		
		const void checkString(){
			ptr = str;
			while(*ptr!='\0'){
				if(!(((*ptr)<91  && (*ptr)>64 )||((*ptr)<123  && (*ptr)>96 ))){
					cout<<"Invalid string"<<endl;
					return;
				}				
				ptr++;
			}
		}
};
int main(){
	ValidateString string1("Hem1@looo");
	string1.checkString();	
	ValidateString string2("Helooo");
	string2.checkString();	
	ValidateString string3("Hemlooo mic test 1234...");
	string3.checkString();
}
