#include "CSNPrinter.hpp"

CSNPrinter::CSNPrinter() : Cprinter(), first("None"), last("None") {}

CSNPrinter::CSNPrinter(CReferee* start, CReferee* end) :
Cprinter(start, end)
{
    setFirst();
    setLast();
}

void CSNPrinter::print() const
{
    bool empty = true;
    for (CReferee* pIterator = start_pointer; pIterator <= end_pointer; ++pIterator)
    {
        if (pIterator->isSameName(first, last))
        {
            std::cout << *pIterator << std::endl;
            empty = false;
        }
    }
    if (empty)
    {
        printEmpty();
    }
}

void CSNPrinter::setFirst()
{
    first = getFirst();
}

void CSNPrinter::setLast()
{
    last = getLast();
}

std::string CSNPrinter::getFirst() const
{
    std::cout << "Enter First Name: ";
    std::string first;
    std::cin >> first;
    std::cout << std::endl;
    return first;
}

std::string CSNPrinter::getLast() const
{
    std::cout << "Enter Last Name: ";
    std::string last;
    std::cin >> last;
    std::cout << std::endl;
    return last;
}