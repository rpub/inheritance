/*
 * Title:		Professor.cpp
 * Purpose:		Methods for Person Class
 * Author:		Rami Isaac
 * Date:		5/4/2020
 */

#include "date.h"
#include "person.h"
#include "student.h"
#include "professor.h"

#include <iostream>
#include <string>
#include <sstream>
using std::istream;
using std::ostream;
using std::string;
using std::stringstream;
using namespace std;

/**
 * Destructor
 * @param n/a
 * @return true if the date is valid, false otherwise
 */
Professor::~Professor(){}

/**
 * Professor constructor
 * @param name
 * @param birthDay
 * @param string
 * @param department
 * @return -
 */
Professor::Professor(const string& name, const Date& birthDay, const string& department):
        Person(name, birthDay), _department(department){

    // Default values
    _hireDate = Date::Now();     // Sets hire date to today
    _rank = ASSISTANT_PROFESSOR; // Sets rank to Assistant Professor
    _salary = 60000.00;          // Sets initial salary as $60,000

}

/**
 * Professor constructor
 * @param name
 * @param birthDay
 * @param string
 * @param department
 * @return hireDate
 */
Professor::Professor(const string& name, const Date& birthDay, const string& department, const Date & hireDate):
        Person(name, birthDay), _department(department), _hireDate(hireDate){

    // Finds how long a professor has been employed for in years
    int employedFor = (Date::Now().Difference(_hireDate))/365;

    // Uses determined rank to set rank and set salary
    if(employedFor < 5){
        _rank = ASSISTANT_PROFESSOR;
        _salary = 60000;
    } else if (employedFor >= 5 && employedFor < 10){
        _rank = ASSOCIATE_PROFESSOR;
        _salary = 70000;
    } else if (employedFor >= 10){
        _rank = PROFESSOR;
        _salary = 75000;
    }
}

/**
 * Professor constructor
 * @param name
 * @param birthDay
 * @param string
 * @param department
 * @param hireDate
 * @param salary
 * @return -
 */
Professor::Professor(const string& name, const Date& birthDay, const string& department,
        const Date & hireDate, Rank rank, float salary):
        Person(name, birthDay), _department(department), _hireDate(hireDate), _rank(rank), _salary(salary){
}



/**
 * Returns a string representation of the Professor in JSON format:
 * {Person: {name: XXX, birthday: {year: 9999, month: 9, day: 9}}, department: XXX,
 * rank: 9, hire-date: {year: 9999, month: 9, day: 9}, salary: 999.99}
 * @param -
 * @return -
 */
string Professor::ToString()const {
    stringstream ss;
    ss << "{Person: " << Person::ToString()
        << ", department: " << _department << ", rank: " << _rank << ", hire date: "
            << _hireDate.ToString() << ", salary: " << _salary << "}";
    return  ss.str();
}

/**
 * Calculated raise for professor salary
 * @param percentage
 * @return -
 */
void Professor::Raise(float percentage){
    _salary += _salary * percentage;
}

/**
 * Promotes professor
 * @param -
 * @return -
 */
void Professor::Promote(){
    Rank rank = GetRank();
    if(rank == ASSISTANT_PROFESSOR){
        _rank = ASSOCIATE_PROFESSOR;
    } else if (rank == ASSOCIATE_PROFESSOR){
        _rank = PROFESSOR;
    }
}

/**
 * Gets current rank of professor
 * @param -
 * @return -
 */
Rank Professor::GetRank()const{
    return _rank;
}

/**
 * Gets current salary of professor
 * @param -
 * @return -
 */
float Professor::GetSalary()const{
    return _salary;
}

void Professor::Read(istream& input){

}

void Professor::Write(ostream& output)const{

}