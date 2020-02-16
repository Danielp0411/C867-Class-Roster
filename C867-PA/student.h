#pragma once
#include <string>
#include "degree.h"
using namespace std;

class Student //rubric D1: Student class.
{
public:
	const static int daysArraySize = 3;

protected: //visible to derived classes
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int days[daysArraySize]; //days will be an array of size 3
	Degree dtype;

public:

	Student(); //empty constructor
	Student(string ID, string firstName, string lastName, string email, int age, int days[], Degree DegreeProgram); // rubric D2c: full constructor, including enum Degree (as directions state).

	//rubric D2a: getters
	string getID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDays();
	virtual Degree getDegreeProgram() = 0; //rubric D2f: virtual getDegreeProgram()

	//rubric D2b: setters
	void setID(string ID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDays(int days[]);

	virtual void print() = 0; //rubric D2d: void print()

	~Student(); //rubric D2e: destructor
};