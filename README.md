# Student Record Management System

A C++ console application for managing student academic records. This project allows users to add, delete, search, and display student records, including calculating their GPA based on subject marks.

## Features
- **Add New Student Record**: Enter student details and marks for predefined subjects to automatically calculate their grades and GPA.
- **Delete Student Record**: Remove a student from the system using their matrix number.
- **Display Student Record**: View a summary of all students or search for detailed records of a specific student.
- **Search Student by Matrix Number**: Quickly find a specific student's details and GPA.
- **Interactive UI**: Includes simulated login and logout animations.

## Subjects Evaluated
1. Computer Architecture (3 credits)
2. Network Data Communication (3 credits)
3. Algebra and Calculus (3 credits)
4. Programming (3 credits)
5. English Career Development (3 credits)
6. Philosophy Current Issue (2 credits)
7. Kokurikulum 2 (1 credit)

## How to Run
1. Ensure you have a C++ compiler installed (e.g., MinGW `g++`).
2. Compile the source code:
   ```bash
   g++ pf_projectcode_s4_g2.cpp -o student_management
   ```
3. Run the compiled executable:
   ```bash
   ./student_management
   ```
   *(On Windows, run `.\student_management.exe`)*

## Project Structure
- `pf_projectcode_s4_g2.cpp`: The main source code file containing all the logic and UI flows.
