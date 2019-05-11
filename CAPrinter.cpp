#include "CAPrinter.hpp"

CAPrinter::CAPrinter() : Cprinter() {}

CAPrinter::CAPrinter(CReferee* start, CReferee* end) : Cprinter(start, end) {}

void CAPrinter::print() const
{
    for (CReferee* pIterator = start_pointer; pIterator <= end_pointer; ++pIterator)
    {
        if (!pIterator->isEmpty())
        {
            std::cout << *pIterator << std::endl;
        }
    }
}