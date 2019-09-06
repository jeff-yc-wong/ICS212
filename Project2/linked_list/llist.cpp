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
//  DATE:        April 7, 2019
//
//  FILE:        llist.cpp
//
//  DESCRIPTION:
//   This is the file that contains the class definition for a linked list
//   used in Project 2
//
//
****************************************************************/

#include "llist.h"

using namespace std;

/*****************************************************************
//
//  Function name: llist
//
//  DESCRIPTION:   A constructor for a linked list with no parameters
//
//  Parameters:    N/A
//
//  Return values:  N/A
//
****************************************************************/

llist::llist()
{
    #ifdef DEBUG
    cout << "\n--------llist() constructor called--------\n";
    #endif

    char file[16] = "llist.txt";

    start = NULL;

    strcpy(file, filename);
}

/*****************************************************************
//
//  Function name: llist
//
//  DESCRIPTION:   A constructor for a linked list with a file as
//                 a parameter
//
//  Parameters:    filename (char *) : The file name to be read from
//
//  Return values:  N/A
//
****************************************************************/

llist::llist(char filename[])
{
    #ifdef DEBUG
    cout << "\n--------llist(char *) constructor called--------\n";
    #endif

    start = NULL;

    strcpy(this->filename, filename);

    readfile();
}

/*****************************************************************
//
//  Function name: ~llist
//
//  DESCRIPTION:   A deconstructor for a linked list that removes
//                 all memory of the linked list in the heap
//
//  Parameters:    N/A
//
//  Return values:  N/A
//
****************************************************************/

llist::~llist()
{
    #ifdef DEBUG
    cout << "\n-------- ~llist() de-constructor called --------\n";
    #endif

    writefile();

    cleanup();
}

/*****************************************************************
//
//  Function name: llist
//
//  DESCRIPTION:   A copy constructor for a linked list
//
//  Parameters:    list (const llist &) : the linked list to be copied from
//
//  Return values:  N/A
//
****************************************************************/

llist::llist(const llist & list)
{
    record *temp2 = list.start;

    while (temp2 != NULL)
    {
        this->addRecord(temp2->accountno, temp2->name, temp2->address);

        temp2 = temp2->next;
    }
}

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   A function that reads the records from a file
//                 then store it in to the linked list
//
//  Parameters:    N/A
//
//  Return values:  0 : successfully read from the file
//                 -1 : reading from file was unsuccessful
//
****************************************************************/

int llist::readfile()
{
    #ifdef DEBUG
    cout << "\n--------readfile method called--------\n";
    #endif

    char *filename;

    char input, address[255], name[255];

    int value, accountno, count;

    ifstream file;

    filename = this->filename;

    value = 0;

    if (strstr(filename, ".txt") != NULL)
    {
        file.open(filename);

        if (file.fail() != 1)
        {
            while (file.get() == '$')
            {
                count = 0;

                file >> accountno;

                file.get();

                file.getline(name, 25);

                while ((input = file.get()) != '$')
                {
                    address[count] = input;

                    count++;
                }

                address[count - 1] = '\0';

                file.get();

                this->addRecord(accountno, name, address);

                memset(address, 0, 255);
            }

            file.close();
        }
        else
        {
            value = -1;
        }    
    }
    else
    {
        value = -1;
    }

    return value;
}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   A function that writes the records stored in a
//                 linked list to the designated file
//
//  Parameters:    N/A
//
//  Return values:  N/A
//
****************************************************************/

void llist::writefile()
{
    #ifdef DEBUG
    cout << "\n--------writefile method called--------\n";
    #endif

    struct record *temp;

    ofstream file;

    temp = start;

    if (strstr(filename, ".txt") != NULL)
    {
        file.open(filename);

        while (temp != NULL)
        {
            file << "$\n";

            file << temp->accountno << "\n";

            file << temp->name << "\n";

            file << temp->address << "\n";

            file << "$\n";

            temp = temp->next;
        }

        file.close();
    }
}

