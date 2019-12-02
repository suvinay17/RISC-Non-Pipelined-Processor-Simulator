#ifndef __ALUCONTROL_H__
#define __ALUCONTROL_H__

#include <string>

using namespace std;

class ALUControl{

  public:
   int getControlInput();
   void setControlInput(int input);
   void setImmediate(string imm);

  private:
   int controlInput;
   string immediate;
};

#endif
