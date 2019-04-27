#include "Referee.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
// using namespace std;



// int menu();
// void listAllReferees();
// void listRefereesOfSpecificGrade();
// void listtRefereesWithGradeHigherThanSpecificGrade();
// void listtRefereesWithGradeLowerThanSpecificGrade();
// void listtRefereeInfoWithId();
// void listtRefereeInfoWithNames();
// void addNewReferee();
// void removeReferee();
// void updateRefereeGrade();
// void Quit();
// void readRefereeInfo();
// void writeRefereeInfo();

// CReferee* findSlot(std::string const&);
// std::string getFirstName();
// std::string getLastName();
// std::string getID();
// RefereeGrade getGrade();
// RefereeGrade convertShortToGrade(unsigned short const&);
// void outputError();
// void outputNoSlot();
// // void brute_search(std::ostream&);
// // void brute_search(State const&, RefereeGrade const& = UNKNOWN, std::string const& = "0000", std::string const& = "None", std::string const& = "None");
// void printheader(std::ostream&);
// void checkOutput(bool const&);
// void output(CReferee*, std::ostream&);
// void outputFile();



CReferee referees[10];
const CReferee* END = &referees[((sizeof(referees)/sizeof(*referees)) - 1)];
enum State {EXACT, ID, HIGHER, LOWER, NAME};



// int main(void)
// {
//     int choice;
//     do
//     {
//             system("clear");
//             choice = menu();
//             switch (choice)
//             {
//             case 1:
//                 listAllReferees();
//                 break;
//             case 2:
//                 listRefereesOfSpecificGrade();
//                 break;
//             case 3:
//                 listtRefereesWithGradeHigherThanSpecificGrade();
//                 break;
//             case 4:
//                 listtRefereesWithGradeLowerThanSpecificGrade();
//                 break;
//             case 5:
//                 listtRefereeInfoWithId();
//                 break;
//             case 6:
//                 listtRefereeInfoWithNames();
//                 break;
//             case 7:
//                 addNewReferee();
//                 break;
//             case 8:
//                 removeReferee();
//                 break;
//             case 9:
//                 updateRefereeGrade();
//                 break;
//             case 10:
//                 Quit();
//                 break;
//             default:
//                 cout << "That was an invalid choice, please try again! \n";
//             }
//     } while (choice > 0 && choice < 10);
// }



// int menu()
// {
//     short option;
//     cout << "             REFEREE ASSIGNING SYSTEM \n\n";
//     cout << " 1.  List All Referees. \n";
//     cout << " 2.  List All Referees Of A Specific Grade. \n";
//     cout << " 3.  List All Referees With Grade Higher A Specific Grade. \n";
//     cout << " 4.  List All Referees With Grade Lower A Specific Grade. \n";
//     cout << " 5.  List Referee Information With ID. \n";
//     cout << " 6.  List Referee Information With Names. \n";
//     cout << " 7.  Add New Referee. \n";
//     cout << " 8.  Remove A Referee. \n";
//     cout << " 9.  Update Referee Grade. \n";
//     cout << "10.  Quit. \n\n";
//     cout << "Please select your option: ";
//     cin >> option;
//     while (option < 1 || option > 10)
//     {
//         cout << "Invalid option!!! Please select valid option: ";
//         cin >> option;
//     }
//     return option;
// }

 

// void listAllReferees()
// {
//     for (CReferee* pItr = referees; pItr <= END; ++pItr)
//     {
//         if (pItr->getGrade != UNKNOWN)
//             cout << *pItr;
//     }
// }

 

// void listRefereesOfSpecificGrade()
// {
//     cout << "Select Grade:\n"
//          << "1. CLUB\n"
//          << "2. STATE\n"
//          << "3. NATIONAL\n"
//          << "4. FIFA" << endl;
//     short input;
//     cin >> input;
//     RefereeGrade grade;
//     switch (input)
//     {
//         case 1:
//             grade = CLUB;
//             break;
//         case 2:
//             grade = STATE;
//             break;
//         case 3:
//             grade = NATIONAL;
//             break;
//         case 4:
//             grade = FIFA;
//             break;
//         default:
//             grade = UNKNOWN;
//             break;
//     }
//     for (CReferee* pItr = referees; pItr <= END; ++pItr)
//     {
//         if (pItr->getGrade == grade)
//             cout << *pItr;
//     }
// }

 

