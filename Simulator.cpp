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
  DataMemory memory;
  RegisterTable registry;
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
  string addrBin = "";
  i = instMem->getNextInstruction();


  while(i.getOpcode() != UNDEFINED) {


    addr = pc.getCurrentAddress();
    addrBin = help.hextoBin(addr);

  
    //adds 4 to the PC
    alu1.setInput_1(addrBin);
    alu1.setInput_2("100");
    alu1.setOperation("add");
    alu1.conductOperation();
    string add4toPC = alu1.getResult();
    if(debug_mode){
	    cout << " The result of adding 4 to the address using ALU is: :" << add4toPC << endl;
    }


    //reset control and values in control
    control.setInstruction(i);
    multi1.setControlInput(control.getValue("regDest"));
    multi2.setControlInput(control.getValue("aluSrc"));
    multi3.setControlInput(control.getValue("memToReg"));
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
       string combined = addrBin.substr(0,4);       //combine first 4 bits of current address with the shifted jump value
       combined.append(shifted);

       if(multi4.getControlInput() == 1)
       {
            pc.setAddress(combined);
            i = instMem->getNextInstruction1(combined);  //calculates which instruction in the instrution vector i should be
       }


    }
    else
    {
        string encoded = instMem->encode(i);

        string reg1 = encoded.substr(6,5);
        string reg2 = encoded.substr(11,5);
        string reg3 = encoded.substr(16,5);
        string immediate = encoded.substr(17,15);
        string jAddress = encoded.substr(6,26);

       
        string functCode = encoded.substr(26,6);
       
        string jsll = sll1.shift(jAddress);
        

        multi4.setSecondInput(jsll);
        multi1.setFirstInput(reg2);
        multi1.setSecondInput(reg3);

        string writerRegister = multi1.mux();
        int reg1Int = help.binaryToDecimal(reg1); //move to helper functions
        int reg21Int = help.binaryToDecimal(reg2); //move to helper functions
         
        string valatreg1 = registry.getRegValue("" + reg1);
        string valatreg2 = registry.getRegValue(""  + reg2);

        string ext = signext.extend(immediate);

        multi2.setFirstInput(help.hextoBin(valatreg2));
        multi2.setSecondInput(ext);

        string AluInput = multi2.mux();

        alu3.setInput_1(help.hextoBin(valatreg1));
        alu3.setInpuit_2(AluInput);


        //alucontrol.setControl(control.getValue("aluOp1"), control.getValue("aluOp2"));
        
        string op = alucontrol.getOperation(control.getValue("aluOp1"), control.getValue("aluOp2"), functcode);

        alu3.setOperation(op);

        alu3.conductOperation();

        string alu3result = alu3.getResult();

        if(control.getValue("branch") == 1 && alu3result == "equal")
        {
            multi5.setControlInput(control.getValue("branch"));
        }
        else {
            multi5.setControlInput(0);
        }

        if(control.getValue("memWrite") == 1)
        {
            string hexMemWrite = help.bintoHex(alu3result);
            memory.setData(hexMemWrite, valatreg2);
        }

        string alu3resultHex = help.bintoHex(alu3result);

        multi3.setFirstInput(alu3resultHex);

        if(control.getValue("memRead") == 1)
        {
            string dataFromMem = memory.getData(alu3resultHex);
        }

        //maybe think about removing 0x
        

        multi3.setSecondInput(dataFromMem); //Data from mem here should not have 0x
        if(control.getValue("regWrite") == 1)
        {
            string writeData = multi3.mux()
        

        int writeint = help.hextoDec(registry.getRegValue(writerRegister));

        registry.setRegValueByNumber("" + writeint, writeData);

        }

        string instructionSLL = sll2.shift(ext);

        alu2.setInput_1(add4toPC);
        alu2.setInput_2(instructionSLL);
        alu2.setOperation("add");
        alu2.conductOperation();
        string resultofAlu2 = alu2.getResult();

        multi5.setFirstInput(add4toPC);
        multi5.secondInput(resultofAlu2);
        string resultofmux5 = multi5.mux();

        multi4.setFirstInput(resultofmux5);
        
        string resultofmux4 = multi4.mux();
        
        string hexfinal = help.bintoHex(resultofmux4);
        pc.setAddress(hexfinal);


        i = instMem->getNextInstruction1(add4toPC);

    }


  //i.getNextInstruction();
        

  }







































}
