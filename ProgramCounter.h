//This is the .h file for the ProgramCounter
//Written by Suvinay Bothra
//CMSC 301
#ifndef __PROGRAM_COUNTER_H__
#define __PROGRAM_COUNTER_H__
#include <string>
//This h file creates the guidelines for the program counter
//methods are string type for testing

class ProgramCounter
{
   private:
      std::string     currentAddress;

   public:
      ProgramCounter();
      ProgramCounter(std::string address);
      ~ProgramCounter();

      // getCurrentAddress returns the current address of the PC

      std::string    getCurrentAddress();

      //setAddress will set the address in the PC
      //this is for branch and j type instructions. Main calls
      std::string    setAddress(std::string newAddress);

};

#endif
