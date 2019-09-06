/*****************************************************************
//
//  NAME:        Yick Ching Wong
//
//  HOMEWORK:    Project 2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        April 10, 2019
//
//  FILE:        user_int.c
//
//  DESCRIPTION:
//   This file contains the user & menu interface used for
//   Project 2
//
****************************************************************/

#include <limits>
#include "user_int.h"

using namespace std;

/*****************************************************************
//
//  Function name: user_interface
//
//  DESCRIPTION:   A user interface function that takes a linked list
//
//  Parameters:    list (llist &) : the list to be used for the database
//
//  Return values:  N/A
//
****************************************************************/

void user_interface(llist & list)
{
    int running = 1;

    while (running == 1)
    {
        int input;
        int accountnum;
        int valid;
        char name[100];
        char address[80];

        cout << "\nHello welcome to the ICS212 Bank Database!\n"
            "    1. Add a new record in the database\n"
            "    2. Print information about a record using the accountno as"
            " the key\n"
            "    3. Print all information in the database\n"
            "    4. Print records whose names start with the given string as"
            " a key\n"
            "    5. Delete an existing record from the database using the"
            " accountno as a key\n"
            "    6. Reverse the list of records\n"
            "    7. Quit the program\n"
            "Please enter the above menu number to select what you want to do: ";

        cin >> input;

        switch (input)
        {
            case 1:
                system("clear");

                cin.get();

                cout << "Aloha!";

                cout << "\nYou have selected the Add Record Option\n";

                cout << "Please enter the account number of the record you wish to add: ";

                cin >> accountnum;

                while (cin.fail() == 1)
                {
                    cin.clear();

                    cin.ignore(numeric_limits <streamsize>::max(), '\n');

                    cout << "Error invalid account number, please enter the account number again: ";

                    cin >> accountnum;
                }

                cin.ignore(numeric_limits <streamsize>::max(), '\n');

                cout << "Please enter the name: ";

                cin.getline(name, 24);

                valid = checkName(name);

                while (valid == -1)
                {
                    if (valid == -1)
                    {
                        cout << "\nError: Name contains special characters, Please Enter Again: ";
                    }
                    else
                    {
                        cout << "\nError: Name exceeds 25 characters, Please Enter Again: ";
                    }

                    memset(name, 0, sizeof(name));

                    cin.getline(name, sizeof name);

                    valid = checkName(name);
                }

                cout << "Please enter the address, Press $ and Enter when done:\n";

                getaddress(address, static_cast<int>(sizeof(address)));

                while (static_cast<char>(address[0]) == 0)
                {
                    cout << "\nError: Address exceed characters limit\n";

                    cout << "\nPlease enter the address again, press $ and Enter when done:\n";

                    getaddress(address, sizeof(address));
                }

                if (list.addRecord(accountnum, name, address) == -1)
                {
                    cout << "\nError: Record not added, Record with the"

                         << "same account number already existed\n";
                }
                else
                {
                    cout << "\nRecord with account #" << accountnum << " was successfully added!\n";
                }

                break;

            case 2:
                system("clear");

                cout << "Aloha!";

                cout << "\nYou have selected the Print a Record Option\n";

                cout << "Please enter the account number of the record you want to find: ";

                cin >> accountnum;

                while (cin.fail() == 1)
                {
                    cin.ignore(numeric_limits <streamsize>::max(), '\n');

                    cout << "Error invalid account number, please enter account number again: ";

                    cin >> accountnum;
                }

                cin.ignore(numeric_limits <streamsize>::max(), '\n');

                if (list.printRecord(accountnum) == -1)
                {
                    cout << "\nThere is no record linked with the given account number\n";
                }

                break;

            case 3:
                system("clear");

                cout << "Aloha! You have selected the print all record Option";

                cout << "\n----------Printing All Record(s)----------";

                cout << list;

                break;

            case 4:
                system("clear");

                getchar();

                cout << "Aloha!";

                cout << "\nYou have selected the Find Record Option\n";

                cout << "Please enter the name of user you want to find: ";

                cin.getline(name, sizeof(name));

                valid = checkName(name);

                while (valid == -1)
                {
                    if (valid == -1)
                    {
                        cout << "\nError: Name contains special characters, Please Enter Again: ";
                    }
                    else
                    {
                        cout << "\nError: Name exceeds 25 characters, Please Enter Again: ";
                    }

                    memset(name, 0, sizeof(name));

                    cin.getline(name, sizeof name);

                    valid = checkName(name);
                }

                if (list.findRecords(name) == -1)
                {
                    cout << "\nThere are no record whose name starts with " <<  name << "\n";
                }

                break;

            case 5:
                system("clear");

                cout << "Aloha!";

                cout << "\nYou have selected the Delete Record Option\n";

                cout << "Please enter the account number of the record you want to delete: ";

                cin >> accountnum;

                while (cin.fail() == 1)
                {
                    cin.clear();

                    cin.ignore(numeric_limits <streamsize>::max(), '\n');

                    cout << "Error invalid account number, please enter account number again: ";

                    cin >> accountnum;
                }

                cin.ignore(numeric_limits <streamsize>::max(), '\n');

                if (list.deleteRecord(accountnum) != 0)
                {
                    cout << "\nError: Record #" << accountnum

                         << " does not exist in the database\n";
                }
                else
                {
                    cout << "\nRecord #" << accountnum << " was successfully deleted\n";
                }

                break;

            case 6:
                system("clear");

                cout << "\n----------Reversing the list---------\n";

                list.reverse();

                cout << "The list have been reversed\n";

                break;

            case 7:
                system("clear");

                cout << "Thank you for visiting the ICS212 Bank Database!\n";

                cout << "We hope to see you soon!\n";

                running = 0;

                break;
            default:
                system("clear");

                cin.clear();

                cin.ignore(numeric_limits <streamsize>::max(), '\n');

                cout << "\nError: The Number You Enter is Invalid!\n\n";
        }
    }
}

/*****************************************************************
//
//  Function name: getaddress
//
//  DESCRIPTION:   AThis function obtains the address from the
//                 user
//
//  Parameters:    output[](char *) : where the address is being
//                                    outputted
//                 limit (int) : the maximum length of an
//                               address
//
//  Return values:  N/A
//
****************************************************************/

void getaddress(char output[], int limit)
{
    cin.getline(output, limit, '$');

    if (cin.fail() == 1)
    {
        cin.clear();

        cin.ignore(numeric_limits <streamsize>::max(), '\n');

        memset(output, 0, 255);
    }
}

/*****************************************************************
//
//  Function name: checkName
//
//  DESCRIPTION:   A function that checks if the name inputted
//                 is valid
//
//  Parameters:    name[](char *) : the name inputted
//
//  Return values:  0 : name is valid
//                 -1 : the name was not valid
//                 -2 : the name is too long
//
****************************************************************/

int checkName(char name[])
{
    int i;

    i = 0;

    while (name[i] != '\0' && i != -1)
    {
        if ((name[i] >= 65 && name[i] <= 90) || (name[i] >= 97 && name[i] <= 122)
            || name[i] == ' ' || name[i] == '\n')
        {
            i++;
        }
        else
        {
            i = -1;
        }
    }

    if (i > 24)
    {
        i = -2;
    }

    if (i != -1 && i != -2)
    {
        i = 0;
    }

    return i;
}
