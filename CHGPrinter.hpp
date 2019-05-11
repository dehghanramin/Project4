#ifndef _CHGPRINTER_HPP_
#define _CHGPRINTER_HPP_
#include "Cprinter.hpp"

class CHGPrinter : public Cprinter
{
public:
    CHGPrinter();
    CHGPrinter(CReferee*, CReferee*);
    virtual void print() const;
private:
    RefereeGrade grade;
    void setGrade();
    RefereeGrade getGrade() const;
    RefereeGrade toGrade(unsigned short const&) const;
};

#endif