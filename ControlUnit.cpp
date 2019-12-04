#include "ControlUnit.h"

ControlUnit::ControlUnit()
{
    int i = 0;
    myControls[i].name = "regDest"; myControls[i].value = -1; i++;
    myControls[i].name = "jump"; myControls[i].value = -1; i++;
    myControls[i].name = "branch"; myControls[i].value = -1; i++;
    myControls[i].name = "memRead"; myControls[i].value = -1; i++;
    myControls[i].name = "memToReg"; myControls[i].value = -1; i++;
    myControls[i].name = "aluOp1"; myControls[i].value = -1; i++;
    myControls[i].name = "aluOp2"; myControls[i].value = -1; i++;
    myControls[i].name = "memWrite"; myControls[i].value = -1; i++;
    myControls[i].name = "aluSrc"; myControls[i].value = -1; i++;
    myControls[i].name = "regWrite"; myControls[i].value = -1; i++;
}


//returns the control value based what control was asked for
int ControlUnit::getValue(string control)
{
    for(int i = 0; i < 9; i++) {
        if(myControls[i].name == control)
            return myControls[i].value;
    }
    return -1;
}

//sets the control values based on each instruction
void ControlUnit::setInstruction(Instruction inst)
{
    int i = 0;
    switch(inst.getName())
    {
        case 0:
            myControls[i].value = 1; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 1; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 1; i++;
        case 1:
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 1; i++;
            myControls[i].value = 1; i++;
        case 2:
            myControls[i].value = 1; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 1; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 1; i++;
        case 3:
            myControls[i].value = 1; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 1; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 1; i++;
        case 4:
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 1; i++;
            myControls[i].value = 1; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 1; i++;
            myControls[i].value = 1; i++;
        case 5:
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 1; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 1; i++;
            myControls[i].value = 1; i++;
            myControls[i].value = 0; i++;
        case 6:
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 1; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 1; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 1; i++;
            myControls[i].value = 0; i++;
        case 7:
            myControls[i].value = 0; i++;
            myControls[i].value = 1; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
    }
}
