/* Programmer: Amna Asim
   ID: 23K-0859
   Date: 15th February, 2024
   Lab 03
   Task # 5
   Description:Construct a class for a stationary shop.
   This class maintains lists for all items it sells (hint: an array of strings) and their corresponding
   prices (hint: an array of prices).
   Design a menu-driven program to:
   • Enable the shop owner to add items and their prices.
   • Retrieve the list of items.
   • Modify the prices of items.
   • Display all items along with their prices.
   Generate a receipt that the shopkeeper can share with customers. This receipt can only be
   generated after the shopkeeper inputs the items and their quantities bought by the customer.
*/



#include<iostream>
#include<vector>
using namespace std;

class Stationary{
	private:
		vector<string> items;
		vector<int> price;
	
	public: 
		void add(string product, int worth)
		{
			items.push_back(product);
			price.push_back(worth);
		}
		
		void modify(string product, int worth)
		{
			for(int i =0; i< items.size(); i++)
			{
				if(items[i]==product)
				{
					price[i]=worth;
				}
			}
		}
		
		void display()
		{
			cout<<"ITEMS\t"<<"PRICES"<<endl<<endl;
			for(int i =0; i<items.size(); i++)
			{
				cout<<items[i]<<"\t"<<price[i]<<endl;
			}
		}
		
		void retrieve()
		{
			cout<<"Following is the list of all the item\n";
			for(int i=0; i<items.size(); i++)
			{
				cout<<items[i]<<endl;
			}
		}
		
		double reciept()
		{
			int qty = 0;
			double bill = 0;
			cout<<"Enter the number of items: ";
			cin>>qty;
			int prodqty=1;
			string product;
			for(int i =0; i<qty; i++)
			{
				cout<<"\nEnter the name of product: ";
				cin>>product;
				cout<<"\nEnter the quantity of this product: ";
				cin>>prodqty;
				
				for(int j =0; j<items.size(); j++)
				{
					if(items[j]==product)
					{
						bill+=price[j]*prodqty;
						break;
					}
				}
			}
			
			return bill;
		}
};

int main()
{
	Stationary s1;
	int choice;
	cout<<"\n--------------------WELCOME TO THE SHOP--------------------\n";
	
	int number;
	string name;
	double price;
	string old;
	double Newprice;
			
	while(number!=6)
	{
		cout<<"1. Add items\n2. Modify items\n3. Retrieve items\n4. Display all the items\n5. Generate bill\n6. Exit\n";
		cin>>choice;
		switch(choice)
	{
		case 1:
			
			cout<<"\nEnter the name of item: ";
			cin>>name;
			cout<<"\nEnter the price of item: ";
			cin>>price;
			
			s1.add(name, price);
			break;
			
		case 2:
			
			cout<<"\nEnter the item to modify: ";
			cin>>old;
			cout<<"\nEnter the new price: ";
			cin>>Newprice;
			s1.modify(old, Newprice);
			break;
			
		case 3:
			s1.retrieve();
			break;
			
		case 4:
			s1.display();
			break;
			
		case 5:
			cout<<"\nYour bill is: "<<s1.reciept()<<" Rs/-"<<endl;
			
			break;
			
		case 6:
			return 0;
			
		default:
			cout<<"Invalid input";
	}
	}

	return 0;
}
