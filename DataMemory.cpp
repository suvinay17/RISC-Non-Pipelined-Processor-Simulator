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

//Printing the contents of the data memory
void DataMemory::dataMemoryPrint()
{
//using an iterator to get contents of the data memory
  map<string,string>::iterator itr = mapping.begin();
  itr++;
  while(itr != mapping.end())
  {

    cout<< itr->first << ": " << "0x" <<  itr->second <<endl;
    itr++;

  }
}

//Priting the contents of the data memory to the output file            
 void DataMemory::dataMemoryPrintFinal(string memoryFile)
            {
//using an iterator to get contents of the data memory
              ofstream file;
              file.open(memoryFile);
              map<string,string>::iterator itr = mapping.begin();
              itr++;
              while(itr != mapping.end())
                   {
                       file<< itr->first << ": " << "0x" << itr->second <<endl;
                       itr++;
                   }
              file.close();
   
             }
                                     
#endif
