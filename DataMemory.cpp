//This code implements DataMemory
//Written by Suvinay
//CMSC301
#ifndef __DATA_MEMORY_CPP__
#define __DATA_MEMORY_CPP__

#include "DataMemory.h"
#include <vector>
#include <string>
#include <map>
using namespace std;
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
void DataMemory::setData(std::string address, std::string data)
    {
            this->mapping[address] = data;
           // return this->mapping[address];
    }

void DataMemory::dataMemoryPrint()
{

  map<string,string>::iterator itr = mapping.begin();
  itr++;
  while(it != mapping.end())
  {
    cout<< itr->first << ":" << itr->second <<endl;
    itr++;
  }
}
            
 void DataMemory::dataMemoryPrintFinal(string memoryFile)
            {
              ofstream file;
              file.open(memoryFile);
              map<string,string>::iterator itr = mapping.begin();
              itr++;
              while(itr != mapping.end())
                   {
                       file<< itr->first << ":" << itr->second <<endl;
                       itr++;
                   }
              file.close()   
             }
                                     
#endif
