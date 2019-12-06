//The main class that simulates the operation of the processor
//Written by Suvinay, Jimmy, Caleb_


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

/* 
 * The main class gets an input configuration file which send it to simulator which is the driver
 * class of the NON pipelined processor simulator
 *
 */


 int main(int argc, char *argv[])
 {

   Simulator* sim; //creating an instance of simulator

//If we have less than 2 arguments, it means the config file was not included
   if(argc < 2){

     cerr << "Cannot run program without configuration file, please include a configuration file"<<endl;
     exit(1);

   }

   //Pass the configuration file into the simulator
 	sim =new Simulator (argv[1]);
   //Run the driver method
 	sim->simulate();
       
 	delete sim;

 };




