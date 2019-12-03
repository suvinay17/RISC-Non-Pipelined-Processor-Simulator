//This code implements DataMemory
//Written by Suvinay
//CMSC301
#ifndef __DATA_MEMORY_CPP__
#define __DATA_MEMORY_CPP__

#include "DataMemory.h"
#include <vector>
#include <string>
#include <map>

//Contstructor for creating DataMemory
DataMemory::DataMemory(){}



//Parametrized Constructor
DataMemory::DataMemory(std::string address, std::string data)
{
    this->mapping[address] = data;
}

//Deconstructor
DataMemory::~DataMemory(){}

// getData will return the data in the provided address
std::string    DataMemory::getData(std::string address)
        {
            return this->mapping[address];
        }

/*
setData will set data to the given address, the return type is string for test purposes
*/
std::string    DataMemory::setData(std::string address, std::string data)
    {
            this->mapping[address] = data;
            return this->mapping[address];
    }

#endif
