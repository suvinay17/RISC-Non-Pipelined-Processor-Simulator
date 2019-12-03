#include "ControlUnit.h"

ControlUnit::ControlUnit()
{
    int i = 0;
    myControls[i].name = "regDest"; myControls[i].value = -1; i++;
    myControls[i].name = "jump"; myControls[i].value = -1; i++;
    myControls[i].name = "branch"; myControls[i].value = -1; i++;
    myControls[i].name = "memRead"; myControls[i].value = -1; i++;
    myControls[i].name = "memToRead"; myControls[i].value = -1; i++;
    myControls[i].name = "aluOp"; myControls[i].value = -1; i++;
    myControls[i].name = "memWrite"; myControls[i].value = -1; i++;
    myControls[i].name = "aluSrc"; myControls[i].value = -1; i++;
    myControls[i].name = "regWrite"; myControls[i].value = -1; i++;
}
i

//returns the control value based what control was asked for
int ControlUnit::getValue(string control)
{
    for(int i = 0; i < 9; i++) {
        if(myControl[i].name == control)
            return myControl[i].value;
    }
    return -1;
}

//sets the control values based on each instruction
void ControlUnit::setInstruction(Instruction inst)
{
    int i = 0;
    switch(inst.getName())
    {
        case "ADD":
            myControls[i].value = 1; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 1; i++;
        case "ADDI":
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 1; i++;
            myControls[i].value = 1; i++;
        case "SUB":
            myControls[i].value = 1; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 1; i++;
        case "SLT":
            myControls[i].value = 1; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 1; i++;
        case "LW":
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 1; i++;
            myControls[i].value = 1; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 1; i++;
            myControls[i].value = 1; i++;
        case "SW":
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 1; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 1; i++;
            myControls[i].value = 1; i++;
            myControls[i].value = 0; i++;
        case "BEQ":
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 1; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 1; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 1; i++;
            myControls[i].value = 0; i++;
        case "J":
            myControls[i].value = 0; i++;
            myControls[i].value = 1; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
    }
}
