#ifndef _CSNPRINTER_HPP_
#define _CSNPRINTER_HPP_
#include "Cprinter.hpp"

class CSNPrinter : public Cprinter
{
public:
    CSNPrinter();
    CSNPrinter(CReferee*, CReferee*, std::string const&, std::string const&);
    void setFirst(std::string const&);
    void setLast(std::string const&);
    virtual void print() const;
private:
    std::string first;
    std::string last;
};

#endif