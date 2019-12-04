#ifndef __ALUCONTROL_H__
#define __ALUCONTROL_H__

#include <string>

using namespace std;

class ALUControl{

  public:
   int getControlInput_1();
   int getControlInput_2();
   void setControlInput(int input1, int input2);
   void setImmediate(string imm);

  private:
   int controlInput1;
   int controlInput2;
   string immediate;
};

#endif