/*****************************************************************
//
//  Function name: reverse
//
//  DESCRIPTION:   A function that reverses the records in a
//                 linked list recursively
//
//  Parameters:    temp (record *) : the first record in the linked
//                                   list
//
//  Return values:  temp (record *) : the record used as the previous
//                                   pointer should point to
//
****************************************************************/

record *    llist::reverse(record * temp)
{
    #ifdef DEBUG
    cout << "\n--------private reverse(record *) method called--------\n";
    #endif

    record *temp2 = NULL;

    if (temp == NULL)
    {
        temp2 = NULL;
    }
    else if (temp->next == NULL)
    {
        start = temp;

        temp2 = temp;
    }
    else
    {
        temp2 = reverse(temp->next);

        temp2->next = temp;

        temp->next = NULL;

        temp2 = temp;
    }

    return temp2;
}

/*****************************************************************
//
//  Function name: cleanup
//
//  DESCRIPTION:   A functIon that removes all records from the heap
//                 space
//
//  Parameters:    N/A
//
//  Return values:  N/A
//
****************************************************************/

void llist::cleanup()
{
    #ifdef DEBUG
    cout << "\n--------cleanup method called--------\n";
    #endif

    record *temp, *temp2;
    if (start != NULL)
    {
        temp = start;
        temp2 = start->next;
        do
        {
            delete(temp);
            temp = temp2;
            if (temp != NULL)
            {
                temp2 = temp->next;
            }
        } 
        while (temp != NULL);
    }
}

/*****************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   A function that adds a record to the database with
//                 the given parameters
//
//  Parameters:    accountnum (int) : the account number of the record
//                                    to be added
//                 name (char *) :  the name of the record to be added
//
//                 address (char *) : the address of the record to be added
//
//  Return values:  0 : success
//                 -1 : the value was not found
//
****************************************************************/

int llist::addRecord(int accountnum, char name[], char address[])
{
    record *temp;

    record *temp2;

    int x;

    x = 0;

    #ifdef DEBUG

    cout << "\n--------addRecord method called with Parameters--------\n"

        << "Account Number: " << accountnum << "\n"

        << "Name: " << name << "\n"

        << "Address: " << address << "\n";

    #endif

    if (this->start == NULL)
    {
        temp = new struct record;

        temp->accountno = accountnum;

        strcpy(temp->name, name);

        strcpy(temp->address, address);

        temp->next = NULL;

        this->start = temp;
    }
    else
    {
        temp = this->start;

        temp2 = NULL;

        do
        {
            if (temp->accountno == accountnum)
            {
                x = -1;
            }

            if (temp->next == NULL)
            {
                temp2 = temp;
            }

            temp = temp->next;
        } 
        while (temp != NULL);

        if (x != -1)
        {
            temp = new struct record;

            temp->accountno = accountnum;

            strcpy(temp->name, name);

            strcpy(temp->address, address);

            temp->next = NULL;

            temp2->next = temp;

            temp = NULL;

            temp2 = NULL;
        }
    }

    return x;
}

/*****************************************************************
//
//  Function name: printRecord
//
//  DESCRIPTION:   A function that prints the record linked with
//                 the given account number
//
//  Parameters:    accountnum : The account number to print
//                              a record for
//
//  Return values:  0 : success
//                 -1 : There is no record with the given
//                      accountnum
//
****************************************************************/

int llist::printRecord(int accountnum)
{
    #ifdef DEBUG
    cout << "\n--------printRecord method called with Parameters:--------\n"

        << "Account Number: " << accountnum << endl;
    #endif

    struct record *temp;

    int returnVal;

    temp = start;

    returnVal = -1;

    while (temp != NULL && returnVal != 0)
    {
        if (temp->accountno == accountnum)
        {
            returnVal = 0;
            cout << "\n----------Record Data----------" << endl
                << "Account Number: " << temp->accountno << endl
                << "Name: " << temp->name << endl
                << "Address: " << temp->address << "\n" << endl;
        }

        temp = temp->next;
    }

    return returnVal;
}

