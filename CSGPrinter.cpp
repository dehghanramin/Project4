#include "CSGPrinter.hpp"

CSGPrinter::CSGPrinter() : Cprinter(), grade(UNKNOWN) {}

CSGPrinter::CSGPrinter(CReferee* start, CReferee* end, RefereeGrade const& grade) : Cprinter(start, end), grade(grade) {}

void CSGPrinter::setGrade(RefereeGrade const& grade_)
{
    grade = grade_;
}

void CSGPrinter::print() const
{
    for (CReferee* pIterator = start_pointer; pIterator <= end_pointer; ++pIterator)
    {
        if (*pIterator == grade)
        {
            std::cout << *pIterator << std::endl;
        }
    }
}