#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

#include "Opcode.h"
#include "RegisterTable.h"
#include <sstream>
#include <string>

/* This class provides an internal representation for a MIPS assembly instruction.
 * Any of the fields can be queried.  Additionally, the class stores a 32 bit binary
 * encoding of the MIPS instruction.
 */


class Instruction{
 public:
  Instruction();

  // You can specify all the fields to initialize the Instruction
  Instruction(Opcode op, Register rs, Register rt, Register rd, int imm);
  ~Instruction() {};

  // Allows you to specify all the fields of the Instruction
  void setValues(Opcode op, Register rs, Register rt, Register rd, int imm);
  void setAsmString(string str);
  string getAsmString();
  // Returns the various fields for the Instruction
  Opcode getOpcode()   { return myOpcode;}
  Register getRS()     { return myRS; };
  Register getRD()     { return myRD; };
  Register getRT()     { return myRT; };
  string getImmediate()   { return to_string(myImmediate); };
  //void setImm(string imm);  {  };

  // Returns a string which represents all of the fields 
  string getString();
  string getimmLabel() { return immLabel; };
  void setimmLabelData(string label) { immLabel = label; };
  // Stores the 32 bit binary encoding of MIPS instruction passed in
  void setEncoding(string s) { myEncoding = s;};

  // Returns the name of the instruction
  Opcode getName();

  string getFunctionField();

  // Returns string representing the 32 binary encoding of MIPS instruction
  string getEncoding() { return myEncoding; };

 private:
  string asmStr;
  Opcode myOpcode;
  Register myRS;
  Register myRT;
  Register myRD;
  int myImmediate;
  string immLabel;
  string myEncoding;
};

#endif
