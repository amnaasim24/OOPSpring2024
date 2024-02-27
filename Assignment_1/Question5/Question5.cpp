/* Programmer: Amna Asim Khan
   ID: 23K-0859
   OBJECT ORIENTED PROGRAMMING (OOP) [Theory] 
   Assignment 1
   Question 5
   Description:Your task is to create a platform dedicated to connecting users with exciting BOGO (Buy One Get One)
deals offered by restaurants. This platform will make it effortless for people to discover and enjoy special
offers from various restaurants, allowing them to savor delicious meals with the added bonus of getting
another one for free.
Restaurant Class encapsulates key details and functionalities related to each restaurant. Features include:
restaurant_name, location, menu_list, price_list, valid_coupon_codes_list, and coupons_redeemed_count
(static variable),a static variable tracking the total number of coupons redeemed across all instances of the
Restaurant class.
Restaurant class must have following member functions:
? display_menu()
? generate_bill()
? apply_discount()

BOGOCoupon Class includes features related to coupons such as:
? coupon_code: Alphanumeric code representing the unique identity of each coupon.
? valid_from: The start date when the coupon becomes active.
? valid_until: The expiration date marking the end of the coupon's validity.
? restaurant_code: The prefix indicating the associated restaurant.
It must have the is_valid Method which validates whether the coupon is within its validity period. Also
checks if the coupon is associated with the selected restaurant.
User Class must have the following attributes name, age, mobile_number, coupons_list: A list containing
the BOGO coupons accumulated by the user, and redeemed_coupons_list.
It must have the following member functions:
? Accumulate_coupon(): Adds a new coupon to the user's list, acquired through various activities or
promotions.
? Has_valid_coupon(): Checks if the user has a valid unredeemed coupon for a specific restaurant
and item.
? redeem_coupon(): Validates the coupon code and ensures it hasn't been previously redeemed.
Main Details:
Two restaurants, namely Food Haven and Pixel Bites, are established with distinctive characteristics. Food
Haven, located in the City Center, offers a fusion of delightful dishes such as Sushi, Pad Thai, and Mango
Tango. On the other hand, Pixel Bites, situated in Cyber Street, entices users with its Digital Delicacies like
Binary Burger, Quantum Quinoa, and Data Donuts.
Users are invited to explore the diverse menu offerings of Food Haven and Pixel Bites through the
display_menu method. BOGO coupons are introduced with restaurant-specific codes. For instance, a

coupon with the code "FH-BOGO-12345" is associated with Food Haven, and another with "PB-BOGO-
67890" is linked to Pixel Bites. When placing an order, users employ the redeem_coupon process. The

system validates the coupon code, ensuring it corresponds to the selected restaurant and has not been
previously redeemed. Successful redemption allows users to enjoy a delightful BOGO offer on their orders,
contributing to a rich and immersive dining experience.
*/



