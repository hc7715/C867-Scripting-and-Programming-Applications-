#pragma once
#include <string>
using namespace std;

class Student {
	private:
		//the variables (not accessible outside of the class without the setter/getters)
		string studentID;
		string firstName;
		string lastName;
		string email;
		int age;
		int days[3];
		DegreeProgram degree;
		

	public:

		//constructors
		Student(string a_studentID, string a_firstName, string a_lastName, string a_email, int a_age, int* a_days, DegreeProgram a_degree);
		Student(); //default value 

		//getter fucntions
		string getStudentID();
		string getFirstName();
		string getLastName();
		string getEmail();
		int getAge();
		int * getDays();
		DegreeProgram getDegree();

		//setter functions
		void setStudentID(string a_studentID);
		void setFirstName(string a_firstName);
		void setLastName(string a_lastName);
		void setEmail(string a_email);
		void setAge(int a_age);
		void setDays(int* a_days);
		void setDays(int day1, int day2, int day3);
		void setDegree(DegreeProgram a_degree);

		//print function
		void print(printAttributeType a);
		void print();

		//destructor
		~Student();

};

