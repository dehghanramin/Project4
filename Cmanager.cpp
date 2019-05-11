#include "Cmanager.hpp"

Cmanager::Cmanager() : Ccollection(NULL, NULL) {}

Cmanager::Cmanager(CReferee* start, CReferee* end) : Ccollection(start, end) {}

void Cmanager::addRef()
{
    bool found = false;
    for (CReferee* pIterator = start_pointer; pIterator <= end_pointer; ++pIterator)
    {
        if (pIterator->isEmpty())
        {
            pIterator->updateReferee(getID(), getFirst(), getLast(), toGrade(getGrade()));
            found = true;
            break;
        }
    }
    if (!found)
        printFound();
}

void Cmanager::updateRef()
{
    bool found = false;
    std::string target = getID();
    for (CReferee* pIterator = start_pointer; pIterator <= end_pointer; ++pIterator)
    {
        if (*pIterator == target)
        {
            pIterator->setGrade(toGrade(getGrade()));
            found = true;
            break;
        }
    }
    if (!found)
        printFound();
}

void Cmanager::removeRef()
{
    bool found = false;
    std::string target = getID();
    for (CReferee* pIterator = start_pointer; pIterator <= end_pointer; ++pIterator)
    {
        if (*pIterator == target)
        {
            pIterator->reset();
            found = true;
            break;
        }
    }
    if (!found)
        printFound();
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

void Cmanager::printFound() const
{
    std::cout << std::string(14, ' ')
                  << "Nothing found here!!" << std::string(14, ' ')
                  << std::endl;
}