// void listtRefereesWithGradeHigherThanSpecificGrade()
// {
//     cout << "Select Grade:\n"
//          << "1. CLUB\n"
//          << "2. STATE\n"
//          << "3. NATIONAL\n"
//          << "4. FIFA" << endl;
//     short input;
//     cin >> input;
//     RefereeGrade grade;
//     switch (input)
//     {
//         case 1:
//             grade = CLUB;
//             break;
//         case 2:
//             grade = STATE;
//             break;
//         case 3:
//             grade = NATIONAL;
//             break;
//         case 4:
//             grade = FIFA;
//             break;
//         default:
//             grade = UNKNOWN;
//             break;
//     }
//     for (CReferee* pItr = referees; pItr <= END; ++pItr)
//     {
//         if (pItr->getGrade > grade)
//             cout << *pItr;
//     }
// }

 

// void listtRefereesWithGradeLowerThanSpecificGrade()
// {
//     cout << "Select Grade:\n"
//          << "1. CLUB\n"
//          << "2. STATE\n"
//          << "3. NATIONAL\n"
//          << "4. FIFA" << endl;
//     short input;
//     cin >> input;
//     RefereeGrade grade;
//     switch (input)
//     {
//         case 1:
//             grade = CLUB;
//             break;
//         case 2:
//             grade = STATE;
//             break;
//         case 3:
//             grade = NATIONAL;
//             break;
//         case 4:
//             grade = FIFA;
//             break;
//         default:
//             grade = UNKNOWN;
//             break;
//     }
//     for (CReferee* pItr = referees; pItr <= END; ++pItr)
//     {
//         if (pItr->getGrade < grade)
//             cout << *pItr;
//     }
// }

 

// void listtRefereeInfoWithId()
// {
//     cout << "Enter ID: ";
//     string input;
//     cin >> input;
//     cout << endl;
//     for (CReferee* pItr = referees; pItr <= END; ++pItr)
//     {
//         if (pItr->getID == input)
//             cout << *pItr;
//     }
// }

 

// void listtRefereeInfoWithNames()
// {
//     cout << "Enter name: ";
//     string input;
//     cin >> input;
//     cout << endl;
//     for (CReferee* pItr = referees; pItr <= END; ++pItr)
//     {
//         if (pItr->getFirstName == input || pItr->getLastName == input)
//             cout << *pItr;
//     }
// }

 

// void addNewReferee()
// {
//     for (CReferee* pItr = referees; pItr <= END; ++pItr)
//     {
//         if (pItr->getID == UNKNOWN)
//         {
//             cout << "Enter ID: ";
//             string id;
//             cin >> id;
//             cout << endl;
//             cout << "Enter First Name: ";
//             string fname;
//             cin >> fname;
//             cout << endl;
//             cout << "Enter Last Name: ";
//             string lname;
//             cin >> lname;
//             cout << endl;
//             cout << "Select Grade:\n"
//                  << "1. CLUB\n"
//                  << "2. STATE\n"
//                  << "3. NATIONAL\n"
//                  << "4. FIFA" << endl;
//             short input;
//             cin >> input;
//             RefereeGrade grade;
//             switch (input)
//             {
//                 case 1:
//                     grade = CLUB;
//                     break;
//                 case 2:
//                     grade = STATE;
//                     break;
//                 case 3:
//                     grade = NATIONAL;
//                     break;
//                 case 4:
//                     grade = FIFA;
//                     break;
//                 default:
//                     grade = UNKNOWN;
//                     break;
//             }
//             pItr->setID(id);
//             pItr->setFirstName(fname);
//             pItr->setLastName(lname);
//             pItr->setGrade(grade);
//         }
//         break;
//     }
// }



// void removeReferee()
// {
//     cout << "Enter ID: ";
//     string input;
//     cin >> input;
//     cout << endl;
//     for (CReferee* pItr = referees; pItr <= END; ++pItr)
//     {
//         if (pItr->getID() == input)
//         {
//             pItr->reset();
//             break;
//         }
//     }
// }



