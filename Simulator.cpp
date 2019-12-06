#include "Simulator.h"
using namespace std;


// method that uses parser to put parsed results so simulator can use it
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


void Simulator::testRegSet(RegisterTable &registry, int number, string data)
{
    cout << "side 1" << endl;
    registry.setRegValueByNumber("0", "fasd");
    cout << "side 2"<< endl;
}

void Simulator::simulate(){
  getFiles(); // calling method to parse required configurations based on input
  Parser parser;// inititalizing an instance of the parser
  DataMemory memory;//initializing the data memory
  RegisterTable registry;// initializing the register table that has all the registers
  HelperFunctions help; //Initializing Helper functions for decimal hex and binary conversions


  SymbolTable symbolTable; //initializing an instance of the sybmol table
  symbolTable.readASM(program_input);        //populates symbolTable

  InstructionMemory *instMem;
  instMem = new InstructionMemory(program_input); //sending program input to the instruction memory to set it

  ProgramCounter pc("00400000"); //Intitializing PC with initital address "00400000"

  ALU alu1;                 //Adds 4 to PC
  ALU alu2;                 //Add and ALU Result
  ALU alu3;                 //ALU and ALU Result

  Multiplexor multi1;       //RegDest
  Multiplexor multi2;       //ALUSrc
  Multiplexor multi3;       //MemToReg
  Multiplexor multi4;       //Jump
  Multiplexor multi5;       //To branch AND

  ControlUnit control;      //Creating an instance of the control unit
  ALUControl alucontrol;    //creating an instance of alu control

  SLL sll1;                 //for jump instructions
  SLL sll2;                 //for branch instructions

  SignExtend signext;      //creating an instance of sign extend

  parser.ParseRegFile(register_file_input, registry); //parsing the register file
  parser.ParseMemFile(memory_contents_input, memory);// parsing the memory contents input
  string addr;


  Instruction i; //instance of an Instruction
  string addrBin = "";
  i = instMem->getNextInstruction(); // i has instruction to be executed


  while(i.getOpcode() != UNDEFINED) { //Execute as long as the OpCode is not undefined, check for the end


    if(output_mode == "single_step"){ //single step output mode, takes user input to execute one instruction at a time

       while(true)
       {
          string in;
          cout << "Enter y to go to the next step , press n to exit" << endl;
          cin >> in;
          if(in == "y")
          {
            break;
          }
          if(in == "n")
          {
            exit(1);
          }
      }
       cout << endl;
    }

  cout << "printing the next instruction to see if it was fetched correctly: " << i.getAsmString() << endl;


  addr = pc.getCurrentAddress();//getting the current address in the program counter
  addrBin = help.hextoBin(addr);
  //Instruction j = instMem->getNextInstruction(); // new addition

    //ALU adds 4 to the PC
    alu1.setInput_1(addrBin);
    alu1.setInput_2("100");
    alu1.setOperation("add");
    alu1.conductOperation(memory);
    string incrementedPC = alu1.getResult();
    cout << "ALU1 input_1: " << addrBin << endl;
    cout << "ALU1 input_2: " << "100" << endl;
    cout << " The result of adding 4 to the address using ALU is :" << incrementedPC << endl;

    control.setInstruction(i);
    cout << "Control Signals: " << endl;
    cout << "Control Signal sent to regDest: " << control.getValue("regDest") << endl;
    cout << "Control Signal sent to jump: " << control.getValue("jump") << endl;
    cout << "Control Signal sent to branch: " << control.getValue("branch") << endl;
    cout << "Control Signal sent to memRead: " << control.getValue("memRead") << endl;
    cout << "Control Signal sent to memWrite: " << control.getValue("memWrite") << endl;
    cout << "Control Signal sent to aluSrc: " << control.getValue("aluSrc") << endl;
    cout << "Control Signal sent to regWrite: " << control.getValue("regWrite") << endl;
    cout << "Control Signal sent to memToRead: " << control.getValue("memToReg") << endl;
    cout << "Control Signal 1 sent to ALUControl: " << control.getValue("aluOp1") << endl;
    cout << "Control Signal 2 sent to ALUControl: " << control.getValue("aluOp2") << endl;

    //Setting control input from the control unit to the different multiplexors
    multi1.setControlInput(control.getValue("regDest"));
    multi2.setControlInput(control.getValue("aluSrc"));
    multi3.setControlInput(control.getValue("memToReg"));
    multi4.setControlInput(control.getValue("jump"));
    multi5.setControlInput(control.getValue("branch"));
    cout << " Instruction in 32 bit format is: " << instMem->encode(i) << endl;
    cout << i.getString() << endl;

    /*if(i.getName() == 7)
    {
       //we need to check if the immediate is a hex or dec number
       string shifted = sll1.shift(help.hextoBin(i.getImmediate()));
       string combined = addrBin.substr(0,4);       //combine first 4 bits of current address with the shifted jump value
       combined.append(shifted);
       cout << "SLL1 input: " << help.hextoBin(i.getImmediate()) << endl;
       cout << "SLL1 output: " << shifted << endl;
       if(multi4.getControlInput() == 1)
       {
            pc.setAddress(combined);
            i = instMem->getNextInstruction1(combined);  //calculates which instruction in the instrution vector i should be
       }


    }
    else
    {*/
        //binary encoding of mips instruction
        string encoded = instMem->encode(i);
        //taking substrings to get various components from the encoding
        string r1 = encoded.substr(6,5);
        string r2 = encoded.substr(11,5);
        string r3 = encoded.substr(16,5);
        string immediate = encoded.substr(17,15);
        string jumpAddr = encoded.substr(6);
        string functCode = encoded.substr(26,6);
        //shifting the jump address
        string jsll = sll1.shift(jumpAddr);
        cout << "SLL1 input: " << jumpAddr << endl;
        cout << "SLL1 output: " << jsll << endl;
        cout << "Address for Jump in binary: " << jumpAddr << endl;
        cout << "immediate value in binary: " << immediate << endl;
        cout << "r1,r2,r3 are: " << r1 << "," << r2 << "," << r3 << endl;
        cout << "function code is: " << functCode << endl;
        cout << "Jump shifted left by 2 is" << jumpAddr << endl;






        multi4.setSecondInput(jsll);
        cout << "multi4 second input: " << jsll << endl;
        multi1.setFirstInput(r2);
        multi1.setSecondInput(r3);
        cout << "multi1 first input: " << r2 << endl;
        cout << "multi second input: " << r3 << endl;

        string writeRegister = multi1.getResult();
    	cout << " Multiplexor 1 result is : " << writeRegister << endl;
        int r1_Int = help.binaryToDecimal(r1); //move to helper functions
        int r2_Int = help.binaryToDecimal(r2); //move to helper functions
        string r1_Str= to_string(r1_Int);
	    string r2_Str= to_string(r2_Int);

        string valatr1 = registry.getRegValue(r1_Str);
        string valAtR2 = registry.getRegValue(r2_Str);

        string ext = signext.extend(immediate);
        cout << "sign extend input: " << immediate << endl;
        cout << "sign extend output: " << ext << endl;
        multi2.setFirstInput(help.hextoBin(valAtR2));
        multi2.setSecondInput(ext);
        cout << "multi2 first input: " << help.hextoBin(valAtR2) << endl;
        cout << "multi2 second input: " << ext << endl;


        string AluInput = multi2.getResult();

    	    cout << " Multiplexor 2 result is : " << AluInput << endl;

        alu3.setInput_1(help.hextoBin(valatr1));
        alu3.setInput_2(AluInput);

        cout << "ALU3 input_1 : " << help.hextoBin(valatr1) << endl;
        cout << "ALU3 input_2: " << AluInput << endl;




        //alucontrol.setControl(control.getValue("aluOp1"), control.getValue("aluOp2"));
        string funct = i.getFunctionField();
        cout << control.getValue("aluOp1") << "\t" << control.getValue("aluOp2") << endl;
        string op = alucontrol.getControlOutput(control.getValue("aluOp1"), control.getValue("aluOp2"), funct);
        cout << "ALU Control result is: " << op << endl;

        alu3.setOperation(op);

        alu3.conductOperation(memory);

        string alu3_Result = alu3.getResult();
        cout << "ALU 3 result: " << alu3_Result << endl;


        if(control.getValue("branch") == 1 && alu3_Result == "equal")
        {
            multi5.setControlInput(control.getValue("branch"));
        }
        else {
            multi5.setControlInput(0);
        }

        if(control.getValue("memWrite") == 1)
        {
            string hexMemWrite = help.bintoHex(alu3_Result);
                cout << "Write to mem: " << valAtR2 << "\tat: " << hexMemWrite << endl;
            memory.setData(hexMemWrite, valAtR2);

        }

        string alu3_ResultHex;
        if(op == "load/store"){
            alu3_ResultHex = alu3_Result;
            cout << "ALU3 result: " << alu3_ResultHex << endl;
        }
        else{
            alu3_ResultHex = help.bintoHex(alu3_Result);
            cout << "ALU3 result: " << alu3_ResultHex << endl;
        }
        multi3.setFirstInput(alu3_ResultHex);
        cout << "multi3 first input: " << alu3_ResultHex << endl;
        if(control.getValue("memRead") == 1)
        {
            //string dataFromMem = memory.getData(alu3_ResultHex);
            string dataFromMem = "10000000";
            multi3.setSecondInput(dataFromMem);
            cout << "multi3 second input: " << dataFromMem << endl;
        }

        //maybe think about removing 0x


        if(control.getValue("regWrite") == 1)
        {
            string writeData = multi3.getResult();
            int writeRegisterNum = help.binaryToDecimal(writeRegister);
            string regNum= to_string(writeRegisterNum);
            cout << "writedata test: " << writeData << endl;
            registry.setRegValueByNumber(regNum, writeData);

        }
        cout << "test2" << endl;
        string instructionSLL = sll2.shift(ext);
        cout << "SLL2 input: " << ext << endl;
        cout << "Sll2 output: " << instructionSLL << endl;
        alu2.setInput_1(incrementedPC);
        alu2.setInput_2(instructionSLL);
        alu2.setOperation("add");
        alu2.conductOperation(memory);
        string alu2_Result = alu2.getResult();
        cout << "ALU2 input_1: " << incrementedPC << endl;
        cout << "ALU2 input_2: " << instructionSLL << endl;
        cout << "ALU2 result: " << alu2_Result << endl;
        multi5.setFirstInput(incrementedPC);
        multi5.setSecondInput(alu2_Result);
        string multi5_Result = multi5.getResult();
        cout << "multi5 first input: " << incrementedPC << endl;
        cout << "multi5  secodn input: " << alu2_Result << endl;
        multi4.setFirstInput(multi5_Result);
        cout << "Multi4 first input: " << multi5_Result << endl;

        string multi4_Result = multi4.getResult();
        cout << "multi4 result: " << multi4_Result << endl;

        string hexResult = help.bintoHex(multi4_Result);
        pc.setAddress(hexResult);

        cout << hexResult << endl;

        i = instMem->getNextInstruction1(hexResult);
        if(print_memory_contents)
            cout << endl;
            registry.printRegisters();
        //i = instMem->getNextInstruction1(incrementedPC);
        cout << endl << endl;
        cout << i.getOpcode() << endl;
        if((int)i.getOpcode() == 8)
        {
            cout << "break" << endl;
            break;
        }
        cout << "end" << endl;

  }
    if(write_to_file)
  {
  
  cout<<"The final register contents have been output to registerOutput"<<endl;
  registry.printFinalRegisters("registerOutput.memory");
   /*cout<<"The Instructionmemory has been written to outinstruction.memory"<<endl;
 *     instMem->imemPrintFinal("instructionMemoryOutput");*/
    cout<<"The final data memory has been output to dataMemoryOutput"<<endl;
      memory.dataMemoryPrintFinal("dataMemoryOutput.memory");
      
  }

  
}
