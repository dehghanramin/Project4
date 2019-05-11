//Filename: P4.cpp
//Programmer:  Ramin Dehghan                                      CSCI 123, Spring 2019
//Project #4                                                      Instructor:  Timothy Mai
//Due Date:  04/27/2019                                           Date Submitted: 
//Program Description: A referee listing program with various different ways to display content it is holding. Can add, remove, list, ...
//referees. All search algorithms written in linear time. Includes input spinners and function abstractions. Reformatted to prevent the use of
//dynamic varibales for optimization. Now implemented with use of classes instead of structs, print functions implemented using polymorphism

#include "includes.hpp"
using namespace std;

CReferee referees[10];
constexpr CReferee* END = &referees[((sizeof(referees)/sizeof(*referees)) - 1)];

int menu();
void printheader(std::ostream&);
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
void writeRefereeInfo();
void readRefereeInfo();
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

int menu()
{
    short option;
    cout << "\n\tREFEREE ASSIGNING SYSTEM\n\n";
    cout << "1. List All Referees.\n"
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
    cin >> option;
    if (option < 1 || option > 10)
    {
        system("clear");
        cout << "Invalid Entry, Please Try Again!" << std::endl;
        return menu();
    }
    return option;
}

void listAllReferees()
{
    CAPrinter printer(referees, END);
    printheader(cout);
    printer.print();
}

void ListRefereesOfSpecificGrade()
{
    CSGPrinter printer(referees, END);
    printheader(cout);
    printer.print();
}

void listRefereesWithGradeHigherThanSpecifiedGrade()
{
    CHGPrinter printer(referees, END);
    printheader(cout);
    printer.print();
}

void listRefereesWithGradeLowerThanSpecifiedGrade()
{
    CLGPrinter printer(referees, END);
    printheader(cout);
    printer.print();
}

void listRefereeInfoWithId()
{
    CSIPrinter printer(referees, END);
    printheader(cout);
    printer.print();
}

void listRefereeInfoWithNames()
{
    CSNPrinter printer(referees, END);
    printheader(cout);
    printer.print();
}

void addNewReferee()
{
    Cmanager manager(referees, END);
    manager.addRef();
}

void removeReferee()
{
    Cmanager manager(referees, END);
    manager.removeRef();
}

void updateRefereeGrade()
{
    Cmanager manager(referees, END);
    manager.updateRef();
}

void Quit()
{
    cout << "Quitting....." << std::endl;
    writeRefereeInfo();
}

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

void readRefereeInfo()
{
    std::ifstream inStream;
    inStream.open("Referees_input.dat");
    if (inStream.fail())
    {
        std::cerr << "Open failure!";
        exit(1);
    }
    readFile(inStream);
    inStream.close(); 
}

void writeRefereeInfo()
{
    std::ofstream outStream;
    outStream.open("Referees.dat");
    CAFPrinter printer(referees, END, outStream);
    printer.print();
    outStream.close();
}



void readFile(std::ifstream& ins)
{
    CReferee* pItr = referees;
    while((ins >> *pItr) && (pItr <= END))
    {
        ++pItr;
    }
}