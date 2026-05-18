#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <climits>
#include <windows.h>
using namespace std;

//Helper to read an integer safely. Reprompts on non-numeric input and
//optionally enforces an inclusive [min, max] range.
int readInt(int minVal = INT_MIN, int maxVal = INT_MAX) {
	int value;
	while (true) {
		cin >> value;
		if (cin.fail() || value < minVal || value > maxVal) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a number";
			if (minVal != INT_MIN || maxVal != INT_MAX) {
				cout << " between " << minVal << " and " << maxVal;
			}
			cout << ": ";
			continue;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return value;
	}
}

//Declare and initialize the size declarator of the arrays
/*

Constant variable names and its purpose.

MAX 				: Constant for maximum number of students (100).
SUBJECT_COUNT 		: Constant for total number of subjects (7).

*/
const int MAX = 100;
const int SUBJECT_COUNT = 7;

//Declare and initialize the subjects[] array with string literals
string subjects[SUBJECT_COUNT] = {
	"Computer Architecture",
	"Network Data Communication",
	"Algebra and Calculus",
	"Programming",
	"English Career Development",
	"Philosophy Current Issue",
	"Kokurikulum 2"
};

//Declare arrays and variables
/* 

Array & variable names and its purpose.

StudentName[] 		: Stores names of students.
StudentMatrix[] 	: Stores matrix numbers of students.
StudentGrade[][] 	: Stores grades (A+, A, etc.) per subject for each student.
StudentMarks[][] 	: Stores marks per subject for each student.
StudentPointer[][] 	: Stores grade points per subject for each student.
StudentGPA[] 		: Stores final GPA of each student.
totalStudents 		: Tracks how many students are stored.

*/

string StudentName[MAX], StudentMatrix[MAX], StudentGrade[MAX][SUBJECT_COUNT];
int StudentMarks[MAX][SUBJECT_COUNT];
float StudentPointer[MAX][SUBJECT_COUNT], StudentGPA[MAX];
int totalStudents = 0;

//Function prototypes
void assignGradeAndPointer(int index, int subj, int marks);
float calculateGPA(int index);
void addRecord();
void displayRecord();
void deleteRecord();
void searchRecord();
void loginScreen();
void loggingOutAnimation();
void loggingInAnimation();



int main() {
	while (true) {

		//Call the loginScreen(), loggingInAnimation() and system() functions
		loginScreen();
		loggingInAnimation();
		system("cls");

		// Display the main menu
		int choice;
		do {
			cout << "========================================\n";
			cout << "     STUDENT RECORD MANAGEMENT SEM 2\n";
			cout << "========================================\n";
			cout << "1) ADD NEW STUDENT RECORD\n";
			cout << "2) DELETE STUDENT RECORD\n";
			cout << "3) DISPLAY STUDENT RECORD\n";
			cout << "4) SEARCH STUDENT BY MATRIX NUMBER\n";
			cout << "5) LOGOUT\n";

			cout << "\nYour choice: ";
			choice = readInt(1, 5);
			system("cls");

			//Switch statements to select which functions to call based on user input
			switch (choice) {
			case 1: addRecord();
				break;
			case 2: deleteRecord();
				break;
			case 3: displayRecord();
				break;
			case 4: searchRecord();
				break;
			case 5: loggingOutAnimation();
				break;
			default: cout << "Invalid choice. Try again.\n";
				break;
			}
		} while (choice != 5);
	}

	return 0;
}


//Function to assign grade and pointer value based on student marks
void assignGradeAndPointer(int index, int subj, int marks) {

	//if-esle if statements to determine the grade and pointer based on student's marks
	if (marks >= 90) {
		StudentGrade[index][subj] = "A+";
		StudentPointer[index][subj] = 4.00;
	}

	else if (marks >= 80) {
		StudentGrade[index][subj] = "A"; StudentPointer[index][subj] = 4.00;
	}

	else if (marks >= 75) {
		StudentGrade[index][subj] = "A-"; StudentPointer[index][subj] = 3.67;
	}

	else if (marks >= 70) {
		StudentGrade[index][subj] = "B+"; StudentPointer[index][subj] = 3.33;
	}

	else if (marks >= 65) {
		StudentGrade[index][subj] = "B"; StudentPointer[index][subj] = 3.00;
	}

	else if (marks >= 60) {
		StudentGrade[index][subj] = "B-"; StudentPointer[index][subj] = 2.67;
	}

	else if (marks >= 55) {
		StudentGrade[index][subj] = "C+"; StudentPointer[index][subj] = 2.33;
	}

	else if (marks >= 50) {
		StudentGrade[index][subj] = "C"; StudentPointer[index][subj] = 2.00;
	}

	else if (marks >= 40) {
		StudentGrade[index][subj] = "D"; StudentPointer[index][subj] = 1.00;
	}

	else {
		StudentGrade[index][subj] = "F"; StudentPointer[index][subj] = 0.00;
	}
}

