#include <sstream>
#include <iostream>
#include "roster.h"
#include "Student.h"
#include "Degree.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"
using namespace std;

Roster::Roster() //empty constructor
{
	this->lastIndex = -1;
	this->capacity = 0;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity)
{
	this->lastIndex = -1;
	this->capacity = capacity;
	this->classRosterArray = new Student * [capacity];
}


//rubric E3a
void Roster::parseThenAdd(string row)
{
	if (lastIndex < capacity) {
		lastIndex++;
		Degree DegreeProgram;
		if (row[4] == 'o') {
			DegreeProgram = Degree::SECURITY;
		}
		else if (row[4] == 'r') {
			DegreeProgram = Degree::SECURITY;
		}
		else if (row[4] == 'u') {
			DegreeProgram = Degree::NETWORKING;
		}
		else {
			DegreeProgram = Degree::SOFTWARE;
		}

		//parse student ID
		int rhs = row.find(",");
		string sID = row.substr(0, rhs);
		//parse first name
		int lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string fName = row.substr(lhs, rhs - lhs);
		//parse last name
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string lName = row.substr(lhs, rhs - lhs);
		//parse email
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string eAddr = row.substr(lhs, rhs - lhs);
		//parse age
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int a = stoi(row.substr(lhs, rhs - lhs));
		//parse each of the days
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int day0 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int day1 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int day2 = stoi(row.substr(lhs, rhs - lhs));

		add(sID,fName,lName,eAddr,a,day0,day1,day2,DegreeProgram);

	}
}

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int day0, int day1, int day2, Degree DegreeProgram)
{
	int Days[Student::daysArraySize];
	Days[0] = day0;
	Days[1] = day1;
	Days[2] = day2;
	if (DegreeProgram == Degree::SECURITY) {
		classRosterArray[lastIndex] = new SecurityStudent(studentID, firstName, lastName, email, age, Days, DegreeProgram);
	}
	else if (DegreeProgram == Degree::NETWORKING) {
		classRosterArray[lastIndex] = new NetworkStudent(studentID, firstName, lastName, email, age, Days, DegreeProgram);
	}
	else if (DegreeProgram == Degree::SOFTWARE) {
		classRosterArray[lastIndex] = new SoftwareStudent(studentID, firstName, lastName, email, age, Days, DegreeProgram);
	}
}
//rubric E3b
bool Roster::remove(string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getID() == studentID)
		{
			found = true;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
		}
	}
	if (!found) {
		cout << "The student ID: " << studentID << " was not found!" << "\n";
	}
	return found;
}

//rubric E3c
void Roster::printAll() {
	for (int i = 0; i <= this->lastIndex; i++) {
		(this->classRosterArray)[i]->print();
	}
	cout << "\n";
}
//rubric E3d
void Roster::printDaysInCourse(string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getID() == studentID)
		{
			found = true;
			int* d = classRosterArray[i]->getDays();
			cout << "Average days in a course for student ID: " << studentID << " is " << (d[0] + d[1] + d[2]) / 3 << "\n";
		}
	}
	if (!found)
	{
		cout << "Student not found!\n";
	}
}
//rubric E3e
void Roster::printInvalidEmails()
{
	cout << "Displaying invalid emails:\n";
	for (int i = 0; i <= lastIndex; i++) {
		bool foundAt = false;
		bool foundPeriod = false;
		bool foundSpace = false;
		string email = "";
		email = (*classRosterArray[i]).getEmail();
		for (char& f : email) {
			if (f == '@') {
				foundAt = true;
			}
			if (f == '.') {
				foundPeriod = true;
			}
			if (f == ' ') {
				foundSpace = true;
			}
		}
		if (foundAt == false) {
			cout << (*classRosterArray[i]).getEmail() << " - missing an @ symbol.\n";
		}
		if (foundPeriod == false) {
			cout << (*classRosterArray[i]).getEmail() << " - missing a period.\n";
		}
		if (foundSpace == true) {
			cout << (*classRosterArray[i]).getEmail() << " - no spaces allowed.\n";
		}
	}
	cout << "\n";
}
//rubric E3f
void Roster::printByDegreeProgram(Degree degreeProgram)
{
	cout << "Displaying students in program: " << DegreeStrings[(int)degreeProgram] << "\n";
	for (int i = 0; i <= lastIndex; ++i) 
	{
		if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram)
		{
			this->classRosterArray[i]->print();
		}
	}
	cout << "\n";
}
//Rubric F5
Roster::~Roster()
{
	for (int i = 0; i <= lastIndex; ++i)
	{
		delete this->classRosterArray[i]; //deletes each student
	}
	delete classRosterArray; //deletes array of pointers
}



int main()
{	//rubric F1
	cout << "Scripting and Programming Applications - C867" << endl;
	cout << "C++" << endl;
	cout << "Student ID: 001044985" << endl;
	cout << "Daniel Phillips" << endl;
	cout << endl;
	int numStudents = 5;
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Daniel,Phillips,Dphi134@wgu.edu,22,28,35,40,SOFTWARE"
	};

	//rubric F2
	Roster* classRoster = new Roster(numStudents);
	cout << "Parsing data and adding students:\t";
	//rubric F3
	for (int i = 0; i < numStudents; i++)
	{
		classRoster->parseThenAdd(studentData[i]);
	}
	cout << "DONE.\n";
	cout << "Displaying all students:\n";
	//rubric F4
	classRoster->printAll();
	classRoster->printInvalidEmails();

	for (int i = 0; i < numStudents; ++i) {
		classRoster->printDaysInCourse(classRoster->classRosterArray[i]->getID());
	}
	cout << "\n";

	classRoster->printByDegreeProgram(Degree::SOFTWARE);
	cout << "Removing student ID: A3!" << "\n";
	classRoster->remove("A3");
	cout << "Done!" << "\n" << "\n";
	classRoster->remove("A3");
	return 0;

	//rubric F5
	classRoster->~Roster();
}