/* Programmer: Amna Asim Khan
   ID: 23K-0859
   BS-AI 2A
   OBJECT ORIENTED PROGRAMMING
   ASSIGNMENT # 2
   Task 2
   Description:You are tasked with creating an inheritance hierarchy for a gaming environment. The
environment consists of different aspects of the game.
Class Player:
• Attributes: playerID (int), playerName (string), health (int)
• Parameterized constructor that sets the attributes playerID, playerName. Health is
initially initialized to 100 for the players.
Class Weapon:
• Attributes: weaponsList(contains a list of weapons)
• Constructor: Initialize the weapons list. The list should at least contain 5 or more
weapons
• use( ): the function asks the user which weapon they want to use from the available list of
weapons.
Class Character:
• Attributes: level (int), experience (string), points (int)
• Constructor: Parameterized constructor to set all attributes. Initial level and points are
always set to 0 and experience is always set to Beginner.
• Function: levelUp(), increments the level and experience. The level and experience is
incremented whenever the points are incremented by 10.
The following conditions are applied for experience:
1. If the experience is “Beginner” change the experience to “Intermediate”.
2. If the experience is “Intermediate” change the experience to “Advanced”.
3. If the experience is “Advanced” change the experience to “Expert”.
• Function: playGame() – The Character can play game by using any weapon to attack the
enemy. When a character attacks an enemy, the enemy’s health decrements by 5 and 10
are added to the points.
Class Enemy:
• Attributes: damage (int).
• Constructor: Parameterized constructor to set damage. Damage can be set from a value
ranging from 1 to 10.
• Function: void attack(), asks the users which weapon they want to use. When an enemy
attacks a character, the character’s health decrements by the damage amount.
In your main function, simulate the gaming environment and by showing all the experience
starting from “Beginner” to “Expert”.
*/



#include <iostream>
#include <vector>
using namespace std;

class Weapon {
      protected:
             string weaponsList[7];
      public:
             Weapon() {
                      weaponsList[0] = "Sword";
                      weaponsList[1] = "Axe";
                      weaponsList[2] = "Bow";
                      weaponsList[3] = "Dagger";
                      weaponsList[4] = "Staff";
                      weaponsList[5] = "Hammer";
                      weaponsList[6] = "Knife";
             }
             string use() {
                    int choice;
                    cout << "Available weapons (Enter a number between 0 and 6): ";
                    cin >> choice;
                    cout << endl;
                    if (choice >= 0 && choice <= 6) {
                    return weaponsList[choice];
                    }
                    else {
                         cout << "Invalid choice" << endl;
                         return "";
                    }
             }
};
class Player {
      protected:
             int playerID;
             string playerName;
             int health;
      public:
             Player(int Id, string name) : playerID(Id), playerName(name), health(100) {}
             int getPlayerID() {
                 return playerID;
             }
             string getPlayerName() {
                 return playerName;
             }
             int getPlayerHealth() {
                 return health;
             }
             void setPlayerHealth(int newHealth) {    
                 health = max(0, newHealth);
             }
};
class Character : public Player {
      protected:
             int level;
             string experience;
             int points;
      public:
             Character(string name, int ID, int level = 0, int points = 0, string experience = "Beginner") : Player(ID, name), level(level), points(points), experience(experience) {}	
             int getLevel() {
                 return level;
             }
             void setLevel(int newLevel) {
                  level = newLevel;
             }
             void levelUp() {
                  points += 10;
                  setLevel(++level);
                  if (points >= 10) {
                     if (experience == "Beginner") {
                        experience = "Intermediate";
                     }
                     else if (experience == "Intermediate") {
                          experience = "Advanced";
                     }
                     else if (experience == "Advanced") {
                          experience = "Expert";
                     }
                  }
             }
             void playGame(Weapon& weapon) {
                  string weaponName = weapon.use();
                  cout << endl << "Playing with " << experience << " level: " << level << " using " << weaponName << endl;
             }
             string getExperience() {
                    return experience;
             }
             void setExperience(string newExperience) {
                    experience = newExperience;
             }
};
class Enemy : public Character {
      protected:
             int damage;
             string name;
             int ID;
      public:
             Enemy(int dmg, string name, int id) : Character(name, id), damage(dmg) {}
             void attack(Player& player) {
                  int oldHealth = player.getPlayerHealth();
                  int newHealth = oldHealth - damage;
                  player.setPlayerHealth(newHealth);
                  cout << "Enemy attacked --> " << player.getPlayerName() << "'s health decreased by " << damage << endl;
             }
};
int main() {
    cout << "Amna" << endl << "23k-0859" << endl;
    Player player(1, "Player1");
    Character character("Character1", 2);
    Weapon weapon;
    Enemy enemy(5, "Enemy", 23);
    cout << "Experience progression:" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << "Current Experience: " << character.getExperience() << endl;
        character.levelUp();
        character.playGame(weapon);
        enemy.attack(player);
    }
    cout << player.getPlayerName() << "'s final health: " << player.getPlayerHealth() << endl;
    return 0;
}
