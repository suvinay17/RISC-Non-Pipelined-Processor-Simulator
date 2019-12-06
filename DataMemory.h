//This is the .h file for the DataMemory
//Written by Suvinay Bothra
//CMSC 301
#ifndef __DATA_MEMORY_H__
#define __DATA_MEMORY_H__
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
//This h file creates the guidelines for the data memory


class DataMemory
{
   private:
      std::map<std::string,std::string> mapping;

   public:
     //Constructor
      DataMemory();
      DataMemory(std::string address, std::string data);
      //Deconstructor
      ~DataMemory();

      // getData returns the data in the specified address
      std::string    getData(std::string address);

      //setData will set the data in the specified address
      void    setData(std::string address, std::string data);
      void dataMemoryPrintFinal(string memoryFile);
      void dataMemoryPrint();
};

#endif
