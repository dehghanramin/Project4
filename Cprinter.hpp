#ifndef _CPRINTER_HPP_
#define _CPRINTER_HPP_
#include "Referee.hpp"
#include <cstddef>
#include <iostream>

class Cprinter
{
public:
    Cprinter();
    void setStartPointer(CReferee*);
    void setEndPointer(CReferee*);
    virtual void print() const;
private:
    CReferee* start_pointer;
    CReferee* end_pointer;
};

#endif