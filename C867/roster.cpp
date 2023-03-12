#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

#include "degree.h"
#include "student.h"
#include "roster.h"

//roster size
int Roster::rosterSize() {
	return sizeof(classRosterArray) / sizeof(Student);
}


//add and remove functions
void Roster::add(string studentID, string firstName, string lastName, string email, int age, int day1, int day2, int day3, DegreeProgram degree) {
	int daysLeft[3] = { day1, day2, day3 };
	int* pDaysLeft = daysLeft;
	classRosterArray[tracker].setFirstName(firstName);
	classRosterArray[tracker].setStudentID(studentID);
	classRosterArray[tracker].setLastName(lastName);
	classRosterArray[tracker].setEmail(email);
	classRosterArray[tracker].setAge(age);
	classRosterArray[tracker].setDays(pDaysLeft);
	classRosterArray[tracker].setDegree(degree);
	tracker++;
}


void Roster::remove(string studentID) {
	bool success = false;
	for (int i = 0; i < rosterSize(); i++) {
		if (classRosterArray[i].getStudentID() == studentID) {
			//removing student from array
			classRosterArray[i].~Student();
			cout << "Removed Student " << studentID << endl;
			success = true;
			break;
		}
	}
	if (success == false) {
		cout << "Did not find matching Student ID" << endl;
	}
}

//print functions
void Roster::printAll() {
	printAttributeType a = pAll;
	cout << "Roster Size: " << rosterSize() << endl;
	for (int i = 0; i < rosterSize(); i++) {
		classRosterArray[i].print();
		cout << "." << endl;
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	bool success = false;
	for (int i = 0; i < rosterSize(); i++) {
		if (classRosterArray[i].getStudentID() == studentID) {
			int* tempArray = classRosterArray[i].getDays();
			double average = 0;
			cout << "Average Days in Course for " << classRosterArray[i].getStudentID() << " " << classRosterArray[i].getFirstName() << " "
				<< classRosterArray[i].getLastName() << ": ";
			for (int j = 0; j < 3; j++) {
				average = average + tempArray[j];
			}
			average = average / 3;
			cout << average << endl;
			success = true;
			break;
		}
	}
	if (success = false) {
		cout << "Did not find matching Student ID" << endl;
	}
}

void Roster::printByDegreeProgram(DegreeProgram degree) {
	printAttributeType a = pAll;
	cout << "Students studying this degree: \n";
	for (int i = 0; i < rosterSize(); i++) {
		if (classRosterArray[i].getDegree() == degree) {
			classRosterArray[i].print();
			cout << "\n";
		}
	}
	cout << "\n";
}

void Roster::printInvalidEmails() {
	//regex email format
	const regex emailFormat("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

	cout << "Invaldi Emails: ";
	for (int i = 0; i < rosterSize(); i++) {
		if ((regex_match(classRosterArray[i].getEmail(), emailFormat)) == false) {
			cout << classRosterArray[i].getEmail() << "\t";
		}
	}
	cout << "\n";
}

//constructor function
Roster::Roster() {
}

//destructor function
Roster::~Roster() {
	cout << "Roster destructor activated" << endl;
}