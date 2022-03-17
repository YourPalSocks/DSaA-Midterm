/* Ethan Heinlein CIS.2207.502
* Midterm Project
* Create a class to hold Rainfall Statistics. This class will be a LinkedList.
*
* The program will have the following:

    Driver.cpp -- Contains the main and any unique subroutines.
    Rainfall.h -- Contains the header information for the Rainfall class
    Rainfall.cpp -- Contains the implementation of the Rainfall class
    List.h -- Contains the header information for your linked list class.
    List.cpp -- Contains the implementation

Implement:

    ListInterface.h in Listing 8-1 on pp. 261-262.
    Node.h
    PrecondViolatedExcept.h
    LinkedList.h in Listing 9-2 on p. 273-274.

*/

#include <iostream>
#include "Rainfall.h"
using namespace std;

//Function definitions
bool checkMonth(string month);

int main()
{
    //Private Variables
    char menuChoice;
    Rainfall rainStats;
    do
    {
        //Display the menu
        cout << "Enter your choice: " << endl;
        cout << "A -- Add a month of statistics" << endl;
        cout << "E -- Edit a month of statistics" << endl;
        cout << "P -- Print Report" << endl;
        cout << "Q -- Quit" << endl;
        cout << "Choice: ";
        //Get input
        cin >> menuChoice;
        //Generify input
        menuChoice = toupper(menuChoice);
        switch (menuChoice)
        {
        default:
            cout << "ERORR: Menu selection not valid" << endl;
            system("pause");
            break;

        case('A'): //Add Month's data
        {
            //Make variables to hold input
            string month = "";
            float rainFall;
            //Get input
            cout << "Enter Month (first 3 letters): ";
            cin >> month;
            cout << endl << "Enter Rainfall (in Inches): ";
            cin >> rainFall;
            //Assure month is correct
            bool check = checkMonth(month);
            if (check)
            {
                rainStats.addMonth(month, rainFall);
            }
            else
            {
                cout << "ERROR: Month invalid or already exists" << endl;
                system("pause");
            }
            break;
        }

        case('E'): // Edit Month's data
        {
            //Make variables to hold input
            string month = "";
            float rainFall;
            //Get input
            cout << "Enter Month to change (first 3 letters): ";
            cin >> month;
            cout << endl << "Enter Rainfall (in Inches): ";
            cin >> rainFall;
            //Make sure month is valid
            bool check = checkMonth(month);
            if (check)
            {
                //Do edit task and check for success
                bool taskStatus = rainStats.editMonth(month, rainFall);
                if (!taskStatus) //Uh oh, didn't work
                {
                    cout << "ERROR: Month not in database" << endl;
                    system("pause");
                }
            }
            else
            {
                cout << "ERROR: Month invalid, returning to menu" << endl;
                system("pause");
            }
            break;
        }

        case('P'): // Print report to console
            cout << rainStats.getInfo() << endl;
            system("pause");
            break;

        case('Q'): // Quit
            cout << "Now leaving..." << endl;
            break;
        }
        system("cls");
    } while (toupper(menuChoice) != 'Q');
    return 0;
}

/** Checks whether the month inputted is valid
*/
bool checkMonth(string month)
{
    string months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    bool valid = false;
    for (string m : months)
    {
        if (m._Equal(month))
        {
            valid = true;
            return valid;
        }
    }
    return valid;
}