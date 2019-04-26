#ifndef _REFEREE_HPP_
#define _REFEREE_HPP_
#include <string>

enum RefereeGrade {UNKNOWN, CLUB, STATE, NATIONAL, FIFA};

class CReferee
{
    public:
        CReferee(std::string const& = "R000", std::string const& = "None", std::string const& = "None", RefereeGrade const& = UNKNOWN);
        ~CReferee();
        friend std::istream& operator>>(std::istream&, CReferee&);
        friend std::ostream& operator<<(std::ostream&, CReferee&);
        void updateGrade(RefereeGrade const&);
        std::string getGrade() const;
        void setGrade(RefereeGrade const&);
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