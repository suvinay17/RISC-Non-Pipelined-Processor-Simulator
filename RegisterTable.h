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
  Register getNum(string reg);
  string getRegValue(string reg);
  void setRegValue(string reg, string data);

 private:
  RegisterEntry myRegisters[64];

};


#endif
