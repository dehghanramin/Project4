#ifndef _CAFPRINTER_HPP_
#define _CAFPRINTER_HPP_
#include "Cprinter.hpp"

class CAFPrinter : public Cprinter
{
public:
    CAFPrinter();
    CAFPrinter(CReferee*, CReferee*, std::ofstream&);
    virtual void print() const;
private:
    std::ofstream& handle;
};

#endif