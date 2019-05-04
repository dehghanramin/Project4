//Filename: P4.cpp
//Programmer:  Ramin Dehghan                                      CSCI 123, Spring 2019
//Project #4                                                      Instructor:  Timothy Mai
//Due Date:  04/27/2019                                           Date Submitted: 
//Program Description: A referee listing program with various different ways to display content it is holding. Can add, remove, list, ...
//referees. All search algorithms written in linear time. Includes input spinners and function abstractions. Reformatted to prevent the use of
//dynamic varibales for optimization. Now implemented with use of classes instead of structs

#include "Referee.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <fstream>




CReferee referees[10];
constexpr CReferee* END = &referees[((sizeof(referees)/sizeof(*referees)) - 1)];
enum State {EXACT, ID, HIGHER, LOWER, NAME};


int menu();
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
void writeRefereeInfo();
void readRefereeInfo();
void checkOpenFile(std::ifstream&);
void checkOpenFile(std::ofstream&);
void promptUser(std::string const&);
void readFile(std::ifstream&);

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
        std::cin >> *referee;
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
        referee->reset();
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
        referee->setGrade(getGrade());
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
    writeRefereeInfo();
}

//Print functions used in direct output

void output(CReferee* referee, std::ostream& handle)
{
    if (handle && referee)
    {
        handle << *referee;
    }
}

//Helper function: returns a pointer to a slot with a specif ID

CReferee* findSlot(std::string const& s)
{
    for (CReferee* pR = referees; pR <= END; ++pR)
    {
        if (*pR == s)
        {
            return pR;
        }
    }
    return nullptr;
}



std::string getFirstName()
{
    promptUser("Enter First Name: ");
    std::string input;
    std::cin >> input;
    std::cout << std::endl;
    return input;
}



std::string getLastName()
{
    promptUser("Enter Last Name: ");
    std::string input;
    std::cin >> input;
    std::cout << std::endl;
    return input;
}



std::string getID()
{
    promptUser("Enter ID: ");
    std::string input;
    std::cin >> input;
    std::cout << std::endl;
    return input;
}



RefereeGrade getGrade()
{
    promptUser("Select Grade:\n1. CLUB\n2. STATE\n3. NATIONAL\n4. FIFA\n");
    unsigned short grade;
    std::cin >> grade;
    return convertShortToGrade(grade);
    
}




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
        if (!pR->isEmpty())
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
            if (*pR > grade)
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
            if ((pR->getGrade(1) < grade) && (!pR->isEmpty()))
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
            if (*pR == grade)
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
            if (pR->isSameName(first, last))
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
        
        handle<< "|" <<std::string(56, '-') << "|" << std::endl
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
    inStream.open("Referees_input.dat");
    checkOpenFile(inStream);
    readFile(inStream);
    inStream.close(); 
}



void writeRefereeInfo()

{
    std::ofstream outStream;
    outStream.open("Referees.dat");
    checkOpenFile(outStream);
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

void checkOpenFile(std::ifstream& handle)
{
    if (handle.fail())
    {
        std::cerr << "Error in opening file!" << std::endl;
        exit(1);
    }
}

void promptUser(std::string const& prompt)
{
    std::string input;
    std::cout << prompt << std::endl;
}

// void readFile(std::ifstream& ins)
// {
//     std::string id;
//     CReferee* pItr = referees;
//     while(ins >> id)
//     {
//         std::string fname, lname, grade_s;
//         ins >> fname >> lname >> grade_s;
//         pItr->updateReferee(id, fname, lname, convertStringToGrade(grade_s));
//         pItr++;
//     }
// }

void readFile(std::ifstream& ins)
{
    CReferee* pItr = referees;
    while((ins >> *pItr) && (pItr <= END))
    {
        pItr++;
    }
}


void checkOpenFile(std::ofstream& handle)
{
    if (handle.fail())
    {
        std::cerr << "Error in opening file!" << std::endl;
        exit(1);
    }
}

//END