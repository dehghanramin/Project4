#ifndef _CPRINTER_HPP_
#define _CPRINTER_HPP_
#include "Referee.hpp"
#include <cstddef>
#include <iostream>

class Cprinter
{
public:
    Cprinter();
    Cprinter(CReferee*, CReferee*);
    void setStartPointer(CReferee*);
    void setEndPointer(CReferee*);
    virtual void print() const;
protected:
    CReferee* start_pointer;
    CReferee* end_pointer;
};

#endif