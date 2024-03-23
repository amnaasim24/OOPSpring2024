/* Programmer: Amna Asim Khan
   Due Date: 21st March, 2024
   LAB 06
   Task 1
   Description:Consider a banking system where you have a BankAccount class representing
individual accounts. Each BankAccount object contains a pointer to an array of
transactions representing the account history.
For that, create class BankAccount which contains the private member variables int
accountId, double balance to store account information., int* transactionHistory is a
pointer to an array storing transaction history and int numTransactions used to
stores the number of transactions.
Also, the class should have the following Public Member Functions:
Constructor that initializes account information and allocates memory for the
transaction history, copying provided transactions.
Copy constructor that creates a new BankAccount object as a copy of another
BankAccount object, including its transaction history.
Destructor that deallocates memory allocated for the transaction history.
display() Function: function to output the account details including the account ID,
balance, and transaction history.
updateTransactionHistory() Function:
This function updates the transaction history of the BankAccount object.
It deletes the existing transaction history, allocates memory for the new transaction
history, and copies the new transaction data into the allocated memory.
Main Function:
Create a BankAccount object with initial account details and transaction history.
Create a copy of the original account.
Displays the details of both the original and copied accounts using the display()
function.
Now , call updateTransactionHistory() Function to update the transaction history of
the original account to observe the changes.
Now call the display function to see the changes.
*/ 



#include<iostream>
using namespace std;
class BankAccount{
	private:
		int accountId;
		double balance;
		int* transactionHistory;
		int numTransaction;
	public:
		BankAccount(int accountId, double balance, int* transactions, int number){
			this->accountId=accountId;
			this->balance = balance;
			this->numTransaction=number;			
			transactionHistory=new int[number];
			for(int i =0; i<number;i++){
				this->transactionHistory[i]=transactions[i];
			}
		}
		BankAccount(BankAccount& obj2){
			this->accountId=obj2.accountId;
			this->balance = obj2.balance;
			this->numTransaction=obj2.numTransaction;			
			transactionHistory=new int[numTransaction];
			for(int i =0; i<numTransaction;i++){
				this->transactionHistory[i]=obj2.transactionHistory[i];
			}
		}		
		~BankAccount(){
			delete []transactionHistory;
		}		
		void display(){
			cout<<"---------DISPLAYING ACCOUNT DETAILS--------"<<endl;
			cout<<"Account ID: "<<accountId<<endl;
			cout<<"Current Balance: "<<balance<<endl;
			cout<<"Transaction history: "<<endl;			
			for(int i =0; i<numTransaction; i++){
				cout<<transactionHistory[i]<<"\t";
			}
			cout<<endl;
		}	
		void updateTransactionHistory(int* newTransactions, int newNumber){
			delete []transactionHistory;			
			transactionHistory=new int[newNumber];			
			for(int i =0; i<newNumber; i++){
				transactionHistory[i] = newTransactions[i];
			}
		}
};
int main(){
	int transactions[]={1200, 130, 500}
	;int size = sizeof(transactions)/sizeof(transactions[0]);	
	BankAccount account1(123456, 23000, transactions, size);
	BankAccount account2 = account1;	
	cout<<"Account 1: "<<endl;
	account1.display();
	cout<<"Account 2: "<<endl;
	account2.display();	
	int newTransactions[]= {-900, 800, 65};
	int newSize = sizeof(newTransactions)/sizeof(newTransactions[0]);
	account1.updateTransactionHistory(newTransactions, newSize);	
	cout<<"After updating"<<endl;
	cout<<"Account 1: "<<endl;
	account1.display();
	cout<<"Account 2: "<<endl;
	account2.display();	
	return 0;
}
