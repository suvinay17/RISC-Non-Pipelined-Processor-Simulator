#include "InstructionMemory.h"
#include <bits/stdc++.h>

InstructionMemory::InstructionMemory(string filename)
  // Specify a text file containing MIPS assembly instructions. Function
  // checks syntactic correctness of file and creates a list of Instructions.
{
  Instruction i;
  myFormatCorrect = true;

  myLabelAddress = 0x400000;

  ifstream in;
  in.open(filename.c_str());
  if(in.bad()){
    myFormatCorrect = false;
  }
  else{
    string line;
    while( getline(in, line)){
      cout << line << endl;
      if(line.length() > 2)
      {
      i.setAsmString(line);
      string opcode("");
      string operand[80];
      int operand_count = 0;

      getTokens(line, opcode, operand, operand_count);

      if(opcode.length() == 0 && operand_count != 0){
	    // No opcode but operands
	    myFormatCorrect = false;
	    break;
      }

      Opcode o = opcodes.getOpcode(opcode);
      if(o == UNDEFINED){
	    // invalid opcode specified
	    myFormatCorrect = false;
	    break;
      }

      bool success = getOperands(i, o, operand, operand_count);
      if(!success)
      {
        cout << (int)o << endl;
        cout << operand << endl;
        cout << operand_count << endl;;
	    myFormatCorrect = false;
        cout << "myFormat = false" << endl;
	    break;
      }

      string encoding = encode(i);
      i.setEncoding(encoding);
      cout << encoding << endl;
      myInstructions.push_back(i);

    }
    }
  }

  myIndex = 0;
}


Instruction InstructionMemory::getNextInstruction()
  // Iterator that returns the next Instruction in the list of Instructions.
{
  if(myIndex <= (int)(myInstructions.size())){
    myIndex++;
    return myInstructions[myIndex-1];
  }

  Instruction i;
  return i;

}


Instruction InstructionMemory::getNextInstruction1(string position)
  // Returns the next Instruction in the list of Instructions.
{
  HelperFunctions help;
  string start = "0x400000";
  cout << help.hextoDec(position) << "\t" << help.hextoDec(start) << endl;
  unsigned int place = (help.hextoDec(position) - help.hextoDec(start))/4;
  cout << place << endl;
  cout << myInstructions.size() << endl;
  if(myInstructions.size() <= place) {
      cout << "at the end" << endl;
    Instruction i;
    cout << i.getOpcode() << endl;
    return i;
  }

  return myInstructions[place];
}

void InstructionMemory::getTokens(string line,
			       string &opcode,
			       string *operand,
			       int &numOperands)
  // Decomposes a line of assembly code into strings for the opcode field and operands,
  // checking for syntax errors and counting the number of operands.
{
    // locate the start of a comment
    string::size_type idx = line.find('#');
    if (idx != string::npos) // found a ';'
	line = line.substr(0,idx);
    int len = line.length();
    opcode = "";
    numOperands = 0;

    if (len == 0) return;
    int p = 0; // position in line

    // line.at(p) is whitespace or p >= len
    while (p < len && isWhitespace(line.at(p)))
	p++;
    // opcode starts
    while (p < len && !isWhitespace(line.at(p)))
    {
	opcode = opcode + line.at(p);
	p++;
    }
    //    for(int i = 0; i < 3; i++){
    int i = 0;
    while(p < len){
      while ( p < len && isWhitespace(line.at(p)))
	p++;

      // operand may start
      bool flag = false;
      while (p < len && !isWhitespace(line.at(p)))
	{
	  if(line.at(p) != ','){
	    operand[i] = operand[i] + line.at(p);
	    flag = true;
	    p++;
	  }
	  else{
	    p++;
	    break;
	  }
	}
      if(flag == true){
	numOperands++;
      }
      i++;
    }


    idx = operand[numOperands-1].find('(');
    string::size_type idx2 = operand[numOperands-1].find(')');

    if (idx == string::npos || idx2 == string::npos ||
	((idx2 - idx) < 2 )){ // no () found
    }
    else{ // split string
      string offset = operand[numOperands-1].substr(0,idx);
      string regStr = operand[numOperands-1].substr(idx+1, idx2-idx-1);

      operand[numOperands-1] = offset;
      operand[numOperands] = regStr;
      numOperands++;
    }



    // ignore anything after the whitespace after the operand
    // We could do a further look and generate an error message
    // but we'll save that for later.
    return;
}

bool InstructionMemory::isNumberString(string s)
  // Returns true if s represents a valid decimal integer
{
    int len = s.length();
    if (len == 0) return false;
    if ((isSign(s.at(0)) && len > 1) || isDigit(s.at(0)))
    {
	// check remaining characters
	for (int i=1; i < len; i++)
	{
	    if (!isdigit(s.at(i))) return false;
	}
	return true;
    }
    return false;
}


int InstructionMemory::cvtNumString2Number(string s)
  // Converts a string to an integer.  Assumes s is something like "-231" and produces -231
{
    if (!isNumberString(s))
    {
	cerr << "Non-numberic string passed to cvtNumString2Number"
		  << endl;
	return 0;
    }
    int k = 1;
    int val = 0;
    for (int i = s.length()-1; i>0; i--)
    {
	char c = s.at(i);
	val = val + k*((int)(c - '0'));
	k = k*10;
    }
    if (isSign(s.at(0)))
    {
	if (s.at(0) == '-') val = -1*val;
    }
    else
    {
	val = val + k*((int)(s.at(0) - '0'));
    }
    return val;
}


