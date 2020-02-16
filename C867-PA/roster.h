#pragma once
#include "Student.h"
#include <array>

class Roster {
private:

	//rubric E1: array of pointers
	int lastIndex;
	int capacity;

public:
	Student** classRosterArray;
	Roster();
	Roster(int capacity);
	void parseThenAdd(string row);
	void add(string studentID, string firstName, string lastName, string email, int age, int day0, int day1, int day2, Degree DegreeProgram); //sets the instance variables from part D1 and updates the roster.
	bool remove(string studentID); // removes students from the roster by student ID. If ID does not exist, the function prints an error message.
	void printAll(); //prints a complete tab-separated list of student data using accessor functions 
	void printDaysInCourse(string studentID); //prints student’s average number of days in the three courses.
	void printInvalidEmails(); //verifies student email addresses and displays all invalid email addresses to the user
	void printByDegreeProgram(Degree degreeProgram); //prints out student information for a degree program specified by an enumerated type
	~Roster();
};
