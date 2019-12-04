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

  ProgramCounter pc("400000");

  ALU alu1;
  ALU alu2;
  ALU alu3;

  Multiplexor multi1;
  Multiplexor multi2;
  Multiplexor multi3;
  Multiplexor multi4;
  Multiplexor multi5;

  ControlUnit control;
  ALUControl alucontrol;

  SLL sll1;
  SLL sll2;

  SignExtend signext;

  parser.ParseRegFile(register_file_input, registry);
  parser.ParseMemFile(memory_contents_input, memory);

  Instruction i(program_input);

  //i is are encoding instruction

  string addr = pc.getCurrentAddress();
  instruc=getInstruction(addr);
  //instruc.toString() --> print the instruction


  //convert addresss to binAddr

  alu1.setInput_1(binAddr);
  alu1.setInput_2("100");
  alu1.setOperation("add");
  alu1.conductOperation();
  string add4toAddr = alu1.getResult();
  if(debug_mode){
	cout << " The result of adding 4 to the address using ALU is: :" << newAddr << endl;
  }
  //reset control and values in control
  control.setValues(Binary encodingi of the first 6 bits of instruction);
  multi1.setControlInput(control.getRegDest());
  multi2.setControlInput(controlgetAluSrc());
  multi3.setControlInput(control.setControlInput(control.getmemToReg());
  multi4.setControlInput(control.getJump());
  if(debug_mode){
	cout << " Instruction (32 bits is): " << instr.getEncdoing() << endl;
  }

  string reg1 = inst.getEncoding().substr(6, 5);















  i.getNextInstruction();










































}
