//.h file for Simulator that drives main
// Written by Suvinay, Caleb , Jimmy

#include <string>
#include <sstream>
#include <map>
#include <iostream>
#include <cstring>
#include <fstream>
#include "Multiplexor.h"
#include "Instruction.h"
#include "SLL.h"
#include "SignExtend.h"
#include "SymbolTable.h"
#include "InstructionMemory.h"
#include "ProgramCounter.h"
#include "DataMemory.h"
#include "ControlUnit.h"
#include "ALU.h"
#include "Parser.h"
#include "ALUControl.h"
#include "HelperFunctions.h"
#include "RegisterTable.h"
#include "Opcode.h"

class Simulator{
  public:
  //Constructor
   Simulator(){
  }
  //Parametrized Constructor, parameter configurationFilefile comes from main
  Simulator(std::string file){
  	configurationFile=file;
  }
  //deconstructor
  ~Simulator(){}
  //Method for getting all the files and modes from Parser
   	void getFiles();
  //The actual driver of the program
    void simulate();

private:

    std::string configurationFile; //Default
    std::string program_input;
    std::string memory_contents_input;
    std::string register_file_input;
    std::string output_mode;
    bool debug_mode;
    bool print_memory_contents;
    bool write_to_file;
    bool output_file;

};

