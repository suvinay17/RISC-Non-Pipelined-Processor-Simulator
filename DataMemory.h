//This is the .h file for the DataMemory
//Written by Suvinay Bothra
//CMSC 301
#ifndef __DATA_MEMORY_H__
#define __DATA_MEMORY_H__
#include <string>
#include <map>
//This h file creates the guidelines for the data memory


class DataMemory
{
   private:
      std::map<char,int> mapping;

   public:
     //Constructor
      DataMemory();
      //Deconstructor
      ~DataMemory();

      // getData returns the data in the specified address
      std::string    getData(std::string address);

      //setData will set the data in the specified address
      std::string    setData(std::string data, std::string address);

};

#endif
