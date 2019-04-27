#include "Referee.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;



int menu();
void listAllReferees();
void listRefereesOfSpecificGrade();
void listtRefereesWithGradeHigherThanSpecificGrade();
void listtRefereesWithGradeLowerThanSpecificGrade();
void listtRefereeInfoWithId();
void listtRefereeInfoWithNames();
void addNewReferee();
void removeReferee();
void updateRefereeGrade();
void Quit();
void readRefereeInfo();
void writeRefereeInfo();

CReferee* findSlot(std::string const&);
std::string getFirstName();
std::string getLastName();
std::string getID();
RefereeGrade getGrade();
RefereeGrade convertShortToGrade(unsigned short const&);
void outputError();
void outputNoSlot();
// void brute_search(std::ostream&);
// void brute_search(State const&, RefereeGrade const& = UNKNOWN, std::string const& = "0000", std::string const& = "None", std::string const& = "None");
void printheader(std::ostream&);
void checkOutput(bool const&);
void output(CReferee*, std::ostream&);
void outputFile();



CReferee referees[10];
const CReferee* END = &referees[((sizeof(referees)/sizeof(*referees)) - 1)];
enum State {EXACT, ID, HIGHER, LOWER, NAME};



int main(void)
{
    int choice;
    do
    {
            system("clear");
            choice = menu();
            switch (choice)
            {
            case 1:
                listAllReferees();
                break;
            case 2:
                listRefereesOfSpecificGrade();
                break;
            case 3:
                listtRefereesWithGradeHigherThanSpecificGrade();
                break;
            case 4:
                listtRefereesWithGradeLowerThanSpecificGrade();
                break;
            case 5:
                listtRefereeInfoWithId();
                break;
            case 6:
                listtRefereeInfoWithNames();
                break;
            case 7:
                addNewReferee();
                break;
            case 8:
                removeReferee();
                break;
            case 9:
                updateRefereeGrade();
                break;
            case 10:
                Quit();
                break;
            default:
                cout << "That was an invalid choice, please try again! \n";
            }
    } while (choice > 0 && choice < 10);
}



int menu()
{
    short option;
    cout << "             REFEREE ASSIGNING SYSTEM \n\n";
    cout << " 1.  List All Referees. \n";
    cout << " 2.  List All Referees Of A Specific Grade. \n";
    cout << " 3.  List All Referees With Grade Higher A Specific Grade. \n";
    cout << " 4.  List All Referees With Grade Lower A Specific Grade. \n";
    cout << " 5.  List Referee Information With ID. \n";
    cout << " 6.  List Referee Information With Names. \n";
    cout << " 7.  Add New Referee. \n";
    cout << " 8.  Remove A Referee. \n";
    cout << " 9.  Update Referee Grade. \n";
    cout << "10.  Quit. \n\n";
    cout << "Please select your option: ";
    cin >> option;
    while (option < 1 || option > 10)
    {
        cout << "Invalid option!!! Please select valid option: ";
        cin >> option;
    }
    return option;
}

 

void listAllReferees()
{
    for (CReferee* pItr = referees; pItr <= END; ++pItr)
    {
        if (pItr->getGrade != UNKNOWN)
            cout << *pItr;
    }
}

 

void listRefereesOfSpecificGrade()
{
    cout << "Select Grade:\n"
         << "1. CLUB\n"
         << "2. STATE\n"
         << "3. NATIONAL\n"
         << "4. FIFA" << endl;
    short input;
    cin >> input;
    RefereeGrade grade;
    switch (input)
    {
        case 1:
            grade = CLUB;
            break;
        case 2:
            grade = STATE;
            break;
        case 3:
            grade = NATIONAL;
            break;
        case 4:
            grade = FIFA;
            break;
        default:
            grade = UNKNOWN;
            break;
    }
    for (CReferee* pItr = referees; pItr <= END; ++pItr)
    {
        if (pItr->getGrade == grade)
            cout << *pItr;
    }
}

 

void listtRefereesWithGradeHigherThanSpecificGrade()
{
    cout << "Select Grade:\n"
         << "1. CLUB\n"
         << "2. STATE\n"
         << "3. NATIONAL\n"
         << "4. FIFA" << endl;
    short input;
    cin >> input;
    RefereeGrade grade;
    switch (input)
    {
        case 1:
            grade = CLUB;
            break;
        case 2:
            grade = STATE;
            break;
        case 3:
            grade = NATIONAL;
            break;
        case 4:
            grade = FIFA;
            break;
        default:
            grade = UNKNOWN;
            break;
    }
    for (CReferee* pItr = referees; pItr <= END; ++pItr)
    {
        if (pItr->getGrade > grade)
            cout << *pItr;
    }
}

 

