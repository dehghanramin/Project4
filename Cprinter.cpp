#include "Cprinter.hpp"

Cprinter::Cprinter() : start_pointer(NULL), end_pointer(NULL) {}

void Cprinter::setStartPointer(CReferee* pointer_input)
{
    start_pointer = pointer_input;
}

void Cprinter::setEndPointer(CReferee* pointer_input)
{
    end_pointer = pointer_input;
}

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