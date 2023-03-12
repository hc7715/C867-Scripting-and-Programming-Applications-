#include <iostream>

using namespace std;

#include "degree.h"
#include "student.h"

//getter functions

	 string Student::getStudentID() {
		return studentID;
	}

	 string Student::getFirstName() {
		 return firstName;
	}

	 string Student::getLastName() {
		 return lastName;
	}

	 string Student::getEmail() {
		 return email;
	}

	 int Student::getAge() {
		 return age;
	}

	 int* Student::getDays() {
		 return days;
	}

	DegreeProgram Student::getDegree() {
		return degree;
	}


//setter functions

	void Student::setStudentID(string a_studentID) {
		studentID = a_studentID;
	}

	void Student::setFirstName(string a_firstName) {
		firstName = a_firstName;
	}

	void Student::setLastName(string a_lastName) {
		lastName = a_lastName;
	}

	void Student::setEmail(string a_email) {
		email = a_email;
	}

	void Student::setAge(int a_age) {
		age = a_age;
	}

	void Student::setDays(int* a_days) {
		for (int i = 0; i < 3; i++) {
			days[i] = *(a_days + i);
		}
	}

	void Student::setDays(int day1, int day2, int day3) {
		days[0] = day1;
		days[1] = day2;
		days[2] = day3;
	}

	void Student::setDegree(DegreeProgram a_degree) {
		degree = a_degree;
	}


//constructor 

	Student::Student(string a_studentID, string a_firstName, string a_lastName, string a_email, int a_age, int* a_days, DegreeProgram a_degree) {
		studentID = a_studentID;
		firstName = a_firstName;
		lastName = a_lastName;
		email = a_email;
		age = a_age;

		//initialize days array
		for (int i = 0; i < 3; i++) {
			days[i] = *(a_days + i);
		}

		degree = a_degree;
		cout << "Student Constructor Activated" << endl;
	}

	//default constructor
	Student::Student() {
		studentID = "Blank";
		firstName = "Blank";
		lastName = "Blank";
		email = "Blank";
		age = 0;
	}

//destructor
	Student::~Student() {
		cout << "Destructor Activated" << endl;
	}


//print function

	void Student::print(printAttributeType a) {

		switch (a) {
		case pStudentID:
			cout << "ID: " << studentID << endl;
			break;

		case pFirstName:
			cout << "First Name: " << firstName << endl;
			break;

		case pLastName:
			cout << "Last Name: " << lastName << endl;
			break;

		case pEmail:
			cout << "Email: " << email << endl;
			break;

		case pAge:
			cout << "Age: " << age << endl;
			break;

		case pDays:
			cout << "Days left:";
			for (int i = 0; i < sizeof(days) / sizeof(days[0]); i++) {
				cout << " " << days[i];
			}
			cout << endl;
			break;

		case pDegree:
			cout << "Degree: ";
			switch (degree) {
			case SECURITY:
				cout << "Security" << endl;
				break;

			case SOFTWARE:
				cout << "Software" << endl;
				break;

			case NETWORK:
				cout << "Network" << endl;
				break;

			case NONE:
				cout << "N/A" << endl;
				break;
				
			}
			break;

		case pAll:
			cout << "ID: " << studentID << "\t";
			cout << " First Name: " << firstName << "\t";
			cout << " Last Name: " << lastName << "\t";
			cout << " Email: " << email << "\t";
			cout << " Age: " << age << "\t";
			cout << " Days In Course: {";
			for (int i = 0; i < sizeof(days) / sizeof(days[0]); i++) {
				cout << " " << days[i];
			}
			cout << "} \t";
			cout << " Degree: ";
			switch (degree) {
			case SECURITY:
				cout << "Security";
				break;

			case SOFTWARE:
				cout << "Software";
				break;

			case NETWORK:
				cout << "Network";
				break;

			case NONE:
				cout << "N/A";
				break;

				break;
				
			}
		}
	}

	void Student::print() {
		cout << "ID: " << studentID << "\t";
		cout << " First Name: " << this->firstName << "\t";
		cout << " Last Name: " << this->lastName << "\t";
		cout << " Email: " << this->email << "\t";
		cout << " Age: " << this->age << "\t";
		cout << " Days In Course: {";
		for (int i = 0; i < sizeof(days) / sizeof(days[0]); i++) {
			cout << " " << days[i];
		}
		cout << "} \t";
		cout << " Degree: ";
		switch (degree) {
		case SECURITY:
			cout << "Security";
			break;

		case SOFTWARE:
			cout << "Software";
			break;

		case NETWORK:
			cout << "Network";
			break;

		case NONE:
			cout << "N/A";
			break;

			break;

		}
	}







