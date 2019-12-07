//This code implements __PROGRAM_COUNTER
//Written by Suvinay
//CMSC301
#ifndef __PROGRAM_COUNTER_CPP__
#define __PROGRAM_COUNTER_CPP__

#include "ProgramCounter.h"
#include "HelperFunctions.h"
#include <stdio.h>
#include <string>

using namespace std;

//Contstructor for creating ProgramCounter
ProgramCounter::ProgramCounter(){}

//Parametrized Constructor
ProgramCounter::ProgramCounter(string address)
{
    this->currentAddress = address;
}

//Deconstructor
ProgramCounter::~ProgramCounter(){}

// getCurrentAddress will return the current address of the ProgramCounter
string    ProgramCounter::getCurrentAddress()
        {
            return currentAddress;
        }

/*
setAddress will set the address in the ProgramCounter to a given address
used for j type and branch instructions
returning current address for testing purposes
*/
string    ProgramCounter::setAddress(string newAddress)
    {
            this->currentAddress = newAddress;
            return currentAddress;
    }


#endif
