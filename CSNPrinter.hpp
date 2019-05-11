#ifndef _CSNPRINTER_HPP_
#define _CSNPRINTER_HPP_
#include "Cprinter.hpp"

class CSNPrinter : public Cprinter
{
public:
    CSNPrinter();
    CSNPrinter(CReferee*, CReferee*);
    virtual void print() const;
private:
    std::string first;
    std::string last;
    void setFirst();
    void setLast();
    std::string getFirst() const;
    std::string getLast() const;
};

#endif