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
