#include "ALUControl.h"

int ALUControl::getControlInput_1(){
  return controlInput1;
}

int ALUControl::getControlInput_2(){
  return controlInput2;
}

void ALUControl::setControlInput(int input1, int input2){
  controlInput1 = input1;
  controlInput2 = input2;

}

void ALUControl::setImmediate(string imm){
  immediate = imm;

}

string ALUControl::getControlOutput(int input1, int input2, string funct)
{
   string last4 = funct.substr(2); 
   if(input1 == 0 && input2 == 1)
   {
        return "compare";
   }
   else if(input1 == 1 && input2 == 0)
   {
       if(funct == "0000")
           return "add";
       else if(funct == "0010")
           return "sub";
       else if(funct == "1010")
           return "lessThan";
   }
}
