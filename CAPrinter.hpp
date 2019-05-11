#ifndef _CAPRINTER_HPP_
#define _CAPRINTER_HPP_
#include "Cprinter.hpp"

class CAPrinter : public Cprinter
{
public:
    CAPrinter();
    CAPrinter(CReferee*, CReferee*);
    virtual void print() const;
};

#endif