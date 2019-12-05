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

  ProgramCounter pc("04000000");

  ALU alu1;                 //Adds 4 to PC
  ALU alu2;                 //Add and ALU Result
  ALU alu3;                 //ALU and ALU Result

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
  if(debug_mode)
  {
    cout << "printing the next instruction to see if it was fetched correctly" << i.getName() << endl;

  }


  while(i.getOpcode() != UNDEFINED) {

    if(output_mode == "single_step"){ //new addition

       while(true)
       {
          string x;
          cout << "Enter y to go to the next step , press n to exit" << endl;
          cin >> x;
          if(x == "y")
          {
            break;
          }
          if(x == "n")
          {
            exit(1);
          }
      }
    }


    addr = pc.getCurrentAddress();
    addrBin = help.hextoBin(addr);
    //Instruction j = instMem->getNextInstruction(); // new addition
    //cout << "The above instruction is " <<  << endl;


    //adds 4 to the PC
    alu1.setInput_1(addrBin);
    alu1.setInput_2("100");
    alu1.setOperation("add");
    alu1.conductOperation();
    string incrementedPC = alu1.getResult();
    if(debug_mode){
	    cout << " The result of adding 4 to the address using ALU is :" << incrementedPC << endl;
    }


    //reset control and values in control
    control.setInstruction(i);
    multi1.setControlInput(control.getValue("regDest"));
    multi2.setControlInput(control.getValue("aluSrc"));
    multi3.setControlInput(control.getValue("memToReg"));
    multi4.setControlInput(control.getValue("jump"));
    multi5.setControlInput(control.getValue("branch"));
    if(debug_mode){
	    cout << " Instruction in 32 bit format is: " << instMem->encode(i) << endl;
    }

    if(i.getName() == 7)
    {
       //we need to check if the immediate is a hex or dec number
       string shifted = sll1.shift(help.hextoBin(i.getImmediate()));
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

        string r1 = encoded.substr(6,5);
        string r2 = encoded.substr(11,5);
        string r3 = encoded.substr(16,5);
        string immediate = encoded.substr(17,15);
        string jumpAddr = encoded.substr(6,26);
        string functCode = encoded.substr(26,6);
        string jsll = sll1.shift(jumpAddr);

        if(debug_mode){
        cout << "Address for Jump in binary: " << jumpAddr << endl;
        cout << "immediate value in binary: " << immediate << endl;
        cout << "r1,r2,r3 are: " << r1 << "," << r2 << "," << r3 << endl;
        cout << "function code is: " << functCode << endl;
        cout << "Jump shifted left by 2 is" << jumpAddr << endl;
      }






        multi4.setSecondInput(jsll);
        multi1.setFirstInput(r2);
        multi1.setSecondInput(r3);

        string writeRegister = multi1.getResult();
        if(debug_mode){
    	    cout << " Multiplexor 1 result is : " << writeRegister << endl;
        }
        int r1_Int = help.binaryToDecimal(r1); //move to helper functions
        int r2_Int = help.binaryToDecimal(r2); //move to helper functions
        cout << "test" << endl;
        cout << r1_Int << endl;
        string test = registry.getRegValue("2");
        cout << test << endl;
        string valatr1 = registry.getRegValue(to_string(r1_Int));
        string valAtR2 = registry.getRegValue(to_string(r2_Int));

        cout << "test" << endl;
        string ext = signext.extend(immediate);

        cout << "test" << endl;
        multi2.setFirstInput(help.hextoBin(valAtR2));
        multi2.setSecondInput(ext);

        cout << "test" << endl;

        string AluInput = multi2.getResult();

        if(debug_mode){
    	    cout << " Multiplexor 2 result is : " << AluInput << endl;
        }

        alu3.setInput_1(help.hextoBin(valatr1));
        alu3.setInput_2(AluInput);
        cout << "test" << endl;

        //alucontrol.setControl(control.getValue("aluOp1"), control.getValue("aluOp2"));
        string funct = i.getFunctionField();
        string op = alucontrol.getControlOutput(control.getValue("aluOp1"), control.getValue("aluOp2"), funct);

        if(debug_mode) {
            cout << "ALU Control result is: " << op << endl;
        }

        alu3.setOperation(op);

        alu3.conductOperation();

        string alu3_Result = alu3.getResult();

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
            memory.setData(hexMemWrite, valAtR2);
        }

        string alu3_ResultHex = help.bintoHex(alu3_Result);

        multi3.setFirstInput(alu3_ResultHex);

        if(control.getValue("memRead") == 1)
        {
            string dataFromMem = memory.getData(alu3_ResultHex); //consider removing 0x
            multi3.setSecondInput(dataFromMem); //Data from mem here should not have 0x
        }

        //maybe think about removing 0x



        if(control.getValue("regWrite") == 1)
        {
            string writeData = multi3.getResult();


        int writeint = help.hextoDec(registry.getRegValue(writeRegister));

        registry.setRegValueByNumber(to_string(writeint), writeData);

        }

        string instructionSLL = sll2.shift(ext);

        alu2.setInput_1(incrementedPC);
        alu2.setInput_2(instructionSLL);
        alu2.setOperation("add");
        alu2.conductOperation();
        string alu2_Result = alu2.getResult();

        multi5.setFirstInput(incrementedPC);
        multi5.setSecondInput(alu2_Result);
        string multi5_Result = multi5.getResult();

        multi4.setFirstInput(multi5_Result);

        string multi4_Result = multi4.getResult();

        string hexResult = help.bintoHex(multi4_Result);
        pc.setAddress(hexResult);


        i = instMem->getNextInstruction1(incrementedPC);

    }


  //i.getNextInstruction();


  }

}
