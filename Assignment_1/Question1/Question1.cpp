/* Programmer: Amna Asim Khan
   ID: 23K-0859
   OBJECT ORIENTED PROGRAMMING (OOP) [Theory] 
   Assignment 1
   Question 1
   Description: You are tasked with designing a platform named Virtual Pet Adoption System where users can adopt and
care for virtual pets with advanced capabilities. The system comprises two essential classes: "Pet" and
"Adopter." Your goal is to implement the system with extended features to enhance user experience and
satisfaction.
Pet Class:
The Pet class represents virtual pets available for adoption. It has following features:
? healthStatus: A string indicating the health status of the pet (e.g., "Healthy," "Sick").
? hungerLevel: An integer representing the pet's hunger level.
? happinessLevel: An integer representing the pet's happiness level.
? specialSkills: A list containing special skills possessed by the pet.
Implement the following member functions within the Pet class:
? displayPetDetails(): Displays detailed information about the pet, including happiness level, health
status, hunger level, and special skills.
? updateHappiness(): Updates the pet's happiness level based on user interactions.
? updateHealth(): Updates the health status of the pet, considering any changes in health.
? updateHunger(): Updates the hunger level of the pet, accounting for feeding or other relevant
actions.
Moreover, if a pet is hungry their happiness also decreases by 1 and vice versa. And if you feed it the
happiness increases by 1 upto max 10 happiness.
Adopter Class:
The Adopter class serves as a representation of users who are enthusiastic about adopting virtual pets. In
order to enrich the functionality of this class, you are tasked with incorporating the following features:
adopterName and adopterMobileNum, these attributes should be initialized during the creation of an
Adopter object. A list named adoptedPetRecords within the Adopter class. This list should be responsible
for maintaining detailed records of the adopted pets by the respective adopter.
Implement the following member functions within the Adopter class:
? adoptPet(): Allows the adopter to adopt a virtual pet and records its details.
? returnPet(): Enables the adopter to return a pet, updating records accordingly.
? displayAdoptedPets(): Displays detailed information about all adopted pets, including their species,
happiness, health, hunger, and skills.
Create instances of the extended Pet class, showcasing diverse characteristics and skills for virtual pets.
Instantiate objects of the enhanced Adopter class to represent users interested in adopting virtual pets.
Demonstrate the functionalities of both classes by simulating the adoption, care, and interaction with virtual
pets.                                                                      
*/



#include <iostream>
#include <sstream>
using namespace std;
class Pet {
private:
    int hungerLevel;
    int happinessLevel;
    int size;
    string healthStatus;
    string* specialSkills;
public:
   Pet(string health = "", int hunger = 0, int happiness = 0, int size = 0, const string skills[] = NULL)
        : healthStatus(health), happinessLevel(happiness), hungerLevel(hunger), size(size) {
        specialSkills = new string[size];
        if (skills != NULL) {
            for (int i = 0; i < size; i++) {
                specialSkills[i] = skills[i];
            }
        }
    }
    string displayPetDetails(int num) const {
        stringstream ss;
        ss << "Displaying info for pet " << num << endl;
        ss << "Health Status: " << healthStatus << endl;
        ss << "Hunger Level: " << hungerLevel << endl;
        ss << "Skills:" << endl;
        for (int i = 0; i < size; i++) {
            ss << specialSkills[i] << endl;
        }
        return ss.str();
    }
    void updateHappiness(int num) {
        if (happinessLevel < 10) {
            happinessLevel++;
        }
    }
    void updateHunger(int num) {
        hungerLevel += num;
        updateHappiness(happinessLevel - 1);
    }
    void updateHealth(string updatedHealth) {
        healthStatus = updatedHealth;
    }
    void feedPet() {
        if (happinessLevel < 10) {
            happinessLevel++;
        }
        if (hungerLevel > 0) {
            hungerLevel--;
        }
    }
    ~Pet() {
        delete[] specialSkills;
    }
};
class Adopter {
private:
    string adopterName;
    string adopterMobileNum;
    Pet adoptedPetRecords[3];
    bool slotsEmpty[3];
public:
    Adopter(string name, string mobileNum) : adopterName(name), adopterMobileNum(mobileNum) {
        for (int i = 0; i < 3; i++) {
            slotsEmpty[i] = true;
        }
    }
    void adoptPet(const Pet& pet) {
        for (int i = 0; i < 3; ++i) {
            if (slotsEmpty[i]) {
                adoptedPetRecords[i] = pet;
                slotsEmpty[i] = false;
                cout << adopterName << " has adopted a new pet!\n";
                return;
            }
        }
        cout << "Sorry, " << adopterName << " cannot adopt more pets.\n";
    }
    void returnPet(const Pet& pet) {
        for (int i = 0; i < 3; ++i) {
            if (!slotsEmpty[i] && &adoptedPetRecords[i] == &pet) {
                adoptedPetRecords[i] = Pet("", 0, 0, 0);
                slotsEmpty[i] = true;
                cout << adopterName << " has returned the pet.\n";
                return;
            }
        }
        cout << "Pet not found in adopted records.\n";
    }
    void displayAdoptedPets() const {
        cout << adopterName << "'s Adopted Pets:\n";
        for (int i = 0; i < 3; i++) {
            if (!slotsEmpty[i]) {
                cout << adoptedPetRecords[i].displayPetDetails(i + 1) << endl;
                cout << "-----------------------------\n";
            }
        }
    }
};
int main() {
    string dogSkills[] = { "Fetch", "Sit" };
	Pet dog("Healthy", 5, 5, 2, dogSkills);
	string catSkills[] = { "Climbing", "Purring" };
	Pet cat("Healthy", 6, 4, 2, catSkills);
    Adopter john("John", "123-456-789");
    Adopter alice("Alice", "987-654-321");
    john.adoptPet(dog);
    alice.adoptPet(cat);
    john.displayAdoptedPets();
    alice.displayAdoptedPets();
    john.returnPet(dog);
    john.displayAdoptedPets();
}