/*****************************************************************
//
//  Function name: findRecords
//
//  DESCRIPTION:   A function that searches for a record whose name
//                 starts with the given name
//
//  Parameters:    name (char *) : the name of the record to find
//
//  Return values:  0 : success
//                 -1 : there are no record whose name starts
//                      with the given string
//
****************************************************************/

int llist::findRecords(char name[])
{
    struct record *temp;

    int returnVal;

    int count;

    temp = start;

    returnVal = -1;

    count = 1;


    #ifdef DEBUG

    cout << "\n--------findRecords method called with Parameters:--------\n"
        << "Name: " << name << "\n";

    #endif


    cout << "\n--------Record(s) Data--------\n";

    while (temp != NULL)
    {
        if (strstr(temp->name, name) - temp->name == 0)
        {
            cout << count << "." << endl;

            cout << "Account Number: " << temp->accountno << endl;

            cout << "Name: " << temp->name << endl;

            cout << "Address: " << temp->address << endl;

            returnVal = 0;

            count++;
        }
        temp = temp->next;
    }

    return returnVal;
}

/*****************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   A function that deletes the record of the given
//                 accountnum
//
//  Parameters:    accountnum (int) : the account number of the record
//                                    to be deleted
//
//  Return values:  0 : success
//                 -1 : record was not deleted
//
****************************************************************/

int llist::deleteRecord(int accountnum)
{
    int returnVal;

    struct record *temp;

    struct record *temp2;

    #ifdef DEBUG

    cout << "\n--------deleteRecord method called--------\n"
        << "Account Number: " << accountnum << endl;

    #endif 

    returnVal = -1;

    if (start == NULL)
    {
        returnVal = -1;
    }
    else
    {
        if (start->accountno == accountnum)
        {
            temp = start->next;

            delete(start);

            start = temp;

            returnVal = 0;
        }
        else
        {
            temp = start;

            temp2 = temp->next;

            do
            {
                if (temp2 == NULL)
                {
                    returnVal = -1;
                }
                else if (temp2->accountno == accountnum)
                {
                    temp->next = temp2->next;

                    delete(temp2);

                    temp2 = NULL;

                    returnVal = 0;
                }
                else
                {
                    temp = temp->next;

                    temp2 = temp2->next;
                }
            } 
            while (temp2 != NULL);
        }
    }

    return returnVal;
}

/*****************************************************************
//
//  Function name: reverse
//
//  DESCRIPTION:   A public method within the llist class that
//                 utilize the private reverse method to be use
//                 for the user
//
//  Parameters:    N/A
//
//  Return values:  N/A
//
****************************************************************/

void llist::reverse()
{
    #ifdef DEBUG

    cout << "\n--------reverse() method called--------\n";

    #endif

    reverse(start);
}

/*****************************************************************
//
//  Function name: operator<<
//
//  DESCRIPTION:   A function that overload the << operator to accept
//                 a linked list and will print  out all the records
//
//  Parameters:    os (ostream &) : the output stream that will store the
//                                  record datas;
//  Parameters:    list (const llist &) : the linked list that contains the
//                                        records to be printed
//
//  Return values: os (ostream &) : the output stream with all
//                                  the record from the linked list
//
****************************************************************/

ostream &operator<<(ostream &os, const llist &list)
{
    #ifdef DEBUG

    cout << "\n--------operator<< method called--------\n";

    #endif

    record *temp;

    int number;

    number = 1;

    temp = list.start;

    if (temp == NULL)
    {
        os << "\nEmpty: There is no record in the database\n";
    }

    while (temp != NULL)
    {
        os << number << "." << endl;

        os << "Account Number: " << temp->accountno << endl;

        os << "Name: " << temp->name << endl;

        os << "Address: " << temp->address << endl;

        number++;

        temp = temp->next;
    }

    return os;
}

llist llist::operator=(const llist & list)
{
    llist copy = llist(list);

    return copy;
}
