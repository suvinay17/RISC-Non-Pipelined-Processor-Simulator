//The main class that simulates the operation of the processor
//Written by Suvinay, Jimmy, Caleb
#ifndef __MAIN_CPP__
#define __MAIN_CPP__

#include "ProgramCounter.h"
#include "Multiplexor.h"
#include "ALU.h"
#include "DataMemory.h"
#include "ALUControl.h"
#include "SLL.h"
#include "HelperFunctions.h"
#include "Parser.h"
#include "ControlUnit.h"
#include "Instruction.h"
#include "Opcode.h"
#include "RegisterTable.h"
#include "SignExtend.h"
#include "SymbolTable.h"
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>

int main(int argc, char *argv[])
{


  if(argc < 2){
    cerr << "Need to specify a configuration file to stimulate the processr."<<endl;
    exit(1);
  }
	
};



#endif
