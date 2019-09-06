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
//  DATE:        April 3, 2019
//
//  FILE:        llist.h
//
//  DESCRIPTION:
//   This file contains the function prototype of the class linked list
//   used for Project 2
//
//
****************************************************************/

#ifndef LLIST_H

#define LLIST_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include "record.h"
#include "llist.h"

using namespace std;

class llist
{
private:
    record *    start;
    /*char        filename[16];*/
    int         readfile();
    void        writefile();
    record *    reverse(record *);
    void        cleanup();

public:
    char        filename[16];
    llist();
    llist(char[]);
    ~llist();
    llist(const llist &);
    int addRecord(int, char[], char[]);
    int printRecord(int);
    friend ostream& operator<<(ostream &, const llist &);
    llist operator=(const llist &);
    int findRecords(char[]);
    int deleteRecord(int);
    void reverse();
};

#endif
