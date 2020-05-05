 /*
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

    srand(time(NULL)); // apparently this is important

    size_t year = 0, day = 0, month = 0;
    string name;

    cout << "Name: ";
    cin >> name;
    cout << "Birth date yyyy mm dd: ";
    cin >> year >> month >> day;

    Person person(name, Date(year, month, day));

    cout << person.ToString() << endl;

    cout << "Age: " << person.GetAge() << endl;

    return 0;
}
 */