// void updateRefereeGrade()
// {
//     cout << "Enter ID: ";
//     string input;
//     cin >> input;
//     cout << endl;
//     for (CReferee* pItr = referees; pItr <= END; ++pItr)
//     {
//         if (pItr->getID() == input)
//         {
//             cout << "Select Grade:\n"
//                  << "1. CLUB\n"
//                  << "2. STATE\n"
//                  << "3. NATIONAL\n"
//                  << "4. FIFA" << endl;
//             short input;
//             cin >> input;
//             RefereeGrade grade;
//             switch (input)
//             {
//                 case 1:
//                     grade = CLUB;
//                     break;
//                 case 2:
//                     grade = STATE;
//                     break;
//                 case 3:
//                     grade = NATIONAL;
//                     break;
//                 case 4:
//                     grade = FIFA;
//                     break;
//                 default:
//                     grade = UNKNOWN;
//                     break;
//             }
//             pItr->setGrade(grade);
//             break;
//         }
//     }
// }



// void Quit()
// {
//     writeRefereeInfo();
//     cout << "Quitting......." << endl;
// }



// void readRefereeInfo()

// {
//     cout << "Inside readRefereeInfo () \n\n";  //Remove when starting coding
// }



// void writeRefereeInfo()

// {
//     cout << "Inside writeRefereeInfo () \n\n";  //Remove when starting coding
// }




//--------------------------------------------------------------------------------------------------------------------------------------------
int menu();
// std::string convertGradeToString(RefereeGrade const&);
CReferee* findSlot(std::string const&);
std::string getFirstName();
std::string getLastName();
std::string getID();
RefereeGrade getGrade();
RefereeGrade convertShortToGrade(unsigned short const&);
RefereeGrade convertStringToGrade(std::string const&);
void outputError();
void outputNoSlot();
void brute_search(std::ostream&);
void brute_search(State const&, RefereeGrade const& = UNKNOWN, std::string const& = "0000", std::string const& = "None", std::string const& = "None");
void printheader(std::ostream&);
void checkOutput(bool const&);
void listAllReferees();
void ListRefereesOfSpecificGrade();
void listRefereesWithGradeHigherThanSpecifiedGrade();
void listRefereesWithGradeLowerThanSpecifiedGrade();
void listRefereeInfoWithId();
void listRefereeInfoWithNames();
void addNewReferee();
void removeReferee();
void updateRefereeGrade();
void Quit();
void output(CReferee*, std::ostream&);
void outputFile();
void readRefereeInfo();

int main(void)
{
    readRefereeInfo();
    int choice;
    do
    {
        choice = menu();
        system("clear");
        switch (choice)
        {
            case 1:
                listAllReferees();
                break;
            case 2:
                ListRefereesOfSpecificGrade();
                break;
            case 3:
                listRefereesWithGradeHigherThanSpecifiedGrade();
                break;
            case 4:
                listRefereesWithGradeLowerThanSpecifiedGrade();
                break;
            case 5:
                listRefereeInfoWithId();
                break;
            case 6:
                listRefereeInfoWithNames();
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
                std::cerr << "Invalid option: please retry!" << std::endl;
                break;
        }
    } while (choice > 0 && choice < 10);
    
    return 0;
}

//Function Implementations

int menu()
{
    short option;
    std::cout << "\n\tREFEREE ASSIGNING SYSTEM\n\n";
    std::cout << "1. List All Referees.\n"
              << "2. List All Referees Of A Specific Grade.\n"
              << "3. List All Referees With Grade Higher Than A Specific Value.\n"
              << "4. List All Referees With Grade Lower Than A specific Value.\n"
              << "5. List Referee Information With ID.\n"
              << "6. List Referee Information With Name.\n"
              << "7. Add New Referee.\n"
              << "8. Remove Referee.\n"
              << "9. Update Referee Grade.\n"
              << "10. Quit.\n" << std::endl
              << "Please select your option: ";
    std::cin >> option;
    if (option < 1 || option > 10)
    {
        system("clear");
        std::cout << "Invalid Entry, Please Try Again!" << std::endl;
        return menu();
    }
    return option;
}



