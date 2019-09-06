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
//  DATE:        April 6, 2019
//
//  FILE:        proj2.cpp
//
//  DESCRIPTION:
//   This file contains the driver for Project 2.
//
//
****************************************************************/

#include <iostream>
#include <string.h>
#include<stdlib.h>
#include "record.h"
#include "user_int.h"
#include "llist.h"

using namespace std;

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   A main function that starts the menu from
//                 the user_interface in user_int.cpp
//
//  Parameters:    argc (int) : The number of command argument
//                 argv (char *) : the string of the command
//                                 argument
//
//  Return values:  0 : success
//
****************************************************************/

int main(int argc, char * argv[])
{
    #ifdef DEBUG

        cout << "\n----------------------DEBUG MODE ACTIVATED----------------------\n";

    #endif

    #ifdef UNIX

        system("sccs edit llist.txt");

    #endif

    char filename[10] = "llist.txt";

    llist linked(filename);

    user_interface(linked);

    #ifdef UNIX

        system("sccs delta -y  llist.txt");

    #endif

    cout << "done";

    return 0;
}
