#include "RegisterTable.h"
#include <iostream>

RegisterTable::RegisterTable()
{
  int i = 0;

  myRegisters[i].name = "$0";  myRegisters[i].number = i; /* myRegisters[i].value = "0x0000"; */i++;
  myRegisters[i].name = "$1";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000";*/ i++;
  myRegisters[i].name = "$2";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000";*/ i++;
  myRegisters[i].name = "$3";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000"; */i++;

  myRegisters[i].name = "$4";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000";*/ i++;
  myRegisters[i].name = "$5";  myRegisters[5].number = i;/*  myRegisters[i].value.reserve(20); myRegisters[i].value = "0x000000000";*/ i++;
  myRegisters[i].name = "$6";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000";*/ i++;
  myRegisters[i].name = "$7";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000";*/ i++;

  myRegisters[i].name = "$8";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000";*/ i++;
  myRegisters[i].name = "$9";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000";*/ i++;
  myRegisters[i].name = "$10";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000";*/ i++;
  myRegisters[i].name = "$11";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000";*/ i++;

  myRegisters[i].name = "$12";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000";*/ i++;
  myRegisters[i].name = "$13";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000";*/ i++;
  myRegisters[i].name = "$14";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000";*/ i++;
  myRegisters[i].name = "$15";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000";*/ i++;

  myRegisters[i].name = "$16";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000";*/ i++;
  myRegisters[i].name = "$17";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000";*/ i++;
  myRegisters[i].name = "$18";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000";*/ i++;
  myRegisters[i].name = "$19";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000";*/ i++;

  myRegisters[i].name = "$20";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000";*/ i++;
  myRegisters[i].name = "$21";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000";*/ i++;
  myRegisters[i].name = "$22";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000";*/ i++;
  myRegisters[i].name = "$23";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000";*/ i++;

  myRegisters[i].name = "$24";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000";*/ i++;
  myRegisters[i].name = "$25";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000";*/ i++;
  myRegisters[i].name = "$26";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000";*/ i++;
  myRegisters[i].name = "$27";  myRegisters[i].number = i; /* myRegisters[i].value = "0x0000"; */i++;

  myRegisters[i].name = "$28";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000";*/ i++;
  myRegisters[i].name = "$29";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000";*/ i++;
  myRegisters[i].name = "$30";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000";*/ i++;
  myRegisters[i].name = "$31";  myRegisters[i].number = i;/*  myRegisters[i].value = "0x0000";*/ i++;

}

Register RegisterTable::getNum(string reg)
  // Given a string representing a MIPS register operand, returns the number associated
  // with that register.  If string is not a valid register, returns NumRegisters.
{
  for(int i = 0; i < 32; i++){
    if(myRegisters[i].name == reg){
      return myRegisters[i].number;
    }

  }
  return NumRegisters;

}

void RegisterTable::setRegValueByName(string reg, string data)
{
  for(int i = 0; i < 32; i++){
    if(myRegisters[i].name == reg){
      myRegisters[i].value = data;
    }

  }
}
void RegisterTable::setRegValueByNumber(string regNum, string data)
{
     myReg[regNum] = data;

 
}


//string RegisterTable::getRegValue(string reg)
string RegisterTable::getRegValue(string reg)
{
  return myReg[reg];

}

//print the current values of register
void  RegisterTable::printRegisters()
{
    for(int i = 0; i < 32; i++)
    {
        string j = to_string(i);
        cout << i << ": " << "0x" <<  myReg[j] << endl;
    }
  }

//prints the final values of the register file to the outputfile
void  RegisterTable::printFinalRegisters(string regFile)
{
  ofstream file;
  file.open(regFile);
    for(int i = 0; i < 32; i++)
    {
        string j = to_string(i);   
        file << i << ": " << "0x" <<  myReg[j] << endl;
    }
    file.close();      
}

