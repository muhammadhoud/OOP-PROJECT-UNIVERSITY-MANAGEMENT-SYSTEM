//TO FIRST TIME RUN THE PROGRAM TO TEST:
//
//FOR STUDENT:-
//USERNAME: GORDON123
//PASSWORD: JLJIJJIJJ345
//
//FOR TEACHER:-
//USERNAME: HAPO1234
//PASSWORD: PASS1234
//
//FOR ADMIN:-
//USERNAME: Admin
//PASSWORD: Admin123

#pragma once

#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>
#include <sstream>

using namespace std;

// Class declaration for Admin
class Admin
{
protected:
	string username;  // Admin username
	string password;  // Admin password
private:
	// Teacher attributes
	string t_id;
	string t_firstname;
	string t_lastname;
	string t_department;
	string tuser_name;
	string tpassword;
	string date;
	string t_gender;
	string t_number;
	string t_qualification;
	string address;

	// Student attributes
	string s_id;
	string s_firstname;
	string s_lastname;
	string s_department;
	string rollno;
	string suser_name;
	string spassword;
	string s_date;
	string s_gender;
	string s_number;
	string s_address;
	string fee;
	string s_qualification;
	string s_marks;

public:
	// Function declarations for Admin operations
	void signin();        // Admin sign in
	void addteacher();    // Add teacher
	void addstudent();    // Add student
	void editstudent();   // Edit student details
	void editteacher();   // Edit teacher details
	void viewstudent();   // View all students
	void viewteacher();   // View all teachers
};

// Class declaration for Student
class Student
{
private:
	// Student attributes
	string firstName, lastName, id, dept, srollno, user, pass, date, gender, phone, address, fee, quali, marks;
public:
	// Function declarations for Student operations
	void sign_in_student();             // Student sign in
	void view_attendance();             // View attendance
	void view_marks();                  // View marks
	void view_grades();                 // View grades
	void view_registered_courses();     // View registered courses
	void view_fee_status();             // View fee status
};

// Derived class declaration for Teacher inheriting Admin
class Teacher :public Admin
{
private:
	string t_username;      // Teacher username
	string t_password;      // Teacher password
	string firstname;
	string lastname;
	Student std;
	string id, dept;
public:
	// Function declarations for Teacher operations
	Teacher();               // Constructor
	void signin();           // Teacher sign in
	void timetable();        // View timetable
	void markingattendance();  // Mark attendance
	void assignmarks();      // Assign marks
	void assigngrades();     // Assign grades
};
