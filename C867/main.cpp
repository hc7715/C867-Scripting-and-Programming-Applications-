#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <sstream>
#include "degree.h"
#include "student.h"
#include "roster.h"

using namespace std;

int main()
{
	//class, code, name, and id
	cout << "Scripting and Programming Applications C867 \n";
	cout << "C++ \n";
	cout << "hchen22\n";
	cout << "Hao Chen\n";

	//creating instance of roster class called classRoster
	Roster classRoster;

	//input data
	const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Hao,Chen,hchen22@wgu.edu,22,10,15,20,SOFTWARE" };

	//using string stream to read studentData
	for (int i = 0; i < (sizeof(studentData) / sizeof(studentData[0])); i++) {
		vector<string> input;
		stringstream tempStream(studentData[i]);
		while (tempStream.good()) {
			string subString;
			getline(tempStream, subString, ','); //gets the string until comma
			input.push_back(subString);
		}
		//test purposes only *COMMENT OUT LATER*
		/*
		for (int j = 0; j < input.size(); j++) {
			cout << input[j] << endl;
		}
		*/

		//making temporary DegreeProgram Enum to be used in roster add function
		DegreeProgram tempDegree;
		if (input[8] == "SECURITY") {
			tempDegree = SECURITY;
		}
		else if (input[8] == "NETWORK") {
			tempDegree = NETWORK;
		}
		else if (input[8] == "SOFTWARE") {
			tempDegree = SOFTWARE;
		}
		else {
			tempDegree = NONE;
		}
		

		classRoster.add(input[0], input[1], input[2], input[3], stoi(input[4]), stoi(input[5]), stoi(input[6]), stoi(input[7]), tempDegree);

	}
	//print all
	classRoster.printAll();
	cout << "\n";
	//print invalid emails
	classRoster.printInvalidEmails();
	cout << "\n";
	//print average days
	for (int i = 0; i < classRoster.rosterSize(); i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i].getStudentID());
	}
	cout << "\n";
	//print by degree course
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << "\n";
	//removal
	classRoster.remove("A3");
	classRoster.printAll();
	cout << "\n";
	classRoster.remove("A3");
	cout << "\n";
	//expected: the above line should print a message saying such a student with this ID was not found.
	



	return 0;
}