//Function to calculate GPA using grade points and credit hours
float calculateGPA(int index) {
	float total = 0;
	int totalCredit = 0;

	//preset the credit hours according to the subjects
	int Credit[SUBJECT_COUNT] = { 3, 3, 3, 3, 3, 2, 1 };

	//Calculate GPA: sum (pointer * credit), divided by sum of credits
	for (int i = 0; i < SUBJECT_COUNT; i++) {
		total += StudentPointer[index][i] * Credit[i];
		totalCredit += Credit[i];
	}

	return total / totalCredit;    //Return calculated GPA
}

//Function to add new student records
void addRecord() {
	if (totalStudents >= MAX) {
		cout << "Record storage full (" << MAX << " students). Cannot add more.\n";
		system("pause");
		system("cls");
		return;
	}

	int remaining = MAX - totalStudents;
	cout << " Number of student (1-" << remaining << "): ";
	int n = readInt(1, remaining);

	//Take user input based on the number of students
	for (int i = 0; i < n; i++) {
		cout << "\n--- Student " << (i + 1) << " ---\n";

		cout << "Enter name     : ";
		getline(cin, StudentName[totalStudents]);
		cout << "Enter matrix   : ";
		getline(cin, StudentMatrix[totalStudents]);

		cout << "\n\n========= Enter Mark Percentage For Each Subject =========\n\n";
		//Enter marks for each subject (validated to 0-100)
		for (int j = 0; j < SUBJECT_COUNT; j++) {
			cout << setw(28) << left << subjects[j] << " : ";
			StudentMarks[totalStudents][j] = readInt(0, 100);

			assignGradeAndPointer(totalStudents, j, StudentMarks[totalStudents][j]);
		}
		//Calculate and store GPA
		StudentGPA[totalStudents] = calculateGPA(totalStudents);

		system("cls");
		//Display confirmation
		cout << "\n Student successfully added!\n";
		cout << "Name    : " << StudentName[totalStudents] << endl;
		cout << "Matrix  : " << StudentMatrix[totalStudents] << endl;
		cout << fixed << setprecision(2);
		cout << "GPA     : " << StudentGPA[totalStudents] << endl;

		totalStudents++;
	}
	cout << endl;
	system("pause");
	system("cls");
}

//Function to display all student records
void displayRecord() {
	if (totalStudents == 0) {
		cout << "No student record found.\n";
	}
	else {
		//Display header for student list
		cout << "| NO | " << setw(20) << left << "NAME"
			<< "| " << setw(10) << "MATRIX"
			<< "| " << setw(6) << "GPA" << " |\n";
		//Loop through and display all students' name,matrix number and GPA
		for (int i = 0; i < totalStudents; i++) {
			cout << "| " << setw(3) << (i + 1)
				<< "| " << setw(20) << StudentName[i]
				<< "| " << setw(10) << StudentMatrix[i]
					<< "| " << setw(6) << fixed << setprecision(2) << StudentGPA[i] << " |\n";
		}

		char seeMore;
		cout << "\nDo you want to see student details? (Y/N): ";
		cin >> seeMore;

		//selection for a detailed record of the student
		if (seeMore == 'Y' || seeMore == 'y') {
			string matrix;
			cout << "Enter Matrix Number: ";
			cin >> matrix;

			bool found = false;
			for (int i = 0; i < totalStudents; i++) {
				if (StudentMatrix[i] == matrix) {
					found = true;
					cout << "\n--- Detailed Record ---\n";
					cout << "Name   : " << StudentName[i] << endl;
					cout << "Matrix : " << StudentMatrix[i] << endl;

					cout << "\n-----------------------\n";

					for (int j = 0; j < SUBJECT_COUNT; j++) {
						cout << setw(30) << left << subjects[j] << " : "
							<< StudentGrade[i][j]
							<< setw(3) << left << " (" << StudentMarks[i][j] << " marks)\n";
					}

					cout << fixed << setprecision(2);
					cout << "\nFINAL GPA : " << StudentGPA[i] << "\n\n";
					break;
				}
			}

			if (!found) {
				cout << "\nMatrix number not found.\n";
			}
		}
	}

	system("pause");
	system("cls");
}

