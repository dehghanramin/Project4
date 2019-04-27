#ifndef _REFEREE_HPP_
#define _REFEREE_HPP_
#include <string>

enum RefereeGrade {UNKNOWN, CLUB, STATE, NATIONAL, FIFA};

class CReferee
{
    public:
        CReferee(std::string const& = "0000", std::string const& = "None", std::string const& = "None", RefereeGrade const& = UNKNOWN);
        ~CReferee();
        friend std::istream& operator>>(std::istream&, CReferee&);
        friend std::ostream& operator<<(std::ostream&, CReferee&);
        void updateGrade(RefereeGrade const&);
        std::string getGrade() const;
        std::string getID() const;
        RefereeGrade getGrade(short const&) const;
        std::string getFirstName() const;
        std::string getLastName() const;
        void setGrade(RefereeGrade const&);
        void setID(std::string const&);
        void setFirstName(std::string const&);
        void setLastName(std::string const&);
        void reset();
    private:
        std::string id;
        std::string firstname;
        std::string lastname;
        RefereeGrade grade;
        void promptUser(std::string const&) const;
        RefereeGrade gradeSpinner() const;
        RefereeGrade convertShortToGrade(short const&) const;
        std::string convertGradeToString() const;
        void displayHeader(std::ostream&) const;
        std::string insertFirstName() const;
        std::string insertLastName() const;
        std::string insertID() const;
        std::string insertGrade() const;
        void formattedOutput(std::ostream&) const;
        bool isNumeric(char* const) const;
};

#endif