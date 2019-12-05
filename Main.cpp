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
#include "Simulator.h"
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

/* This file reads in a MIPS assembly file specified at the command line.
 * If the file is correct syntactically, each instruction in the file
 * will be translated into its 32 bit MIPS binary encoding and printed
 * to stdout, one per line.
 *
 */


 int main(int argc, char *argv[])
 {
 	Simulator* stim ;

   if(argc < 2){
     cerr << "Need to specify a configuration file to stimulate the processr."<<endl;
     exit(1);
   }
 	stim =new Simulator (argv[1]);
 	stim->simulate();

 	delete stim;
 };



#endif
