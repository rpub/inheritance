#include "date.h"
#include "person.h"
#include "student.h"
#include "professor.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::vector;

using namespace std;

size_t Menu();

int main(int argc, char* argv[]) {

    // Vector of People
    vector<Person*> people;

    // Menu Option
    int userOption;

    // System Variables
    size_t year, day, month;
    size_t hireYear, hireDay, hireMonth;
    string name, major, department;

    // Variable Validation, bool-s
    bool birthdayIsValid;
    bool hireDateIsValid;

    // System Objects
    Date date;

    while ((userOption = Menu()) != 15){
		if (userOption == 1){            // Add Person

		    // -- VARS;
            Date birthDate;
            srand(time(NULL)); // apparently this is important

            // -- NAME INPUT
            cout << "Name: ";
            cin >> name;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // -- BIRTHDAY INPUT
            do{
                // False if input is wrong
                birthdayIsValid = true;

                // Birthday Input
                cout << "Birth date yyyy mm dd: ";
                cin >> year >> month >> day;

                // Validate Input
                birthDate = Date(year, month, day);
                if (cin.fail() || year <= 0 || month <= 0 || day <= 0 || birthDate.IsInvalidDate()){
                    cout << "Invalid Date!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    birthdayIsValid = false;
                }
            } while (!birthdayIsValid);

            // -- CREATE PERSON
            if(birthdayIsValid){
                people.push_back(new Person(name, Date(year, month, day)));
                cout << "Person inserted in position: " << people.size() - 1 << endl;
            }

        }else if (userOption == 2){		// Add Student

            // -- VARS
            Date birthDate;

            // -- NAME INPUT
            cout << "Name: ";
            cin >> name;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // -- BIRTHDAY INPUT
            do{
                // False if input is wrong
                birthdayIsValid = true;

                // Birthday Input
                cout << "Birth date yyyy mm dd: ";
                cin >> year >> month >> day;

                // Validate Input
                birthDate = Date(year, month, day);
                if (cin.fail() || year <= 0 || month <= 0 || day <= 0 || birthDate.IsInvalidDate()){
                    cout << "Invalid Date!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    birthdayIsValid = false;
                }
            } while (!birthdayIsValid);

            // -- MAJOR INPUT
            cout << "Major: ";
            cin >> major;

            // -- CREATE STUDENT
            if(birthdayIsValid){
                people.push_back(new Student (name, Date(year, month, day), major));
                cout << "Student inserted in position: " << people.size() - 1 << endl;
            }

        }else if (userOption == 3){		// Add Professor

		    // -- VARS
            Date hireDate;
            Date birthDate;

            // -- NAME INPUT
            cout << "Name: ";
            cin >> name;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // -- BIRTHDAY INPUT
            do{
                // False if input is wrong
                birthdayIsValid = true;

                // Birthday Input
                cout << "Birth date yyyy mm dd: ";
                cin >> year >> month >> day;

                // Validate Input
                birthDate = Date(year, month, day);
                if (cin.fail() || year <= 0 || month <= 0 || day <= 0 || birthDate.IsInvalidDate()){
                    cout << "Invalid Date!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    birthdayIsValid = false;
                }
            } while (!birthdayIsValid);

            // Department Input
            cout << "Department: ";
            cin >> department;

            // -- HIRE DATE INPUT
            do{
                // False if input is wrong
                hireDateIsValid = true;

                // Hire Date Input
                cout << "Hire date: yyyy mm dd: ";
                cin >> hireYear >> hireMonth >> hireDay;

                // Validate Input
                hireDate = Date(hireYear, hireMonth, hireDay);
                if(cin.fail() || hireYear <= 0 || hireMonth <= 0 || hireDay <= 0 || hireDate.IsInvalidDate()){
                    cout << "Invalid Date!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    hireDateIsValid = false;
                }
            } while (!hireDateIsValid);

            // -- CREATE PROFESSOR
            if(birthdayIsValid && hireDateIsValid){
                people.push_back(new Professor (name, Date(year, month, day),
                                                department, Date(hireYear, hireMonth, hireDay)));
                cout << "Professor inserted in position: " << people.size() - 1 << endl;
            }

        }else if (userOption == 4){		// List All People

            // -- LIST ALL PEOPLE
            for(Person* p : people)
                cout << p->ToString() << endl;

		}else if (userOption == 5){		// Show Students Report

            // -- LIST ALL STUDENTS
            for (Person* person: people){
                if (dynamic_cast<Student*>(person) != nullptr) {
                    cout << person->ToString() << endl;
                }
            }

		}else if (userOption == 6){		// Show Professor Report

            // -- LIST ALL PROFESSORS
            for (Person* person: people){
                if (dynamic_cast<Professor*>(person) != nullptr) {
                    cout << person->ToString() << endl;
                }
            }

		}else if (userOption == 7){		// Show !Professor !Student

            // -- LIST PERSONS ONLY

		    // Loop traverses vector
		    for (Person* person: people){
                // Student & Prof. objects...
		        Student* student = dynamic_cast<Student*> (person);
                Professor* professor = dynamic_cast<Professor*> (person);

                // Print, only if Person is !Professor && !Student
                if(person != student && person != professor && person != nullptr){
                    cout << person->ToString() << endl;
                }
            }

		}else if (userOption == 8){		// Calculate Average GPA

            float gpaAll = 0.0; // Holds total of all student GPAs
            float avgGPA;       // Holds avg. of all student GPAs
            int counter = 0;    // Counts every time a GPA is added to avgGPA

            // Loop traverses vector
            for (Person* person: people){
                // If student...
                if (dynamic_cast<Student*>(person) != nullptr){
                    Student *student = dynamic_cast<Student*>(person);
                    gpaAll += student->GetGPA(); // Get student's GPA, add it to gpaAll
                    counter++; // Increment counter
                }
            }

            // Calculates avgGPA, avoids dividing by 0
            if(gpaAll == 0.0){
                cout << "No students exist for which to calculate an average GPA" << endl;
            } else {
                avgGPA = gpaAll / counter;
                cout << "The average GPA of the students is: " << avgGPA << endl;
            }

		}else if (userOption == 9){		// Calculate Average Salary

            float salaryAll = 0.0; // Holds total of all professor salaries
            float avgSalary;       // Holds avg. of all professor salaries
            int counter = 0;       // Counts every time a salary is added to avgSalary

            // Loop traverses vector
            for (Person* person: people){
                // If professor...
                if (dynamic_cast<Professor*>(person) != nullptr){
                    Professor *professor = dynamic_cast<Professor*>(person);
                    salaryAll += professor->GetSalary(); // Get professor's salary, add it to salaryAll
                    counter++; // Increment counter
                }
            }

            // Calculates avgSalary, avoids dividing by 0
            if(salaryAll == 0.0){
                cout << "No professors exist for which to calculate an average Salary" << endl;
            } else {
                avgSalary = salaryAll / counter;
                cout << "The average salary of the professors is: " << avgSalary << endl;
            }

		}else if (userOption == 10){	// Input Grades to Student

		    int studentIndex = 0;  // counter, student position
		    int countStudents = 0;  // counter, the actual num of students
            int studentNum;        // user inputs which student to modify, based on counter
            int studentCredits;    // num of credits, input
            float studentGrade;    // student grade, input

            // -- PRINT STUDENTS + POSITION
            for (Person* person: people){
                if (dynamic_cast<Student*>(person) != nullptr) {
                    cout << studentIndex << " " << person->ToString() << endl;
                    countStudents++;
                }
                studentIndex++;
            }

            // Verify that students exist...
            if(countStudents == 0){
                cout << "No students exist for which to add a grade" << endl;
            } else {
                // -- SELECT STUDENT
                Student* stu = nullptr;
                while( stu == nullptr ) {

                    cout << "Number of student to input grades to: ";
                    cin >> studentNum;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Incorrect input!" << endl;
                    }

                    if( studentNum < 0 || studentNum > people.size()-1){
                        cout << "Position out of range!" << endl;
                        continue;
                    }

                    if(dynamic_cast<Student*>(people[studentNum]) == nullptr ){
                        cout << people[studentNum]->ToString() << " is not a student" << endl;
                        continue;
                    }
                    stu = dynamic_cast<Student*>(people[studentNum]);
                }

                // -- INPUT GRADE
                bool gradeIsValid;
                do {
                    // Validator...
                    gradeIsValid = true;

                    // Input Grade
                    cout << "Grade of the student [0.0 to 4.0]: ";
                    cin >> studentGrade;

                    // If cin fails, clear and ignore everything else
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Incorrect input!" << endl;
                        gradeIsValid = false;
                    } else if (studentGrade > 4.0 || studentGrade < 0.0) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid grade value, make sure [0.0, 4.0]" << endl;
                        gradeIsValid = false;
                    }
                } while (!gradeIsValid);

                // -- INPUT CREDITS
                bool creditsAreValid;
                do{
                    // Validator...
                    creditsAreValid = true;

                    // Input Credits
                    cout << "Credits {1, 2, 3, 4, 5}: ";
                    cin >> studentCredits;

                    // If cin fails, clear and ignore everything else
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Incorrect input!" << endl;
                        creditsAreValid = false;
                    } else if (studentCredits < 1 || studentCredits > 5) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid credit value, make sure {1, 2, 3, 4, 5}: " << endl;
                        creditsAreValid = false;
                    }
                } while (!creditsAreValid);

                // -- ADD GRADE
                Student* student = dynamic_cast<Student*> (people[studentNum]);
                if (student != nullptr){
                    // Add new grade....
                    student -> AddGrade(studentGrade, studentCredits);
                }
            }
        }else if (userOption == 11){	// Promote Professor

            int profIndex = 0;  // counter, student position
            int countProfs = 0; // counter, the actual num of profs
            int profNum;        // user inputs which student to modify, based on counter

            // -- PRINT PROFESSOR + POSITION
            for (Person *person: people) {
                if (dynamic_cast<Professor *>(person) != nullptr) {
                    cout << profIndex << " " << person->ToString() << endl;
                    countProfs++;
                }
                profIndex++;
            }

            // Verify that professors exist...
            if(countProfs == 0){
                cout << "No professors exist for which to promote" << endl;
            } else {
                // -- SELECT PROFESSOR
                Professor* prof = nullptr;
                while( prof == nullptr ) {

                    // Input
                    cout << "Number of professor to promote: ";
                    cin >> profNum;

                    // Input Validation
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Incorrect input!" << endl;
                    }

                    if( profNum < 0 || profNum > people.size()-1){
                        cout << "Position out of range!" << endl;
                        continue;
                    }

                    if(dynamic_cast<Professor*>(people[profNum]) == nullptr ){
                        cout << people[profNum]->ToString() << " is not a professor" << endl;
                        continue;
                    }
                    prof = dynamic_cast<Professor*>(people[profNum]);
                }

                // -- PROMOTE PROFESSOR
                Professor *professor = dynamic_cast<Professor *> (people[profNum]);
                if (professor != nullptr) {
                    // Promote...
                    professor->Promote();
                }
            }
		}else if (userOption == 12){	// Give Raise to Professor

            int profIndex = 0;  // counter, student position
            int countProfs = 0; // counter, the actual num of profs
            int profNum;        // user inputs which student to modify, based on counter
            float raise = 0.0;  // percent of raise (before division by 100)

            // -- PRINT PROFESSOR + POSITION
            for (Person *person: people) {
                if (dynamic_cast<Professor *>(person) != nullptr) {
                    cout << profIndex << " " << person->ToString() << endl;
                    countProfs++;
                }
                profIndex++;
            }

            // Verify that professors exist...
            if(countProfs == 0){
                cout << "No professors exist for which to give a raise" << endl;
            } else {
                // -- SELECT PROFESSOR
                Professor* prof = nullptr;
                while( prof == nullptr ) {

                    // Input
                    cout << "Number of professor to give raise: ";
                    cin >> profNum;

                    // Input Validation
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Incorrect input!" << endl;
                    }

                    if( profNum < 0 || profNum > people.size()-1){
                        cout << "Position out of range!" << endl;
                        continue;
                    }

                    if(dynamic_cast<Professor*>(people[profNum]) == nullptr ){
                        cout << people[profNum]->ToString() << " is not a professor" << endl;
                        continue;
                    }
                    prof = dynamic_cast<Professor*>(people[profNum]);
                }

                // -- INPUT RAISE
                bool raiseIsValid;
                do {
                    // Validator...
                    raiseIsValid = true;

                    // Input Raise Amount
                    cout << "Raise to the professor ]0.0, 50.0]: ";
                    cin >> raise;

                    // If cin fails, clear and ignore everything else
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Incorrect input!" << endl;
                        raiseIsValid = false;
                    } else if (raise > 50.0 || raise < 0.0) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid raise value, make sure ]0.0, 50.0]" << endl;
                        raiseIsValid = false;
                    }
                } while (!raiseIsValid);

                // -- GIVE RAISE TO PROFESSOR
                Professor* professor = dynamic_cast<Professor*> (people[profNum]);
                if (professor != nullptr){
                    // Gives professor a raise...
                    professor -> Raise(raise/100);
                }
            }

		}else if (userOption == 13){	// Load from File

		    // RAN OUT OF TIME TO COMPLETE...

		    /*
            ifstream fileLoad;
            string fileName;

            cout << "Input Filename: ";
            cin >> fileName;

            fileLoad.open(fileName);

            char firstLetter;

            Student* stu;

            if(fileLoad.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
		        cout << "Unable to open file " << fileName << endl;
		    } else {
                while (!fileLoad.eof()) {
                    fileLoad >> firstLetter;

                    if (firstLetter == 'P') {

                        // create new person
                        people.push_back(new Person("Placeholder", Date(1, 1, 1)));
                        people[people.size() - 1]->Read(fileLoad);

                    } else if (firstLetter == 'S') {

                        // create new student
                        people.push_back(new Student("Placeholder", Date
                                (1, 1, 1), "undecided"));
                        people[people.size() - 1]->Read(fileLoad);

                    } else if (firstLetter == 'R') {

                        // create new student
                        people.push_back(new Professor
                        ("Placeholder", Date(0, 0, 0), "undecided"));
                        people[people.size() - 1]->Read(fileLoad);
                    }
                }
            }
            */
		}else if (userOption == 14){	// Write to File

		}
	}
	return 0;
}

size_t Menu(){
	int option = 0;
	while(true){
		cout << "-------------------------------------------" << endl;
		cout << "1. Add a Person" << endl;
		cout << "2. Add a Student" << endl;
		cout << "3. Add a Professor" << endl;
		cout << "4. List all People" << endl;
		cout << "5. Show Students Report" << endl;
		cout << "6. Show Professors Report" << endl;
		cout << "7. Show People (not Professors or Students)" << endl;
		cout << "8. Calculate all Students Average GPA" << endl;
		cout << "9. Calculate all Professors Average Salary" << endl;
		cout << "10. Input Grades to Student" << endl;
		cout << "11. Promote Professor" << endl;
		cout << "12. Give Raise to Professor" << endl;
		cout << "13. Load Data from File" << endl;
		cout << "14. Write Data to File" << endl;
		cout << "15. Exit" << endl;

		cin >> option;
		if (cin.fail()){
			cin.clear();
			cin.ignore(255, '\n');
			cerr << "Incorrect input!" << endl;
			continue;
		}
		if (option < 1 || option > 15){
			cerr << "Incorrect menu option!" << endl;
			continue;
		}
		break;
	}
	cout << endl;
	return static_cast<size_t>(option);
}