//Function to delete a student record based on matrix number
void deleteRecord() {
	if (totalStudents == 0) {
		cout << "No student records to delete.\n";
	}
	else {
		string matrix;
		//Display all current records before deletion
		cout << "| NO | " << setw(20) << left << "NAME"
			<< "| " << setw(10) << "MATRIX"
			<< "| " << setw(6) << "GPA" << " |\n";

		for (int i = 0; i < totalStudents; i++) {
			cout << "| " << setw(3) << (i + 1)
				<< "| " << setw(20) << StudentName[i]
				<< "| " << setw(10) << StudentMatrix[i]
					<< "| " << setw(6) << fixed << setprecision(2) << StudentGPA[i] << " |\n";
		}

		cout << "\nEnter Matrix Number of student to delete: ";
		cin >> matrix;

		bool found = false;

		//Loop to find and delete the student record
		for (int i = 0; i < totalStudents; i++) {
			if (StudentMatrix[i] == matrix) {
				//Shift all data up to remove the selected record
				for (int j = i; j < totalStudents - 1; j++) {
					StudentName[j] = StudentName[j + 1];
					StudentMatrix[j] = StudentMatrix[j + 1];
					StudentGPA[j] = StudentGPA[j + 1];

					for (int k = 0; k < SUBJECT_COUNT; k++) {
						StudentMarks[j][k] = StudentMarks[j + 1][k];
						StudentGrade[j][k] = StudentGrade[j + 1][k];
						StudentPointer[j][k] = StudentPointer[j + 1][k];
					}
				}
				totalStudents--;
				found = true;
				cout << "\n Student record successfully deleted.\n";
				break;
			}
		}

		//if statement to display error message
		if (!found) {
			cout << "\nMatrix number not found.\n";
		}

		//Display updated list of students after deletion
		if (totalStudents > 0) {
			cout << "\n====== UPDATED STUDENT RECORD ======\n";
			cout << "| NO | " << setw(20) << left << "NAME"
				<< "| " << setw(10) << "MATRIX"
				<< "| " << setw(6) << "GPA" << " |\n";

			for (int i = 0; i < totalStudents; i++) {
				cout << "| " << setw(3) << (i + 1)
					<< "| " << setw(20) << StudentName[i]
					<< "| " << setw(10) << StudentMatrix[i]
						<< "| " << setw(6) << fixed << setprecision(2) << StudentGPA[i] << " |\n";
			}
		}
		else {
			cout << "\nNo more records available.\n";
		}
	}

	system("pause");
	system("cls");
}

//Function to search for a student by matrix number
void searchRecord() {
	string matrix;
	cout << "Enter Matrix Number to search: ";
	cin >> matrix;

	bool found = false;

	//for loop to search for matching matrix number 
	for (int i = 0; i < totalStudents; i++) {

		//display the students record only if the matrix number match
		if (StudentMatrix[i] == matrix) {
			cout << "\nRecord Found:\n";
			cout << "Name    : " << StudentName[i] << endl;
			cout << "Matrix  : " << StudentMatrix[i] << endl;
			cout << fixed << setprecision(2);
			cout << "GPA     : " << StudentGPA[i] << endl;
			found = true;
			break;
		}
	}

	if (!found) {
		cout << "\nNo record found with that matrix number.\n";
	}

	system("pause");
	system("cls");
}

//Function to simulate a login screen 
void loginScreen() {
	string username, staffId;
	cout << "==============================\n";
	cout << "         STAFF LOGIN \n";
	cout << "==============================\n";
	cout << "Username : ";
	getline(cin, username);
	cout << "Staff ID : ";
	getline(cin, staffId);
	system("cls");
}

//Function to simulate logout animation using dots
void loggingOutAnimation() {
	string message = "Logging out";
	int dots = 0;

	//Display dots one at a time for animation effect
	for (int i = 0; i < 4; ++i) {
		cout << "\r";
		cout << message << string(dots, '.') << "   ";
		cout.flush();  										 //Force display immediately
		dots++;

		Sleep(500);   //Pause 0.5 second
	}
	cout << "\rLogging out... Done!                     \n";
	Sleep(500);
	system("cls");
}
//Function to simulate login animation using dots
void loggingInAnimation() {
	string message = "Logging in";
	int dots = 0;
	//Display dots one at a time for animation effect
	for (int i = 0; i < 4; ++i) {
		cout << "\r";
		cout << message << string(dots, '.') << "   ";
		cout.flush();
		dots++;

		Sleep(600);  // Pause 0.6 second
	}
	cout << "\rWELCOME :)                    \n";
	Sleep(800);      // Final pause
}