#ifndef _REGISTERTABLE_H
#define _REGISTERTABLE_H

#include <string>
#include <map>
#include <iostream>
#include <fstream>
using namespace std;

/* This class stores information about the valid register names for MIPS.
 */

typedef int Register;
const int NumRegisters = 32;

struct RegisterEntry{
  string name;
  Register number;
  string value;
};

class RegisterTable{
 public:
  RegisterTable();

  // Given a string representing a MIPS register operand, returns the number associated
  // with that register.  If string is not a valid register, returns NumRegisters.
  Register getNum(string reg);                      //returns the numerical value of the register
  string getRegValue(string reg);                   //returnts the registers data
 // string getRegValue(int reg);                   //returnts the registers data
 void setRegValueByName(string reg, string data);        //updates the registers data by its reg name
  //void changeValue(RegisterEntry *change, string data);
 void setRegValueByNumber(string regNum, string data);   //updates the registers data by its reg number  
 // void setRegValueByNum(int regNum, string data);   //updates the registers data by its reg number  
 // Outputs the contents of the register to terminal
 void printRegisters();
//outputs the final contents of register to output file
 void printFinalRegisters(string regFile);
 private:
  RegisterEntry myRegisters[64];
//map defined to store values of registers , the key is the register number, and the value is the data vlaue
  map<string, string> myReg;
};


#endif