bool InstructionMemory::getOperands(Instruction &i, Opcode o,
			    string *operand, int operand_count)
  // Given an Opcode, a string representing the operands, and the number of operands,
  // breaks operands apart and stores fields into Instruction.
{

  if(operand_count != opcodes.numOperands(o))
    return false;

  int rs, rt, rd, imm;
  imm = 0;
  rs = rt = rd = NumRegisters;

  int rs_p = opcodes.RSposition(o);
  int rt_p = opcodes.RTposition(o);
  int rd_p = opcodes.RDposition(o);
  int imm_p = opcodes.IMMposition(o);

  if(rs_p != -1){
    rs = registers.getNum(operand[rs_p]);
    if(rs == NumRegisters){
        cout << "break 1" << endl;
        return false;
    }
  }

  if(rt_p != -1){
    rt = registers.getNum(operand[rt_p]);
    if(rt == NumRegisters){
        cout << "break 2" << endl;
        return false;
    }

  }

  if(rd_p != -1){
    rd = registers.getNum(operand[rd_p]);
    if(rd == NumRegisters) {
        cout << "break 3" << endl;
        return false;
    }

  }

  if(imm_p != -1){
    if(isNumberString(operand[imm_p])){  // does it have a numeric immediate field?
      imm = cvtNumString2Number(operand[imm_p]);
      if(((abs(imm) & 0xFFFF0000)<<1)) { // too big a number to fit
        cout << "break 4" << endl;
	    return false;
      }
    }
    else{
      if(opcodes.isIMMLabel(o)){  // Can the operand be a label?
	    // Assign the immediate field an address
	    imm = myLabelAddress;
	    myLabelAddress += 4;  // increment the label generator
      }
      else {  // There is an error
        cout << "break 5" << endl;
	    return false;
      }
    }

  }

  i.setValues(o, rs, rt, rd, imm);

  return true;
}


string InstructionMemory::encode(Instruction i)
  // Given a valid instruction, returns a string representing the 32 bit MIPS binary encoding
  // of that instruction.
{
  HelperFunctions help;
  string inst = "";	//string to store 32 bit address in
  Opcode op = i.getOpcode();	//get the opcode of Instruction i
  InstType type = opcodes.getInstType(op);	//get the instType for the switch
  string empty = "00000"; 	//A 5 bit string of 0's for if a register is not used

  switch(type)	//switch based on the type of instruction
  {
    case JTYPE: {
	inst.append(opcodes.getOpcodeField(op));	//Appends the opcode
    //string temp = (help.hextoDec(i.getImmediate()));
    int imm = help.hextoDec(i.getImmediate());			//gets the immediate value and translates it into 26 bit binary
	bitset<26> bitImm(imm);
  cout << i.getImmediate() << endl;
  cout << "JTYPE imm " << imm << endl;
  cout << "JTYPE immbin " << bitImm << endl;
	inst.append(bitImm.to_string());		//appends immediate field
 	}
    break;

    case RTYPE: {
	inst.append(opcodes.getOpcodeField(op));	//appends opcode

	//appends the register for rs if there is one
 	if(opcodes.RSposition(op) == -1)
	    inst.append(empty);
	else {
	    int rs = i.getRS();
	    bitset<5> bitRS(rs);
	    inst.append(bitRS.to_string());
	}

	//appends the register for rt if there is one
 	if(opcodes.RTposition(op) == -1)
	    inst.append(empty);
	else {
	    int rt = i.getRT();
	    bitset<5> bitRT(rt);
	    inst.append(bitRT.to_string());
	}


	//appends the register for rd if there is one
 	if(opcodes.RDposition(op) == -1)
	    inst.append(empty);
	else {
	    int rd = i.getRD();
	    bitset<5> bitRD(rd);
	    inst.append(bitRD.to_string());
	}


	//appends the shamt amount if there is one
 	if(opcodes.IMMposition(op) == -1)
	    inst.append(empty);
	else {
	    int imm = stoi(i.getImmediate());
	    bitset<5> bitIMM(imm);
	    inst.append(bitIMM.to_string());
	}

	//appends the function field
	inst.append(opcodes.getFunctField(op));
    	}
    break;

    case ITYPE: {
	inst.append(opcodes.getOpcodeField(op));	//appends the opcode
	int rs = i.getRS();				//reads in the values for rs, rt, and imm fields
	int rt = i.getRT();
	int imm = stoi(i.getImmediate());
	bitset<5> bitRS(rs);				//bitsets rs and rt to 5 bits and imm to 16 bits
	bitset<5> bitRT(rt);
	bitset<16> bitImm(imm);
	inst.append(bitRS.to_string());			//appends the bitset to_string() to inst
	inst.append(bitRT.to_string());
	inst.append(bitImm.to_string());
	}
    break;

    default:
	break;
  }

  return inst;	//returns the 32 bit amount
}
















