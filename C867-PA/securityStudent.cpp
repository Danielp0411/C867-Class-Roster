#include <iostream>
#include "securityStudent.h"
using namespace std;

SecurityStudent::SecurityStudent():Student()
{
	dtype = Degree::SECURITY;
}

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string email, int age, int days[], Degree DegreeProgram)
	:Student(studentID, firstName, lastName, email, age, days, DegreeProgram)
{
	dtype = Degree::SECURITY;
}

Degree SecurityStudent::getDegreeProgram()
{
	return Degree::SECURITY;
}

void SecurityStudent::print()
{
	this->Student::print();
	cout << "SECURITY" << "\n";
}

SecurityStudent::~SecurityStudent()
{
	Student::~Student();
}