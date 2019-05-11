//Filename: Referee.cpp
//Programmer:  Ramin Dehghan                                      CSCI 123, Spring 2019
//Project #4                                                      Instructor:  Timothy Mai
//Due Date:  04/27/2019                                           Date Submitted: 
//Program Description: A referee listing program with various different ways to display content it is holding. Can add, remove, list, ...
//referees. All search algorithms written in linear time. Includes input spinners and function abstractions. Reformatted to prevent the use of
//dynamic varibales for optimization. Now implemented with use of classes instead of structs

#include "Referee.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>

CReferee::CReferee(std::string const& id_, std::string const& firstname_, std::string const& lastname_, RefereeGrade const& grade_) :
id(id_),
firstname(firstname_),
lastname(lastname_),
grade(grade_) {}

CReferee::~CReferee() {}

std::istream& operator>>(std::ifstream& ins, CReferee& obj)
{
    ins >> obj.id;
    ins >> obj.firstname;
    ins >> obj.lastname;
    std::string grade;
    ins >> grade;
    obj.grade = obj.convertStringToGrade(grade);
    return ins;
}

std::ostream& operator<<(std::ofstream& ost, CReferee& obj)
{
    obj.formattedOutput(ost);
    return ost;
}

RefereeGrade CReferee::convertStringToGrade(std::string const& input) const
{ 
    if (input == "UNKNOWN")
    {
        return UNKNOWN;
    }
    else if (input == "CLUB")
    {
        return CLUB;
    }
    else if (input == "STATE")
    {
        return STATE;
    }
    else if (input == "NATIONAL")
    {
        return NATIONAL;
    }
    else if (input == "FIFA")
    {
        return FIFA;
    }
}

std::string CReferee::convertGradeToString() const
{
    switch (grade)
    {
        #define DEFINE_GRADE(grade, int) case grade: return #grade;
        #include "GradeEnum.hpp"
        #undef DEFINE_GRADE
        default: return "ERROR";
    }
}

void CReferee::formattedOutput(std::ostream& ost) const
{
   ost << std::setw(12) << id << std::setw(14)
        << firstname << std::setw(14)
        << lastname << std::setw(14)
        << convertGradeToString() << std::endl
        << std::endl;
}

bool CReferee::isNumeric(char* const pInput) const
{
  for (char* pIterator = pInput; *pIterator != '\0'; ++pIterator)
  {
    if (isdigit(*pIterator))
      return false;
  }
  return true;
}

void CReferee::reset()
{
    id = "0000";
    firstname = "None";
    lastname = "None";
    grade = UNKNOWN;
}

bool CReferee::isEmpty() const
{
    return (id == "0000");
}

bool operator==(CReferee const& obj, std::string const& input)
{
    return (obj.id == input);
}

bool operator==(CReferee const& obj, RefereeGrade const& grade_)
{
    return (obj.grade == grade_);
}

bool operator>(CReferee const& obj, RefereeGrade const& grade_)
{
    return (obj.grade > grade_);
}

bool operator<(CReferee const& obj, RefereeGrade const& grade_)
{
    return (obj.grade < grade_);
}

bool CReferee::isSameName(std::string const& fname, std::string const& lname) const
{
    return (firstname == fname || lastname == lname);
}

void CReferee::updateReferee(std::string const& id_, std::string const& fname, std::string const& lname, RefereeGrade const& grade_)
{
    id = id_;
    firstname = fname;
    lastname = lname;
    grade = grade_;
}

std::ostream& operator<<(std::ostream& ost, CReferee& obj)
{
    obj.formattedOutput(ost);
    return ost;
}

void CReferee::setGrade(RefereeGrade const& input)
{
    grade = input;
}