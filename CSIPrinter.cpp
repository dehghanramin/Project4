#include "CSIPrinter.hpp"

CSIPrinter::CSIPrinter() : Cprinter(), id("R000") {}

CSIPrinter::CSIPrinter(CReferee* start, CReferee* end) : Cprinter(start, end)
{
    setID();
}

void CSIPrinter::setID(std::string const& id_)
{
    id = id_;
}

void CSIPrinter::print() const
{
    bool empty = true;
    for (CReferee* pIterator = start_pointer; pIterator <= end_pointer; ++pIterator)
    {
        if ((!pIterator->isEmpty()) && (*pIterator == id))
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

void CSIPrinter::setID()
{
    id = getID();
}

std::string CSIPrinter::getID() const
{
    std::cout << "Enter ID: ";
    std::string id;
    std::cin >> id;
    std::cout << std::endl;
    return id;
}