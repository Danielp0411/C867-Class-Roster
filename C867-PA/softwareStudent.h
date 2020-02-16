#pragma once
#include "student.h"
using namespace std;

class SoftwareStudent : public Student //rubric D3: create subclass of Student
{

public:
	SoftwareStudent();
	SoftwareStudent(
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

	~SoftwareStudent();
};