void listtRefereesWithGradeLowerThanSpecificGrade()
{
    cout << "Select Grade:\n"
         << "1. CLUB\n"
         << "2. STATE\n"
         << "3. NATIONAL\n"
         << "4. FIFA" << endl;
    short input;
    cin >> input;
    RefereeGrade grade;
    switch (input)
    {
        case 1:
            grade = CLUB;
            break;
        case 2:
            grade = STATE;
            break;
        case 3:
            grade = NATIONAL;
            break;
        case 4:
            grade = FIFA;
            break;
        default:
            grade = UNKNOWN;
            break;
    }
    for (CReferee* pItr = referees; pItr <= END; ++pItr)
    {
        if (pItr->getGrade < grade)
            cout << *pItr;
    }
}

 

void listtRefereeInfoWithId()
{
    cout << "Enter ID: ";
    string input;
    cin >> input;
    cout << endl;
    for (CReferee* pItr = referees; pItr <= END; ++pItr)
    {
        if (pItr->getID == input)
            cout << *pItr;
    }
}

 

void listtRefereeInfoWithNames()
{
    cout << "Enter name: ";
    string input;
    cin >> input;
    cout << endl;
    for (CReferee* pItr = referees; pItr <= END; ++pItr)
    {
        if (pItr->getFirstName == input || pItr->getLastName == input)
            cout << *pItr;
    }
}

 

void addNewReferee()
{
    for (CReferee* pItr = referees; pItr <= END; ++pItr)
    {
        if (pItr->getID == UNKNOWN)
        {
            cout << "Enter ID: ";
            string id;
            cin >> id;
            cout << endl;
            cout << "Enter First Name: ";
            string fname;
            cin >> fname;
            cout << endl;
            cout << "Enter Last Name: ";
            string lname;
            cin >> lname;
            cout << endl;
            cout << "Select Grade:\n"
                 << "1. CLUB\n"
                 << "2. STATE\n"
                 << "3. NATIONAL\n"
                 << "4. FIFA" << endl;
            short input;
            cin >> input;
            RefereeGrade grade;
            switch (input)
            {
                case 1:
                    grade = CLUB;
                    break;
                case 2:
                    grade = STATE;
                    break;
                case 3:
                    grade = NATIONAL;
                    break;
                case 4:
                    grade = FIFA;
                    break;
                default:
                    grade = UNKNOWN;
                    break;
            }
            pItr->setID(id);
            pItr->setFirstName(fname);
            pItr->setLastName(lname);
            pItr->setGrade(grade);
        }
        break;
    }
}



void removeReferee()
{
    cout << "Enter ID: ";
    string input;
    cin >> input;
    cout << endl;
    for (CReferee* pItr = referees; pItr <= END; ++pItr)
    {
        if (pItr->getID() == input)
        {
            pItr->reset();
            break;
        }
    }
}



void updateRefereeGrade()
{
    cout << "Enter ID: ";
    string input;
    cin >> input;
    cout << endl;
    for (CReferee* pItr = referees; pItr <= END; ++pItr)
    {
        if (pItr->getID() == input)
        {
            cout << "Select Grade:\n"
                 << "1. CLUB\n"
                 << "2. STATE\n"
                 << "3. NATIONAL\n"
                 << "4. FIFA" << endl;
            short input;
            cin >> input;
            RefereeGrade grade;
            switch (input)
            {
                case 1:
                    grade = CLUB;
                    break;
                case 2:
                    grade = STATE;
                    break;
                case 3:
                    grade = NATIONAL;
                    break;
                case 4:
                    grade = FIFA;
                    break;
                default:
                    grade = UNKNOWN;
                    break;
            }
            pItr->setGrade(grade);
            break;
        }
    }
}



void Quit()
{
    writeRefereeInfo();
    cout << "Quitting......." << endl;
}



void readRefereeInfo()

{
    cout << "Inside readRefereeInfo () \n\n";  //Remove when starting coding
}



void writeRefereeInfo()

{
    cout << "Inside writeRefereeInfo () \n\n";  //Remove when starting coding
}