void listAllReferees()
{
    brute_search(std::cout);
}



void ListRefereesOfSpecificGrade()
{
    brute_search(EXACT, getGrade());
}



void listRefereesWithGradeHigherThanSpecifiedGrade()
{
    brute_search(HIGHER, getGrade());
}



void listRefereesWithGradeLowerThanSpecifiedGrade()
{
    brute_search(LOWER, getGrade());
}



void listRefereeInfoWithId()
{
    brute_search(ID, UNKNOWN, getID());
}



void listRefereeInfoWithNames()
{
    brute_search(NAME, UNKNOWN, "0000", getFirstName(), getLastName());
}



void addNewReferee()
{
    if (CReferee* referee = findSlot("0000"))
    {
        referee->setFirstName(getFirstName());
        referee->setLastName(getLastName());
        referee->setID(getID());
        referee->setGrade(getGrade());
    }
    else
    {
        outputNoSlot();
    }
}



void removeReferee()
{
    if (CReferee* referee = findSlot(getID()))
    {
        referee->getFirstName() = "None";
        referee->getLastName() = "None";
        referee->getID() = "0000";
        referee->getGrade() = UNKNOWN;
        std::cout << "Referee Removed!" << std::endl;
    }
    else
    {
        outputError();
    }
}



void updateRefereeGrade()
{
    if (CReferee* referee = findSlot(getID()))
    {
        referee->getGrade() = getGrade();
        std::cout << "Grade Updated!" << std::endl;
    }
    else
    {
        outputError();
    }
}



void Quit()
{
    std::cout << "Quitting....." << std::endl;
    outputFile();
}

//Print functions used in direct output

void output(CReferee* referee, std::ostream& handle)
{
    if (handle && referee)
    {
        (handle)
              << "| " << std::setw(12) << referee->getID() << " |" << std::setw(12)
              << referee->getFirstName() << " |" << std::setw(12)
              << referee->getLastName() << " |" << std::setw(12)
              << referee->getGrade() << " |" << std::endl
              << std::endl;
    }
}

//Helper function: returns a pointer to a slot with a specif ID

CReferee* findSlot(std::string const& s)
{
    for (CReferee* pR = referees; pR <= END; ++pR)
    {
        if (pR->getID() == s)
        {
            return pR;
        }
    }
    return nullptr;
}



std::string getFirstName()
{
    std::string input;
    std::cout << "Enter First Name: ";
    std::cin >> input;
    std::cout << std::endl;
    return input;
}



std::string getLastName()
{
    std::string input;
    std::cout << "Enter Last Name: ";
    std::cin >> input;
    std::cout << std::endl;
    return input;
}



std::string getID()
{
    std::string input;
    std::cout << "Enter ID: ";
    std::cin >> input;
    std::cout << std::endl;
    return input;
}



RefereeGrade getGrade()
{
    std::cout << "Select Grade:\n"
              << "1. CLUB\n"
              << "2. STATE\n"
              << "3. NATIONAL\n"
              << "4. FIFA" << std::endl;
    unsigned short grade;
    std::cin >> grade;
    return convertShortToGrade(grade);
    
}

//Output helper function

void outputFile()
{
    std::ofstream outStream;
    outStream.open("Referees.dat");
    brute_search(outStream);
    outStream.close();
}



// std::string convertGradeToString(RefereeGrade const& grade)
// {
//     switch (grade)
//     {
//     case UNKNOWN:
//         return "UNKNOWN";
//         break;
//     case CLUB:
//         return "CLUB";
//         break;
//     case STATE:
//         return "STATE";
//         break;
//     case NATIONAL:
//         return "NATIONAL";
//         break;
//     case FIFA:
//         return "FIFA";
//         break;
//     default:
//         std::cerr << "Error in conversion!" << std::endl;
//         return "UNKNOWN";
//         break;
//     }
// }

//Output helper function: detects if no output has been made.

void checkOutput(bool const& parity)
{
    if (!parity)
    {
        std::cout << "|               Sorry! Nothing to show here              |" << std::endl;
    }
}

//General output function used for outputting all referees.

