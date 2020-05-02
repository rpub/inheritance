#include "date.h"
#include "person.h"
#include "student.h"
#include "professor.h"


#include <iostream>
#include <vector>

using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::vector;

size_t Menu();

int main(int argc, char* argv[]) {
	vector<Person*> people; // This is the only vector you need, remember to release the memory
	int userOption;
	while ( (userOption = Menu()) != 15){
		if (userOption == 1){			// Add Person

		}else if (userOption == 2){		// Add Student

		}else if (userOption == 3){		// Add Professor

		}else if (userOption == 4){		// List All People

		}else if (userOption == 5){		// Show Students Report

		}else if (userOption == 6){		// Show Professor Report

		}else if (userOption == 7){		// Show !Professor !Student

		}else if (userOption == 8){		// Calculate Average GPA

		}else if (userOption == 9){		// Calculate Average Salary

		}else if (userOption == 10){	// Input Grades to Student

		}else if (userOption == 11){	// Promote Professor

		}else if (userOption == 12){	// Give Raise to Professor

		}else if (userOption == 13){	// Load from File

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
