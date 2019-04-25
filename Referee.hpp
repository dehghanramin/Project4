#ifndef _REFEREE_HPP_
#define _REFEREE_HPP_
#include <string>

enum RefereeGrade {UNKNOWN, CLUB, STATE, NATIONAL, FIFA};

class CReferee
{
    public:
        CReferee(std::string const& = "R000", std::string const& = "None", std::string const& = "None", RefereeGrade const& = UNKNOWN);
        ~CReferee();
    private:
        std::string id;
        std::string firstname;
        std::string lastname;
        RefereeGrade grade;
};

#endif