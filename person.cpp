/*
 * Title:		person.cpp
 * Purpose:		Methods for Person Class
 * Author:		Rami Isaac
 * Date:		5/4/2020
 */

#include "person.h"
#include "date.h"

#include <iostream>
#include <string>
#include <sstream>
using std::istream;
using std::ostream;
using std::string;
using std::stringstream;
using namespace std;

Person::~Person(){}

Person::Person(const string &name, const Date &birthDay): _name(name), _birthDay(birthDay) {

}

Person::Person(const string &name, size_t year, size_t month, size_t day)
        : _name(name), _birthDay(Date(year, month, day)) {
}

string Person::ToString() const {
    stringstream ss;
    ss << "{name: " << _name << ", birthday: " << _birthDay.ToString() << "}";
    return ss.str();
}

string Person::GetName() const {
    return _name;
}

size_t Person::GetAge() const {
    return _birthDay.Difference(Date::Now()) / 365;
}

void Person::Read(istream& input){

}

void Person::Write(ostream& output)const{

}