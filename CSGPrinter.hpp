#ifndef _CSGPRINTER_HPP_
#define _CSGPRINTER_HPP_
#include "Cprinter.hpp"

class CSGPrinter : public Cprinter
{
public:
    CSGPrinter();
    CSGPrinter(CReferee*, CReferee*, RefereeGrade const&);
    void setGrade(RefereeGrade const&);
    virtual void print() const;
private:
    RefereeGrade grade;
};

#endif