#include<iostream>
#include<iomanip>
#include "student.h"
using namespace std;

Student::Student() //empty constructor for default values
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < daysArraySize; i++) this->days[i] = 0;
}

Student::Student(string ID, string firstName, string lastName, string email, int age, int days[], Degree DegreeProgram) //full constructor
{
	this->studentID = ID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < daysArraySize; i++) this->days[i] = days[i];
}

//getters
string Student::getID()
{
	return studentID;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmail()
{
	return email;
}

int Student::getAge()
{
	return age;
}

int* Student::getDays()
{
	return days;
}

//setters
void Student::setID(string ID)
{
	studentID = ID;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setEmail(string email)
{
	this->email = email;
}

void Student::setAge(int age)
{
	this->age = age;
}

void Student::setDays(int days[])
{
	for (int i = 0; i < daysArraySize; i++) 
		this->days[i] = days[i];
}

void Student::print()
{
	cout << left << "ID: " << setw(5) << getID();
	cout << left << "First: " << setw(10) << getFirstName();
	cout << left << "Last: " << setw(10) << getLastName();
	cout << left << "Age: " << setw(5) << getAge();
	cout << left << "daysInCourse: {";
	cout << left << setw(3) << getDays()[0];
	cout << left << setw(3) << getDays()[1];
	cout << left << getDays()[2] << "}" << setw(3) << " Degree Program: ";
}

Student::~Student()
{

}