#include "Cprinter.hpp"


Cprinter::Cprinter() : Ccollection(NULL, NULL) {}

Cprinter::Cprinter(CReferee* start, CReferee* end) : Ccollection(start, end) {}

void Cprinter::print() const
{
    for (CReferee* pIterator = start_pointer; pIterator <= end_pointer; ++pIterator)
    {
        if (!pIterator->isEmpty())
        {
            std::cout << *pIterator << std::endl;
        }
    }
}

void Cprinter::printEmpty() const
{
    std::cout << std::string(17, ' ') << "Nothing to show here !"
              << std::string(17, ' ') << std::endl;
}