void brute_search(std::ostream& handle)
{
    printheader(handle);
    for (CReferee* pR = referees; pR <= END; ++pR)
    {
        if (pR->getID() != "0000")
        {
            output(pR, handle);
        }
    }

}

//General search function to find & output referees based on State.

void brute_search(State const& state, RefereeGrade const& grade, std::string const& cond, std::string const& first, std::string const& last)
{
    bool found = false;
    switch (state)
    {
    case ID:
        printheader(std::cout);
        if (CReferee* ref = findSlot(cond))
        {
            output(ref, std::cout);
            found = true;
        }
        break;
    case HIGHER:
        printheader(std::cout);
        for (CReferee* pR = referees; pR <= END; ++pR)
        {
            if (pR->getGrade(1) > grade)
            {
                output(pR, std::cout);
                found = true;
            }
        }
        break;
    case LOWER:
        printheader(std::cout);
        for (CReferee* pR = referees; pR <= END; ++pR)
        {
            if ((pR->getGrade(1) < grade) && ((pR->getGrade(1))))
            {
                output(pR, std::cout);
                found = true;
            }
        }
        break;
    case EXACT:
        printheader(std::cout);
        for (CReferee* pR = referees; pR <= END; ++pR)
        {
            if (pR->getGrade(1) == grade)
            {
                output(pR, std::cout);
                found = true;
            }
        }
        break;
    case NAME:
        printheader(std::cout);
        for (CReferee* pR = referees; pR <= END; ++pR)
        {
            if ((pR->getFirstName() == first) || (pR->getLastName() == last))
            {
                output(pR, std::cout);
                found = true;
            }
        }
        break;
    default:
        std::cout << "Error in conversion!" << std::endl;
        break;
    }
    checkOutput(found);
}

//Print Header Information for output.

void printheader(std::ostream& handle)
{
    if (handle)
    {
        (handle)
              << "|" <<std::string(56, '-') << "|" << std::endl
              << "| " << std::setw(12) << "ID" << " |" << std::setw(12)
              << "Fisrt Name" << " |" << std::setw(12)
              << "Last Name" << " |" << std::setw(12)
              << "Grade" << " |"
              << std::endl
              << "|" <<std::string(56, '-') << "|" << std::endl;
    }
}


RefereeGrade convertShortToGrade(unsigned short const& input)
{
    switch (input)
    {
    case 1:
        return CLUB;
        break;
    case 2:
        return STATE;
        break;
    case 3:
        return NATIONAL;
        break;
    case 4:
        return FIFA;
        break;
    default:
        std::cout << "Wrong format: please try again!" << std::endl;
        return getGrade();
        break;
    }
}



void outputError()
{
    std::cout << "Wrong input try again!" << std::endl;
}



void outputNoSlot()
{
    std::cout << "Error: No empty slots or invalid entry!" << std::endl;
}


void readRefereeInfo()

{
    std::ifstream inStream;
    inStream.open("Referees.dat");
    if (inStream.fail())
    {
        std::cerr << "Error in opening file!" << std::endl;
        exit(1);
    }
    std::string id;
    CReferee* pItr = referees;
    while(inStream >> id)
    {
        std::string fname, lname, grade_s;
        inStream >> fname >> lname >> grade_s;
        RefereeGrade grade = convertStringToGrade(grade_s);
        pItr->setID(id);
        pItr->setFirstName(fname);
        pItr->setLastName(lname);
        pItr++->setGrade(grade);
    }
    inStream.close();
    
}



void writeRefereeInfo()

{
    std::ofstream outStream;
    outStream.open("Referees.dat");
    brute_search(outStream);
    outStream.close();
}

RefereeGrade convertStringToGrade(std::string const& input)
{
    if (input == "UNKNOWN")
    {
        return UNKNOWN;
    }
    else if (input == "CLUB")
    {
        return CLUB;
    }
    else if (input == "STATE")
    {
        return STATE;
    }
    else if (input == "NATIONAL")
    {
        return NATIONAL;
    }
    else if (input == "FIFA")
    {
        return FIFA;
    }
    else
    {
        std::cerr << "Invalid input! Default: UNKNOWN" << std::endl;
        return UNKNOWN;
    }
}


//END