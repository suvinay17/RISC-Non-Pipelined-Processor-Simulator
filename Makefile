DEBUG_FLAG= -DDBUG -g -Wall
CFLAGS=-DDBUG -g -Wall

.SUFFIXES: .cpp .o

.cpp.o:
	g++ $(CFLAGS) -c $<

Main: Main.o Simulator.o ProgramCounter.o Multiplexor.o ALU.o DataMemory.o ALUControl.o SLL.o HelperFunctions.o Parser.o ControlUnit.o Instruction.o Opcode.o RegisterTable.o SignExtend.o SymbolTable.o InstructionMemory.o
	g++ -o Main Main.o Simulator.o ProgramCounter.o Multiplexor.o ALU.o DataMemory.o ALUControl.o SLL.o HelperFunctions.o Parser.o ControlUnit.o Instruction.o Opcode.o RegisterTable.o SignExtend.o SymbolTable.o InstructionMemory.o

Simulator.o: Simulator.h  IProgramCounter.h Multiplexor.h ALU.h DataMemory.h ALUControl.h SLL.h HelperFunctions.h Parser.h ControlUnit.h Instruction.h Opcode.h RegisterTable.h SignExtend.h SymbolTable.h InstructionMemory.h

ControlUnit.o: ControlUnit.h Instruction.h Opcode.h RegisterTable.h

InstructionMemory.o: InstructionMemory.h HelperFunctions.h Instruction.h Opcode.h RegisterTable.h

Instruction.o: Instruction.h Opcode.h RegisterTable.h

SymbolTable.o: SymbolTable.h HelperFunctions.h

ProgramCounter.o: ProgramCounter.h

Multiplexor.o: Multiplexor.h

ALU.o: ALU.h

DataMemory.o: DataMemory.h

ALUControl.o: ALUControl.h

SLL.o: SLL.h

HelperFunctions.o: HelperFunctions.h

Parser.o: Parser.h

Opcode.o: Opcode.h

RegisterTable.o: RegisterTable.h

SignExtend.o: SignExtend.h

clean:
	/bin/rm/ -f Main *.o core
