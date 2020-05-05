/*
 * Title:		professor.h
 * Purpose:		Header file for Professor Class
 * Author:		Rami Isaac
 * Date:		5/4/2020
 */

#ifndef SCHOOL_INHERITANCE_PROFESSOR_H
#define SCHOOL_INHERITANCE_PROFESSOR_H

#include "date.h"

enum Rank {ASSISTANT_PROFESSOR, ASSOCIATE_PROFESSOR, PROFESSOR};

class Professor : public Person {
    string _department;
    Date _hireDate;
    Rank _rank;
    float _salary;
public:
    virtual ~Professor();
    Professor(const string& name, const Date& birthday, const string& department);
    Professor(const string& name, const Date& birthday, const string& department, const Date & hireDate);
    Professor(const string& name, const Date& birthday, const string& department, const Date& hireDate, Rank rank, float salary);

    string ToString()const;

    Rank GetRank()const;
    float GetSalary()const;

    void Raise(float percentage);
    void Promote();

    void Read(istream& input);
    void Write(ostream& output)const;
};

#endif