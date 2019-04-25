#include <iostream>
#include <string>
#include "Referee.hpp"
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



CReferee referees[10];



void main()
{
    int choice;
    do {
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
    cout << "Inside listAllReferees () \n\n";
}

 

void listRefereesOfSpecificGrade()
{
    cout << "Inside listRefereesOfSpecificGrade () \n\n";
}

 

void listtRefereesWithGradeHigherThanSpecificGrade()
{
    cout << "Inside listtRefereesWithGradeHigherThanSpecificGrade () \n\n";
}

 

void listtRefereesWithGradeLowerThanSpecificGrade()
{
    cout << "Inside listtRefereesWithGradeLowerThanSpecificGrade () \n\n";
}

 

void listtRefereeInfoWithId()
{
    cout << "Inside listtRefereeInfoWithId () \n\n";
}

 

void listtRefereeInfoWithNames()
{
    cout << "Inside listtRefereeInfoWithNames () \n\n";
}

 

void addNewReferee()
{
    cout << "Inside addNewReferee () \n\n";
}



void removeReferee()
{
    cout << "Inside removeReferee () \n\n";
}



void updateRefereeGrade()
{
    cout << "Inside updateRefereeGrade () \n\n";
}



void Quit()
{
    writeRefereeInfo();
    cout << "Have a nice day \n\n";
}



void readRefereeInfo()

{
    cout << "Inside readRefereeInfo () \n\n";  //Remove when starting coding
}



void writeRefereeInfo()

{
    cout << "Inside writeRefereeInfo () \n\n";  //Remove when starting coding
}