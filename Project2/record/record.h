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
//  FILE:        record.h
//
//  DESCRIPTION:
//   This file contains the function prototype for the record structure
//   used in Project 2
//
//
****************************************************************/

#ifndef RECORD_H

#define RECORD_H

struct record
{
    int              accountno;
    char             name[25];
    char             address[80];
    struct record           *next;
};

#endif
