#ifndef _REGISTERTABLE_H
#define _REGISTERTABLE_H

#include <string>

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
  void setRegValueByName(string reg, string data);        //updates the registers data by its reg name
  void setRegValueByNumber(string regNum, string data);   //updates the registers data by its reg number  

 private:
  RegisterEntry myRegisters[64];

};


#endif
