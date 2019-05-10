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


std::string CReferee::getGrade() const
{
    return convertGradeToString();
}

std::istream& operator>>(std::ifstream& ins, CReferee& obj) // Equilivant of getInfo()
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

void CReferee::promptUser(std::string const& prompt) const
{
    std::cout << "Please Enter " << prompt << ": ";
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




std::string CReferee::insertFirstName() const
{
    return firstname;
}

std::string CReferee::insertLastName() const
{
    return lastname;
}

std::string CReferee::insertID() const
{
    return id;
}

std::string CReferee::insertGrade() const
{
    return convertGradeToString();
}

std::string CReferee::convertGradeToString() const
{
    switch (grade)
    {
    case UNKNOWN:
        return "UNKNOWN";
        break;
    case CLUB:
        return "CLUB";
        break;
    case STATE:
        return "STATE";
        break;
    case NATIONAL:
        return "NATIONAL";
        break;
    case FIFA:
        return "FIFA";
        break;
    default:
        std::cerr << "Error in conversion!" << std::endl;
        return "Error";
        break;
    }
}

void CReferee::formattedOutput(std::ostream& ost) const
{
   ost << id << std::setw(12)
        << firstname << std::setw(12)
        << lastname << std::setw(12)
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

std::string CReferee::getID() const
{
    return id;
}

std::string CReferee::getFirstName() const
{
    return firstname;
}

std::string CReferee::getLastName() const
{
    return lastname;
}

void CReferee::setID(std::string const& id_)
{
    id = id_;
}

void CReferee::setFirstName(std::string const& firstname_)
{
    firstname = firstname_;
}

void CReferee::setLastName(std::string const& lastname_)
{
    lastname = lastname_;
}

void CReferee::setGrade(RefereeGrade const& grade_)
{
    grade = grade_;
}

void CReferee::reset()
{
    id = "0000";
    firstname = "None";
    lastname = "None";
    grade = UNKNOWN;
}

RefereeGrade CReferee::getGrade(short const& i) const
{
    return grade;
}

bool CReferee::isEmpty() const
{
    return (id == "0000");
}

bool operator==(CReferee const& obj, CReferee const& ibj)
{
    return (obj.id == ibj.id);
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

std::istream& operator>>(std::istream& ins, CReferee& obj)
{
    obj.promptUser("ID");
    ins >> obj.id;
    std::cout << std::endl;
    obj.promptUser("First Name");
    ins >> obj.firstname;
    std::cout << std::endl;
    obj.promptUser("Last Name");
    ins >> obj.lastname;
    std::cout << std::endl;
    obj.promptUser("Grade");
    std::string grade;
    ins >> grade;
    std::cout << std::endl;
    obj.grade = obj.convertStringToGrade(grade);
    return ins;
}

std::ostream& operator<<(std::ostream& ost, CReferee& obj)
{
    obj.formattedOutput(ost);
    return ost;
}