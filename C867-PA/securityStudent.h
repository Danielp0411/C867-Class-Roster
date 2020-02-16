#pragma once
#include "student.h"
using namespace std;

class SecurityStudent : public Student //rubric D3: create subclass of Student
{

public:
	SecurityStudent();
	SecurityStudent(
		string studentID,
		string firstName,
		string lastName,
		string email,
		int age,
		int days[],
		Degree DegreeProgram
	);

	Degree getDegreeProgram();
	void print();

	~SecurityStudent();
};