#ifndef _CSIPRINTER_HPP_
#define _CSIPRINTER_HPP_
#include "Cprinter.hpp"

class CSIPrinter : public Cprinter
{
public:
    CSIPrinter();
    CSIPrinter(CReferee*, CReferee*);
    void setID(std::string const&);
    virtual void print() const;
private:
    std::string id;
    void setID();
    std::string getID() const;
};

#endif