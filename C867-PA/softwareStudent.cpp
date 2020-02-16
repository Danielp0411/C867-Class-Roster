#include <iostream>
#include "softwareStudent.h"
using namespace std;

SoftwareStudent::SoftwareStudent() :Student()
{
	dtype = Degree::SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string email, int age, int days[], Degree DegreeProgram)
	: Student(studentID, firstName, lastName, email, age, days, DegreeProgram)
{
	dtype = Degree::SOFTWARE;
}

Degree SoftwareStudent::getDegreeProgram()
{
	return Degree::SOFTWARE;
}

void SoftwareStudent::print()
{
	this->Student::print();
	cout << "SOFTWARE" << "\n";
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
}