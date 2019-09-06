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
//  FILE:        user_int.h
//
//  DESCRIPTION:
//   This is a header file that contains the function prototype that 
//   are defined in user_int.cpp
//
****************************************************************/

#ifndef USER_INT

#define USER_INT

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <limits>
#include "llist.h"
#include "record.h"

void user_interface(llist &);
void getaddress(char *, int);
int checkName(char *);

#endif
