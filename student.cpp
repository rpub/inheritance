/*
 * Title:		person.cpp
 * Purpose:		Methods for Student Class
 * Author:		Rami Isaac
 * Date:		5/4/2020
 */

#include "date.h"
#include "person.h"
#include "student.h"

#include <iostream>
#include <string>
#include <sstream>
using std::istream;
using std::ostream;
using std::string;
using std::stringstream;
using namespace std;

Student::~Student(){}

Student::Student(const string &name, const Date &birthDay):Person(name, birthDay){
    // Default values
    _major = 'undecided';
    _credits = 0;
    _gpa = 0.0;
}

Student::Student(const string &name, const Date &birthDay, const string& major):
    Person(name, birthDay), _major(major){

}

string Student::ToString()const {
    stringstream ss;
    ss << "{Person: " << Person::ToString() << ", major: " << _major << ", gpa: " << _gpa << ", credits:" << _credits << "}";
    return  ss.str();
}

float Student::GetGPA()const{
    return _gpa;
}

size_t Student::GetCredits()const{
    return _credits;
}

void Student::AddGrade(float grade, size_t credits){
    // GPA = (Old Points) + (New Points) / Total Credits
    _gpa = ((_credits*_gpa)+(grade*credits))/(credits+_credits);
    // New, Total Credits = Old Credits + New Credits
    _credits += credits;
}

void Student::Read(istream& input){

}

void Student::Write(ostream& output)const{

}