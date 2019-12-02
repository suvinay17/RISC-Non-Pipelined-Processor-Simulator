#include "ALUControl.h"

int ALUControl::getControlInput(){
  return controlInput;
}

void ALUControl::setControlInput(int input){
  controlInput = input;

}

void ALUControl::setImmediate(string imm){
  immediate = imm;

}
