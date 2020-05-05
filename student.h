/*
 * Title:		student.h
 * Purpose:		Header file for Student Class
 * Author:		Rami Isaac
 * Date:		5/4/2020
 */
#ifndef SCHOOL_INHERITANCE_STUDENT_H
#define SCHOOL_INHERITANCE_STUDENT_H

#include "date.h"

class Student : public Person {
    string _major;
    size_t _credits;
    float _gpa;
public:
    virtual ~Student();
    Student(const string& name, const Date& birthday);
    Student(const string& name, const Date& birthday, const string& major);

    virtual string ToString()const;

    float GetGPA()const;
    size_t GetCredits()const;

    void AddGrade(float grade, size_t credits);

    void Read(istream& input);
    void Write(ostream& output)const;
};

#endif