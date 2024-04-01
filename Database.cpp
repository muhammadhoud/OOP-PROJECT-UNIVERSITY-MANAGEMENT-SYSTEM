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

#include "Database.hpp"
//--------------------Admin Class Functions--------------------
void Admin::signin() {
	char f;
	bool found = false;
	ifstream file("Admin.txt");
	if (!file.is_open()) {
		cout << "Error! Unable to open file.\n";
		return;
	}

	string user, pass, username, password;
	cout << "PLEASE INPUT THE USERNAME:    ";
	cin >> username;
	cout << "PLEASE INPUT THE PASSWORD:    ";
	cin >> password;

	while (getline(file, user, ',')) {
		getline(file, pass);

		if (username == user && password == pass) {
			found = true;
			break;
		}
	}

	if (found) {
		cout << "THE USERNAME AND PASSWORD ARE CORRECT" << endl;
		cout << "YOU CAN PROCEED" << endl;
		cout << "PRESS ANY KEY TO CONTINUE" << endl;
		f = _getch();
		file.close();

		char j = 'y';
		while (j != 8)
		{
			system("cls");
			system("Color C7");
			cout << endl << "1.    PRESS 1 TO ADD TEACHER" << endl;
			cout << "2.    PRESS 2 TO ADD STUDENT" << endl;
			cout << "3.    PRESS 3 TO EDIT TEACHER" << endl;
			cout << "4.    PRESS 4 TO EDIT STUDENT" << endl;
			cout << "5.    PRESS 5 TO VIEW ALL TEACHERS" << endl;
			cout << "6.    PRESS 6 TO VIEW ALL STUDENTS" << endl;
			cout << "7.    PRESS BACKSPACE <------ TO EXIT ADMIN MODULE" << endl;
			j = _getch();
			if (j == '1')
			{
				addteacher();
			}
			else if (j == '2')
			{
				addstudent();
			}
			else if (j == '3')
			{
				editteacher();
			}
			else if (j == '4')
			{
				editstudent();
			}
			else if (j == '5')
			{
				viewteacher();
			}
			else if (j == '6')
			{
				viewstudent();
			}
			else if (j != 8)
			{
				cout << endl << "PLEASE PRESS VALID NUMBER" << endl;
			}
		}
	}
	else {
		cout << "USERNAME OR PASSWORD IS INCORRECT" << endl;
	}

}
void Admin::addteacher()
{
	char f;
	cout << "PLEASE INPUT THE ID OF TEACHER    ";
	cin >> t_id;
	cout << "PLEASE INPUT THE FIRST NAME OF TEACHER    ";
	cin >> t_firstname;
	cout << "PLEASE INPUT THE LAST NAME OF TEACHER    ";
	cin >> t_lastname;
	cout << "PLEASE INPUT THE DEPARTMENT OF TEACHER    ";
	cin >> t_department;
	cout << "PLEASE INPUT THE USER NAME OF TEACHER    ";
	cin >> tuser_name;
	cout << "PLEASE INPUT THE PASSWORD OF TEACHER    ";
	cin >> tpassword;
	cout << "PLEASE INPUT THE REGISTERATION DATE OF TEACHER    ";
	cin >> date;
	cout << "PLEASE INPUT THE GENDER OF TEACHER    ";
	cin >> t_gender;
	cout << "PLEASE INPUT THE NUMBER OF TEACHER    ";
	cin >> t_number;
	cout << "PLEASE INPUT THE QUALIFICATION OF TEACHER    ";
	cin >> t_qualification;
	cout << "PLEASE INPUT THE CITY OF TEACHER AS ADDRESS    ";
	cin >> address;
	ofstream out("Teacher.txt", ios::app);  // Open file in append mode
	out << t_id << "," << t_firstname << "," << t_lastname << "," << t_department << "," << tuser_name << "," << tpassword << "," << date << "," << t_gender << "," << t_number << "," << t_qualification << "," << address << endl;
	out.close();  // Remember to close the file
	cout << endl << "THE DATA OF TEACHER HAS BEEN ADDED" << endl;
	cout << "PRESS ANY KEY TO CONTINUE" << endl;
	f = _getch();
}
void Admin::addstudent()
{
	char f;
	cout << "PLEASE INPUT THE ID OF STUDENT    ";
	cin >> s_id;
	cout << "PLEASE INPUT THE FIRST NAME OF STUDENT    ";
	cin >> s_firstname;
	cout << "PLEASE INPUT THE LAST NAME OF STUDENT    ";
	cin >> s_lastname;
	cout << "PLEASE INPUT THE DEPARTMENT OF STUDENT    ";
	cin >> s_department;
	cout << "PLEASE INPUT THE ROLL NUMBER OF STUDENT    ";
	cin >> rollno;
	cout << "PLEASE INPUT THE USER NAME OF STUDENT    ";
	cin >> suser_name;
	cout << "PLEASE INPUT THE PASSWORD OF STUDENT    ";
	cin >> spassword;
	cout << "PLEASE INPUT THE REGISTERATION DATE OF STUDENT    ";
	cin >> s_date;
	cout << "PLEASE INPUT THE GENDER OF STUDENT    ";
	cin >> s_gender;
	cout << "PLEASE INPUT THE NUMBER OF STUDENT   ";
	cin >> s_number;
	cout << "PLEASE INPUT THE CITY OF STUDENT AS ADDRESS    ";
	cin >> s_address;
	cout << "PLEASE INPUT THE FEE STATUS OF STUDENT    ";
	cin >> fee;
	cout << "PLEASE INPUT THE QUALIFICATION OF STUDENT    ";
	cin >> s_qualification;
	cout << "PLEASE INPUT THE MARKS OF STUDENT    ";
	cin >> s_marks;
	ofstream out("Student.txt", ios::app);  // Open file in append mode
	out << s_id << "," << s_firstname << "," << s_lastname << "," << s_department << "," << rollno << "," << suser_name << "," << spassword << "," << s_date << "," << s_gender << "," << s_number << "," << s_address << "," << fee << "," << s_qualification << "," << s_marks << endl;
	out.close();
	cout << endl << "THE DATA OF STUDENT HAS BEEN ADDED" << endl;
	cout << "PRESS ANY KEY TO CONTINUE" << endl;
	f = _getch();
}
void Admin::editstudent()
{
	char f;
	fstream file("Student.txt", ios::in);
	fstream file2("TEMP.txt", ios::out);
	if (!file.is_open())
	{
		cout << "Error opening file1!\n";
		return;
	}
	if (!file2.is_open())
	{
		cout << "Error opening file2!\n";
		return;
	}

	string firstName, lastName, id, dept, srollno, user, pass, date, gender, phone, address, fee, quali, marks;
	string fname, lname;
	if (cin.fail()) {
		cin.clear(); cin.ignore();
	}
	cout << "PLEASE INPUT THE FIRST NAME OF STUDENT TO EDIT INFO:    ";
	cin >> fname;
	cout << "PLEASE INPUT THE LAST NAME OF STUDENT TO EDIT INFO:    ";
	cin >> lname;

	bool found = false;
	while (getline(file, id, ','))
	{
		getline(file, firstName, ',');
		getline(file, lastName, ',');
		getline(file, dept, ',');
		getline(file, srollno, ',');
		getline(file, user, ',');
		getline(file, pass, ',');
		getline(file, date, ',');
		getline(file, gender, ',');
		getline(file, phone, ',');
		getline(file, address, ',');
		getline(file, fee, ',');
		getline(file, quali, ',');
		getline(file, marks);

		if (fname == firstName && lname == lastName)
		{
			found = true;
			cout << "PLEASE INPUT THE ID OF STUDENT    ";
			cin >> s_id;
			cout << "PLEASE INPUT THE FIRST NAME OF STUDENT    ";
			cin >> s_firstname;
			cout << "PLEASE INPUT THE LAST NAME OF STUDENT    ";
			cin >> s_lastname;
			cout << "PLEASE INPUT THE DEPARTMENT OF STUDENT    ";
			cin >> s_department;
			cout << "PLEASE INPUT THE ROLL NUMBER OF STUDENT    ";
			cin >> rollno;
			cout << "PLEASE INPUT THE USER NAME OF STUDENT    ";
			cin >> suser_name;
			cout << "PLEASE INPUT THE PASSWORD OF STUDENT    ";
			cin >> spassword;
			cout << "PLEASE INPUT THE REGISTERATION DATE OF STUDENT    ";
			cin >> s_date;
			cout << "PLEASE INPUT THE GENDER OF STUDENT    ";
			cin >> s_gender;
			cout << "PLEASE INPUT THE NUMBER OF STUDENT   ";
			cin >> s_number;
			cout << "PLEASE INPUT THE CITY OF STUDENT AS ADDRESS    ";
			cin >> s_address;
			cout << "PLEASE INPUT THE FEE STATUS OF STUDENT    ";
			cin >> this->fee;
			cout << "PLEASE INPUT THE QUALIFICATION OF STUDENT    ";
			cin >> s_qualification;
			cout << "PLEASE INPUT THE MARKS OF STUDENT    ";
			cin >> s_marks;


			file2 << s_id << "," << s_firstname << "," << s_lastname << "," << s_department << "," << rollno << "," << suser_name << "," << spassword << "," << s_date << "," << s_gender << "," << s_number << "," << s_address << "," << this->fee << "," << s_qualification << "," << s_marks << endl;
		}
		else {
			file2 << id << "," << firstName << "," << lastName << "," << dept << "," << srollno << "," << user << "," << pass << "," << date << "," << gender << "," << phone << "," << address << "," << fee << "," << quali << "," << marks << endl;
		}
	}
	file.close();
	file2.close();
	if (found == false)
	{
		cout << "THE ENTERED FIRST NAME AND LAST NAME DID NOT MATCH TO ANY DATA" << endl;
		remove("TEMP.txt");
	}
	else {
		remove("Student.txt");
		rename("TEMP.txt", "Student.txt");
	}
	cout << endl << "THE DATA OF STUDENT HAS BEEN EDITED" << endl;
	cout << "PRESS ANY KEY TO CONTINUE " << endl;
	f = _getch();
}
void Admin::editteacher()
{
	char f;
	fstream file3("Teacher.txt", ios::in);
	fstream file4("TEMP.txt", ios::out);
	if (!file3.is_open())
	{
		cout << "Error opening file1!\n";
		return;
	}
	if (!file4.is_open())
	{
		cout << "Error opening file2!\n";
		return;
	}

	string firstName, lastName, id, dept, srollno, user, pass, date, gender, phone, address, fee, quali, marks;
	string fname, lname;
	if (cin.fail()) {
		cin.clear(); cin.ignore();
	}
	cout << "PLEASE INPUT THE FIRST NAME OF TEACHER TO EDIT INFO:    ";
	cin >> fname;
	cout << "PLEASE INPUT THE LAST NAME OF TEACHER TO EDIT INFO:    ";
	cin >> lname;

	bool found = false;
	while (getline(file3, id, ','))
	{
		getline(file3, firstName, ',');
		getline(file3, lastName, ',');
		getline(file3, dept, ',');
		getline(file3, user, ',');
		getline(file3, pass, ',');
		getline(file3, date, ',');
		getline(file3, gender, ',');
		getline(file3, phone, ',');
		getline(file3, address, ',');
		getline(file3, quali);

		if (fname == firstName && lname == lastName)
		{
			found = true;
			cout << "PLEASE INPUT THE ID OF TEACHER    ";
			cin >> t_id;
			cout << "PLEASE INPUT THE FIRST NAME OF TEACHER    ";
			cin >> t_firstname;
			cout << "PLEASE INPUT THE LAST NAME OF TEACHER    ";
			cin >> t_lastname;
			cout << "PLEASE INPUT THE DEPARTMENT OF TEACHER    ";
			cin >> t_department;
			cout << "PLEASE INPUT THE USER NAME OF TEACHER    ";
			cin >> tuser_name;
			cout << "PLEASE INPUT THE PASSWORD OF TEACHER    ";
			cin >> tpassword;
			cout << "PLEASE INPUT THE REGISTERATION DATE OF TEACHER    ";
			cin >> this->date;
			cout << "PLEASE INPUT THE GENDER OF TEACHER    ";
			cin >> t_gender;
			cout << "PLEASE INPUT THE NUMBER OF TEACHER   ";
			cin >> t_number;
			cout << "PLEASE INPUT THE CITY OF TEACHER AS ADDRESS    ";
			cin >> this->address;
			cout << "PLEASE INPUT THE QUALIFICATION OF TEACHER    ";
			cin >> t_qualification;


			file4 << t_id << "," << t_firstname << "," << t_lastname << "," << t_department << "," << tuser_name << "," << tpassword << "," << this->date << "," << t_gender << "," << t_number << "," << this->address << "," << t_qualification << endl;
		}
		else {
			file4 << id << "," << firstName << "," << lastName << "," << dept << "," << user << "," << pass << "," << date << "," << gender << "," << phone << "," << address << "," << quali << "," << endl;
		}
	}
	file3.close();
	file4.close();
	if (found == false)
	{
		cout << "THE ENTERED FIRST NAME AND LAST NAME DID NOT MATCH TO ANY DATA" << endl;
		remove("TEMP.txt");
	}
	else {
		remove("Teacher.txt");
		rename("TEMP.txt", "Teacher.txt");
	}
	cout << endl << "THE DATA OF TEACHER HAS BEEN EDITED" << endl;
	cout << "PRESS ANY KEY TO CONTINUE " << endl;
	f = _getch();
}
void Admin::viewstudent()
{
	char f;
	fstream file("Student.txt", ios::in);
	if (!file.is_open()) { cout << "Error!\n"; }

	string firstName, lastName, id, dept, srollno, user, pass, date, gender, phone, address, fee, quali, marks;

	cout << endl << "TOTAL RECORDS OF STUDENTS FOUND: " << endl;
	while (getline(file, id, ','))
	{
		getline(file, firstName, ',');
		getline(file, lastName, ',');
		getline(file, dept, ',');
		getline(file, srollno, ',');
		getline(file, user, ',');
		getline(file, pass, ',');
		getline(file, date, ',');
		getline(file, gender, ',');
		getline(file, phone, ',');
		getline(file, address, ',');
		getline(file, fee, ',');
		getline(file, quali, ',');
		getline(file, marks);

		cout << "ID#    " << id << endl;
		cout << "FIRST NAME:    " << firstName << endl;
		cout << "LAST NAME:    " << lastName << endl;
		cout << "DEPARTMENT:    " << dept << endl;
		cout << "ROLL NUMBER:    " << srollno << endl;
		cout << "USER NAME:    " << user << endl;
		cout << "PASSWORD:    " << pass << endl;
		cout << "REGISTERATION DATE:    " << date << endl;
		cout << "GENDER:    " << gender << endl;
		cout << "PHONE #    " << phone << endl;
		cout << "ADDRESS:    " << address << endl;
		cout << "FEE:    " << fee << endl;
		cout << "QUALIFICATION:    " << quali << endl;
		cout << "MARKS:    " << marks << endl << endl;
	}

	file.close();
	cout << "PRESS ANY KEY TO CONTINUE " << endl;
	f = _getch();
}
void Admin::viewteacher()
{
	char f;
	fstream file("Teacher.txt", ios::in);
	if (!file.is_open()) { cout << "Error!\n"; }

	string firstName, lastName, id, dept, user, pass, date, gender, phone, quali, address;

	cout << endl << "TOTAL RECORDS OF TEACHERS FOUND: " << endl;
	while (getline(file, id, ',')) {
		getline(file, firstName, ',');
		getline(file, lastName, ',');
		getline(file, dept, ',');
		getline(file, user, ',');
		getline(file, pass, ',');
		getline(file, date, ',');
		getline(file, gender, ',');
		getline(file, phone, ',');
		getline(file, quali, ',');
		getline(file, address);

		cout << "FIRST NAME:    " << firstName << endl;
		cout << "LAST NAME:    " << lastName << endl;
		cout << "ID#    " << id << endl;
		cout << "DEPARTMENT:    " << dept << endl;
		cout << "USER NAME:    " << user << endl;
		cout << "PASSWORD:    " << pass << endl;
		cout << "REGISTERATION DATE:    " << date << endl;
		cout << "GENDER:    " << gender << endl;
		cout << "PHONE #    " << phone << endl;
		cout << "QUALIFICATION:    " << quali << endl;
		cout << "ADDRESS:    " << address << endl << endl;

	}

	file.close();
	cout << "PRESS ANY KEY TO CONTINUE " << endl;
	f = _getch();
}

