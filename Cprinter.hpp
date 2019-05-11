#ifndef _CPRINTER_HPP_
#define _CPRINTER_HPP_
#include "Ccollection.hpp"
#include <iostream>

class Cprinter : public Ccollection
{
public:
    Cprinter();
    Cprinter(CReferee*, CReferee*);
protected:
    virtual void print() const;
    virtual void printEmpty() const;
};

#endif