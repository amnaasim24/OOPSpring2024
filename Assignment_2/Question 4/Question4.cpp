/* Programmer: Amna Asim Khan
   ID: 23K-0859
   BS-AI 2A
   OBJECT ORIENTED PROGRAMMING
   ASSIGNMENT # 2
   Task 4
   Description:You've been tasked with designing the core components of a social media app similar to
Instagram. The app will allow users to create profiles, post content, interact with posts (e.g.,
liking, commenting), and view their feed. There are different types of users, each with specific
functionalities and access levels.
Tasks:
User Class Design:
• Design a base class User to represent common attributes and functionalities shared by all
users, including username, email, and password.
• Implement user verification and password encryption to enhance security.
[Choose a suitable encryption algorithm (e.g., bcrypt, Argon2) for securely hashing passwords.]

Derived User Classes:
• Create derived classes for different types of users: RegularUser, and BusinessUser.
• Each derived class should inherit from the User class and provide specialized behavior
based on the user's role and access level.
o RegularUser Class:
? Limited Posting: Regular users can post a maximum of 5 posts. Implement logic
to enforce this limit.
? Interactions: Regular users can like posts, comment on posts, and view their feed.
• The RegularUser class maintains an array feed to store pointers to Post
objects.
• The addToFeed() method adds a post to the feed if there is space available.
• The viewFeed() method displays the posts in the feed by iterating over the
array and calling the display() method of each Post object.
• Note: max feed size is 10; static const int MAX_FEED_SIZE = 10;

o BusinessUser Class:
? Post Promotion: Business users can promote their posts to reach a larger audience.
Implement a method to promote posts.
• User Validation: Ensure that only BusinessUser objects can invoke the
promotePost() method.

• Promotion Limit: Apply a limit on the number of posts a business user can
promote. [let’s say 10 posts only]
• Post Visibility: A custom logic within the promotePost() method to
increase the post's likes by double and views by thrice.

? Analytics Integration: Enhance the User and Post classes to include the following
analytics functionalities:
• Likes Tracking: Implement methods to track and retrieve the number of
likes for each post.
• Comments Tracking: Implement methods to track and retrieve the number
of comments for each post.
• Views Tracking: Implement methods to track and retrieve the number of
views for each post.

Post Class Design:
• Define a class Post to represent individual posts in the app. Consider properties like
postId, content, likes, comments, etc., and methods for adding comments, liking posts,
and displaying post details.
Interaction Simulation:
• Simulate interactions within the app by creating instances of different types of users and
posts. Demonstrate how users can post content, interact with posts (e.g., liking,
commenting), and view their feed. Use polymorphism to ensure that the same methods
can be used uniformly across different user types.
*/



#include <iostream>
using namespace std;

class Post;
class RegularUser;
class BusinessUser;

void passwordEncryption(string& password) {
    string key = "nothing";
    for (int i = 0; i < password.length(); i++) {
        password[i] = password[i] ^ key[i % key.length()];
    }
}
void passwordDecryption(string& password) {
    passwordEncryption(password);
}
class Post {
      public:
             int postId;
             string content;
             int likes;
             string comments[100];
             int no_of_comments;
             int views;
             
             Post(int postId, string content) : content(content), postId(postId), likes(0), no_of_comments(0), views(0) {}

             void addingComments(string comment) {
                  comments[no_of_comments] = comment;
                  no_of_comments++;
             }
             void like() {
                  likes++;
             }
             void view() {
                  views++;
             }
             void setLikes(int x){
                  likes*=x;
             }  
             void setViews(int x){
                  views*=x;
             }
             void displaypostdetails() {
                  cout << "The post id is = " << postId << endl
                  << "content = " << content << endl
                  << "likes = " << likes << endl
                  << "no of Comments = " << no_of_comments << endl
                  << "views = " << views<<endl;
                  cout << endl;
             }
};
class User {
      public:
             string username;
             string email;
             string password;
             
             User(string username, string email, string password) : username(username), email(email), password(password) {}            
             virtual bool verifyUser(string inputPassword) = 0;
             void printVerificationMessage(bool verified) {
                  if (verified) {
                     cout << "User verified" << endl;
                  }
             }
};
class RegularUser : public User {
      public:
             int feedSize;
             static const int MAX_FEED_SIZE = 10;
             Post* feed[MAX_FEED_SIZE];

             RegularUser(string username, string email, string password) : User(username, email, password), feedSize(0) {}
             void addToFeed(Post &fe) {
                  if (feedSize <= 5) {
                     feed[feedSize] = &fe;
                     feedSize++;
                  }
                  else {
                       cout << "Regular User can post a maximum of 5 posts" << endl;
                       return;
                  }
             }
             void viewFeed() {
                  for (int i = 0; i < feedSize; i++) {
                      feed[i]->displaypostdetails();
                  }
             }
             bool verifyUser(string inputPassword) override {
                  string decryptedPassword = inputPassword;
                  passwordDecryption(decryptedPassword);
                  bool verified = decryptedPassword == password;
                  printVerificationMessage(verified);
                  return verified;
             }
};
class BusinessUser : public User {
      public:
             int promotionLimit = 10;
             static int countpromote;

             BusinessUser(string username, string email, string password) : User(username, email, password) {}
             void promotePost(Post &post) {
                  if (checkPromotionLimit(post)) {
                     cout << "Your post is promoted" << endl;
                     post.setLikes(2);
                     post.setViews(3);
                  }
             }
             bool checkPromotionLimit(Post &post) {
                  if (countpromote > promotionLimit) {
                     cout << "Can't promote more, the maximum post promotion limit reached" << endl;
                     return 0;
                  }
                  countpromote++;
                  return 1;
             }
             bool verifyUser(string inputPassword) override {
                  string decryptedPassword = inputPassword;
                  passwordDecryption(decryptedPassword);
                  bool verified = decryptedPassword == password;
                  printVerificationMessage(verified);
                  return verified;
             }
};
int BusinessUser::countpromote = 0;

int main() {
	cout<<"Amna Asim Khan"<<"23k-0859"<<endl;
    RegularUser regularUser("user1", "user1@example.com", "password1");
    BusinessUser businessUser("business1", "business1@example.com", "password2");
    cout << "User1 verified: " << regularUser.verifyUser("password1") << endl;
    cout << "User2 verified: " << businessUser.verifyUser("password2") << endl;
    Post post1(001, "Hello");
    Post post2(112, "Feeling happy");
    Post post3(113, "Completed my school");
    regularUser.addToFeed(post1);
    regularUser.addToFeed(post2);
    regularUser.addToFeed(post3);
    regularUser.viewFeed();
    post3.like();
    businessUser.promotePost(post3);
    post2.displaypostdetails();
    post3.displaypostdetails();
    return 0;
}
