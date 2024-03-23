/* Programmer: Amna Asim Khan
   Due Date: 21st March, 2024
   LAB 06
   Task 4
   Description:You have been asked to write a program that calculates the batting average and strike
rate for a cricket player. The program should take as input the total number of runs
scored by the player and the total number of balls faced, and should output the batting
average and strike rate.
To calculate the batting average, divide the total runs scored by the number of times
the player has been dismissed (i.e., gotten out). To calculate the strike rate, divide the
total runs scored by the total number of balls faced and multiply the result by 100.
To implement this program, create an inline function that takes the total number of
runs scored and the number of times the player has been dismissed as arguments,
and returns the batting average. Create another inline function that takes the total
number of runs scored and the total number of balls faced as arguments, and returns
the strike rate.
Demonstrate the functions using main function
*/



#include<iostream>
using namespace std;
inline double battingAverage(int totalRuns, int dismissed){
	double avg;
	avg = totalRuns/dismissed;
	return avg;
}
inline int strikeRate(int totalRuns, int totalBalls){
	int rate;
	rate = (totalRuns/totalBalls)*100;
	return rate;
}
int main(){
	int totalRuns;
	int totalBalls;
	int dismissed;	
	cout<<"Enter the total number of balls:";
	cin>>totalBalls;
	cout<<endl;
	cout<<"Enter the total number of runs:";
	cin>>totalRuns;
	cout<<endl;	
	cout<<"Enter the total number of player dismissal:";
	cin>>dismissed;
	cout<<endl;
	double avg;
	int rate;
	avg=battingAverage(totalRuns, dismissed);
	rate=strikeRate(totalRuns, totalBalls);	
	cout<<"The batting average is: "<<avg<<endl;
	cout<<"The strike rate is: "<<rate<<endl;
}
