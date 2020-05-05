/*
 * Title:		person.h
 * Purpose:		Header file for Person Class
 * Author:		Rami Isaac
 * Date:		5/4/2020
 */
#ifndef SCHOOL_INHERITANCE_PERSON_H
#define SCHOOL_INHERITANCE_PERSON_H

#include "date.h"

class Person {
    string _name;
    Date _birthDay;
public:
    virtual ~Person();
    Person(const string& name, const Date& birthday);
    Person(const string& name, size_t year, size_t month, size_t day);

    virtual string ToString()const;

    string GetName()const;
    size_t GetAge()const;

    void Read(istream& input);
    void Write(ostream& output)const;
};

#endif