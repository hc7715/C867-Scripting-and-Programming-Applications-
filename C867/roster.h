#pragma once


class Roster
{
public:
	//tracker to know where to add next Student information
	int tracker = 0;

	//array
	Student classRosterArray[5];

	//size
	int rosterSize();

	//add and remove functions
	void add(string studentID, string firstName, string lastName, string email, int age, int day1, int day2, int day3, DegreeProgram degree);


	void remove(string studentID);

	//print functions
	void printAll();

	void printAverageDaysInCourse(string studentID);

	void printByDegreeProgram(DegreeProgram degree);

	void printInvalidEmails();

	//constructor function
	Roster();

	//destructor function
	~Roster();

};