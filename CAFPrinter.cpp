#include "CAFPrinter.hpp"

CAFPrinter::CAFPrinter() : Cprinter(), handle(handle) {}

CAFPrinter::CAFPrinter(CReferee* start, CReferee* end, std::ofstream& handle) : Cprinter(start, end), handle(handle) {}

void CAFPrinter::print() const
{
    for (CReferee* pIterator = start_pointer; pIterator <= end_pointer; ++pIterator)
    {
        if (!pIterator->isEmpty())
        {
            handle << *pIterator << std::endl;
        }
    }
}