#include "Ccollection.hpp"

Ccollection::Ccollection() : start_pointer(NULL), end_pointer(NULL) {}

Ccollection::Ccollection(CReferee* start, CReferee* end) : start_pointer(start), end_pointer(end) {}

void Ccollection::setStartPointer(CReferee* pointer_input)
{
    start_pointer = pointer_input;
}

void Ccollection::setEndPointer(CReferee* pointer_input)
{
    end_pointer = pointer_input;
}