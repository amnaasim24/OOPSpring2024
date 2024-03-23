/* Programmer: Amna Asim Khan
   Due Date: 21st March, 2024
   LAB 06
   Task 2
   Description:Consider that You're working on Images to handle images in your graphics
application. Each Image object contains a pointer to image data stored in memory.
You are asked to create Image Class: The Image class represents an image with
width, height, and image data as private. The data member represents the image data
stored in memory. It's a pointer to a block of memory where the actual pixel values
of the image are stored.
Create Constructor: Constructor that initializes the width, height, and data pointer. It
dynamically allocates memory for the image data and copies the provided data. By
copying the provided image data, the Image class creates an independent copy of the
data. This means that modifications made to the original image data outside the class
won't affect the internal representation of the image within the Image object.
Create Copy constructor that creates a new Image object as a copy of another Image
object. It allocates memory for the image data and copies the data from the original
image.
Class must have Destructor that deallocates the memory allocated for the image
data.
Create void display(): Displays the image data.
Create the updateData function: that takes original image data and updates those
values which are 0 are less than 0 with any random value between the range of 1<=255
Main Function:
Create an Image object with dimensions 2x3 and initialize it with sample data.
Creates a copy of the original image.
Displays the data of both the original and copied images using the display() function.
After that call the updateData function and then call the display() function again to
verify that changes are made in both original and copied data.
*/



#include<iostream>
#include<cstdlib>
using namespace std;
class Image{
	private:
		int width;
		int height;
		int* imgData;		
	public:
		Image(double w, double h, int* data){
			this->width = w;
			this->height =h;			
			int size = width*height;
			imgData = new int[size];
			for(int i =0; i<size; i++){
				imgData[i] = data[i];
			}
		}
		Image(Image& obj2){
			this->width = obj2.width;
			this->height = obj2.height;			
			int size = width*height;
			imgData = new int[size];			
			for(int i =0; i<size; i++){
				imgData[i] = obj2.imgData[i];			}
		}		
		~Image(){
			delete []imgData;
		}		
		void display(){
			cout<<"Image Data: "<<endl;
			for(int i =0; i<width*height; i++){
				cout<<imgData[i]<<"\t";
				if((i+1)%width==0){
					cout<<endl;
				}
			}
		}	
		void updateData(){
			for(int i =0; i<width*height; i++){
				if(imgData[i]<=0){
					imgData[i]=rand()%255+1;
				}
			}
		}
};
int main(){
	int imgData[] = {1,2,66,78};
	Image original(2,3 ,imgData);
	Image copy = original;	
	cout<<"Original Image: "<<endl;
	original.display();	
	cout<<"Copied image: "<<endl;
	copy.display();	
	original.updateData();
	cout<<"Updated original image data:"<<endl;
	original.display();	
	cout<<"Updated copy image data:"<<endl;
	copy.display();	
	return 0;
}
