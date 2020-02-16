#include <iostream>
#include "networkStudent.h"
using namespace std;

NetworkStudent::NetworkStudent() :Student()
{
	dtype = Degree::NETWORKING;
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string email, int age, int days[], Degree DegreeProgram)
	: Student(studentID, firstName, lastName, email, age, days, DegreeProgram)
{
	dtype = Degree::NETWORKING;
}

Degree NetworkStudent::getDegreeProgram()
{
	return Degree::NETWORKING;
}

void NetworkStudent::print()
{
	this->Student::print();
	cout << "NETWORKING" << "\n";
}

NetworkStudent::~NetworkStudent()
{
	Student::~Student();
}