//--------------------Teacher Class Functions--------------------

Teacher::Teacher() {}
void Teacher::signin()
{
	char f;
	bool found = false;
	ifstream file("Teacher.txt");
	if (!file.is_open()) {
		cout << "Error! Unable to open file.\n";
		return;
	}

	string firstName, lastName, user, pass, date, gender, phone, quali, address;
	string  username, password;
	cout << "PLEASE INPUT THE USERNAME:    ";
	cin >> username;
	cout << "PLEASE INPUT THE PASSWORD:    ";
	cin >> password;

	while (getline(file, id, ',')) {
		getline(file, firstName, ',');
		getline(file, lastName, ',');
		getline(file, dept, ',');
		getline(file, user, ',');
		getline(file, pass, ',');
		getline(file, date, ',');
		getline(file, gender, ',');
		getline(file, phone, ',');
		getline(file, quali, ',');
		getline(file, address);
		if (username == user && password == pass) {
			found = true;
			break;
		}
	}

	if (found) {
		cout << "THE USERNAME AND PASSWORD ARE CORRECT" << endl;
		cout << "YOU CAN PROCEED" << endl;
		cout << "PRESS ANY KEY TO CONTINUE" << endl;
		f = _getch();
		file.close();

		char j = 'y';
		while (j != 8)
		{
			system("cls");
			system("Color 6F");
			cout << endl << "1.    PRESS 1 TO SEE TIMETABLE" << endl;
			cout << "2.    PRESS 2 TO MARK ATTENDANCE" << endl;
			cout << "3.    PRESS 3 TO ASSIGN MARKS" << endl;
			cout << "4.    PRESS 4 TO ASSIGN GRADES" << endl;
			cout << "5.    PRESS BACKSPACE <------ TO EXIT TEACHER MODULE" << endl;
			j = _getch();
			if (j == '1')
			{
				timetable();
			}
			else if (j == '2')
			{
				markingattendance();
			}
			else if (j == '3')
			{
				assignmarks();
			}
			else if (j == '4')
			{
				assigngrades();
			}
			else if (j != 8)
			{
				cout << endl << "PLEASE PRESS VALID NUMBER" << endl;
			}
		}
	}
	else {
		cout << "USERNAME OR PASSWORD IS INCORRECT" << endl;
	}
}
void Teacher::timetable()
{
	char f;
	string department, courseName, startDate, endDate, timetable;
	cout << "Enter Department name: ";
	cin >> department;
	cout << "Enter course name: ";
	cin >> courseName;
	cout << "Enter start date (YYYY-MM-DD): ";
	cin >> startDate;
	cout << "Enter end date (YYYY-MM-DD): ";
	cin >> endDate;
	cout << "Enter timetable (comma-separated list of times in 24-hour format, e.g. 08:00,10:00,14:00): ";
	cin.ignore(); // Ignore any newline character in the input stream
	getline(cin, timetable);

	ofstream out("course_schedule.txt", ios::app); // Open file in append mode
	if (out.is_open()) {
		out << department << " " << courseName << " " << startDate << " " << endDate << " " << timetable << endl;
		out.close();
		cout << endl << "Course schedule created successfully." << endl << endl;
	}
	else {
		cout << "Unable to open file." << endl;
	}
	fstream file("course_schedule.txt", ios::in);
	if (!file.is_open()) { cout << "Error!\n"; }
	while (getline(file, department, ' ')) {
		getline(file, courseName, ' ');
		getline(file, startDate, ' ');
		getline(file, endDate, ' ');
		getline(file, timetable);
		cout << department << "\t" << courseName << "\t" << startDate << "\t" << endDate << "\t" << timetable << endl;
	}
	file.close();
	cout << endl << "PRESS ANY KEY TO CONTINUE " << endl;
	f = _getch();
}
void Teacher::markingattendance()
{
	char f;
	string courseName, date, studentId, attendanceStatus;
	cout << "Enter course name: ";
	cin >> courseName;
	cout << "Enter date (YYYY-MM-DD): ";
	cin >> date;

	ifstream courseScheduleFile("course_schedule.txt");
	bool courseExists = false;
	string line;
	while (getline(courseScheduleFile, line)) {
		istringstream iss(line);
		string course, startDate, endDate, timetable;
		if (iss >> course >> startDate >> endDate >> timetable) {
			if (course == courseName) {
				courseExists = true;
				break;
			}
		}
	}
	courseScheduleFile.close();

	if (!courseExists) {
		cout << "Error: Course name does not exist." << endl;
		return;
	}

	ofstream out("attendance.txt", ios::app); // Open file in append mode
	if (out.is_open()) {
		ifstream studentIdsFile("student_ids.txt");
		while (getline(studentIdsFile, studentId)) {
			cout << "Enter attendance status for student " << studentId << " (P for present, A for absent): ";
			cin >> attendanceStatus;
			out << courseName << " " << date << " " << studentId << " " << attendanceStatus << endl;
		}
		studentIdsFile.close();
		out.close();
		cout << "Attendance marked successfully." << endl;
		cout << "PRESS ANY KEY TO CONTINUE" << endl;
		f = _getch();
	}
	else {
		cout << "Unable to open file." << endl;
	}
}
void Teacher::assignmarks()
{
	char f;
	string studentId, subject, newMarks;
	cout << "Roll number of student whose marks you want to update: ";
	cin >> studentId;
	cout << "Enter the subject for which you want to  update marks : ";
	cin >> subject;

	ifstream in("student_marks.txt");
	ofstream newFile("temp_marks.txt"); // Temporary file to write updated marks

	string id, course_name, marks;
	while (in >> id) {
		if (id == studentId) {
			newFile << id;

			while (in >> course_name && course_name != ".") {
				if (course_name == subject) {
					cout << "Enter new marks for subject " << subject << ": ";
					cin >> newMarks;
					newFile << " " << course_name << " " << newMarks;
				}
				else {
					newFile << " " << course_name;
					in >> marks;
					newFile << " " << marks;
				}
			}

			newFile << " ." << endl;
		}
		else {
			newFile << id;

			while (in >> course_name && course_name != ".") {
				newFile << " " << course_name;
				in >> marks;
				newFile << " " << marks;
			}

			newFile << " ." << endl;
		}
	}

	in.close();
	newFile.close();

	// Rename the temporary file to overwrite the original file
	remove("student_marks.txt");
	rename("temp_marks.txt", "student_marks.txt");

	cout << "Marks updated successfully." << endl;
	cout << "PRESS ANY KEY TO CONTINUE" << endl;
	f = _getch();

}
void Teacher::assigngrades()
{
	char f;
	ifstream in("assign_course.txt");
	string teacherId, course;

	while (in >> teacherId >> course) {
		if (teacherId == Admin::username) {
			cout << "Teacher ID: " << id << endl;
			cout << "DEPARTMENT: " << dept << endl;
		}
	}

	in.close();
	cout << "GRADES HAVE BEEN ASSIGNED" << endl;
	cout << "PRESS ANY KEY TO CONTINUE" << endl;
	f = _getch();
}

