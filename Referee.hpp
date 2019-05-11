//Filename: Referee.chpp
//Programmer:  Ramin Dehghan                                      CSCI 123, Spring 2019
//Project #4                                                      Instructor:  Timothy Mai
//Due Date:  04/27/2019                                           Date Submitted: 
//Program Description: A referee listing program with various different ways to display content it is holding. Can add, remove, list, ...
//referees. All search algorithms written in linear time. Includes input spinners and function abstractions. Reformatted to prevent the use of
//dynamic varibales for optimization. Now implemented with use of classes instead of structs

#ifndef _REFEREE_HPP_
#define _REFEREE_HPP_
#include <string>

enum RefereeGrade
{
    #define DEFINE_GRADE(grade, int) grade,
    #include "GradeEnum.hpp"
    #undef DEFINE_GRADE
};

class CReferee
{
    public:
        CReferee(std::string const& = "0000", std::string const& = "None", std::string const& = "None", RefereeGrade const& = UNKNOWN);
        ~CReferee();
        friend std::istream& operator>>(std::ifstream&, CReferee&);
        friend std::ostream& operator<<(std::ofstream&, CReferee&);
        friend std::ostream& operator<<(std::ostream&, CReferee&);
        friend bool operator==(CReferee const&, std::string const&);
        friend bool operator==(CReferee const&, RefereeGrade const&);
        friend bool operator>(CReferee const&, RefereeGrade const&);
        friend bool operator<(CReferee const&, RefereeGrade const&);
        bool isSameName(std::string const&, std::string const&) const;
        void updateReferee(std::string const&, std::string const& , std::string const&, RefereeGrade const&);
        void setGrade(RefereeGrade const&);
        void reset();
        bool isEmpty() const;
    private:
        std::string id;
        std::string firstname;
        std::string lastname;
        RefereeGrade grade;
        RefereeGrade convertStringToGrade(std::string const& input) const;
        std::string convertGradeToString() const;
        void formattedOutput(std::ostream&) const;
        bool isNumeric(char* const) const;
};

#endif