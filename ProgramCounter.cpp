//This code implements __PROGRAM_COUNTER
//Written by Suvinay
//CMSC301
#ifndef __PROGRAM_COUNTER_CPP__
#define __PROGRAM_COUNTER_CPP__

#include "ProgramCounter.h"
#include <stdio.h>
#include <string>

//Contstructor for creating ProgramCounter
ProgramCounter::ProgramCounter(){}

//Parametrized Constructor
ProgramCounter::ProgramCounter(std::string address)
{
    this->currentAddress = address;
}

//Deconstructor
ProgramCounter::~ProgramCounter(){}

// getCurrentAddress will return the current address of the ProgramCounter
std::string    ProgramCounter::getCurrentAddress()
        {
            return currentAddress;
        }

/*
setAddress will set the address in the ProgramCounter to a given address
used for j type and branch instructions
returning current address for testing purposes
*/
std::string    ProgramCounter::setAddress(std::string newAddress)
    {
            this->currentAddress = newAddress;
            return currentAddress;
    }

#endif