//--------------------Student Class Functions--------------------

void Student::sign_in_student()
{
	char f;
	fstream file("Student.txt", ios::in);
	if (!file.is_open()) { cout << "Error!\n"; }
	bool found = false;
	string firstName, lastName, id, dept, srollno, user, pass, date, gender, phone, address, fee, quali, marks;
	string  username, password;
	cout << "PLEASE INPUT THE USERNAME:    ";
	cin >> username;
	cout << "PLEASE INPUT THE PASSWORD:    ";
	cin >> password;
	while (getline(file, this->id, ','))
	{
		getline(file,this-> firstName, ',');
		getline(file, this->lastName, ',');
		getline(file, dept, ',');
		getline(file, srollno, ',');
		getline(file, user, ',');
		getline(file, pass, ',');
		getline(file, date, ',');
		getline(file, gender, ',');
		getline(file, phone, ',');
		getline(file, address, ',');
		getline(file, this->fee, ',');
		getline(file, quali, ',');
		getline(file, marks);
		if (username == user && password == pass) {
			found = true;
			break;
		}
	}
	if (found) {
		cout << "THE USERNAME AND PASSWORD ARE CORRECT" << endl;
		cout << "YOU CAN PROCEED" << endl;
		cout << "PRESS ANY KEY TO CONTINUE" << endl;
		f = _getch();
		file.close();

		char j = 'y';
		while (j != 8)
		{
			system("cls");
			system("Color B5");
			cout << endl << "1.    PRESS 1 TO VIEW ATTENDANCE" << endl;
			cout << "2.    PRESS 2 TO VIEW MARKS" << endl;
			cout << "3.    PRESS 3 TO VIEW GRADES" << endl;
			cout << "4.    PRESS 4 TO VIEW REGISTERED COURSES" << endl;
			cout << "5.    PRESS 5 TO VIEW FEE STATUS" << endl;
			cout << "6.    PRESS BACKSPACE <------ TO EXIT STUDENT MODULE" << endl;
			j = _getch();
			if (j == '1')
			{
				view_attendance();
			}
			else if (j == '2')
			{
				view_marks();
			}
			else if (j == '3')
			{
				view_grades();
			}
			else if (j == '4')
			{
				view_registered_courses();
			}
			else if (j == '5')
			{
				view_fee_status();
			}
			else if (j != 8)
			{
				cout << endl << "PLEASE PRESS VALID NUMBER" << endl;
			}
		}
	}
	else {
		cout << "USERNAME OR PASSWORD IS INCORRECT" << endl;
	}
}
void Student::view_attendance()
{
	char f;
	fstream file("attendance.txt", ios::in);
	if (!file.is_open()) { cout << "Error!\n"; }

	string gra[8];
	while (getline(file, gra[0], ',')) {
		getline(file, gra[1], ',');
		getline(file, gra[2], ',');
		getline(file, gra[3], ',');
		getline(file, gra[4], ',');
		getline(file, gra[5], ',');
		getline(file, gra[6], ',');
		getline(file, gra[7]);
		for (int i = 0; i < 8; i++)
		{
			cout << "SUBJECT " << i + 1 << ": " << gra[i] << endl;
		}
	}

	file.close();
	cout << "PRESS ANY KEY TO CONTINUE " << endl;
	f = _getch();
}
void Student::view_marks()
{
	char f;
	fstream file("marks.txt", ios::in);
	if (!file.is_open()) { cout << "Error!\n"; }

	string gra[8];
	while (getline(file, gra[0], ',')) {
		getline(file, gra[1], ',');
		getline(file, gra[2], ',');
		getline(file, gra[3], ',');
		getline(file, gra[4], ',');
		getline(file, gra[5], ',');
		getline(file, gra[6], ',');
		getline(file, gra[7]);
		for (int i = 0; i < 8; i++)
		{
			cout << "SUBJECT " << i + 1 << ": " << gra[i] << endl;
		}
	}

	file.close();
	cout << "PRESS ANY KEY TO CONTINUE " << endl;
	f = _getch();
}
void Student::view_grades()
{
	char f;
	fstream file("assign_course.txt", ios::in);
	if (!file.is_open()) { cout << "Error!\n"; }

	string gra[8];
	while (getline(file, gra[0], ',')) {
		getline(file, gra[1], ',');
		getline(file, gra[2], ',');
		getline(file, gra[3], ',');
		getline(file, gra[4], ',');
		getline(file, gra[5], ',');
		getline(file, gra[6], ',');
		getline(file, gra[7]);
		for (int i = 0; i < 8; i++)
		{
			cout << "SUBJECT " << i + 1 << ": " << gra[i] << endl;
		}
	}

	file.close();
	cout << "PRESS ANY KEY TO CONTINUE " << endl;
	f = _getch();
}
void Student::view_registered_courses()
{
	char f;
	fstream file("Registered_courses.txt", ios::in);
	if (!file.is_open()) { cout << "Error!\n"; }

	string sub[8];
	while (getline(file, sub[0], ',')) {
		getline(file, sub[1], ',');
		getline(file, sub[2], ',');
		getline(file, sub[3], ',');
		getline(file, sub[4], ',');
		getline(file, sub[5], ',');
		getline(file, sub[6], ',');
		getline(file, sub[7]);
		for (int i = 0; i < 8; i++)
		{
			cout << "SUBJECT " << i + 1 << ": " << sub[i] << endl;
		}
	}

	file.close();
	cout << "PRESS ANY KEY TO CONTINUE " << endl;
	f = _getch();
}
void Student::view_fee_status()
{
	char f;
	cout << "THE FEE OF " << firstName << " " << lastName << " IS:" << fee << endl;
	cout << "ID# " << id << endl;
	cout << "PRESS ANY KEY TO CONTINUE" << endl;
	f = _getch();
}
