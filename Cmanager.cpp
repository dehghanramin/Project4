#include "Cmanager.hpp"

Cmanager::Cmanager() : Ccollection(NULL, NULL) {}

Cmanager::Cmanager(CReferee* start, CReferee* end) : Ccollection(start, end) {}

bool Cmanager::addRef()
{
    for (CReferee* pIterator = start_pointer; start_pointer <= end_pointer; ++pIterator)
    {
        if (pIterator->isEmpty())
        {
            pIterator->updateReferee(getID(), getFirst(), getLast(), toGrade(getGrade()));
            return true;
        }
    }
    return false;
}

bool Cmanager::updateRef()
{
    std::string target = getID();
    for (CReferee* pIterator = start_pointer; start_pointer <= end_pointer; ++pIterator)
    {
        if (*pIterator == target)
        {
            pIterator->setGrade(toGrade(getGrade()));
            return true;
        }
    }
    return false;
}

bool Cmanager::removeRef()
{
    std::string target = getID();
    for (CReferee* pIterator = start_pointer; start_pointer <= end_pointer; ++pIterator)
    {
        if (*pIterator == target)
        {
            pIterator->reset();
            return true;
        }
    }
    return false;
}

std::string Cmanager::getID() const
{
    std::cout << "Enter ID: ";
    std::string input;
    std::cin >> input;
    std::cout << std::endl;
    return input;

}

std::string Cmanager::getFirst() const
{
    std::cout << "Enter First Name: ";
    std::string input;
    std::cin >> input;
    std::cout << std::endl;
    return input;
}
 
std::string Cmanager::getLast() const
{
    std::cout << "Enter Last Name: ";
    std::string input;
    std::cin >> input;
    std::cout << std::endl;
    return input;
}

unsigned short Cmanager::getGrade() const
{
    std::cout << "Select Grade:\n1. CLUB\n2. STATE\n3. NATIONAL\n4. FIFA\n";
    unsigned short input;
    std::cin >> input;
    std::cout << std::endl;
    return input;
}

RefereeGrade Cmanager::toGrade(short const& input) const
{
    switch (input)
    {
        #define DEFINE_GRADE(grade, int) case int: return grade;
        #include "GradeEnum.hpp"
        #undef DEFINE_GRADE
        default: return UNKNOWN;
    }
}