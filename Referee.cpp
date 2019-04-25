#include "Referee.hpp"

CReferee::CReferee(std::string const& id_, std::string const& firstname_, std::string const& lastname_, RefereeGrade const& grade_) :
id(id_),
firstname(firstname_),
lastname(lastname_),
grade(grade_) {}

CReferee::~CReferee() {}

