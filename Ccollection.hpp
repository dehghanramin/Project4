#ifndef _CCOLLECTION_HPP_
#define _CCOLLECTION_HPP_
#include <cstddef>
#include "Referee.hpp"

class Ccollection
{
public:
    Ccollection();
    Ccollection(CReferee*, CReferee*);
    void setStartPointer(CReferee*);
    void setEndPointer(CReferee*);
protected:
    CReferee* start_pointer;
    CReferee* end_pointer;
};

#endif