#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstring> 
using namespace std;
class BOGOCoupon {
private:
    string coupon_code;
    string valid_from;
    string valid_until;
    string restaurant_code;
public:
    BOGOCoupon(string code, string from, string until, string restaurant)
        : coupon_code(code), valid_from(from), valid_until(until), restaurant_code(restaurant) {}   
  bool isValid() const {
    time_t currentTime = time(NULL);
    tm validFromTime = {}, validUntilTime = {};
    if (sscanf(valid_from.c_str(), "%4d%2d%2d", &validFromTime.tm_year, &validFromTime.tm_mon, &validFromTime.tm_mday) != 3 ||
        sscanf(valid_until.c_str(), "%4d%2d%2d", &validUntilTime.tm_year, &validUntilTime.tm_mon, &validUntilTime.tm_mday) != 3) {
        cerr << "Error parsing date." << endl;
        return false;
    }
    validFromTime.tm_year -= 1900; 
    validFromTime.tm_mon -= 1;     
    validUntilTime.tm_year -= 1900;
    validUntilTime.tm_mon -= 1;
    time_t validFromTimestamp = mktime(&validFromTime);
    time_t validUntilTimestamp = mktime(&validUntilTime);
    return currentTime >= validFromTimestamp && currentTime <= validUntilTimestamp;
}  
    string getRestaurantCode() const {
        return restaurant_code;
    }  
    string getCouponCode() const {
        return coupon_code;
    }
};
class Restaurant {
private:
    string restaurant_name;
    string location;
    string menu_list[3];
    double price_list[3];
    BOGOCoupon valid_coupon;
public: 
    Restaurant(string name, string loc, string menu[3], double prices[3], BOGOCoupon coupon)
        : restaurant_name(name), location(loc), valid_coupon(coupon) {
        for (int i = 0; i < 3; i++) {
            menu_list[i] = menu[i];
            price_list[i] = prices[i];
        }
    }    
    void displayMenu() const {
        cout << "Menu for " << restaurant_name << " at " << location << endl;
        for (int i = 0; i < 3; i++) {
            cout << menu_list[i] << "\t\t$" << fixed << setprecision(2)<<" "<<price_list[i] << endl;
        }
        cout << "-------------------------------------" << endl;
    } 
    string getRestaurantName() const {
        return restaurant_name;
    }    
    double generateBill(string ordered_items[3], BOGOCoupon& coupon) const {
        double totalBill = 0;
        if (coupon.isValid() && coupon.getRestaurantCode() == restaurant_name) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; ++j) {
                    if (ordered_items[i] == menu_list[j]) {
                        totalBill += price_list[j];
                        break;
                    }
                }
            }
        } 
        else {
            cout << "Invalid or expired coupon" << endl;
        }
        return totalBill;
    }
};
class User {
private:
    string name;
    int age;
    string mobile_number;
    BOGOCoupon coupons_list;
public:
    User(string n, int a, string mobile, BOGOCoupon& coupon) : name(n), age(a), mobile_number(mobile), coupons_list(coupon) {}
    bool hasValidCoupon(const Restaurant& restaurant, const string& item) const {
        return coupons_list.isValid() && coupons_list.getRestaurantCode() == restaurant.getRestaurantName();
    }
	void accumulateCoupon(const BOGOCoupon& coupon) {
    coupons_list = coupon;
	}   
    void redeemCoupon(Restaurant& restaurant, const string& item, const string& coupon_code) {
        if (coupons_list.getCouponCode() == coupon_code && hasValidCoupon(restaurant, item)) {
            cout << "Coupon redeemed successfully for " << item << " at " << restaurant.getRestaurantName() << endl;
        } 
        else {
            cout << "Invalid or expired coupon for " << item << " at " << restaurant.getRestaurantName() << endl;
        }
    }
};
int main() {
	cout<<"Amna Asim Khan"<<"23k-0859"<<endl;
    BOGOCoupon foodHavenCoupon("FH-BOGO-12345", "20220224", "20240301", "Food Haven");
    BOGOCoupon pixelBitesCoupon("PB-BOGO-67890", "20220224", "20240301", "Pixel Bites");
    string foodHavenMenu[3] = {"Sushi", "Pad Thai", "Mango Tango"};
    double foodHavenPrices[3] = {15.99, 12.49, 9.99};
    Restaurant foodHaven("Food Haven", "City Center", foodHavenMenu, foodHavenPrices, foodHavenCoupon);
    string pixelBitesMenu[3] = {"Binary Burger", "Quantum Quinoa", "Data Donuts"};
    double pixelBitesPrices[3] = {8.99, 10.49, 5.99};
    Restaurant pixelBites("Pixel Bites", "Cyber Street", pixelBitesMenu, pixelBitesPrices, pixelBitesCoupon);   
    User user("Rizwan Ahmed", 25, "1234567890", foodHavenCoupon);
    foodHaven.displayMenu();
    pixelBites.displayMenu();
    string orderedItem = "Sushi";
    string couponCode = "PB-BOGO-67890";
	string orderedItem2 = "Sushi";
    string couponCode2 = "FH-BOGO-12345";
    if (user.hasValidCoupon(foodHaven, orderedItem)==1) {  	
        user.redeemCoupon(foodHaven, orderedItem, couponCode);
    }
	if (user.hasValidCoupon(foodHaven, orderedItem)==0) {    	
        user.redeemCoupon(foodHaven, orderedItem, couponCode);
    }
	if (user.hasValidCoupon(foodHaven, orderedItem2)==1) {   	
        user.redeemCoupon(foodHaven, orderedItem2, couponCode2);
    }
	if (user.hasValidCoupon(foodHaven, orderedItem2)==0) {   	
        user.redeemCoupon(foodHaven, orderedItem2, couponCode2);
    }
    return 0;
}
