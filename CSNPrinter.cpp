#include "CSNPrinter.hpp"

CSNPrinter::CSNPrinter() : Cprinter(), first("None"), last("None") {}

CSNPrinter::CSNPrinter(CReferee* start, CReferee* end, std::string const& first, std::string const& last) :
Cprinter(start, end), first(first), last(last) {}

void CSNPrinter::setFirst(std::string const& first_)
{
    first = first_;
}

void CSNPrinter::setLast(std::string const& last_)
{
    last = last_;
}

void CSNPrinter::print() const
{
    for (CReferee* pIterator = start_pointer; pIterator <= end_pointer; ++pIterator)
    {
        if (pIterator->isSameName(first, last))
        {
            std::cout << *pIterator << std::endl;
        }
    }
}