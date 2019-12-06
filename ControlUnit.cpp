//Written by Jimmy, control unit.cpp
#include "ControlUnit.h"
//Constructor for control unit
ControlUnit::ControlUnit()
{
    int i = 0;
    myControls[0].name = "regDest"; myControls[i].value = -1; i++;
    myControls[1].name = "jump"; myControls[i].value = -1; i++;
    myControls[2].name = "branch"; myControls[i].value = -1; i++;
    myControls[3].name = "memRead"; myControls[i].value = -1; i++;
    myControls[4].name = "memToReg"; myControls[i].value = -1; i++;
    myControls[5].name = "aluOp1"; myControls[i].value = -1; i++;
    myControls[6].name = "aluOp2"; myControls[i].value = -1; i++;
    myControls[7].name = "memWrite"; myControls[i].value = -1; i++;
    myControls[8].name = "aluSrc"; myControls[i].value = -1; i++;
    myControls[9].name = "regWrite"; myControls[i].value = -1; i++;
}


//returns the control value based what control was asked for
int ControlUnit::getValue(string control)
{
    for(int i = 0; i < 10; i++) {
        if(myControls[i].name == control)
            return myControls[i].value;
    }
    return -1;
}

//sets the control values based on each instruction
void ControlUnit::setInstruction(Instruction inst)
{
    int i = 0;
    //the instruction name is returned as an enum from 0-7
    switch(inst.getName())
    {
        case 0:
            myControls[0].value = 1; i++;
            myControls[1].value = 0; i++;
            myControls[2].value = 0; i++;
            myControls[3].value = 0; i++;
            myControls[4].value = 0; i++;
            myControls[5].value = 1; i++;
            myControls[6].value = 0; i++;
            myControls[7].value = 0; i++;
            myControls[8].value = 0; i++;
            myControls[9].value = 1; i++;
        case 1:
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 0; i++;
            myControls[i].value = 1; i++;
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
            myControls[i].value = 0; i++;
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
