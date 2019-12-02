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

  ifstream inputFile;

  if(argc < 2){
    cerr << "Specify a configuration file to simulate the processr."<<endl;
    return 0;
  }

  inputFile.open(argv[1]);
    if (!inputFile.is_open()){
        cerr << "Error: Unable to open file " << argv[1] << endl;
        return 1;
    }
  



};



#endif
