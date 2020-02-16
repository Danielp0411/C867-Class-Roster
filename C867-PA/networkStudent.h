#pragma once
#include "student.h"
using namespace std;

class NetworkStudent : public Student //rubric D3: create subclass of Student
{

public:
	NetworkStudent();
	NetworkStudent(
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

	~NetworkStudent();
};