#include "Simulator.h"
using namespace std;


void Simulator::getFiles(){
  Parser par;
  par.ParseConfigFile(configurationFile);
  program_input = par.getProgram_input();
  memory_contents_input = par.getMemory_contents_input();
  register_file_input = par.getRegister_file_input();
  output_mode = par.getOutput_mode();
  debug_mode = par.getDebug_mode();
  print_memory_contents = par.getPrint_memory_contents();
  write_to_file = par.getWrite_to_file();
  output_file = par.getOutput_file();



}

void Simulator::simulate(){
  getFiles();
  Parser parser;
  DataMemory memory
  Register registry;
  HelperFunctions help;

  SymbolTable symbolTable;
  symbolTable.readASM(program_input);        //populates symbolTable

  InstructionMemory *instMem;
  instMem = new InstructionMemory(program_input); 

  ProgramCounter pc("0x400000");

  ALU alu1;                 //Adds 4 to PC
  ALU alu2;
  ALU alu3;

  Multiplexor multi1;       //RegDest
  Multiplexor multi2;       //ALUSrc
  Multiplexor multi3;       //MemToReg
  Multiplexor multi4;       //Jump
  Multiplexor multi5;       //To branch AND

  ControlUnit control;
  ALUControl alucontrol;

  SLL sll1;                 //for jump instructions
  SLL sll2;                 //for branch instructions

  SignExtend signext;

  parser.ParseRegFile(register_file_input, registry);
  parser.ParseMemFile(memory_contents_input, memory);
  string addr;


  Instruction i;
  i = instMem->getNextInstruction();


  while(i.getOpcode() !=UNDEFINED) {


    addr = pc.getCurrentAddress();
    addrBin = help.hextoBin(addr);

  
    //adds 4 to the PC
    alu1.setInput_1(binAddr);
    alu1.setInput_2("100");
    alu1.setOperation("add");
    alu1.conductOperation();
    string add4toPC = alu1.getResult();
    if(debug_mode){
	    cout << " The result of adding 4 to the address using ALU is: :" << newAddr << endl;
    }


    //reset control and values in control
    control.setValues(i);
    multi1.setControlInput(control.getValue("regDest"));
    multi2.setControlInput(controlgetValue("aluSrc"));
    multi3.setControlInput(control.getValue("memToReg");
    multi4.setControlInput(control.getValue("jump"));
    multi5.setControlInput(control.getValue("branch"));
    /*if(debug_mode){
	    cout << " Instruction (32 bits is): " << instr.getEncdoing() << endl;
    }

    string reg1 = inst.getEncoding().substr(6, 5);
    */


    if(i.getName() == 7)
    {
       //we need to check if the immediate is a hex or dec number
       string shifted = sll1.shift(help.hextoBin(""+i.getImmediate()));
       string combined = addrBin.substr(0,3);       //combine first 4 bits of current address with the shifted jump value
       combined.append(shifted);

       if(multi4.getControlInput() == 1)
       {
            pc.setAddress(combined);
            i = inst.getNextInstruction(pc.nextInstruction(combined));  //calculates which instruction in the instrution vector i should be
       }


    }
    else
    {

    }


  //i.getNextInstruction();


  }







































}
