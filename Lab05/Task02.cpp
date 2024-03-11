/* Programmer: Amna Asim Khan
   Due Date: 7th March, 2024
   LAB 05
   Task 2
   Description:Create a class called LoanHelper, which helps the user calculate their loan payments. The
class should have a variable that stores interest rate for the loan as a user defined constant
value. Aside from the that, it also stores the amount for the loan taken and amount of months
that the user will repay the loan in. The loan repayment should be calculated on a monthly
basis, and the interest rate should be applied over the monthly return amount. The output
should be something like:
“You have to pay 999 every month for 12 months to repay your loan”
Note: first divide loan amount by number of months, then apply the interest rate on it. Interest
rate should be a value between 0-0.5%
*/



#include<iostream>
using namespace std;
class LoanHelper{
	const float rate;
	float amount;
	int monthsLoan;	
	public:
		LoanHelper(float userRate, float amount, int monthsLoan):rate(userRate), amount(amount), monthsLoan(monthsLoan){
			if(userRate<=0 || userRate>=0.005){
				cout<<"Not a valid rate"<<endl;
				return;
			}
		}	
		void calculateAmount(){
			float amountToPay;
			float interest;
			float monthlyPayment;
			monthlyPayment = amount/monthsLoan;
			interest = monthlyPayment*interest;
			amountToPay=monthlyPayment+interest;
			cout<<"You have to pay "<<amountToPay<<" every month for "<<monthsLoan<<" months to repay your loan."<<endl;
		}
};
int main(){
	cout<<"Amna Asim Khan"<<"23k-0859"<<endl;
	LoanHelper Loan1(0.003, 13000, 6);
	Loan1.calculateAmount();
}
