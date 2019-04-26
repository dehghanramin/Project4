#include "Referee.hpp"
#include <iostream>
#include <iomanip>

CReferee::CReferee(std::string const& id_, std::string const& firstname_, std::string const& lastname_, RefereeGrade const& grade_) :
id(id_),
firstname(firstname_),
lastname(lastname_),
grade(grade_) {}

CReferee::~CReferee() {}

void CReferee::setGrade(RefereeGrade const& grade_)
{
    grade = convertShortToGrade(grade_);
}

std::string CReferee::getGrade() const
{
    return convertGradeToString();
}

std::istream& operator>>(std::istream& ins, CReferee& obj) // Equilivant of getInfo()
{
    obj.promptUser("ID");
    std::getline(ins, obj.id);
    obj.promptUser("First Name");
    std::getline(ins, obj.firstname);
    obj.promptUser("Last Name");
    std::getline(ins, obj.lastname);
    obj.grade = obj.gradeSpinner();
    return ins;
}

std::ostream& operator<<(std::ostream& ost, CReferee& obj)
{
    obj.displayHeader(ost);
    obj.formattedOutput(ost);
    return ost;
}

void CReferee::promptUser(std::string const& prompt) const
{
    std::cout << "Please Enter " << prompt << ": ";
}

RefereeGrade CReferee::gradeSpinner() const
{
    std::cout << "\tSelect Grade:\n"
              << "1. UNKNOWN\n"
              << "2. CLUB\n"
              << "3. STATE\n"
              << "4. NATIONAL\n"
              << "5. FIFA" << std::endl;
    char input[2];
    std::cin >> input;
    if (!((atoi(input) > 0) && (atoi(input) < 6)))
    {
        return gradeSpinner();
    }
    return convertShortToGrade(atoi(input));
}

RefereeGrade CReferee::convertShortToGrade(short const& input) const
{
    switch (input)
    {
    case 1:
        return UNKNOWN;
        break;
    case 2:
        return CLUB;
        break;
    case 3:
        return STATE;
        break;
    case 4:
        return NATIONAL;
        break;
    case 5:
        return FIFA;
        break;
    default:
        std::cerr << "Error in conversion!" << std::endl;
        return UNKNOWN;
        break;
    }
}

void CReferee::displayHeader(std::ostream& ost) const
{
    ost << "|" <<std::string(56, '-') << "|" << std::endl
               << "| " << std::setw(12) << "ID" << " |" << std::setw(12)
               << "Fisrt Name" << " |" << std::setw(12)
               << "Last Name" << " |" << std::setw(12)
               << "Grade" << " |"
               << std::endl
               << "|" <<std::string(56, '-') << "|" << std::endl;
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
   ost << "| " << std::setw(12) << id << " |" << std::setw(12)
               << firstname << " |" << std::setw(12)
               << lastname << " |" << std::setw(12)
               << convertGradeToString() << " |" << std::endl
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