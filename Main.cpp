//The main class that simulates the operation of the processor
//Written by Suvinay, Jimmy, Caleb
#ifndef __MAIN_CPP__
#define __MAIN_CPP__

#include "ProgramCounter.h"
#include "Multiplexor.h"
#include "ALU.h"
#include "DataMemory.h"
#include "ALUControl.h"
#include "SLL.h"
#include "HelperFunctions.h"
#include "Parser.h"
#include ".h"
#include "ProgramCounter.h"
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>

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

