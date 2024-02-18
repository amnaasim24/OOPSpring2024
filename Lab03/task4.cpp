/* Programmer: Amna Asim
   ID: 23K-0859
   Date: 14th February, 2024
   Lab 03
   Task # 4
   Description: Forge a class labelled "Smartphone" possessing the following attributes:
   • Brand
   • Model
   • Display Resolution
   • RAM
   • ROM
   • Storage
   Develop getter and setter methods for these attributes. Additionally, define specific actions
   smartphones can perform, such as:
   • Making phone calls
   • Sending messages
   • Connecting to Wi-Fi
   • Browsing the internet
   Create distinct smartphone objects, set their attributes using setter functions, and exhibit
   their attributes after retrieving them using getter functions.
*/



#include<iostream>
using namespace std;

class Smartphone{
	private:
		string brand;
		string model;
		string resolution;
		string ram;
		string rom;
		string storage;
		
	public:
		
		void set(string brand, string model, string resolution, string ram , string rom, string storage)
		{
			this->brand = brand;
			this->model = model;
			this->resolution = resolution;
			this->ram = ram;
			this->rom = rom;
			this->storage = storage;
		}
		
		void get()
		{
			cout<<"-------------DISPLAYING YOUR PHONE'S INFOMATION-------------------"<<endl;
			cout<<"Brand: "<<brand<<endl;
			cout<<"Model: "<<model<<endl;
			cout<<"Display resolution: "<<resolution<<endl;
			cout<<"RAM: "<<ram<<endl;
			cout<<"ROM: "<<rom<<endl;
			cout<<"Storage:  "<<storage<<endl;
			cout<<endl;
		}
		
		void makePhoneCall(string number)
		{
			cout<<"Calling "<<number<<" ......."<<endl;
		}
		
		void sendMsg(string number)
		{
			string msg;
			cout<<"Type the message: ";
			cin>>msg;
			cout<<endl;
			cout<<"Message sent to "<<number<<endl;
			
		}
		
		void wifi(string Wifi)
		{
			cout<<"Connecting to "<<Wifi<<" network"<<endl;
			
		}
		
		void browse(string browser)
		{
			cout<<"Browsing on "<<browser<<" with your "<<brand<<" "<<model<<endl;
		}
};

int main()
{
	Smartphone phone1;
	phone1.set("Samsung","Galaxy A32","1080x2400 pixels, 20:9 ratio","128GB","8GB", "64GB of internal memory");
	phone1.get();
	phone1.makePhoneCall("12345678909");
	phone1.sendMsg("12345678909");
	phone1.wifi("PTCL-BB");
	phone1.browse("Opera");
	
	Smartphone phone2;
    phone2.set("Apple", "iPhone 13", "2532x1170 pixels, 19.5:9 ratio", "256GB", "6GB", "128GB of internal memory");
    phone2.get();
    phone2.makePhoneCall("9876543210");
    phone2.sendMsg("9876543210");
    phone2.wifi("Home-WiFi");
    phone2.browse("Safari");
    
     Smartphone phone3;
    phone3.set("Google", "Pixel 6", "1080x2340 pixels, 20:9 ratio", "128GB", "6GB", "No additional memory card slot");
    phone3.get();
    phone3.makePhoneCall("5551234567");
    phone3.sendMsg("5551234567");
    phone3.wifi("Public-WiFi");
    phone3.browse("Chrome");

    return 0;
}
