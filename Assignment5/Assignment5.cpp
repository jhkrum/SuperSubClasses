/*
Spring 2018, COP2272C.04 Computer Programming 1
Assignment 5
Purpose: To illustrate the workings between super and subclasses
Student Name: Justin Krum
*/

#include <iostream>
#include <string>
using namespace std;

//declare the data type of time zone
enum TimeZone { EST, CST, MST, PST };

//declare the super class
class Time
{
public:
	Time(); //default constructor which initializes a time to 00:00:00
	Time(int, int, int); //explicit constructor which initializes a time to given hr:min:sec
	void set(int, int, int); //change a time
	void write() const; //write a time in the hh:mm:ss format
private:
	int hr; //hour
	int min; //minute
	int sec; //second
};



//Implement super class member functions here

//Default Constructor
Time::Time() {
	hr = 0;
	min = 0;
	sec = 0;
}

//Paramatrized Constructor
Time::Time(int hour, int minute, int second) {
	hr = hour;
	min = minute;
	sec = second;
}

//Implementation of set(int,int,int)
void Time::set(int hour, int minute, int second) {
	hr = hour;
	min = minute;
	sec = second;
}

//Implementation of write()
void Time::write() const{
	printf("%02d:%02d:%02d", hr, min, sec);
}



//declare the subclass
class ExtTime : public Time
{
public:
	ExtTime(); //default constructor which initializes an extended time to 00:00:00 EST
	ExtTime(int, int, int, TimeZone); //explicit constructor which initializes an extended time to given hr:min:sec zone
	void set(int, int, int, TimeZone); //change an extended time
	void write() const; //write an extended time
private:
	TimeZone zone; //time zone
};



// Implement subclass member functions here

//Default Constructor
ExtTime::ExtTime() : Time(){
	zone = EST;
}

//Parametrized Constructor
ExtTime::ExtTime(int hour, int minute, int second, TimeZone tZone) : Time(hour,minute, second){
	zone = tZone;
}

//Implementation of set(int,int,int,TimeZone)
void ExtTime::set(int hour, int minute, int second, TimeZone tZone){
	Time::set(hour, minute, second);
	zone = tZone;
}

//Implementation of write()
void ExtTime::write() const {
	Time::write();
	switch (zone) {
	case 0:
		cout << " EST" << endl;
		break;
	case 1:
		cout << " CST" << endl;
		break;
	case 2:
		cout << " MST" << endl;
		break;
	case 3:
		cout << " PST" << endl;
		break;
	}
}


int main()
{
	ExtTime time1, //call default constructor
			time2(10, 26, 38, CST); //call explicit constructor

	//write time1 and time2

	time1.write(); //write 00:00:00 EST
	cout << endl;

	time2.write(); //write 10:26:38 CST
	cout << endl;

	//change time1
	time1.set(6, 28, 8, PST);

	//white time1 again
	time1.write(); //write 06:28:08 PST
	cout << endl;

	return 0; //successfully done
}