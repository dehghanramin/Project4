#ifndef _CLGPRINTER_HPP_
#define _CLGPRINTER_HPP_
#include "Cprinter.hpp"

class CLGPrinter : public Cprinter
{
public:
    CLGPrinter();
    CLGPrinter(CReferee*, CReferee*);
    virtual void print() const;
private:
    RefereeGrade grade;
    void setGrade();
    RefereeGrade getGrade() const;
    RefereeGrade toGrade(unsigned short const&) const;
};

#endif