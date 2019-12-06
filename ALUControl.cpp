//Written by Jimmy, implements ALU control
#include "ALUControl.h"

//returns control input 1 from ALU control
int ALUControl::getControlInput_1(){
  return controlInput1;
}
//returns control input 2 from ALU control 
int ALUControl::getControlInput_2(){
  return controlInput2;
}

//sets the two control inputs for ALU control
void ALUControl::setControlInput(int input1, int input2){
  controlInput1 = input1;
  controlInput2 = input2;

}

//sets the immediate value
void ALUControl::setImmediate(string imm){
  immediate = imm;

}

//returns the operation baed on the control inputs and functionCode
string ALUControl::getControlOutput(int input1, int input2, string funct)
{
   string last4 = funct.substr(2); 
   if(input1 == 0 && input2 == 1)
   {
        return "compare";
   }
   else if(input1 == 1 && input2 == 0)
   {
       if(last4 == "0000")
           return "add";
       else if(last4 == "0010")
           return "sub";
       else if(last4 == "1010")
           return "lessThan";
   }
   return "load/store";
}
